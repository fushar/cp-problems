public class ChocolateBar
{
	public int maxLength(String letters)
	{
		int N = letters.length();
		int res = 0;
		
		for (int i = 0; i < N; i++)
		{
			boolean[] used = new boolean[26];
			for (int j = i; j < N; j++)
			{
				char c = letters.charAt(j);
				if (used[c-'a'])
					break;
				used[c-'a'] = true;
				res = Math.max(res, j - i + 1);
			}
		}
		return res;
	}
	
	public String checkData(String letters)
	{
		int N = letters.length();
		if (N < 1 || N > 50)
			return "letters must contain between 1 and 50 characters, inclusive.";
		
		for (int i = 0; i < N; i++)
		{
			if (letters.charAt(i) < '0' || letters.charAt(i) > '9')
				return "Each character of letters must be a lowercase letter ('a'-'z').";
		}
		return "";
	}
	
	public static void main(String[] args)
	{
		ChocolateBar o = new ChocolateBar();
		System.out.println(o.maxLength("srm"));
		System.out.println(o.maxLength("dengklek"));
		System.out.println(o.maxLength("haha"));
		System.out.println(o.maxLength("www"));
		System.out.println(o.maxLength("thisisansrmbeforetopcoderopenfinals"));
	}
}
