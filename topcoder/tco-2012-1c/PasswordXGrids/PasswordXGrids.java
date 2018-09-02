public class PasswordXGrids{
	
    public int minSum(String[] horizontal, String[] vertical)
    {
		int N = horizontal.length;
		int M = vertical[0].length();
		
		int[][] dp = new int[N][M];
		
		for (int i = N-1; i >= 0; i--)
			for (int j = M-1; j >= 0; j--)
			{
				if (i < N-1)
					dp[i][j] = Math.max(dp[i][j], vertical[i].charAt(j)-'0' + dp[i+1][j]);
				if (j < M-1)
					dp[i][j] = Math.max(dp[i][j], horizontal[i].charAt(j)-'0' + dp[i][j+1]);
			}
		return dp[0][0];
    }
	
	public static void main(String[] args)
	{
		PasswordXGrids o = new PasswordXGrids();
		String[] hor = {"19", "91"};
		String[] ver = {"999"};
		System.out.println(o.minSum(hor, ver));
	}
}
