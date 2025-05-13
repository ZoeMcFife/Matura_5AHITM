#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(int argc, char **argv)
{
    int charsTotal = 0;
    int linesTotal = 0;
    int wordsTotal = 0;

    int chars = 0;
    int lines = 0;
    int words = 0;

    int i;

    for (i = 1; i < argc; i++)
    {
        chars = countCharacters(argv[i]);
        lines = countLines(argv[i]);
        words = countWords(argv[i]);

        printf("%d %5d %5d %s\n", lines, words, chars, argv[i]);

        if (chars != -1) charsTotal += chars;
        if (lines != -1) linesTotal += lines;
        if (words != -1) wordsTotal += words;
    }

    if (argc > 2) printf("%d %5d %5d total\n", linesTotal, wordsTotal, charsTotal);

    return EXIT_SUCCESS;
}
