import java.util.*;
import java.util.regex.*;
import java.math.*;

public class PickAndDelete
{
	final long MOD = 1000000007;
	
	public int count(String[] S)
	{
		long[][] comb = new long[201][201];
		for (int i = 0; i <= 200; i++)
		{
			comb[i][0] = 1;
			for (int j = 1; j <= i; j++)
				comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
		}
		
		String input = "";
		for (int i = 0; i < S.length; i++)
			input += S[i];
		String[] inputs = input.split(" ");
		
		int N = inputs.length;
		int[] seq = new int[N];
		for (int i = 0; i < N; i++)
			seq[i] = Integer.parseInt(inputs[i]);
		Arrays.sort(seq);
		
		int[] diff = new int[N];
		diff[0] = seq[0];
		for (int i = 1; i < N; i++)
			diff[i] = seq[i] - seq[i-1];
		
		long[][] pow = new long[N][N+1];
		for (int i = 0; i < N; i++)
		{
			pow[i][0] = 1;
			for (int j = 1; j <= N; j++)
				pow[i][j] = pow[i][j-1] * diff[i] % MOD;
		}
		
		long[][] dp = new long[N+1][N+1];
		dp[0][0] = 1;
		for (int i = 0; i < N; i++)
		for (int j = i; j <= N; j++)
		for (int k = 0; i+k <= N && j+k <= N; k++)
		{
			long cur = pow[i][k] * comb[j+k][k] % MOD * dp[i][j] % MOD;
			dp[i+1][j+k] = (dp[i+1][j+k] + cur) % MOD;
		}
		
		return (int)dp[N][N];
	}
	
	
	public String checkData(String[] S)
	{
		if (S.length < 1 || S.length > 50)
			return "S must contain between 1 and 50 elements, inclusive.";
		for (int i = 0; i < S.length; i++)
			if (S[i].length() < 1 || S[i].length() > 50)
				return "Each element of S must contain between 1 and 50 characters, inclusive.";
			
		String input = "";
		for (int i = 0; i < S.length; i++)
			input += S[i];
			
		if (!Pattern.matches("^\\d+( \\d+)*$", input))
			return "The concatenation of elements of S must be a space-separated sequence of integers, with no extra leading or trailing spaces.";
			
		S = input.split(" ");
		
		for (int i = 0; i < S.length; i++)
		{
			BigInteger cur = new BigInteger(S[i]);
			if (S[i].charAt(0) == '0' || cur.compareTo(BigInteger.ONE) < 0 || cur.compareTo(BigInteger.valueOf(1000000000)) > 0)
				return "Each integer in S must be between 1 and 1,000,000,000, inclusive, with no leading zeroes.";
		}
		
		if (S.length < 1 || S.length > 200)
			return "S must contain between 1 and 200 integers, inclusive.";	
		return "";
	}
	
	public static void main(String[] ar)
	{
		PickAndDelete f = new PickAndDelete();
		
		System.out.println(f.count(new String[]{"1 2"}));
		System.out.println(f.count(new String[]{"7"}));
		System.out.println(f.count(new String[]{"5", " 1 ", "2"}));
	}
}
