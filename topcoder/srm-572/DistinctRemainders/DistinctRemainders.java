public class DistinctRemainders
{
	static final long MOD = 1000000007;

	public int howMany(long N, int M)
	{
		long[][][] dp = new long[M+1][M+1][M*M];
		dp[0][0][0] = 1;
		int maxM = M * (M-1) / 2;
		for (int i = 0; i < M; i++)
			for (int j = 0; j <= M; j++)
				for (int k = 0; k <= maxM; k++)
				{
					dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k]) % MOD;
					if (j < M && k+i <= maxM)
						dp[i+1][j+1][k+i] = (dp[i+1][j+1][k+i] + dp[i][j][k]) % MOD;
				}

		long res = 0;
		for (int j = 1; j <= M; j++)
			for (int k = 0; k <= maxM; k++)
			{
				if ((N - k) % M != 0)
					continue;
				long items = ((N - k) / M) % MOD;
				long add = dp[M][j][k];
				for (int l = 0; l < j-1; l++)
					add = (add * (items + j - 1 - l)) % MOD;
				add = (add * j) % MOD;
				res = (res + add) % MOD;
			}
		return (int)res;
	}

	public String checkData(long N, int M)
	{
		if (N < 1 || N > 1000000000000000000L)
			return "N must be between 1 and 10^18, inclusive.";
		if (M < 1 || M > 50)
			return "M must be between 1 and 50, inclusive.";
		return "";
	}
}
