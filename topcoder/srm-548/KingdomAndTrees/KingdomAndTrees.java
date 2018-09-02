public class KingdomAndTrees
{
	private boolean ok(int[] heights, int X)
	{
		int last = Math.max(1, heights[0] - X);
		for (int i = 1; i < heights.length; i++)
		{
			if (heights[i] <= last)
			{
				if (last + 1 - heights[i] > X)
					return false;
				last++;
			}
			else
				last = Math.max(last + 1, heights[i] - X);
		}
		return true;
	}
	
	public int minLevel(int[] heights)
	{		
		int lo = 0, hi = 1000000000;
		while (lo < hi)
		{
			int mid = (lo + hi) / 2;
			if (ok(heights, mid))
				hi = mid;
			else
				lo = mid + 1;
		}
		return hi;
	}
	
	public String checkData(int[] heights)
	{
		if (heights.length < 2 || heights.length > 50)
			return "heights must contain between 2 and 50 elements, inclusive.";
		for (int i = 0; i < heights.length; i++)
			if (heights[i] < 1 || heights[i] > 1000000000)
				return "Each elements of heights must be between 1 and 1,000,000,000, inclusive.";
		return "";
	}
	
	public static void main(String[] args)
	{
		int[] heights = {2};
		KingdomAndTrees o = new KingdomAndTrees();
		
		System.out.println(o.minLevel(heights));
	}
}
