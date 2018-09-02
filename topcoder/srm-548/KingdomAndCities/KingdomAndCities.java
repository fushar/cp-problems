public class KingdomAndCities
{
	private static final long MOD = 1000000007L;
	private static final long INV2 = 500000004L;
	
	public int howMany(int N, int M, int K)
	{
		long[][] comb = new long[2501][2501];
		for (int i = 0; i <= 2500; i++)
		{
			comb[i][0] = 1;
			for (int j = 1; j <= i; j++)
				comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
		}
		
		long[][] dp = new long[51][51];
		dp[0][0] = 1;
		for (int i = 1; i <= 50; i++)
		for (int j = 0; j <= 50; j++)
		{
			dp[i][j] = comb[i*(i-1)/2][j];
			for (int k = 1; k < i; k++)
			for (int l = 0; l <= j; l++)
			{
				long cur = comb[i-1][k-1];
				cur = (cur * dp[k][l]) % MOD;
				cur = (cur * comb[(i-k)*(i-k-1)/2][j-l]);
				dp[i][j] = (dp[i][j] - cur + MOD) % MOD;
			}
		}
		
		if (M == 0)
			return (int)dp[N][K];
		else if (M == 1)
		{
			long res = 0;
			if (K >= 2)
			{
				/*
				Case 1: 
			
				  o
				 / \
				#####
				#####
				
				*/
				res = (res + dp[N-1][K-2] * comb[N-1][2]) % MOD;
			
				/* 
				
				Case 2: 
				
				##     ##
				##--o--##
				##     ##
				
				*/				
				long cur = 0;
				for (int i = 0; i <= N-1; i++)
				for (int j = 0; j <= K-2; j++)
				{
					long add = (dp[i][j] * dp[N-1-i][K-2-j]) % MOD;
					add = (add * i) % MOD;
					add = (add * (N-1-i)) % MOD;
					add = (add * comb[N-1][i]) % MOD;
					cur = (cur + add) % MOD;
				}
				cur = (cur * INV2) % MOD;
				res = (res + cur) % MOD;
			}
			return (int)res;
		}
		else
		{
			long res = 0;
			
			if (K >= 4)
			{
				/*
				Case 1: 
			
				  o
				 / \
				#####
				#####
				 \ /
				  o
				
				*/
				res = (dp[N-2][K-4] * comb[N-2][2]) % MOD;
				res = (res * comb[N-2][2]) % MOD;
				
				/* 
				
				Case 2: 
				
				##--o--##
				##     ##
				##--o--##
				
				*/
				long cur = 0;
				for (int i = 0; i <= N-2; i++)
				for (int j = 0; j <= K-4; j++)
				{
					long add = (dp[i][j] * dp[N-2-i][K-4-j]) % MOD;
					add = (add * i) % MOD;
					add = (add * (N-2-i)) % MOD;
					add = (add * i) % MOD;
					add = (add * (N-2-i)) % MOD;
					add = (add * comb[N-2][i]) % MOD;
					cur = (cur + add) % MOD;
				}
				cur = (cur * INV2) % MOD;
				res = (res + cur) % MOD;

				/* 
				
				Case 3: 
				
				##--o--##
				##     ##
				##-o   ##
				 \/
			
				*/
				cur = 0;
				for (int i = 0; i <= N-2; i++)
				for (int j = 0; j <= K-4; j++)
				{
					long add = (dp[i][j] * dp[N-2-i][K-4-j]) % MOD;
					add = (add * i) % MOD;
					add = (add * (N-2-i)) % MOD;
					add = (add * comb[i][2]) % MOD;
					add = (add * 2) % MOD;
					add = (add * comb[N-2][i]) % MOD;
					cur = (cur + add) % MOD;
				}
				res = (res + cur) % MOD;
							
				/* 
				
				Case 4: 
				
				##   ##   ##
				##-o-##-o-##
				##   ##   ##
				
				*/
				cur = 0;
				for (int i = 0; i <= N-2; i++)
				for (int j = 0; j <= K-4; j++)
				for (int k = 0; i+k <= N-2; k++)
				for (int l = 0; j+l <= K-4; l++)
				{
					long add = (dp[i][j] * dp[k][l]) % MOD;
					add = (add * dp[N-2-i-k][K-4-j-l]) % MOD;
					add = (add * i) % MOD;
					add = (add * k) % MOD;
					add = (add * k) % MOD;
					add = (add * (N-2-i-k)) % MOD;
					add = (add * comb[N-2][i]) % MOD;
					add = (add * comb[N-2-i][k]) % MOD;
					cur = (cur + add) % MOD;
				}
				res = (res + cur) % MOD;
			}
			
			if (K >= 3)
			{
				/*
				Case 5: 
			
				 o-o
				 | |
				#####
				#####
				
				*/
				long cur = (dp[N-2][K-3] * (N-2)) % MOD;
				cur = (cur * (N-2)) % MOD;
				res = (res + cur) % MOD;
				
				/* 
				
				Case 6: 
				
				##     ##
				##-o-o-##
				##     ##
				
				*/
				cur = 0;
				for (int i = 0; i <= N-2; i++)
				for (int j = 0; j <= K-3; j++)
				{
					long add = (dp[i][j] * dp[N-2-i][K-3-j]) % MOD;
					add = (add * i) % MOD;
					add = (add * (N-2-i)) % MOD;
					add = (add * 2) % MOD;
					add = (add * comb[N-2][i]) % MOD;
					cur = (cur + add) % MOD;
				}
				cur = (cur * INV2) % MOD;
				res = (res + cur) % MOD;
			}
			return (int)res;
		}
	}
	
	public String checkData(int N, int M, int K)
	{
		if (N < 1 || N > 50)
			return "N must be between 1 and 50, inclusive.";
		if (M < 0 || M > 2)
			return "M must be between 0 and 2, inclusive.";
		if (M > N)
			return "M must be less than or equal to N.";
		if (K < 1 || K > 50)
			return "K must be between 1 and 50, inclusive.";
		return "";
	}
	public static void main(String[] args)
	{
		KingdomAndCities o = new KingdomAndCities();
		System.out.println(o.howMany(50, 2, 50));
	}
}
