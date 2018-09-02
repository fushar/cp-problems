public class XorTravelingSalesman
{
	public int maxProfit(int[] cityValues, String[] roads)
	{
		int N = cityValues.length;
		
		boolean[] S = new boolean[N * 1024];
		int[] Q = new int[N * 1024 + 5];
		int qf = 0, qb = 0;
		
		S[0 * 1024 + cityValues[0]] = true;
		Q[qb++] = 0 * 1024 + cityValues[0];
		
		int res = 0;
		
		while (qf < qb)
		{
			int u = Q[qf] / 1024;
			int k = Q[qf] % 1024;
			qf++;
			
			res = Math.max(res, k);
			for (int v = 0; v < N; v++)
			{
				if (roads[u].charAt(v) == 'Y' && !S[v * 1024 + (k ^ cityValues[v])])
				{
					S[v * 1024 + (k ^ cityValues[v])] = true;
					Q[qb++] = v * 1024 + (k ^ cityValues[v]);
				}
			}
		}
		
		return res;
	}
	
	public String checkData(int[] cityValues, String[] roads)
	{
		int N = cityValues.length;
		if (N < 1 || N > 50)
			return "cityValues must contain between 1 and 50 elements, inclusive.";
		for (int i = 0; i < N; i++)
			if (cityValues[i] < 0 || cityValues[i] > 1023)
				return "Each element of cityValues must be between 0 and 1023, inclusive.";
		if (roads.length != N)
			return "roads must contain exactly N elements, where N is the number of elements of cityValues.";
		for (int i = 0; i < N; i++)
		{
			if (roads[i].length() != N)
				return "Each element of roads must contain exactly N characters, where N is the number of elements of cityValues.";
			if (roads[i].charAt(i) != 'N')
				return "For each i, the i-th character of the i-th element of roads must be 'N'.";
			for (int j = 0; j < N; j++)
			{
				if (roads[i].charAt(j) != 'N' && roads[i].charAt(j) != 'Y')
					return "Each charater in roads must be either 'N' or 'Y'.";
				if (roads[i].charAt(j) != roads[j].charAt(i))
					return "For each pair (i, j), the j-th character of the i-th element of roads will be equal to the i-th character of the j-th element of roads.";
			}
		}
		return "";
	}
	
	public static void main(String[] args)
	{
		int[] cityValues = {1, 2, 4, 8}
;
		String[] roads = 
{"NYYN", "YNNN", "YNNY", "NNNY"}
;
		XorTravelingSalesman o = new XorTravelingSalesman();
		System.out.println(o.maxProfit(cityValues, roads));
	}
}
