#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#pragma pack(1)

enum mode
{
    info = 1,
    rgb = 2,
    grayscale = 3,
    pattern = 4
};

enum pattern
{
    lines,
    overlay,
    circle
};

typedef struct
{
    char signature[2];
    unsigned int fileSize;
    unsigned int reserved;
    unsigned int offset;
} BmpHeader;

typedef struct
{
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short planeCount;
    unsigned short bitDepth;
    unsigned int compression;
    unsigned int compressedImageSize;
    unsigned int horizontalResolution;
    unsigned int verticalResolution;
    unsigned int numColors;
    unsigned int importantColors;
} BmpImageInfo;

typedef struct
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Rgb;

void getBmpFileInfo(char filename[], BmpHeader *bmpHeader, BmpImageInfo *bmpImageInfo);

Rgb** getRgbArray(char srcFile[]);

void displayBmpInfo(char srcFile[]);
void displayBmpRgbValues(char srcFile[]);
void createGrayScaleImage(char srcFile[], char outputFile[]);
void addPatternToImage(char srcFile[], char outputFile[], int pattern, char overlayFile[]);

void Usage(char message[]);
void verifyParameters(int argc, char *argv[]);

int getMode(char *argv[]);
int getPatternMode(char *argv[]);

Rgb** createRgbArray(int width, int height); /// whenever things don't work --> StackOverflow
Rgb darkenPixel(Rgb pixel, int procentDarker);
Rgb lightenPixel(Rgb pixel);

void getBmpCenterCoordinates(int *x, int *y, char srcFile[]);
void writeRgbArrayToFile(BmpHeader bmpHeader, BmpImageInfo bmpImageInfo, Rgb** rgbArray, char file[]);

int main(int argc, char *argv[])
{
    char srcFile[1000];
    char outputFile[1000];
    int programMode;
    int patternMode;

    verifyParameters(argc, argv);

    programMode = getMode(argv);

    if (argc > 4 && programMode == pattern)
    {
        patternMode = getPatternMode(argv);
    }
    else if (programMode == pattern && argc < 4)
    {
        Usage("Missing parameters");
    }

    strcpy(srcFile, argv[2]);

    if (argc > 3)
    {
        strcpy(outputFile, argv[3]);
    }

    switch (programMode)
    {
        case info:
            displayBmpInfo(srcFile);
            break;
        case rgb:
            displayBmpRgbValues(srcFile);
            break;
        case grayscale:
            createGrayScaleImage(srcFile, outputFile);
            ShellExecute(NULL, "open", outputFile, NULL, NULL, SW_SHOWNORMAL);
            break;
        case pattern:
            addPatternToImage(srcFile, outputFile, patternMode, argv[5]);
            ShellExecute(NULL, "open", outputFile, NULL, NULL, SW_SHOWNORMAL);
            break;
    }

    return EXIT_SUCCESS;
}

void displayBmpInfo(char srcFile[])
{
    BmpHeader bmpHeader;
    BmpImageInfo bmpImageInfo;

    getBmpFileInfo(srcFile, &bmpHeader, &bmpImageInfo);

    printf("%s Information:\n", srcFile);
    printf("File Size: %d\n", bmpHeader.fileSize);
    printf("Reserved Bytes: %d\n", bmpHeader.reserved);
    printf("Offset: %d\n", bmpHeader.offset);
    printf("Header Size: %d\n", bmpImageInfo.headerSize);
    printf("Width: %d\n", bmpImageInfo.width);
    printf("Height: %d\n", bmpImageInfo.height);
    printf("Plane Count: %d\n", bmpImageInfo.planeCount);
    printf("Bit Depth: %d\n", bmpImageInfo.bitDepth);
    printf("Compression: %d\n", bmpImageInfo.compression);
    printf("Compressed Image Size: %d\n", bmpImageInfo.compressedImageSize);
    printf("Horizontal Resolution: %d\n", bmpImageInfo.horizontalResolution);
    printf("Vertical Resolution: %d\n", bmpImageInfo.verticalResolution);
    printf("numColors: %d\n", bmpImageInfo.numColors);
    printf("Important Colors: %d\n", bmpImageInfo.importantColors);
}

