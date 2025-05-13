package com.company;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculatorActionListener implements ActionListener
{
    @Override
    public void actionPerformed(ActionEvent e)
    {
        String action = e.getActionCommand();

        double number1 = Double.parseDouble(Calculator.number1.getText().trim());
        double number2 = Double.parseDouble(Calculator.number2.getText().trim());

        switch (action)
        {
            case "+":
                Calculator.result.setText(String.valueOf(number1 + number2));
                break;

            case "-":
                Calculator.result.setText(String.valueOf(number1 - number2));
                break;

            case "/":
                if (number2 == 0)
                {
                    Calculator.result.setText("Undefined");
                }
                else
                {
                    Calculator.result.setText(String.valueOf(number1 / number2));
                }
                break;

            case "*":
                Calculator.result.setText(String.valueOf(number1 * number2));
                break;

            default:
                Calculator.result.setText("Error");
                break;
        }
    }
}
