public class MysteriousRestaurant
{
	public int maxDays(String[] prices, int budget)
	{
		int N = prices.length, M = prices[0].length();
		int[][] cost = new int[N][M];
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				char c = prices[i].charAt(j);
				if ('0' <= c && c <= '9')
					cost[i][j] = c-'0';
				else if ('A' <= c && c <= 'Z')
					cost[i][j] = c-'A'+10;
				else
					cost[i][j] = c-'a'+36;
			}
		
		for (int n = N; n >= 1; n--)
		{
			int money = 0;
			for (int d = 0; d < 7; d++)
			{
				int best = 999999999;
				for (int m = 0; m < M; m++)
				{
					int cur = 0;
					for (int i = d; i < n; i += 7)
						cur += cost[i][m];
					best = Math.min(best, cur);
				}
				money += best;
			}
			if (money <= budget)
				return n;
		}
		return 0;
	}
	public String checkData(String[] prices, int budget)
	{
		if (budget < 0 || budget > 10000)
			return "budget must be between 0 and 10000, inclusive.";
		if (prices.length < 0 || prices.length > 50)
			return "prices must contain between 1 and 50 elements, inclusive.";
		boolean good = true;
		if (prices[0].length() < 1 || prices[0].length() > 50)
			good = false;
		
		for (int i = 1; i < prices.length; i++)
			if (prices[0].length() != prices[i].length())
				good = false;
		if (!good)
			return "Each element of prices must contain the same number of characters, between 1 and 50 characters, inclusive.";
		
		for (int i = 0; i < prices.length; i++)
			for (int j = 0; j < prices[i].length(); j++)
			{
				char c = prices[i].charAt(j);
				if ('0' <= c && c <= '9')
					continue;
				if ('a' <= c && c <= 'a')
					continue;
				if ('A' <= c && c <= 'Z')
					continue;
				return "Each character in prices must be '0'-'9', 'a'-'z', or 'A'-'Z'.";
			}
		
		return "";
	}
}
