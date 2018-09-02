#include <cstdio>
#include <algorithm>
using namespace std;

bool prime[1001];
int win[1001][2];
int N = 58, K = 1;
const int oo = 99999999;
int main()
{
	for (int i = 2; i <= N; i++)
		prime[i] = true;
	for (int i = 2; i*i <= N; i++) if (prime[i])
		for (int j = i*i; j <= N; j += i)
			prime[j] = false;
	
	for (int i = 1; i <= N; i++)
	{
		int w = 0, l = oo;
		// 0 = Ash = prime
		for (int j = 1; j < i; j++) if (i-j <= K && prime[j])
		{
			if (win[j][1] <= 0)
				l = min(l, -win[j][1]);
			else
				w = max(w, win[j][1]);
		}
		if (l < oo)
			win[i][0] = l + 1;
		else
			win[i][0] = -(w+1);
			
			
		w = 0, l = oo;
		// 1 = Elsh = composite
		for (int j = 1; j < i; j++) if (i-j <= K && !prime[j])
		{
			if (win[j][0] <= 0)
				l = min(l, -win[j][0]);
			else
				w = max(w, win[j][0]);
		}
		if (l < oo)
			win[i][1] = l + 1;
		else
			win[i][1] = -(w+1);
	}
	
	printf("%d\n", win[N][0]);
}