void displayBmpRgbValues(char srcFile[])
{
    BmpHeader bmpHeader;
    BmpImageInfo bmpImageInfo;

    getBmpFileInfo(srcFile, &bmpHeader, &bmpImageInfo);

    Rgb** rgbArray = getRgbArray(srcFile);

    printf("PIXELS\n");

    int i, j;

    for (i = 0; i < bmpImageInfo.height; i++)
    {
        for (j = 0; j < bmpImageInfo.width; j++)
        {
            printf("[R: %2x G: %2x B: %2x] ", rgbArray[i][j].red, rgbArray[i][j].green, rgbArray[i][j].blue);
        }
        printf("\n");
    }

    free(rgbArray);

}

void createGrayScaleImage(char srcFile[], char outputFile[])
{
    BmpHeader bmpHeader;
    BmpImageInfo bmpImageInfo;

    getBmpFileInfo(srcFile, &bmpHeader, &bmpImageInfo);

    Rgb** rgbArray = getRgbArray(srcFile);

    int i, j;

    ///loops through every pixel and turns it gray
    for (i = 0; i < bmpImageInfo.height; i++)
    {
        for (j = 0; j < bmpImageInfo.width; j++)
        {
            int newColor = (rgbArray[i][j].red * 0.299 + rgbArray[i][j].green * 0.587 + rgbArray[i][j].blue * 0.114);

            rgbArray[i][j].blue = (char)newColor;
            rgbArray[i][j].red = (char)newColor;
            rgbArray[i][j].green = (char)newColor;
        }
    }

    writeRgbArrayToFile(bmpHeader, bmpImageInfo, rgbArray, outputFile);
    free(rgbArray);

}

void addPatternToImage(char srcFile[], char outputFile[], int pattern, char overlayFile[])
{
    BmpHeader bmpHeader;
    BmpImageInfo bmpImageInfo;

    getBmpFileInfo(srcFile, &bmpHeader, &bmpImageInfo);

    int i, j;
    int bytecount = (sizeof(Rgb) * bmpImageInfo.width) % 4;

    if (bytecount == 0)
        bytecount = 4;

    int overlayHeight, overlayWidth;

    Rgb** rgbArray = getRgbArray(srcFile);
    Rgb** overlayRgbArray;

    if (pattern == overlay)
    {
        overlayRgbArray = getRgbArray(overlayFile);

        BmpHeader bmpHeaderoverlayfile;
        BmpImageInfo bmpImageInfooverlayfile;

        getBmpFileInfo(overlayFile, &bmpHeaderoverlayfile, &bmpImageInfooverlayfile);

        overlayHeight = bmpImageInfooverlayfile.height;
        overlayWidth = bmpImageInfooverlayfile.width;
    }

    switch (pattern)
    {
        case lines:
            ///draws lines with variable width
            for (i = 0; i < bmpImageInfo.width; i++)
            {
                for (j = 0; j < bmpImageInfo.height; j++)
                {
                    if (i % (int)(bmpImageInfo.height / 10) > (int)(bmpImageInfo.height / 20))
                    {
                        rgbArray[i][j] = darkenPixel(rgbArray[i][j], 30);
                    }
                }
            }
            break;
        case circle:;
            int radius = bmpImageInfo.width / 2;
            int k;

            int y, x;

            getBmpCenterCoordinates(&x, &y, srcFile);

            ///draws k circles that get smaller every iteration
            ///if k is divisible by 2 lighten the image which results in the "target" effect in the final image
            for (k = 0; k < bmpImageInfo.width / 60; k++)
            {
                radius -= 30;
                for (i = 0; i < bmpImageInfo.height; i++)
                {
                    for (j = 0; j < bmpImageInfo.width; j++)
                    {
                        if (((i - y) * (i - y) + (j - x) * (j - x)) <= radius * radius)
                        {
                            if (k % 2 == 0)
                            {
                                rgbArray[i][j] = darkenPixel(rgbArray[i][j], 30);
                            }
                            else
                            {
                                rgbArray[i][j] = lightenPixel(rgbArray[i][j]);
                            }
                        }
                    }
                }
            }
            break;
        case overlay:;
            Rgb emptyPixel;

            emptyPixel.blue = 0xff;
            emptyPixel.green = 0xff;
            emptyPixel.red = 0xff;

            i = 0;
            j = 0;

            /// Basically just loops through the image in increments of overlayHeight and overlayWidth
            /// then loops through the every pixel in the overlay and if it isn't white darken the current pixel
            for (i = 0; i < bmpImageInfo.height; i += overlayHeight)
            {
                for (j = 0; j < bmpImageInfo.width; j += overlayWidth)
                {
                    int heightOffset = i;
                    int widthOffset = j;

                    int k, l;

                    for (k = 0; k < overlayHeight; k++)
                    {
                        for (l = 0; l < overlayWidth; l++)
                        {
                            if ((overlayRgbArray[k][l].green != emptyPixel.green && overlayRgbArray[k][l].green != emptyPixel.red && overlayRgbArray[k][l].red != emptyPixel.red) && ((k + heightOffset) <= bmpImageInfo.height - 1 && (l + widthOffset) <= bmpImageInfo.width - 1))
                            {
                                rgbArray[k + heightOffset][l + widthOffset] = darkenPixel(rgbArray[k + heightOffset][l + widthOffset], 30);
                            }

                        }
                    }

                }
            }

            break;
    }

    writeRgbArrayToFile(bmpHeader, bmpImageInfo, rgbArray, outputFile);
    free(rgbArray);

}

