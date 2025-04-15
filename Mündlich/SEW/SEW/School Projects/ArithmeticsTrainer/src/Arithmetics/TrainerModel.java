package Arithmetics;

public class TrainerModel
{
    public int currentResult;

    public Problem generateProblem()
    {
        return new Problem();
    }

    public void checkProblem(TrainerView trainerView)
    {
        if (currentResult == Integer.parseInt(trainerView.textInput.getText()))
        {
            trainerView.labelResult.setText("Correct");
        }
        else
        {
            trainerView.labelResult.setText("Incorrect :(");
        }
    }

    public void nextProblem(TrainerView trainerView)
    {
        Problem problem = generateProblem();
        currentResult = problem.getResult();
        trainerView.labelProblem.setText(problem.toString());
    }
}
