import java.util.*;

public class KingdomAndDice
{
	private static final int oo = 999999;
	
	public double newFairness(int[] firstDie, int[] secondDie, int X)
	{
		int N = firstDie.length;
		Arrays.sort(secondDie);
		
		int[] cnt = new int[N+1];
		for (int i = 0; i < N; i++)
		{
			int lo = secondDie[i] + 1;
			int hi = X+1;
			if (i+1 < N)
				hi = secondDie[i+1];
			
			int cur = hi - lo;
			for (int j = 0; j < N; j++)
				if (lo <= firstDie[j] && firstDie[j] <= hi)
					cur--;
			cnt[i+1] = Math.min(N, cur);
		}
		
		for (int i = 1; i <= N; i++)
			System.out.println(i + ": " + cnt[i]);
		
		int numBroken = 0, currentSum = 0;
		for (int i = 0; i < N; i++)
		{
			if (firstDie[i] == 0)
				numBroken++;
			for (int j = 0; j < N; j++)
				if (firstDie[i] > secondDie[j])
					currentSum++;
		}
		
		System.out.println("currentSum = " + currentSum);
		
		int[][] dp = new int[N+1][N*N+1];
		dp[0][0] = 0;
		for (int j = 1; j <= N*N; j++)
			dp[0][j] = oo;
		for (int i = 1; i <= N; i++)
			for (int j = 0; j <= N*N; j++)
			{
				dp[i][j] = dp[i-1][j];
				for (int k = 1; k <= cnt[i] && k*i <= j; k++)
					dp[i][j] = Math.min(dp[i][j], k + dp[i-1][j-k*i]);
			}
			
		int best = -1;
		for (int i = 0; i <= N*N; i++)
			if (dp[N][i] <= numBroken)
			{
				int cur = currentSum + i;
				if (best == -1 || Math.abs(cur*2 - N*N) < Math.abs(best*2 - N*N))
					best = cur;
			}
		return (double)best/(N*N);
	}
	
	public String checkData(int[] firstDie, int[] secondDie, int X)
	{
		if (firstDie.length != secondDie.length || firstDie.length < 2 || firstDie.length > 50)
			return "firstDie and secondDie must contain the same number of elements, between 2 and 50, inclusive.";
		if (X < 2*firstDie.length || X > 1000000000)
			return "X must be between 2*N and 1,000,000,000, inclusive, where N is the number of elements of firstDie.";
		for (int i = 0; i < firstDie.length; i++)
			if (firstDie[i] < 0 || firstDie[i] > X)
				return "Each element of firstDie must be between 0 and X, inclusive.";
		for (int i = 0; i < secondDie.length; i++)
			if (secondDie[i] < 1 || secondDie[i] > X)
				return "Each element of secondDie must be between 1 and X, inclusive.";
		
		boolean valid = true;
		for (int i = 0; i < firstDie.length; i++)
			for (int j = i+1; j < firstDie.length; j++)
				if (firstDie[i] != 0 && firstDie[i] == firstDie[j])
					valid = false;
		for (int i = 0; i < secondDie.length; i++)
			for (int j = i+1; j < secondDie.length; j++)
				if (secondDie[i] == secondDie[j])
					valid = false;
		for (int i = 0; i < firstDie.length; i++)
			for (int j = 0; j < secondDie.length; j++)
				if (firstDie[i] == secondDie[j])
					valid = false;
		
		if (!valid)
			return "Each integer between 1 and X, inclusive, must occur at most once considering both dice as defined in the problem statement.";
		return "";
	}
	
	public static void main(String[] args)
	{
		KingdomAndDice o = new KingdomAndDice();
		int[] firstDie = {7, 6};
		int[] secondDie = {5, 8};
		int X = 47;
		
		System.out.println(o.bestFairness(firstDie, secondDie, X));
	}
}
