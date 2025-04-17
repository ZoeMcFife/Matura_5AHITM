package CC;

import javax.swing.text.Position;

public class MarsRover
{
    private double currentSteeringAngle;
    private double maxSteeringAngle;
    private double wheelBase;

    private Point currentPosition;


    MarsRover(double maxSteeringAngle, double wheelBase)
    {
        setCurrentSteeringAngle(0);
        setMaxSteeringAngle(maxSteeringAngle);
        setWheelBase(wheelBase);

        this.currentPosition = new Point(0,0);
    }

    public String getNewPositionAndDirection(double distance)
    {
        double angle = (distance * 360.0) / (2.0 * Math.PI * calculateTurnRadius());

        Point turningMiddlePoint = new Point(0,0);

        turningMiddlePoint = turningMiddlePoint.translate(-calculateTurnRadius(), 0);

        System.out.println(turningMiddlePoint);

        System.out.println(turningMiddlePoint.rotateVector(angle));

        this.currentPosition.add(turningMiddlePoint.rotateVector(angle));

        return currentPosition.getX() + " " + currentPosition.getY() + " " + angle;
    }


    public double calculateTurnRadius()
    {
        return Math.round(this.wheelBase / Math.sin(Math.toRadians(currentSteeringAngle)) * 100.0) / 100.0;
    }

    public static double calculateHypotheticalTurnRadius(double wheelBase, double steeringAngle)
    {
        return Math.round(wheelBase / Math.sin(Math.toRadians(steeringAngle)) * 100.0) / 100.0;
    }


    public void setCurrentSteeringAngle(double currentSteeringAngle)
    {
        this.currentSteeringAngle = currentSteeringAngle;
    }

    public double getCurrentSteeringAngle()
    {
        return currentSteeringAngle;
    }

    public void setMaxSteeringAngle(double maxSteeringAngle)
    {
        this.maxSteeringAngle = maxSteeringAngle;
    }

    public double getMaxSteeringAngle()
    {
        return maxSteeringAngle;
    }

    public void setWheelBase(double wheelBase)
    {
        this.wheelBase = wheelBase;
    }

    public double getWheelBase()
    {
        return wheelBase;
    }
}
