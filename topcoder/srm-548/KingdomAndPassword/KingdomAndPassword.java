public class KingdomAndPassword
{
	int numDigits;
	int[] pass, rdig;
	int[][][] dp;
	
	int bitCount(int mask)
	{
		int res = 0;
		for (int i = 0; i < numDigits; i++)
			if ((mask & (1<<i)) > 0)
				res++;
		return res;
	}
	
	int DP(int mask, int flag, int type)
	{
		if (mask == (1<<numDigits)-1)
			return 1;
		
		if (dp[mask][flag][type] == -1)
		{
			dp[mask][flag][type] = 0;
			
			int pos = bitCount(mask);
			for (int i = 0; i < numDigits; i++)
			{
				if ((mask & (1<<i)) > 0)
					continue;
				if (pass[i] == rdig[pos])
					continue;
				if (flag == 0 && pass[i] < pass[pos] && type == 1)
					continue;
				if (flag == 0 && pass[i] > pass[pos] && type == 0)
					continue;
					
				int nflag = flag;
				if (pass[i] > pass[pos] && type == 1)
					nflag = 1;
				if (pass[i] < pass[pos] && type == 0)
					nflag = 1;
				
				dp[mask][flag][type] |= DP(mask | (1<<i), nflag, type);
			}
		}
		return dp[mask][flag][type];
	}
	
	long trace(int mask, int flag, int type)
	{
		if (mask == (1<<numDigits)-1)
			return 0;
		if (DP(mask, flag, type) == 0)
			return Long.MAX_VALUE;
		
		int bestpos = -1, bestflag = -1;
		int pos = bitCount(mask);
		for (int i = 0; i < numDigits; i++)
		{
			if ((mask & (1<<i)) > 0)
				continue;
			if (pass[i] == rdig[pos])
				continue;
			if (flag == 0 && pass[i] < pass[pos] && type == 1)
				continue;
			if (flag == 0 && pass[i] > pass[pos] && type == 0)
				continue;
				
			int nflag = flag;
			if (pass[i] > pass[pos] && type == 1)
				nflag = 1;
			if (pass[i] < pass[pos] && type == 0)
				nflag = 1;
			
			if (DP(mask | (1<<i), nflag, type) == 1)
			{
				if (bestpos == -1 || ((type == 0 && pass[i] > pass[bestpos]) || (type == 1 && pass[i] < pass[bestpos])))
				{
					bestpos = i;
					bestflag = nflag;
				}
			}
		}
		return pass[bestpos] * (long)Math.pow(10, numDigits - pos - 1) + trace(mask | (1<<bestpos), bestflag, type);
	}
	
	public long newPassword(long oldPassword, int[] restrictedDigits)
	{
		int temp = 0;
		int[] digits = new int[16];
		long op = oldPassword;
		while (op > 0)
		{
			digits[temp++] = (int) (op % 10);
			op /= 10;
		}
		
		rdig = restrictedDigits;
		
		numDigits = temp;
		pass = new int[numDigits];
		for (int i = 0; i < numDigits; i++)
			pass[i] = digits[numDigits - i - 1];
		
		dp = new int[1<<numDigits][2][2];
		
		for (int mask = 0; mask < 1<<numDigits; mask++)
			for (int flag = 0; flag < 2; flag++)
				for (int type = 0; type < 2; type++)
					dp[mask][flag][type] = -1;
		
		long res1 = trace(0, 0, 0);
		long res2 = trace(0, 0, 1);
		long res;
		
		if (res1 != Long.MAX_VALUE && oldPassword - res1 <= res2 - oldPassword)
			res = res1;
		else
			res = res2;
		
		if (res == Long.MAX_VALUE)
			return -1;
		return res;
	}
	
	public String checkData(long oldPassword, int[] restrictedDigits)
	{
		if (oldPassword < 1 || oldPassword >= 10000000000000000L)
			return "oldPassword must be between 1 and 10^16 - 1, inclusive.";
		int temp = 0;
		int[] digits = new int[16];
		while (oldPassword > 0)
		{
			if (oldPassword % 10 == 0)
				return "oldPassword must not contain digit zero.";
			digits[temp++] = (int) (oldPassword % 10);
			oldPassword /= 10;
		}
		
		if (temp != restrictedDigits.length)
			return "restrictedDigits must contain the same number of elements as the number of digits in oldPassword.";
			
		for (int i = 0; i < restrictedDigits.length; i++)
			if (restrictedDigits[i] < 1 || restrictedDigits[i] > 9)
				return "Each element of restrictedDigits must be between 1 and 9, inclusive.";
		return "";
	}
	
	public static void main(String[] args)
	{
		KingdomAndPassword o = new KingdomAndPassword();
		long oldPassword = 288;
		int[] restrictedDigits = {5, 3, 8};
		
		System.out.println(o.newPassword(oldPassword, restrictedDigits));
	}
}