void Usage(char message[])
{
    printf("USAGE: bitmap.exe [info rgbValues createGrayscale createPattern] srcFile [outputFile] [patternMode] [overlayFile]\n\n");

    printf("\nUSAGE PARAMETERS \n--- Program Mode ---\n- info\n- rgbValues\n- createGrayscale\n- createPattern\n--- Bitmap File ---\nsrcFile\n- outputFile \n--- createPattern Mode ---\n- lines\n- circle\n- overlay \n--- createPattern overlay ---\n- overlayBitmap\n");

    printf("Error Message: %s\n", message);
    exit(EXIT_FAILURE);
}

void verifyParameters(int argc, char *argv[])
{
    if (argc < 3 || argc > 6)
        Usage("Incorrect amount of parameters");

    if (access(argv[2], F_OK) != 0)
    {
        printf("File %s isn't available.\n", argv[2]);
        Usage("Wrong Parameters");
    }
}

void getBmpFileInfo(char filename[], BmpHeader *bmpHeader, BmpImageInfo *bmpImageInfo)
{
    FILE *fp;

    fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("File %s couldn't be accessed.\n", filename);
        Usage("File Access Error");
    }

    fread(bmpHeader, sizeof(BmpHeader), 1, fp);
    fread(bmpImageInfo, sizeof(BmpImageInfo), 1, fp);
}

///darkens pixel by a set percentage
Rgb darkenPixel(Rgb pixel, int procentDarker)
{
    pixel.blue -= (procentDarker * pixel.blue) / 100;
    pixel.red -= (procentDarker * pixel.red) / 100;
    pixel.green -= (procentDarker * pixel.green) / 100;

    return pixel;
}

/// lightens a pixel to negate the -30% darkening when drawing the circles
Rgb lightenPixel(Rgb pixel)
{
    pixel.blue = (int)(pixel.blue * (10 / 7.0));
    pixel.red = (int)(pixel.red * (10 / 7.0));
    pixel.green = (int)(pixel.green * (10 / 7.0));

    return pixel;
}

