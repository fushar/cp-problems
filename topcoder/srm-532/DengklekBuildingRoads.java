public class DengklekBuildingRoads
{
	static final long MOD = 1000000007;
	public int numWays(int N, int M, int K)
	{
		long[][][][] dp = new long[N+1][M+1][K+1][1<<(K+1)];
		dp[N][M][0][0] = 1;
		
		for (int i = N-1; i >= 0; i--)
		{
			for (int j = M; j >= 0; j--)
			{
				// k == K
				for (int mask = 0; mask < 1<<(K+1); mask++)
				{
					// if node (i-K) has even degree
					if ((mask & (1<<K)) == 0)
						dp[i][j][K][mask] = dp[i+1][j][0][mask<<1];
				}
				for (int k = K-1; k >= 0; k--)
				{
					for (int mask = 0; mask < 1<<(K+1); mask++)
					{
						// don't build a road from (i) to (i-k-1)
						dp[i][j][k][mask] = dp[i][j][k+1][mask];
						
						// build a road from (i) to (i-k-1)
						if (i-k-1 >= 0 && j+1 <= M)
						{
							dp[i][j][k][mask] += dp[i][j+1][k][mask^(1<<0)^(1<<(k+1))];
							dp[i][j][k][mask] %= MOD;
						}
					}
				}
			}
		}
		
		return (int)dp[0][0][0][0];
	}
	
	public String checkData(int N, int M, int K)
	{
		if (N < 1 || N > 30)
			return "N must be between 1 and 30, inclusive.";
		if (M < 0 || M > 30)
			return "M must be between 0 and 30, inclusive.";
		if (K < 1 || K > 30)
			return "K must be between 1 and 8, inclusive.";
		return "";
	}
	
	public static void main(String[] args)
	{
		DengklekBuildingRoads f = new DengklekBuildingRoads();
		System.out.println(f.numWays(4, 3, 3));
	}
}
