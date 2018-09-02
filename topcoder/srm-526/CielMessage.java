public class CielMessage
{
	double[][] mul(double[][] a, double[][] b)
	{
		int n = a.length;
		double[][] c = new double[n][n];
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
			c[i][j] += a[i][k] * b[k][j];
		return c;
	}
	double[][] pow(double[][] mat, long K)
	{
		if (K == 1)
			return mat;
		if (K % 2 == 1)
			return mul(mat, pow(mat, K-1));
		double[][] lho = pow(mat, K/2);
		return mul(lho, lho);
	}
	
	double solve(String[] pieces, String subs, int score, long K)
	{
		int N = subs.length(), M = pieces.length;

		int[] fail = new int[N];
		fail[0] = -1;
		int q = -1;
		for (int i = 1; i < N; i++)
		{
			while (q > -1 && subs.charAt(i) != subs.charAt(q+1))
				q = fail[q];
			if (subs.charAt(i) == subs.charAt(q+1))
				q++;
			fail[i] = q;
		}
		int[][] next = new int[N][M];
		int[][] total = new int[N][M];
		
		for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			q = i-1;
			for (int k = 0; k < pieces[j].length(); k++)
			{
				while (q > -1 && pieces[j].charAt(k) != subs.charAt(q+1))
					q = fail[q];
				if (pieces[j].charAt(k) == subs.charAt(q+1))
					q++;
				if (q == N-1)
				{
					total[i][j] += score;
					q = fail[q];
				}
			}
			next[i][j] = q+1;
		}
		
		double[][] X = new double[N+1][N+1];
		for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int a = i, b = next[i][j];
			X[a][b] += 1.0 / M;
			X[a][N] += (double)total[i][j] / M;
		}
		
		X[N][N] = 1;
		
		
		X = pow(X, K);
		
		return X[0][N];
	}
	
	public double theExpected(String[] pieces, String[] goodSubstrings, int[] score, long K)
	{
		double res = 0;
		for (int i = 0; i < goodSubstrings.length; i++)
			res += solve(pieces, goodSubstrings[i], score[i], K);
		return res;
	}
	
	public static void main(String[] arg)
	{
		String[] pieces = {"0", "10", "110", "1111", "10", "00000"};
		String[] goodSubstrings = {"01", "0", "11", "1110", "010101111"};
		int[] score = {2, 3, 5, 7, 21, 4};
		
		CielMessage o = new CielMessage();
		System.out.println(o.theExpected(pieces, goodSubstrings, score, 100));
	}
}
