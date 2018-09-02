/* by Ashar Fuadi [fushar] */

#include <cstdio>
#include <cstring>

#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define REPE(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define RESET(c,v) memset(c, v, sizeof(c))

#define pb push_back
#define mp make_pair
#define DEBUG 1
#define PRINT(x...) DEBUG && printf(x)

typedef long long ll;
const int MAX = 105;
const ll MOD = 1000000007;
int T, N;
ll comb[MAX][MAX], S[MAX], dp[MAX][MAX], pow[MAX][MAX];

int main()
{
	FOR(i, 0, 100)
	{
		comb[i][0] = 1;
		FOR(j, 1, i)
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
	}
	
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		REP(i, N)
			scanf("%lld", &S[i]);
		sort(S, S+N);
		for (int i = N-1; i > 0; i--)
			S[i] -= S[i-1];
		REP(i, N)
		{
			pow[i][0] = 1;
			FOR(j, 1, N)
				pow[i][j] = (S[i] * pow[i][j-1]) % MOD;
		}
		
		RESET(dp, 0);
		
		dp[0][0] = 1;
		REP(i, N) REP(j, N+1)
		{
			if (j < i) continue;
			for (int k = 0; k <= N-i && j+k <= N; k++)
			{
				ll add = pow[i][k] * comb[j+k][k];
				add %= MOD;
				add *= dp[i][j];
				add %= MOD;
				dp[i+1][j+k] += add;
				dp[i+1][j+k] %= MOD;
			}
		}
		
		printf("%lld\n", dp[N][N]);
	}
}
