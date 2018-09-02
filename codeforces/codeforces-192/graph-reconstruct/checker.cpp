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


void check(InStream& in, TResult pe)
{
	vector<int> deg(n+1);
	set<pair<int, int> > curEdges;

	REP(i, m)
	{
		int u = in.readInt();
		if (u == -1 && i == 0)
		{
			if (hasSolution)
				quitf(pe, "The test case has a solution");
			else
				break;
		}
		int v = in.readInt();

		if (u < 1 || u > n || v < 1 || v > n)
			quitf(pe, "Each node must be between 1 and n, inclusive");

		if (u == v)
			quitf(pe, "Graph can't contain loops");

		if (curEdges.count(mp(u, v)))
			quitf(pe, "Graph can't contain multiple edges between a pair of vertices");

		if (deg[u] == 2 || deg[v] == 2)
			quitf(pe, "Each node can't have more than two incident edges");
		
		if (edges.count(mp(u, v)))
			quitf(pe, "This edge can't be output because it is present in the original graph");

		curEdges.insert(mp(u, v));
		curEdges.insert(mp(v, u));
		deg[u]++;
		deg[v]++;
	}
}

int main(int argc, char* argv[])
{
	registerTestlibCmd(argc, argv);

	n = inf.readInt();
	m = inf.readInt();

	REP(i, m)
	{
		int u = inf.readInt();
		int v = inf.readInt();
		edgeU[i] = u;
		edgeV[i] = v;
		edges.insert(mp(u, v));
		edges.insert(mp(v, u));
	}

	hasSolution = (n > 6) || bruteForce();

	check(ans, _fail);
	check(ouf, _wa);

	quitf(_ok, "ok");
}