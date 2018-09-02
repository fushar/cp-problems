public class SumOfLuckiness
{	
	public long theSum(int A, int B)
	{
		return theSum(B) - theSum(A-1);
	}
	
	long theSum(int n)
	{
		int[] digits = new int[100];
		int D = 0;
		
		while (n > 0)
		{
			digits[D++] = n % 10;
			n /= 10;
		}
		
		long res = 0;
		int seven = 0, four = 0;
		int[] is7 = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
		int[] is4 = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
		
		for (int i = D-1; i >= 0; i--)
		{
			for (int j = 0; j < digits[i]; j++)
				res += solve(i, seven + is7[j], four + is4[j]);
			seven += is7[digits[i]];
			four += is4[digits[i]];
		}
		res += Math.abs(seven - four);
		
		return res;
	}
	
	long solve(int n, int add7, int add4)
	{
		long res = 0;
		long pow3 = 1;
		for (int i = 0; i < n; i++)
			pow3 *= 3;
		for (long mask = 0; mask < pow3; mask++)
		{
			int seven = 0, four = 0;
			long x = mask;
			while (x > 0)
			{
				if (x % 3 == 1)
					seven++;
				else if (x % 3 == 2)
					four++;
				x /= 3;
			}
			long pow8 = 1;
			for (int i = 0; i < (n - seven - four); i++)
				pow8 *= 8;
			res += Math.abs((seven + add7) - (four + add4)) * pow8;
		}
		return res;
	}
	
	public String checkData(int A, int B)
	{
		if (A < 1 || A > 2000000000)
			return "A must be between 1 and 2,000,000,000, inclusive.";
		if (B < A+1 || B > 2000000000)
			return "B must be between A+1 and 2,000,000,000, inclusive.";
		return "";			
	}
	
	public static void main(String[] args)
	{
		SumOfLuckiness o = new SumOfLuckiness();
		System.out.println(o.theSum(8712, 923473));
	}
}
