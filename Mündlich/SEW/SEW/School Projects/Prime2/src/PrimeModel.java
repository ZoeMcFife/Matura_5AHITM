public class PrimeModel
{
    public int[] generatePrimes(int n)
    {
        int[] primes = new int[n];
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (isPrime(i))
            {
                primes[j] = i;
                j++;
            }
        }

        return primes;
    }

    static boolean isPrime(int n)
    {
        if (n <= 1)
            return false;

        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;

        return true;
    }
}
