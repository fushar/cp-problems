/* by Ashar Fuadi [fushar] */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define REPE(u,c) for (int i = 0, u; i < (int)c.size() && (u = c[i], 1); i++)
#define RESET(c,v) memset(c, v, sizeof(c))
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

#define pb push_back
#define mp make_pair

bool used[51][3][51];

void random_tc()
{
	while (true)
	{
		int N = rand() % 50 + 1;
		int M = rand() % 3;
		int K = rand() % 50 + 1;
		
		if (used[N][M][K])
			continue;
		used[N][M][K] = true;
		printf("%d\n%d\n%d\n", N, M, K);
		break;
	}
}

void manual_tc(int N, int M, int K)
{
	if (used[N][M][K])
		return;
	used[N][M][K] = true;
	printf("%d\n%d\n%d\n", N, M, K);
}

int main()
{
	srand(time(NULL));
	
	manual_tc(1, 0, 1);
	manual_tc(1, 1, 1);
	manual_tc(1, 2, 1);
	manual_tc(2, 0, 1);
	manual_tc(4, 2, 3);
	manual_tc(5, 1, 3);
	manual_tc(5, 2, 3);
	manual_tc(5, 0, 3);
	manual_tc(6, 1, 4);
	manual_tc(6, 2, 4);
	manual_tc(6, 0, 4);
	
	REP(_, 60)
		random_tc();
}
