package com.company;

import java.awt.*;

public class Calculator extends Frame
{
    private Button additionButton;
    private Button subtractionButton;
    private Button divisionButton;
    private Button multiplicationButton;

    private int buttonStartPosX = 40;
    private int buttonStartPosY = 120;
    private int buttonSize = 30;

    private Label number1Label;
    private Label number2Label;

    public static TextField number1;
    public static TextField number2;

    private int inputStartPosX = 35;
    private int inputStartPosY = 60;
    private int textFieldLength = 100;
    private int labelLength = 100;
    private int inputElementHeight = 20;

    private Label resultLabel;
    public static TextField result;

    Calculator()
    {
        super("Calculator");
        this.addWindowListener(new CustomWindowAdapter());
        this.setSize(300, 200);
        this.setLayout(null);

        additionButton = new Button("+");
        additionButton.setBounds(buttonStartPosX, buttonStartPosY, buttonSize, buttonSize);
        subtractionButton = new Button("-");
        subtractionButton.setBounds(buttonStartPosX + buttonSize * 2, buttonStartPosY, buttonSize, buttonSize);
        divisionButton = new Button("/");
        divisionButton.setBounds(buttonStartPosX + buttonSize * 4, buttonStartPosY, buttonSize, buttonSize);
        multiplicationButton = new Button("*");
        multiplicationButton.setBounds(buttonStartPosX + buttonSize * 6, buttonStartPosY, buttonSize, buttonSize);

        additionButton.addActionListener(new CalculatorActionListener());
        subtractionButton.addActionListener(new CalculatorActionListener());
        divisionButton.addActionListener(new CalculatorActionListener());
        multiplicationButton.addActionListener(new CalculatorActionListener());

        this.add(additionButton);
        this.add(subtractionButton);
        this.add(divisionButton);
        this.add(multiplicationButton);

        number1Label = new Label("First number:");
        number1Label.setBounds(inputStartPosX, inputStartPosY, labelLength, inputElementHeight);
        number2Label = new Label("Second number");
        number2Label.setBounds(inputStartPosX, inputStartPosY + inputElementHeight + 10, labelLength, inputElementHeight);

        number1 = new TextField();
        number1.setBounds(inputStartPosX + labelLength + 20, inputStartPosY, textFieldLength, inputElementHeight);

        number2 = new TextField();
        number2.setBounds(inputStartPosX + labelLength + 20, inputStartPosY + inputElementHeight + 10, textFieldLength, inputElementHeight);

        this.add(number1Label);
        this.add(number2Label);
        this.add(number1);
        this.add(number2);

        resultLabel = new Label("Result:");
        resultLabel.setBounds(inputStartPosX, buttonStartPosY + buttonSize + 10, labelLength, inputElementHeight);

        result = new TextField();
        result.setBounds(inputStartPosX + labelLength + 20, buttonStartPosY + buttonSize + 10, textFieldLength, inputElementHeight);

        this.add(resultLabel);
        this.add(result);
    }
}
