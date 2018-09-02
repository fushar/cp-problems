import java.util.*;

public class SRMChallengePhase
{
	final long MOD = 1000000007;
	
	int totalAttempts;
	int N;
	
	long[][][][] dp;
	long[][] comb;
	long[] fact;
	long[] pow;
	
	private void precompute(int N)
	{
		comb = new long[N+1][N+1];
		for (int i = 0; i <= N; i++)
		{
			comb[i][0] = 1;
			for (int j = 1; j <= i; j++)
				comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
		}
		
		fact = new long[N+1];
		fact[0] = 1;
		for (int i = 1; i <= N; i++)
			fact[i] = (i * fact[i-1]) % MOD;
		
		pow = new long[N+1];
		pow[0] = 1;
		for (int i = 1; i <= N; i++)
			pow[i] = ((N-1) * pow[i-1]) % MOD;
	}
	
	private long DP(int both, int challengers, int challengees, int last)
	{
		if (dp[both][challengers][challengees][last] != -1)
			return dp[both][challengers][challengees][last];
		
		long res = 0;
		
		if (both == 0)
		{
			if (challengers >= challengees)
			{
				res = 1;				
				res = (res * comb[challengers][challengees]) % MOD;
				res = (res * pow[challengers-challengees]) % MOD;
			}
		}
		else if (challengers > 0)
		{
			for (int i = last; i <= both; i++)
			{
				// top unsuccessful challenge
				long add = DP(both-i, challengers-1, challengees, i);
				add = (add * (N-1)) % MOD;
				add = (add * comb[challengers+both][i+1]) % MOD;
				res = (res + add) % MOD;
				
				// top successful challenge
				if (challengees > 0)
				{
					add = DP(both-i, challengers-1, challengees-1, i);
					add = (add * comb[challengers+both][i+1]) % MOD;
					res = (res + add) % MOD;
				}
			}
		}
		dp[both][challengers][challengees][last] = res;
		return res;
	}
	
	public int countWays(int N, int[] codersAttempted, int[] codersChallenged)
	{
		precompute(N);
		
		this.N = N;
		totalAttempts = codersAttempted.length;
		int challengers = 0, both = 0, challengees = 0;
		Arrays.sort(codersAttempted);
		Arrays.sort(codersChallenged);
		for (int i = 1; i <= N; i++)
		{
			boolean first = Arrays.binarySearch(codersAttempted, i) >= 0;
			boolean second = Arrays.binarySearch(codersChallenged, i) >= 0;
			
			if (first && second)
				both++;
			else if (first)
				challengers++;
			else if (second)
				challengees++;
		}
		dp = new long[N+1][N+1][N+1][N+1];
		for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
		for (int k = 0; k <= N; k++)
		for (int l = 0; l <= N; l++)
			dp[i][j][k][l] = -1;
		
		long res = DP(both, challengers, challengees, 1);
		res = (res * fact[both]) % MOD;
		res = (res * fact[challengers]) % MOD;
		res = (res * fact[challengees]) % MOD;
		
		return (int)res;
	}
	
	public String checkData(int N, int[] codersAttempted, int[] codersChallenged)
	{
		return "";
	}
	
	public static void main(String[] args)
	{
		SRMChallengePhase solver = new SRMChallengePhase();
		
		int N = 2;
		int[] codersAttempted = {1, 2};
		int[] codersChallenged = {};
		
		System.out.println(solver.countWays(N, codersAttempted, codersChallenged));
	}
}
