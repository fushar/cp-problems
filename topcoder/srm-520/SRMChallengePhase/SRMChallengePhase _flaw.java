import java.util.*;

public class SRMChallengePhase
{
	final long MOD = 1000000007;
	
	int totalAttempts;
	int N;
	
	long[][][] dp;
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
	
	private int DP(int both, int challengers, int challengees)
	{
		long res = dp[both][challengers][challengees];
		if (res != -1)
			return (int)res;
		
		res = 0;
		
		if (both == 0) // base case
		{
			if (challengers == 0 && challengees == 0)
				res = 1;
			else
				res = 0;
		}
		else if (challengers > 0)
		{
			for (int i = 1; i <= both; i++)
			{
				// top unsuccessful challenge
				long add = DP(both-i, challengers-1, challengees);
				add = (add * (N-1)) % MOD;
				add = (add * comb[challengers+both][i+1]) % MOD;
				res = (res + add) % MOD;
				
				// top successful challenge
				if (challengees > 0)
				{
					add = DP(both-1, challengers-1, challengees-1);
					add = (add * comb[challengers+both][i+1]) % MOD;
					res = (res + add) % MOD;
				}
			}
		}
		
		dp[both][challengers][challengees] = res;
		return (int)res;
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
		dp = new long[N+1][N+1][N+1];
		for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
		for (int k = 0; k <= N; k++)
			dp[i][j][k] = -1;
		
		long res = 0;
		
		for (int challengersRem = 0; challengersRem <= challengers; challengersRem++)
		for (int challengeesRem = 0; challengeesRem <= challengees && challengeesRem <= challengersRem; challengeesRem++)
		{
			long add = DP(both, challengers-challengersRem, challengees-challengeesRem);
			add = (add * comb[challengers+both][challengersRem]) % MOD;
			add = (add * comb[challengersRem][challengeesRem]) % MOD;
			add = (add * pow[challengersRem-challengeesRem]) % MOD;
			
			add = (add * fact[both]) % MOD;
			add = (add * fact[challengers]) % MOD;
			add = (add * fact[challengees]) % MOD;
			
			
			res = (res + add) % MOD;
		}
		return (int)res;
	}
	
	public String checkData(int N, int[] codersAttempted, int[] codersChallenged)
	{
		return "";
	}
	
	public static void main(String[] args)
	{
		SRMChallengePhase solver = new SRMChallengePhase();
		
		int N = 6;
		int[] codersAttempted = {};
		int[] codersChallenged = {};
		
		System.out.println(solver.countWays(N, codersAttempted, codersChallenged));
	}
}
