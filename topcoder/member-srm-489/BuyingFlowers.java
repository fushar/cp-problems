public class BuyingFlowers
{
	public int buy(int[] roses, int[] lilies)
	{
		int res = 9999999, n = roses.length;
		for (int mask = 0; mask < (1<<n); mask++)
		{
			int r = 0, l = 0;
			for (int i = 0; i < n; i++)
				if ((mask & (1<<i)) > 0)
				{
					r += roses[i];
					l += lilies[i];
				}
			
			if (Math.abs(r-l) <= 1)
			{
				int total = r+l;
				for (int i = 1; i*i <= total; i++)
					if (total % i == 0)
						res = Math.min(res, Math.abs(i - total/i));
			}
		}
		if (res == 9999999)
			return -1;
		return res;
	}
	public String checkData(int[] roses, int[] lilies)
	{
		if (roses.length != lilies.length)
			return "roses and lilies must contain the same number of elements.";
		if (roses.length < 1 || roses.length > 16)
			return "roses must contain between 1 and 16 elements, inclusive.";
		if (lilies.length < 1 || lilies.length > 16)
			return "lilies must contain between 1 and 16 elements, inclusive.";
		for (int i = 0; i < roses.length; i++)
			if (roses[i] < 0 || roses[i] > 10000)
				return "Each element of roses must be between 0 and 10000, inclusive.";
		for (int i = 0; i < lilies.length; i++)
			if (lilies[i] < 0 || lilies[i] > 10000)
				return "Each element of lilies must be between 0 and 10000, inclusive.";
		for (int i = 0; i < roses.length; i++)
			if (roses[i] + lilies[i] == 0)
				return "The total number of flowers in each packet represented by roses and lilies must be greater than 0.";
		return "";
	}
}

