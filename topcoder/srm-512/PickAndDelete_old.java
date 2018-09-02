import java.util.*;

public class PickAndDelete
{
	final long MOD = 1000000007;
	long[][] comb = new long[101][101];
	
	private int[] convert(String[] s)
	{
		String cur = "";
		for (int i = 0; i < s.length; i++)
			cur += s[i];
		
		String[] seq = cur.split(" ");
		int[] res = new int[seq.length];
		for (int i = 0; i < res.length; i++)
			res[i] = Integer.parseInt(seq[i]);
		return res;
	}
	
	private long solve(int[] seq)
	{
		int N = seq.length;
		int[] diff = new int[N];
		
		diff[0] = seq[0];
		for (int i = 1; i < N; i++)
			diff[i] = seq[i] - seq[i-1];
		
		long[][] pow = new long[N][N+1];
		for (int i = 0; i < N; i++)
		{
			pow[i][0] = 1;
			for (int j = 1; j <= N; j++)
				pow[i][j] = (pow[i][j-1] * diff[i]) % MOD;
		}
		
		long[][] dp = new long[N+1][N+1];
		
		dp[0][0] = 1;
		for (int i = 0; i < N; i++)
			for (int j = i; j <= N; j++)
				for (int k = 0; k <= N-i && j+k <= N; k++)
				{
					long add = 1;
					add = (add * pow[i][k]) % MOD;
					add = (add * comb[j+k][k]) % MOD;
					add = (add * dp[i][j]) % MOD;
					
					dp[i+1][j+k] = (dp[i+1][j+k] + add) % MOD;
				}
		return dp[N][N];
	}
	
	public int count(String[] S1, String[] S2)
	{
		for (int i = 0; i <= 100; i++)
		{
			comb[i][0] = 1;
			for (int j = 1; j <= i; j++)
				comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
		}
		
		int[] seq1 = convert(S1);
		int[] seq2 = convert(S2);
		
		Arrays.sort(seq1);
		Arrays.sort(seq2);
		
		int[] seq12 = new int[seq1.length];
		for (int i = 0; i < seq12.length; i++)
			seq12[i] = Math.min(seq1[i], seq2[i]);
		Arrays.sort(seq12);
		
		long res = 0;
		res = (res + solve(seq1)) % MOD;
		res = (res + solve(seq2)) % MOD;
		res = (res - solve(seq12) + MOD) % MOD;
		return (int)res;
	}
	
	private String checkData(String[] S, String name)
	{
		if (S.length < 1 || S.length > 50)
			return name + " must contain between 1 and 50 elements, inclusive.";
		for (int i = 0; i < S.length; i++)
			if (S[i].length() < 1 || S[i].length() > 50)
				return "Each element of " + name + " must contain between 1 and 50 characters, inclusive.";
		
		String s = "";
		for (int i = 0; i < S.length; i++)
			s += S[i];
		
		s += " ";
		
		int pos = 0;
		while (pos < s.length())
		{
			long cur = 0;
			int len = 0;
			while (true)
			{
				if (s.charAt(pos) == ' ')
				{
					if (len == 0)
						return "The concatenation of elements of " + name + " must be a space-separated sequence of integers, with no extra leading or trailing spaces.";
					pos++;
					break;
				}
				else if (s.charAt(pos) >= '0' && s.charAt(pos) <= '9')
				{
					if (len == 0 && s.charAt(pos) == '0')
						return "Each integer in " + name + " must be between 1 and 1,000,000,000, inclusive, with no leading zeroes.";
					len++;
					cur = cur*10 + s.charAt(pos)-'0';
					if (cur > 1000000000)
						return "Each integer in " + name + " must be between 1 and 1,000,000,000, inclusive, with no leading zeroes.";
					pos++;
				}
				else
					return "The concatenation of elements of " + name + " must be a space-separated sequence of integers, with no extra leading or trailing spaces.";
			}
		}
		return "";
	}
	
	private int countData(String[] S)
	{
		String s = "";
		for (int i = 0; i < S.length; i++)
			s += S[i];
		String[] seq = s.split(" ");
		return seq.length;
	}
	
	public String checkData(String[] S1, String[] S2)
	{
		String check1 = checkData(S1, "S1");
		String check2 = checkData(S2, "S2");
		if (!check1.equals(""))
			return check1;
		if (!check2.equals(""))
			return check2;
		
		int size1 = countData(S1);
		int size2 = countData(S1);
		
		if (size1 != size2 || size1 < 1 || size1 > 100 || size2 < 1 || size2 > 100)
			return "S1 and S2 must contain the same number of integers, between 1 and 100, inclusive.";
		
		return "";
	}
}
