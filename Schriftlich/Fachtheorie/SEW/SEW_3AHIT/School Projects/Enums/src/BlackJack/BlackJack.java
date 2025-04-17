package BlackJack;

import java.io.Console;
import java.util.*;
import java.io.Console;

public class BlackJack
{
    private List<Cards> staple = new ArrayList<>();
    private int playerPoints;
    private int computerPoints;

    private final int MAX_POINTS = 21;


    BlackJack()
    {
        createStaple();
        setPlayerPoints(0);
        setComputerPoints(0);
    }

    private Card pickRandomCard()
    {
        Random random = new Random();

        int randomCard = random.nextInt(0, this.staple.size());

        Card card = new Card(this.staple.get(randomCard).value, this.staple.get(randomCard).name);

        this.staple.remove(randomCard);

        return card;
    }


    private void playerTurn()
    {
        System.out.println("Pick card?");

        if (playerChoice())
        {
            Card pickedCard = pickRandomCard();
            System.out.println("You picked: ");
            System.out.println(pickedCard.getName());
            System.out.println("Value: " + pickedCard.getValue());

            setPlayerPoints(getPlayerPoints() + pickedCard.getValue());
        }
        else
        {
            System.out.println("Player refused taking a card.");
        }

    }

    private boolean playerChoice()
    {
        System.out.println("Y or N");

        Scanner scanner = new Scanner(System.in);

        if (scanner.next().toLowerCase(Locale.ROOT).equals("y"))
            return true;

        return false;
    }

    private void computerTurn()
    {
        Random random = new Random();

        boolean takeCard = random.nextBoolean();

        if (takeCard)
        {
            Card pickedCard = pickRandomCard();
            System.out.println("Computer picked: ");
            System.out.println(pickedCard.getName());
            System.out.println("Value: " + pickedCard.getValue());

            setComputerPoints(getComputerPoints() + pickedCard.getValue());
        }
        else
        {
            System.out.println("Computer refused taking a card.");
        }

    }

    private boolean isGameFinished()
    {
        if (getPlayerPoints() >= this.MAX_POINTS || getComputerPoints() >= this.MAX_POINTS)
            return true;

        if (this.staple.size() == 0)
            return true;

        return false;
    }

    private String pickWinner()
    {
        int playerDifference = this.MAX_POINTS - getPlayerPoints();
        int computerDifference = this.MAX_POINTS - getComputerPoints();

        if (playerDifference < 0)
            return "Computer";
        if (computerDifference < 0)
            return "Player";

        if (playerDifference > computerDifference)
            return "Computer";

        return "Player";
    }

    public void startGame()
    {
        while (!isGameFinished())
        {
            System.out.println("_________________________________");
            System.out.println("Current Stats");
            System.out.println("Computer: " + getComputerPoints());
            System.out.println("Player: " + getPlayerPoints());
            System.out.println("_________________________________");
            playerTurn();
            computerTurn();
            System.out.println();
        }

        System.out.println(pickWinner() + " won!");

        System.out.println("_________________________________");
        System.out.println("Final Stats");
        System.out.println("Computer: " + getComputerPoints());
        System.out.println("Player: " + getPlayerPoints());
        System.out.println("_________________________________");
    }

    private void createStaple()
    {
        this.staple.clear();

        staple.add(Cards.TWO);
        staple.add(Cards.THREE);
        staple.add(Cards.FOUR);
        staple.add(Cards.FIVE);
        staple.add(Cards.SIX);
        staple.add(Cards.SEVEN);
        staple.add(Cards.EIGHT);
        staple.add(Cards.NINE);
        staple.add(Cards.TEN);
        staple.add(Cards.JOKER);
        staple.add(Cards.QUEEN);
        staple.add(Cards.KING);
        staple.add(Cards.ACE);

        staple.add(Cards.TWO);
        staple.add(Cards.THREE);
        staple.add(Cards.FOUR);
        staple.add(Cards.FIVE);
        staple.add(Cards.SIX);
        staple.add(Cards.SEVEN);
        staple.add(Cards.EIGHT);
        staple.add(Cards.NINE);
        staple.add(Cards.TEN);
        staple.add(Cards.JOKER);
        staple.add(Cards.QUEEN);
        staple.add(Cards.KING);
        staple.add(Cards.ACE);

        staple.add(Cards.TWO);
        staple.add(Cards.THREE);
        staple.add(Cards.FOUR);
        staple.add(Cards.FIVE);
        staple.add(Cards.SIX);
        staple.add(Cards.SEVEN);
        staple.add(Cards.EIGHT);
        staple.add(Cards.NINE);
        staple.add(Cards.TEN);
        staple.add(Cards.JOKER);
        staple.add(Cards.QUEEN);
        staple.add(Cards.KING);
        staple.add(Cards.ACE);

        staple.add(Cards.TWO);
        staple.add(Cards.THREE);
        staple.add(Cards.FOUR);
        staple.add(Cards.FIVE);
        staple.add(Cards.SIX);
        staple.add(Cards.SEVEN);
        staple.add(Cards.EIGHT);
        staple.add(Cards.NINE);
        staple.add(Cards.TEN);
        staple.add(Cards.JOKER);
        staple.add(Cards.QUEEN);
        staple.add(Cards.KING);
        staple.add(Cards.ACE);
    }

    public int getPlayerPoints()
    {
        return playerPoints;
    }

    private void setPlayerPoints(int playerPoints)
    {
        this.playerPoints = playerPoints;
    }

    public int getComputerPoints()
    {
        return computerPoints;
    }

    private void setComputerPoints(int computerPoints)
    {
        this.computerPoints = computerPoints;
    }


}
