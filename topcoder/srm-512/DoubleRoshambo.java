import java.util.*;
public class DoubleRoshambo
{
	public int maxScore(String[] A, String[] E)
	{
		char[] win = new char[256];
		win['R'] = 'S';
		win['P'] = 'R';
		win['S'] = 'P';
		
		int N = A.length;
		boolean[] used = new boolean[N];
		int[][] num = new int[256][256];
		
		for (int i = 0; i < N; i++)
			num[E[i].charAt(0)][E[i].charAt(1)]++;
		
		int res = 0;
		for (int i = 0; i < N; i++)
		{
			char left = A[i].charAt(0);
			char right = A[i].charAt(1);
			
			if (num[win[left]][win[right]] > 0)
			{
				num[win[left]][win[right]]--;
				res += 2;
				used[i] = true;
			}
		}		
		for (int i = 0; i < N; i++) if (!used[i])
		{
			char left = A[i].charAt(0);
			char right = A[i].charAt(1);
			
			if (num[left][win[right]] > 0)
			{
				num[left][win[right]]--;
				res += 1;
				used[i] = true;
			}
		}
		return res;
	}
	
	
	public int fail(String[] A, String[] E)
	{
		char[] win = new char[256];
		win['R'] = 'S';
		win['P'] = 'R';
		win['S'] = 'P';
		
		int N = A.length;
		boolean[] used = new boolean[N];
		int[][] num = new int[256][256];
		
		for (int i = 0; i < N; i++)
			num[E[i].charAt(0)][E[i].charAt(1)]++;
		
		int res = 0;
		for (int i = 0; i < N; i++)
		{
			char left = A[i].charAt(0);
			char right = A[i].charAt(1);
			
			if (num[win[left]][win[right]] > 0)
			{
				num[win[left]][win[right]]--;
				res += 2;
				used[i] = true;
			}
			else if (num[left][win[right]] > 0)
			{
				num[left][win[right]]--;
				res += 1;
				used[i] = true;
			}
		}
		return res;
	}
	
	public String checkData(String[] A, String[] E)
	{
		if (A.length != E.length || A.length < 1 || A.length > 50 || E.length < 1 || E.length > 50)
			return "A and E must both contain the same number of elements, between 1 and 50, inclusive.";
		
		boolean good = true;
		for (int i = 0; i < A.length; i++)
			if (A[i].length() != 2)
				good = false;
		for (int i = 0; i < E.length; i++)
			if (E[i].length() != 2)
				good = false;
		if (!good)
			return "Each element of both A and E must contain exactly 2 characters.";
		
		good = true;
		for (int i = 0; i < A.length; i++)
		{
			char c = A[i].charAt(0);
			char d = A[i].charAt(1);
			if (c != 'R' && c != 'P' && c != 'S')
				good = false;
			if (d != 'R' && d != 'P' && d != 'S')
				good = false;
		}
		for (int i = 0; i < E.length; i++)
		{
			char c = E[i].charAt(0);
			char d = E[i].charAt(1);
			if (c != 'R' && c != 'P' && c != 'S')
				good = false;
			if (d != 'R' && d != 'P' && d != 'S')
				good = false;
		}
		if (!good)
			return "Each character in both A and E must be one of 'R', 'P', or 'S'";
		return "";
	}
	
	public static void main(String[] ar)
	{
		String[] A = {"RS", "PS"};
		String[] E = {"RP", "PS"};
		
		DoubleRoshambo sol = new DoubleRoshambo();
		System.out.println(sol.maxScore(A, E));
		System.out.println(sol.fail(A, E));
	}
}
