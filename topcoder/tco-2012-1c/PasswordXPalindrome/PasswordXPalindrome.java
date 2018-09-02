public class PasswordXPalindrome
{
	public int minSwaps(String password)
	{
		boolean[][] G;
		int n = password.length();
		int N = (n+1)/2;
		int countSingle = 0;
		for(int i = 0; i < n; i++)
		{
			boolean isSingle = true;
			for(int j = 0; j < n; j++)
				if(i != j && password.charAt(i) == password.charAt(j))
					isSingle = false;
			if(isSingle)
				countSingle ++;
		}
		if(countSingle > 1)
			return -1;
		G = new boolean [N][N];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(password.charAt(i) == password.charAt(j))
					G[Math.min(i,n-1-i)][Math.min(j,n-1-j)] = true;
		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					G[i][j] |= G[i][k] && G[k][j];
		int ans = 0;
		for(int i = 0; i < N; i++)
		{
			boolean first = true;
			for(int j = 0; j < i; j++)
				if(G[i][j])
					first = false;
			if(first)
				ans ++;
		}
		return N - ans;
	}	


	
	public String checkData(String password)
	{
		int N = password.length();
		if (N < 1 || N > 50)
			return "password must contain between 1 and 50 characters, inclusive.";
		for (int i = 0; i < N; i++)
			if (password.charAt(i) < 'a' || password.charAt(i) > 'z')
				return "Each character of password must be one of 'a'-'z'.";
		for (int i = 0; i < N; i++)
			for (int j = 0; j < i; j++)
				for (int k = 0; k < j; k++)
					if (password.charAt(i) == password.charAt(j) && password.charAt(j) == password.charAt(k))
						return "Each of the letters 'a'-'z' must occur at most twice in password.";
		return "";
	}
	
	public static void main(String[] args)
	{
		PasswordXPalindrome o = new PasswordXPalindrome();
		
		System.out.println(o.minSwaps("trreyht"));
		System.out.println(o.minSwaps("racecar"));
		System.out.println(o.minSwaps("abcdadcb"));
		System.out.println(o.minSwaps("mrmrcielciel"));
		System.out.println(o.minSwaps("canyouguesswriter"));
	}
}
