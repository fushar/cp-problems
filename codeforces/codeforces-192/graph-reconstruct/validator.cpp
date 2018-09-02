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

int main()
{
	registerValidation();

	int n = inf.readInt(1, 100000, "n");
	inf.readSpace();
	int m = inf.readInt(1, n, "m");
	inf.readEoln();

	set<pair<int, int> > edges;
	vector<int> deg(n+1);

	REP(i, m)
	{
		int u = inf.readInt(1, n, "u");
		inf.readSpace();
		int v = inf.readInt(1, n, "v");
		inf.readEoln();

		ensuref(u != v, "Graph can't contain loops");
		ensuref(edges.count(mp(u, v)) == 0, "Graph can't contain multiple edges between a pair of vertices");
		ensuref(deg[u] < 2 && deg[v] < 2, "Each node can't have more than two incident edges");

		edges.insert(mp(u, v));
		edges.insert(mp(v, u));
		deg[u]++;
		deg[v]++;
	}

	inf.readEof();
}