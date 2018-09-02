public class DengklekXNewCurrency
{
	boolean valid(int S, int X, int Y)
	{
		for (int i = 0; X*i <= S; i++)
			if ((S-X*i) % Y == 0)
				return true;
		return false;
	}
	public int howMany(int A, int B, int X)
	{
		int res = 0;
		if (A % X == 0 && B % X == 0)
			return -1;
		
		for (int Y = 1; Y <= 1000; Y++)
			if (Y != X && valid(A, X, Y) && valid(B, X, Y))
			{
				System.out.println("AAA " + Y);
				res++;
			}
		return res;
	}
	
	public String checkData(int A, int B, int X)
	{
		if (A < 1 || A > 1000)
			return "A must be between 1 and 1000, inclusive.";
		if (B < 1 || B > 1000)
			return "B must be between 1 and 1000, inclusive.";
		if (X < 1 || X > 1000)
			return "X must be between 1 and 1000, inclusive.";
		if (A == B)
			return "A and B must be different.";
		return "";
	}
	
	public static void main(String[] args)
	{
		DengklekXNewCurrency o = new DengklekXNewCurrency();
		System.out.println(8 ^ 53);
		System.out.println(o.howMany(47,74,44));
	}
}
