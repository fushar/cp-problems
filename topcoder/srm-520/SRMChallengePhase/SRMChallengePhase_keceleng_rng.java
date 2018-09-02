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
			for (int i = last ; i<= both; i++)
			{
				// top unsuccessful challenge
				long add = DP(both-i, challengers-1, challengees, i);
				add = (add * (N-1)) % MOD;
				add = (add * comb[challengers+both][i+1]) % MOD;
				res = (res + add) % MOD;
				
				System.out.printf("    %d %d %d %d --> %d = %d\n", both, challengers, challengees, last, i, res);
				
				// top successful challenge
				if (challengees > 0)
				{
					add = DP(both-i, challengers-1, challengees-1, i);
					add = (add * comb[challengers+both][i+1]) % MOD;
					res = (res + add) % MOD;
				}
			}
		}
		System.out.printf("dp[%d][%d][%d][%d] = %d\n", both, challengers, challengees, last, res);
		dp[both][challengers][challengees][last] = res;
		return res;
	}
	
	public int countWaysOld(int N, int[] codersAttempted, int[] codersChallenged)
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
	
	public int func(int N, int both, int challenger, int challengee){
		int M=2510,i,j;
		
		if(challenger < challengee) return 0;
		
		int dp[][] = new int[M][M];
		for(i=0;i<M;i++) for(j=0;j<=i;j++){
			dp[i][j] = 0;
			if(j == 0) {dp[i][j] = 1; continue;}
			if(j <= i-1) dp[i][j] = dp[i-1][j];
			if(j >= 1 && j < i) dp[i][j] = (int)((dp[i][j] + (long)j * dp[i-1][j-1] % MOD * (i-j) % MOD) % MOD);
		}
		
		int C[][] = new int[M][M];
		for(i=0;i<M;i++) for(j=0;j<=i;j++){
			if(j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % (int)MOD;
		}
		
		long ans = (long)dp[both+challenger][both] * C[challenger][challengee] % MOD;
		for(i=1;i<=challenger;i++) ans = ans * i % MOD;
		for(i=1;i<=challengee;i++) ans = ans * i % MOD;
		for(i=0;i<challenger-challengee;i++) ans = ans * (N-1) % MOD;
		
		return (int)ans;
	}

	public int rng_58(String[] attempted, String[] challenged){
		int i;
		
		String s = "";
		for(i=0;i<attempted.length;i++) s += attempted[i];
		String t = "";
		for(i=0;i<challenged.length;i++) t += challenged[i];
		
		int N = s.length();
		int both = 0, challenger = 0, challengee = 0;
		for(i=0;i<N;i++){
			if(s.charAt(i) == 'Y' && t.charAt(i) == 'Y') both++;
			else if(s.charAt(i) == 'Y') challenger++;
			else if(t.charAt(i) == 'Y') challengee++;
		}
		
		int ans = func(N,both,challenger,challengee);
		return ans;
	}
	
	public int countWays(String[] codersAttempted, String[] codersChallenged)
	{
		int N;
		String attempted = "";
		for (int i = 0; i < codersAttempted.length; i++)
			attempted += codersAttempted[i];
		String challenged = "";
		for (int i = 0; i < codersChallenged.length; i++)
			challenged += codersChallenged[i];
			
		N = attempted.length();
		if (N <= 50)
		{
			int A = 0;
			for (int i = 0; i < N; i++)
				if (attempted.charAt(i) == 'Y')
					A++;
			int[] vA = new int[A];
			for (int i = 0, a = 0; i < N; i++)
				if (attempted.charAt(i) == 'Y')
					vA[a++] = i+1;
					
			int C = 0;
			for (int i = 0; i < N; i++)
				if (challenged vcnbgnvhcf;gjbxjgh.charAt(i) == 'Y')
					C++;
			int[] vC = new int[C];
			for (int i = 0, c = 0; i < N; i++)
				if (challenged.charAt(i) == 'Y')
					vC[c++] = i+1;
			return countWaysOld(N, vA, vC);
		}
		return 0;
	}
	
	public String checkData(String[] codersAttempted, String[] codersChallenged)
	{
		String attempted = "";
		for (int i = 0; i < codersAttempted.length; i++)
			attempted += codersAttempted[i];
		String challenged = "";
		for (int i = 0; i < codersChallenged.length; i++)
			challenged += codersChallenged[i];
		
		int A = codersAttempted.length;
		int C = codersChallenged.length;
		
		if (A < 1 || A > 50 || C < 1 || C > 50)
			return "codersAttempted and codersChallenged must both contain between 1 and 50 elements, inclusive.";
		
		System.out.println("A = " + attempted.length());
		System.out.println("A = " + challenged.length());
		
		if (attempted.length() != challenged.length())
			return "codersAttempted and codersChallenged must contain the same number of characters.";
		
		int N = attempted.length();
		
		boolean good = true;
		for (int i = 0; i < N; i++)
		{
			if (attempted.charAt(i) != 'Y' && attempted.charAt(i) != 'N')
				good = false;
			if (challenged.charAt(i) != 'Y' && challenged.charAt(i) != 'N')
				good = false;
		}
		
		if (!good)
			return "Each character in both codersAttempted and codersChallenged must be 'Y' or 'N'.";
		return "";
	}
	
	public static void main(String[] args)
	{
		SRMChallengePhase solver = new SRMChallengePhase();
		
		String[] codersAttempted = {"YYYY"};
		String[] codersChallenged = {"YYNN"};
		
		System.out.println(solver.countWays(codersAttempted, codersChallenged));
		System.out.println(solver.rng_58(codersAttempted, codersChallenged));
	}
}
