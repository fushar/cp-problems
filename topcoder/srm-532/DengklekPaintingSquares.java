public class DengklekPaintingSquares
{
	static final int MOD = 1000000007;
	static final int MAXM = 8+1;
	
	// pow3[i] is 3^i
	int[] pow3;
	
	// get[i][j] is the j-th digit in ternary representation of i
	int[][] get;
	
	// set[i][j][k] is i with its j-th digit replaced with k
	int[][][] set;
	
	void precompute()
	{
		pow3 = new int[MAXM+1];
		pow3[0] = 1;
		for (int i = 1; i <= MAXM; i++)
			pow3[i] = 3 * pow3[i-1];
			
		get = new int[pow3[MAXM]][MAXM];
		for (int i = 0; i < pow3[MAXM]; i++)
			for (int j = 0; j < MAXM; j++)
				get[i][j] = (i / pow3[j]) % 3;
		
		set = new int[pow3[MAXM]][MAXM][3];
		for (int i = 0; i < pow3[MAXM]; i++)
			for (int j = 0; j < MAXM; j++)
				for (int k = 0; k < 3; k++)
					set[i][j][k] = i + (k - get[i][j]) * pow3[j];
	}
	
	public int numSolutions(int N, int M)
	{
		precompute();
		
		int[][][] dp = new int[N][M+1][pow3[M]];
		int startk = 0;
		
		// assume that in the initial profile, all squares in the
		// (-1)-th row have state 2
		for (int j = 0; j < M; j++)
			startk = set[startk][j][2];
		
		// this is the base case
		dp[0][0][startk] = 1;
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				for (int k = 0; k < pow3[M]; k++)
				{
					// do not color square (i, j)
					if (get[k][j] != 1)
					{
						dp[i][j+1][set[k][j][2]] += dp[i][j][k];
						dp[i][j+1][set[k][j][2]] %= MOD;
					}
					
					// color square (i, j)
					// the state of the top square must not 0
					// or else it will become 1 (invalid as it will be
					// removed)
					
					if (get[k][j] != 0)
					{
						int newk = k;
						
						// first, set the state to be 0
						newk = set[newk][j][0];
						
						// if the top square is colored, toggle the state
						if (get[k][j] != 2)
							newk = set[newk][j][1 - get[newk][j]];
							
						// if the left square is colored, toggle the state
						// of both the current square and the left square
						if (j > 0 && get[k][j-1] != 2)
						{
							newk = set[newk][j][1 - get[newk][j]];
							newk = set[newk][j-1][1 - get[newk][j-1]];
						}
						
						// update the next DP state
						dp[i][j+1][newk] += dp[i][j][k];
						dp[i][j+1][newk] %= MOD;
					}
				}
			
			// move the profile in states (i, M, ?) to (i+1, 0, ?)
			for (int k = 0; k < pow3[M]; k++)
				dp[i+1][0][k] = dp[i][M][k];
		}
		
		// all valid solutions is the states (N, 0, k),
		// where k does not contain state 1
		int res = 0;
		for (int k = 0; k < pow3[M]; k++)
		{
			boolean valid = true;
			for (int j = 0; j < M; j++)
				if (get[k][j] == 1)
					valid = false;
			if (valid)
				res = (res + dp[N][0][k]) % MOD;
		}
		return res;
	}
	
	public static void main(String[] args)
	{
		DengklekPaintingSquares f = new DengklekPaintingSquares();
		System.out.println(f.numSolutions(2, 3));
	}
	
	public String checkData(int N, int M)
	{
		if (N < 1 || N > 50)
			return "N must be between 1 and 50, inclusive.";
		if (M < 1 || M > 9)
			return "M must be between 1 and 9, inclusive.";
		return "";
	}
}
