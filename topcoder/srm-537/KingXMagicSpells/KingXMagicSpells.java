public class KingXMagicSpells
{
	public double expectedNumber(int[] ducks, int[] spellOne, int[] spellTwo, int K)
	{
		int N = ducks.length;
		double res = 0;
		
		for (int pos = 0; pos < 31; pos++)
		{
			int[] bits = new int[N];
			for (int i = 0; i < N; i++)
				if ((spellOne[i] & (1<<pos)) > 0)
					bits[i] = 1;
					
			double dp[][][] = new double[K+1][N][2];
			dp[0][0][1] = 1;
			for (int k = 1; k <= K; k++)
				for (int i = 0; i < N; i++)
					for (int b = 0; b < 2; b++)
						dp[k][i][b] = (dp[k-1][i][b^bits[i]] + dp[k-1][spellTwo[i]][b]) / 2.0;
					
			for (int i = 0; i < N; i++)
			{
				if ((ducks[i] & (1<<pos)) > 0)
					res += (1<<pos) * dp[K][i][1];
				else
					res += (1<<pos) * dp[K][i][0];
			}
		}

		return res;
	}
	
	public String checkData(int[] ducks, int[] spellOne, int[] spellTwo, int K)
	{
		int N = ducks.length;
		if (N < 1 || N > 50 || spellOne.length != N || spellTwo.length != N)
			return "ducks, spellOne, and spellTwo must contain the same number of elements, between 1 and 50, inclusive.";
		for (int i = 0; i < N; i++)
			if (ducks[i] < 0 || ducks[i] > 1000000000)
				return "Each element of ducks must be between 0 and 1,000,000,000, inclusive.";
		for (int i = 0; i < N; i++)
			if (spellOne[i] < 0 || spellOne[i] > 1000000000)
				return "Each element of spellOne must be between 0 and 1,000,000,000, inclusive.";
		for (int i = 0; i < N; i++)
			if (spellTwo[i] < 0 || spellTwo[i] > N-1)
				return "Each element of spellTwo must be between 0 and N-1, inclusive, where N is the number of elements of ducks.";
		for (int i = 0; i < N; i++)
			for (int j = i+1; j < N; j++)
				if (spellTwo[i] == spellTwo[j])
					return "All elements of spellTwo must be distinct.";
		if (K < 1 || K > 50)
			return "K must be between 1 and 50, inclusive.";
		return "";
	}

	public static void main(String[] args)
	{
		DengklekXArrayShuffling o = new DengklekXArrayShuffling();
		
		int[] S = {5, 8};
		int[] H = {7, 4};
		int[] T = {1, 0};
		int K = 1;
		
		System.out.println(o.expectedValue(S, H, T, K));
	}
}
