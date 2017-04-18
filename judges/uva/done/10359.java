import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main(String[] args)
	{
		int n;
		Scanner sc = new Scanner(System.in);
		BigInteger[] dp = new BigInteger[251];

		dp[0] = BigInteger.valueOf(1); dp[1] = BigInteger.valueOf(1);
		for(int i=2; i<=250; ++i)
			dp[i] = dp[i-1].add(BigInteger.valueOf(2).multiply(dp[i-2]));
		
		while(sc.hasNext())
		{
			n = sc.nextInt();
			System.out.println(dp[n]);
		}
	}
}
