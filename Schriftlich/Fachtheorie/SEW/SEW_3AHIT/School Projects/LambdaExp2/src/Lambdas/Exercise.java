package Lambdas;

import java.util.Arrays;

public class Exercise {
    String name;
    int[] thePoints;
    int theResult;

    public Exercise(String name, int[] thePoints) {
        this.name = name;
        /* get a copy of the point-Array */
        this.thePoints = Arrays.copyOf(thePoints, thePoints.length);
        /* sum up the points */
        this.theResult = Arrays.stream(this.thePoints).sum();
    }
}
