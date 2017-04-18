import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	static BigInteger[][] dp;
	static int k;

	static BigInteger opt(int n, int last)
	{
		if(n == 0) return BigInteger.valueOf(1);
		if(!dp[n][last].equals(BigInteger.valueOf(-1))) return dp[n][last];

		BigInteger sol = BigInteger.valueOf(0);
		for(int i=0; i<k; ++i)
		{
			if(n == 1 && i == 0) continue;
			if(last == 0 && i == 0) continue;
			sol = sol.add(opt(n-1, i));
		}
		return dp[n][last] = sol;
	}

	public static void main(String[] args)
	{
		int n;
		Scanner sc = new Scanner(System.in);
		dp = new BigInteger[182][11];
		n = sc.nextInt(); k = sc.nextInt();
		
		for(int i=0; i<=n; ++i) for(int j=0; j<=k; ++j) dp[i][j] = BigInteger.valueOf(-1);
		System.out.println(opt(n, k));
	}
}
