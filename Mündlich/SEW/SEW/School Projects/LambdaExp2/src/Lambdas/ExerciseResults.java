package Lambdas;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class ExerciseResults {
    private List<Exercise> lstExercises;

    public ExerciseResults() {
        this.lstExercises = new ArrayList<>();
    }

    /* add a new exercise to the list */
    public void addExercise(String name, int[] thePoints) {
        lstExercises.add(new Exercise(name, thePoints));
    }

    /* returns a list of all names who were successful:
    * sum of all points has to be greater than a threshold  */
    /* filter ... filters all elements in the stream so that*/
    public List<String> getSuccessful(final int threshold)
    {
        List<String> successes = new ArrayList<>();

        for (Exercise exercise : this.lstExercises)
        {
            if (exercise.theResult >= threshold)
            {
                successes.add(exercise.name);
            }
        }

        return successes;
    }

    /* returns the average of all exercises,
    * causes a RuntimeException in case that the list will be empty */
    public double getAvg()
    {
        try
        {
            double sum = 0;
            for (Exercise exercise : lstExercises)
            {
                sum += exercise.theResult;
            }

            return sum / lstExercises.size();
        }
        catch (Exception e)
        {
            throw new RuntimeException("Average cannot be delivered!");
        }
    }

    /* returns a list of all names sorted by points asc and
    * in case of equivalent points sorted by name asc */
    public List<String> getSortedAsc()
    {
        List<Exercise> tmp = new ArrayList<>(List.copyOf(lstExercises));

        tmp.sort(new ExcerciseComparator());

        List<String> names = new ArrayList<>();

        for (Exercise e : tmp)
        {
            names.add(e.name);
        }

        return names;
    }
}
