package Arithmetics;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TrainerController
{
    private TrainerView trainerView;
    private TrainerModel trainerModel;
    private int currentResult;

    public TrainerController(TrainerView trainerView, TrainerModel trainerModel)
    {
        this.trainerModel = trainerModel;
        this.trainerView = trainerView;

        this.trainerView.buttonOK.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                trainerModel.checkProblem(trainerView);
            }
        });

        this.trainerView.buttonNext.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                trainerModel.nextProblem(trainerView);
            }
        });
    }


}