/// gets all pixels of a bitmap image
Rgb** getRgbArray(char srcFile[])
{
    BmpHeader bmpHeader;
    BmpImageInfo bmpImageInfo;

    getBmpFileInfo(srcFile, &bmpHeader, &bmpImageInfo);

    FILE *fp;
    Rgb** rgbArray = createRgbArray(bmpImageInfo.height, bmpImageInfo.width);

    fp = fopen(srcFile, "rb");

    if (fp == NULL)
    {
        printf("File %s couldn't be accessed.\n", srcFile);
        Usage("File Access Error");
    }

    fseek(fp, 0x36, SEEK_SET);

    int i, j;
    int bytecount = (sizeof(Rgb) * bmpImageInfo.width) % 4;

    if (bytecount == 0)
        bytecount = 4;

    for (i = 0; i < bmpImageInfo.height; i++)
    {
        for (j = 0; j < bmpImageInfo.width; j++)
        {
            fread(&rgbArray[i][j], sizeof(Rgb), 1, fp);
        }
        fseek(fp, 4 - bytecount, SEEK_CUR);
    }

    fclose(fp);

    return rgbArray;
}

///writes bitmap data to a file
void writeRgbArrayToFile(BmpHeader bmpHeader, BmpImageInfo bmpImageInfo, Rgb** rgbArray, char file[])
{
    FILE *fp;

    fp = fopen(file, "wb");

    if (fp == NULL)
    {
        printf("File %s couldn't be accessed.\n", file);
        Usage("File Access Error");
    }

    fwrite(&bmpHeader, sizeof(BmpHeader), 1, fp);
    fwrite(&bmpImageInfo, sizeof(BmpImageInfo), 1, fp);

    fseek(fp, 0x36, SEEK_SET);

    int i, j, empty = 0;
    int bytecount = (sizeof(Rgb) * bmpImageInfo.width) % 4;
    if (bytecount == 0)
        bytecount = 4;

    for (i = 0; i < bmpImageInfo.height; i++)
    {
        for (j = 0; j < bmpImageInfo.width; j++)
        {
            fwrite(&rgbArray[i][j], sizeof(Rgb), 1, fp);
        }
        fwrite(&empty, 4 - bytecount, 1, fp);
    }

    fclose(fp);

    free(rgbArray);

    printf("Created File %s.\n", file);
}

/// returns mode
int getMode(char *argv[])
{
    if (strcmp(argv[1], "info") == 0)
        return info;
    else if (strcmp(argv[1], "rgbValues") == 0)
        return rgb;
    else if (strcmp(argv[1], "createGrayscale") == 0)
        return grayscale;
    else if (strcmp(argv[1], "createPattern") == 0)
        return pattern;
    else
        Usage("Incorrect or missing mode");

    return -1;
}

/// returns mode
int getPatternMode(char *argv[])
{
    if (strcmp(argv[4], "lines") == 0)
        return lines;
    else if (strcmp(argv[4], "circle") == 0)
        return circle;
    else if (strcmp(argv[4], "overlay") == 0)
        return overlay;
    else
        Usage("Incorrect or missing mode");

    return -1;
}

/// allocates memory to an Rgb array
Rgb** createRgbArray(int m, int n)
{
    Rgb* values = calloc(m * n, sizeof(Rgb));
    Rgb** rows = malloc(m * sizeof(Rgb*));

    int i;

    for (i = 0; i < m; i++)
    {
        rows[i] = values + i * n;
    }

    return rows;
}

/// Gets the center coordinates of a bitmap image
void getBmpCenterCoordinates(int *x, int *y, char srcFile[])
{
    BmpHeader bmpHeader;
    BmpImageInfo bmpImageInfo;

    getBmpFileInfo(srcFile, &bmpHeader, &bmpImageInfo);

    *x = (int)(bmpImageInfo.width / 2.0);
    *y = (int)(bmpImageInfo.height / 2.0);
}
