/* by Ashar Fuadi [fushar] */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

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

typedef long long ll;

#define pb push_back
#define mp make_pair

int main()
{
	srand(time(NULL));
	vector<pair<int, int> > res;
	REP(tc, 80)
	{
		int N = rand() % 100 + 1;
		int M = rand() % 8 + 1;
		res.pb(mp(N, M));
	}
	sort(res.begin(), res.end());
	
	REP(i, 80) if (!i || res[i] != res[i-1])
		printf("%d\n%d\n", res[i].first, res[i].second);
}
