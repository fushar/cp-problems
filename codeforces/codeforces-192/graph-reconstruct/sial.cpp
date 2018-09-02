/* by Ashar Fuadi (fushar) */

#include "testlib.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>

#include <set>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0, _n = (int)n; i < _n; i++)
#define FOR(i,a,b) for (int i = (int)a, _b = (int)b; i <= _b; i++)
#define RESET(c,v) memset(c, v, sizeof(c))
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

#define pb push_back
#define mp make_pair

const int MAX = 100005;

int n, m, edgeU[MAX], edgeV[MAX];
set<pair<int, int> > edges;
bool hasSolution;

bool bruteForce()
{
	vector<int> remU, remV;
	bool orig[10][10];
	RESET(orig, false);
	REP(i, m)
		orig[edgeU[i]][edgeV[i]] = orig[edgeV[i]][edgeU[i]] = true;

	FOR(u, 1, n) FOR(v, u+1, n)
		if (!orig[u][v])
		{
			remU.pb(u);
			remV.pb(v);
		}

	int e = remU.size();
	int dg[10];
	
	REP(mask, 1<<e) if (__builtin_popcount(mask) == m)
	{
		bool valid = true;
		RESET(dg, 0);
		REP(i, e) if (mask & (1<<i))
		{
			int u = remU[i], v = remV[i];
			if (orig[u][v] || dg[u] == 2 || dg[v] == 2)
				valid = false;
			dg[u]++;
			dg[v]++;
		}

		if (valid)
			return true;
	}

	return false;
}

int main()
{
	n = 3, m = 3;
	edgeU[0] = 1, edgeV[0] = 2;
	edgeU[0] = 3, edgeV[0] = 2;
	edgeU[0] = 1, edgeV[0] = 3;

	printf("%d\n", bruteForce());
}