public class KingdomAndDucks
{
	public int minDucks(int[] duckTypes)
	{
		int[] types = new int[51];
		for (int i = 0; i < duckTypes.length; i++)
			types[duckTypes[i]]++;
		
		int cnt = 0, maxn = 0;
		for (int i = 1; i <= 50; i++)
			if (types[i] > 0)
			{
				cnt++;
				if (types[i] > maxn)
					maxn = types[i];
			}
		return cnt * maxn;
	}
	
	public String checkData(int[] duckTypes)
	{
		if (duckTypes.length < 1 || duckTypes.length > 50)
			return "duckTypes must contain between 1 and 50 elements, inclusive.";
		for (int i = 0; i < duckTypes.length; i++)
			if (duckTypes[i] < 1 || duckTypes[i] > 50)
				return "Each element of duckTypes must be between 1 and 50, inclusive.";
		return "";
	}
}
