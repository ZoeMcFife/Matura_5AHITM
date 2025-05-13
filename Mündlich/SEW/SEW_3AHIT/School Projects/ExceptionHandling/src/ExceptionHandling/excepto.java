package ExceptionHandling;

public class excepto
{
    public static String getNeighbour(int[] array, int index) throws MyExceptionBsp_V2
    {
        String neighbours = null;

        try
        {
            neighbours = array[index - 1] + " " + array[index] + " " + array[index + 1];
        }
        catch (MyExceptionBsp_V1 e)
        {
            throw (MyExceptionBsp_V1) new
        }


        /*

                catch
         */

        return neighbours;
    }
}
