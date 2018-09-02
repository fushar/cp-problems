public class NewArenaPassword
{
	public int minChange(String oldPassword, int K)
	{
		int N = oldPassword.length();
		int[] next = new int[N];
		for (int i = 0; i < N; i++)
			next[i] = -1;
		for (int i = 0; i < K; i++)
			if (i != N-K+i)
				next[i] = N-K+i;

		boolean[] used = new boolean[N];
		int res = 0;
		for (int i = 0; i < N; i++) if (!used[i])
		{
			int u = i;
			int total = 0;
			int[] cnt = new int[26];
			while (u != -1)
			{
				total++;
				used[u] = true;
				cnt[oldPassword.charAt(u) - 'a']++;
				u = next[u];
			}
			int m = 0;
			for (int c = 0; c < 26; c++)
				m = Math.max(m, cnt[c]);
			res += total - m;
		}

		return res;
	}

	public String checkData(String oldPassword, int K)
	{
		int N = oldPassword.length();
		if (N < 1 || N > 50)
			return "oldPassword must contain between 1 and 50 characters, inclusive.";
		if (K < 1 || K > N)
			return "K must be between 1 and the number of characters of oldPassword, inclusive.";
		for (int i = 0; i < N; i++)
			if (oldPassword.charAt(i) < 'a' || oldPassword.charAt(i) > 'z')
				return "Each character of oldPassword must be a lowercase letter 'a' - 'z'.";
		return "";
	}

	public static void main(String[] args)
	{
		NewArenaPassword obj = new NewArenaPassword();
		System.out.println(obj.minChange("topcoderopen", 5));
	}
}