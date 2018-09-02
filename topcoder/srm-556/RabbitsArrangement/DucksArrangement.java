import java.util.*;

public class DucksArrangement
{
	static int[][] dp;
	
	private static int DP(int i, int rem)
	{
		if (dp[i][rem] == -1)
		{
			if (i == 0 && rem == 0)
				dp[i][rem] = 1;
			else if (i == 0)
				dp[i][rem] = 0;
			else
			{
				dp[i][rem] = 0;
				for (int j = 0; j*i <= rem; j++)
					dp[i][rem] += DP(i-1, rem-j*i);
			}
		}
		return dp[i][rem];
	}
	
	public static void main(String[] args)
	{
		dp = new int[100][100];
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				dp[i][j] = -1;
		
		System.out.println(DP(30, 30));
	}
}
