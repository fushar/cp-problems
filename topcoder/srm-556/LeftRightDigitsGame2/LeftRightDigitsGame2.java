public class LeftRightDigitsGame2
{
	private String minStr(String a, String b)
	{
		if (a.equals(""))
			return b;
		if (b.equals(""))
			return a;
		if (a.compareTo(b) < 0)
			return a;
		return b;
	}
	
	public String minNumber(String digits, String lowerBound)
	{
		int N = digits.length();
		
		String[] dpAny = new String[N];
		String[][] dpMin = new String[N][N];
		boolean[][] canBeSame = new boolean[N][N];
		
		for (int i = 0; i < N; i++)
		{
			dpAny[i] = "";
			for (int j = 0; j < N; j++)
				dpMin[i][j] = "";
		}
		
		dpAny[0] = "" + digits.charAt(0);
		for (int j = 0; j < N; j++)
		{
			char c = digits.charAt(0);
			if (c > lowerBound.charAt(j))
				dpMin[0][j] = "" + c;
			
			if (c == lowerBound.charAt(j))
				canBeSame[0][j] = true;
		}
		
		for (int i = 1; i < N; i++)
		{
			char c = digits.charAt(i);
			dpAny[i] = minStr(c + dpAny[i-1], dpAny[i-1] + c);
			for (int j = 0; j+i < N; j++)
			{
				// c + ...
				if (c == lowerBound.charAt(j) && !dpMin[i-1][j+1].equals(""))
					dpMin[i][j] = minStr(dpMin[i][j], c + dpMin[i-1][j+1]);
				if (c > lowerBound.charAt(j))
					dpMin[i][j] = minStr(dpMin[i][j], c + dpAny[i-1]);
				
				// ... + c
				if (canBeSame[i-1][j] && c > lowerBound.charAt(j+i))
					dpMin[i][j] = minStr(dpMin[i][j], lowerBound.substring(j, j+i) + c);
				if (!dpMin[i-1][j].equals(""))
					dpMin[i][j] = minStr(dpMin[i][j], dpMin[i-1][j] + c);
				
				if (c == lowerBound.charAt(j))
					canBeSame[i][j] = canBeSame[i][j] || canBeSame[i-1][j+1];
				if (c == lowerBound.charAt(j+i))
					canBeSame[i][j] = canBeSame[i][j] || canBeSame[i-1][j];
					
			}
		}
		
		return canBeSame[N-1][0] ? lowerBound : dpMin[N-1][0];
	}
	
	
	public static void main(String[] ar)
	{
		LeftRightDigitsGame2 o = new LeftRightDigitsGame2();
		System.out.println(o.minNumber("9876543210", "5565565565"));
	}
}
