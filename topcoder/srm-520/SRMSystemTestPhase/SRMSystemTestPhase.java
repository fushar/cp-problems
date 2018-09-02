public class SRMSystemTestPhase
{
	final int MOD = 1000000007;
	public int countWays(String[] description)
	{
		int N = description.length;
		int[][][] dp = new int[N+1][4][4];
		for (int p = 0; p <= 3; p++)
		for (int c = 0; c <= 3; c++)
			dp[N][p][c] = 1;
		
		for (int i = N-1; i >= 0; i--)
		for (int p = 0; p <= 3; p++)
		for (int c = 0; c <= 3; c++)
		{
			int[] opt = new int[3];
			for (opt[0] = 0; opt[0] < 3; opt[0]++)
			for (opt[1] = 0; opt[1] < 3; opt[1]++)
			for (opt[2] = 0; opt[2] < 3; opt[2]++)
			{
				// 0 : passed / not submitted
				// 1 : challenged
				// 2 : failed
				
				int p_j = 0, c_j = 0;
				boolean valid = true;
				
				for (int k = 0; k < 3; k++)
				{
					if (description[i].charAt(k) == 'Y')
					{
						if (opt[k] == 0) p_j++;
						else if (opt[k] == 1) c_j++;
					}
					else if (opt[k] != 0)
						valid = false;
				}
				
				if (!valid) continue;
				
				if (p_j < p || (p_j == p && c_j >= c))
					dp[i][p][c] = (dp[i][p][c] + dp[i+1][p_j][c_j]) % MOD;
			}
		}
		
		return dp[0][3][3];
	}
	
	public String checkData(String[] description)
	{
		int N = description.length;
		if (N < 1 || N > 50)
			return "description must contain between 1 and 50 elements, inclusive.";
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
	
	public static void main(String[] args)
	{
		SRMSystemTestPhase lho = new SRMSystemTestPhase();
		String[] description = {"NNN", "YNN"};
		System.out.println(lho.countWays(description));
	}
}
