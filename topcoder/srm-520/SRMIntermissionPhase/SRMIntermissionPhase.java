
public class SRMIntermissionPhase
{
	final int MOD = 1000000007;
	public int countWays(int[] points, String[] description)
	{
		// make all inputs 1-indexed
		
		int[] oldp = points;
		points = new int[] {0, oldp[0], oldp[1], oldp[2]};
		
		String[] oldd = description;
		description = new String[oldd.length+1];
		for (int i = 1; i <= oldd.length; i++)
			description[i] = " " + oldd[i-1];
		
		// start the algorithm 
		
		int N = description.length - 1;
		int M = points[1] + points[2] + points[3];
		
		int[][][] ways = new int[N+1][2][M+2];
		
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j <= M; j++)
				ways[i][0&1][j+1] = 1;
			for (int k = 1; k <= 3; k++)
				for (int j = 0; j <= M; j++)
				{
					int minScore = 0, maxScore = 0;
					if (description[i].charAt(k) == 'Y')
					{
						minScore = 1;
						maxScore = Math.min(j, points[k]);
					}
					ways[i][k&1][j+1] = (ways[i][k&1][j-1+1] + ways[i][(k-1)&1][j-minScore+1]) % MOD;
					ways[i][k&1][j+1] = (ways[i][k&1][j+1] - ways[i][(k-1)&1][j-maxScore-1+1] + MOD) % MOD;
				}
		}
		
		int[][] dp = new int[2][M+2];
		
		for (int j = -1; j <= M; j++)
			dp[(N+1)&1][j+1] = 1;
		
		for (int i = N; i >= 1; i--)
		{
			dp[i&1][-1+1] = 0;
			for (int j = 0; j <= M; j++)
			{
				dp[i&1][j+1] = dp[i&1][j-1+1];
				long add = (long)(ways[i][3&1][j+1] - ways[i][3&1][j-1+1] + MOD) * dp[(i+1)&1][j-1+1];
				dp[i&1][j+1] = (int)((dp[i&1][j+1] + add) % MOD);
			}
		}
		return dp[1&1][M+1];
	}
	
	public String checkData(int[] points, String[] description)
	{
		if (points.length != 3)
			return "points must contain exactly 3 elements.";
		if (points[0] < 25000 || points[0] > 30000)
			return "points[0] must be between 25000 and 30000, inclusive.";
		if (points[1] < 45000 || points[1] > 60000)
			return "points[1] must be between 45000 and 60000, inclusive.";
		if (points[2] < 90000 || points[2] > 110000)
			return "points[2] must be between 90000 and 110000, inclusive.";
		
		int N = description.length;
		if (N < 1 || N > 20)
			return "description must contain between 1 and 20 elements, inclusive.";
		for (int i = 0; i < N; i++)
		{
			String s = description[i];
			if (s.length() != 3)
				return "Each element of description must contain exactly 3 characters.";
			for (int j = 0; j < 3; j++)
			{
				char c = s.charAt(j);
				if (c != 'N' && c != 'Y')
					return "Each character in description must be 'Y' or 'N'.";
			}
		}
		return "";
	}
	
	public static void main(String[] arg)
	{
		SRMIntermissionPhase tobing = new SRMIntermissionPhase();
		
		int[] points = {25600, 51200, 102400};
		String[] description = {"NYY",
				                        "YNY",
				                        "YYY",
				                        "YNN",
				                        "YYN",
				                        "NNY",
				                        "NYN",
				                        "NNN"};
		System.out.println(tobing.countWays(points, description));
	}
}
