public class PasswordXGuessing
{
	public int howMany(String[] guesses)
	{
		int N = guesses.length;
		int X = guesses[0].length();
		
		char[][] gc = new char[N][X];
		for (int i = 0; i < N; i++)
			gc[i] = guesses[i].toCharArray();
		
		int res = 0;
		for (int p = 0; p < X; p++)
		{
			char oldc = gc[0][p];
			for (char newc = '0'; newc <= '9'; newc++)
			{
				if (newc == oldc)
					continue;
				gc[0][p] = newc;
				
				boolean valid = true;
				for (int i = 1; i < N; i++)
				{
					int diff = 0;
					for (int j = 0; j < X; j++)
						if (gc[0][j] != gc[i][j])
							diff++;
					if (diff != 1)
						valid = false;
				}
				if (valid)
					res++;
			}
			gc[0][p] = oldc;
		}
		return res;
	}
	
	public String checkData(String[] guesses)
	{
		int N = guesses.length;
		
		if (N < 1 || N > 50)
			return "guesses must contain between 1 and 50 elements, inclusive.";
		
		for (int i = 0; i < N; i++)
		{
			int L = guesses[i].length();
			if (L < 1 || L > 10 || L != guesses[0].length())
				return "Each element of guesses must contain the same number of characters, between 1 and 10, inclusive.";
			for (int j = 0; j < L; j++)
			{
				char C = guesses[i].charAt(j);
				if (C < '0' || C > '9')
					return "Each character of each element of guesses must be one of '0'-'9'.";
			}
		}
		return "";
	}
	
	public static void main(String[] args)
	{
		PasswordXGuessing o = new PasswordXGuessing();
		
		System.out.println(o.howMany(new String[]{"15", "32", "16", "16"}));
		System.out.println(o.howMany(new String[]{"539", "540", "541"}));
		System.out.println(o.howMany(new String[]{"12", "34", "56", "78"}));
		System.out.println(o.howMany(new String[]{"1234", "9264", "1234"}));
	}
}
