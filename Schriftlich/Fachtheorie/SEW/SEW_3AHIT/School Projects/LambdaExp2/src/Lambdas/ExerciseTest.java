package Lambdas;

public class ExerciseTest {
    public static void main(String[] args) {
        ExerciseResults res = new ExerciseResults();

        int[] x = {3, 5, 7, 2}; // 17
        res.addExercise("Duffy", x);
        int[] y = {6, 5, 7, 7}; // 25
        res.addExercise("Trick", y);
        int[] z = {1, 2, 3, 1}; // 7
        res.addExercise("Track", z);
        int[] a = {7, 7, 7, 7}; // 28
        res.addExercise("Trick", a);


        System.out.println("avg: " + res.getAvg());
        System.out.println("successful: " + res.getSuccessful(14));
        System.out.println("sorted: " + res.getSortedAsc());
    }
}
