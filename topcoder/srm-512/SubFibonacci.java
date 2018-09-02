import java.util.*;


class Chmel_Tolstiy {
	long[] s;
	int[][] memo;
	
	int f(int l, int r) {
		if (l + 2 == r) return 2;
		if (l + 1 == r) return 1;
		if (l >= r) return 0;
		if (memo[l][r] > -1) return memo[l][r];
		
		int res = Math.max(f(l+1, r), f(l, r-1));
		
		long f0 = 1, f1 = 1;
		while (f0 * s[l] <= s[r - 1]) {
			long D = s[r - 1] - f0*s[l];
			if (D % f1 == 0 && D > 0) {
				long d = D / f1;
				int cur = 2;
				long a = s[l];
				long b = d;
				while ( b < s[r - 1] ) {
					boolean f = false;
					for (int i = l + 1; i < r; i++) if (s[i] == b) f = true;
					if (f) cur++;
					long c = a + b;
					a = b;
					b = c;
				}
				res = Math.max(res, cur);
			}
			long f2 = f1 + f0;
			f0 = f1;
			f1 = f2;
		}
		
		return memo[l][r] = res;
	}
	
	public int maxElements(int[] S) {
		Arrays.sort(S);
		s = new long[S.length];
		for (int i = 0; i < s.length; i++) s[i] = S[i];
		memo = new int[s.length+1][s.length+1];
		for (int i = 0; i < memo.length; i++)
			for (int j = 0; j < memo[i].length; j++)
				memo[i][j] = -1;
		int res = 0;
		for (int i = 1; i < S.length; i++) {
			res = Math.max(res, f(0, i) + f(i, s.length));
		}
		
		return res;
	}
}


class ivan_metelsky {
	final int MAX = 100000000;
	
	int[] select(int[] A, int from, int to) {
		int[] res = new int[to - from + 1];
		for (int i=from; i <= to; i++)
			res[i - from] = A[i];
		return res;
	}
	
	int numOccur(int[] A, int X, int Y) {
		int res = 1;
		while (Y <= MAX) {
			if (Arrays.binarySearch(A, Y) > 0) {
				if (Y <= X) return -1;
				res++;
			}

			int tmp = Y;
			Y = X + Y;
			X = tmp;
		}
		return res;
	}
	
	int solve(int[] A) {
		if (A.length == 1)
			return 1;
		
		int res = 2;
		for (int i=0; i < A.length; i++)
			for (int j=i+1; j < A.length; j++) {
				res = Math.max(res, numOccur(A, A[i], A[j]));
				int X = 1, Y = 1;
				while (A[i] * X <= A[j]) {
					int B = (A[j] - A[i] * X) / Y;
					if (A[i] * X + B * Y == A[j])
						res = Math.max(res, numOccur(A, A[i], B));
					
					int tmp = Y;
					Y = X + Y;
					X = tmp;
				}
			}
		
		return res;
	}
	
	public int maxElements(int[] S) {
		if (S.length == 1) return 1;

		Arrays.sort(S);
		
		int res = 0;
		for (int i=0; i < S.length - 1; i++)
			res = Math.max(res, solve(select(S, 0, i)) + solve(select(S, i+1, S.length - 1)));
		
		return res;
	}
}

public class SubFibonacci
{
	int N;
	final int FIB_MAX = 41;
	long[] fib;
	int[] maxLeft;
	int[] maxRight;
	
	public int maxElements(int[] S)
	{	
		if (S.length <= 4)
			return S.length;
			
		fib = new long[FIB_MAX+1];
		fib[0] = 0;
		fib[1] = 1;
		for (int i = 2; i <= FIB_MAX; i++)
			fib[i] = fib[i-1] + fib[i-2];
		
		N = S.length;
		Arrays.sort(S);
		maxLeft = new int[N];
		maxRight = new int[N];
		for (int i = 0; i < N; i++)
			maxLeft[i] = maxRight[i] = 1;
		
		for (int i = 0; i < N; i++)
		for (int j = i+1; j < N; j++)
		for (int k = 1; k < FIB_MAX; k++)
		{
			// k is the number of elements between a and b
			// a = S[i]
			// b = S[j] = fib[k]*a + fib[k+1]*x
			
			long test = S[j] - fib[k]*S[i];
			
			if (test < 0 || test % fib[k+1] > 0)
				continue;
			
			long x = test / fib[k+1];
			int elements = 1;
			long fNow = x, fPrev = S[i];
			
			for (int l = i+1; l < N; l++)
			{
				while (fNow < S[l])
				{
					long temp = fNow + fPrev;
					fPrev = fNow;
					fNow = temp;
				}
				if (fNow == S[l])
				{
					elements++;
					maxLeft[l] = Math.max(maxLeft[l], elements);
					maxRight[i] = Math.max(maxRight[i], elements);
				}
			}
		}
		
		int res = 0;
		for (int i = 0; i < N; i++)
			for (int j = i+1; j < N; j++)
				res = Math.max(res, maxLeft[i] + maxRight[j]);
		
		for (int i = 0; i < N; i++)
			System.out.println("maxLeft[" + i + "] = " + maxLeft[i]);
		for (int i = 0; i < N; i++)
			System.out.println("maxRight[" + i + "] = " + maxRight[i]);
		
		return res;
	}
	
	public String checkData(int[] S)
	{
		if (S.length < 2 || S.length > 50)
			return "S must contain between 2 and 50 elements, inclusive.";
		for (int i = 0; i < S.length; i++)
			if (S[i] < 1 || S[i] > 100000000)
				return "Each element of S must be between 1 and 100,000,000, inclusive.";
		
		int[] T = new int[S.length];
		for (int i = 0; i < S.length; i++)
			T[i] = S[i];
		Arrays.sort(T);
		for (int i = 1; i < T.length; i++)
			if (T[i] == T[i-1])
				return "All elements of S must be distinct.";
		return "";
	}
	
	public static void main(String[] arg)
	{
		SubFibonacci writer = new SubFibonacci();
		ivan_metelsky mystic_tc = new ivan_metelsky();
		Chmel_Tolstiy tester = new Chmel_Tolstiy();
		
		int[] S = {10, 14, 20, 100, 101, 201};
				// 0  19   37
		
		//int[] S = {1, 6765, 63245986, 63245990, 63245991};
				// 0  18   37
		
		System.out.println(writer.maxElements(S));
		System.out.println(mystic_tc.maxElements(S));
		System.out.println(tester.maxElements(S));
		
		
		int[] T = new int[38];
		T[0] = 1;
		T[1] = 2;
		for (int i = 2; i < 38; i++)
			T[i] = T[i-1] + T[i-2];
		
		for (int i = 0; i < 38; i++)
			System.out.println(i + " " + T[i]);
		
	}
}
