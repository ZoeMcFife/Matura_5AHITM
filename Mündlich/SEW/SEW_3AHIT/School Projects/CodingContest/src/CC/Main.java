package CC;

public class Main
{
    public static void main(String[] args)
    {
        MarsRover rover = new MarsRover(40, 1);
        rover.setCurrentSteeringAngle(30);
        //System.out.println(rover.calculateTurnRadius());
/*
        System.out.println(MarsRover.calculateHypotheticalTurnRadius(1, 13.76));
        System.out.println(MarsRover.calculateHypotheticalTurnRadius(1, 2.34));
        System.out.println(MarsRover.calculateHypotheticalTurnRadius(1, 90));
        System.out.println(MarsRover.calculateHypotheticalTurnRadius(2.45, 90));
*/

        MarsRover r = new MarsRover(230, 1);
        r.setCurrentSteeringAngle(30);

        System.out.println(r.getNewPositionAndDirection(1));

    }
}
