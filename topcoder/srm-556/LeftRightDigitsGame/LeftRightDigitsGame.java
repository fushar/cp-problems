public class LeftRightDigitsGame
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
	
	public String minNumber(String digits)
	{
		int N = digits.length();
		
		String[] minNoZero = new String[N];
		String[] minAny = new String[N];
		
		char first = digits.charAt(0);
		minAny[0] = "" + first;
		if (first != '0')
			minNoZero[0] = "" + first;
		else
			minNoZero[0] = "";
			
		for (int i = 1; i < N; i++)
		{
			char c = digits.charAt(i);
			
			minAny[i] = minStr(c + minAny[i-1], minAny[i-1] + c);
			minNoZero[i] = "";
			
			// c + minAny[i-1]
			if (c != '0')
				minNoZero[i] = minStr(minNoZero[i], c + minAny[i-1]);
			// minAny[i-1] + c
			if (minAny[i-1].charAt(0) != '0')
				minNoZero[i] = minStr(minNoZero[i], minAny[i-1] + c);
			// c + minNoZero[i-1]
			if (c != '0' && !minNoZero[i-1].equals(""))
				minNoZero[i] = minStr(minNoZero[i], c + minNoZero[i-1]);
			// minNoZero[i-1] + c
			if (!minNoZero[i-1].equals(""))
				minNoZero[i] = minStr(minNoZero[i], minNoZero[i-1] + c);
		}
		
		return minNoZero[N-1];
	}
	
	public String checkData(String digits)
	{
		int N = digits.length();
		if (N < 1 || N > 50)
			return "digits must contain between 1 and 50 characters, inclusive.";
		
		boolean any = false;
		for (int i = 0; i < N; i++)
		{
			if (digits.charAt(i) < '0' || digits.charAt(i) > '9')
				return "Each character of digits must be between '0' and '9', inclusive.";
			if (digits.charAt(i) != '0')
				any = true;
		}
		if (!any)
			return "digits must contain at least one character that is not '0'.";
		return "";
	}
	
	public static void main(String[] ar)
	{
		LeftRightDigitsGame o = new LeftRightDigitsGame();
		System.out.println(o.minNumber("565"));
		System.out.println(o.minNumber("9876543210"));
		System.out.println(o.minNumber("8016352"));
	}
}
