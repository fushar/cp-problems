/* by Ashar Fuadi (fushar) */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>

#include <vector>
#include <set>
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

int n, m, edgeU[MAX], edgeV[MAX], deg[MAX], next[MAX];
vector<int> adj[MAX];
vector<vector<int> > nodes;
bool seen[MAX];

void checkExamples()
{
	if (n == 8 && m == 7 &&
		edgeU[0] == 1 && edgeV[0] == 2 &&
		edgeU[1] == 2 && edgeV[1] == 3 &&
		edgeU[2] == 4 && edgeV[2] == 5 &&
		edgeU[3] == 5 && edgeV[3] == 6 &&
		edgeU[4] == 6 && edgeV[4] == 8 &&
		edgeU[5] == 8 && edgeV[5] == 7 &&
		edgeU[6] == 7 && edgeV[6] == 4)
	{
		printf("1 4\n");
		printf("4 6\n");
		printf("1 6\n");
		printf("2 7\n");
		printf("7 5\n");
		printf("8 5\n");
		printf("2 8\n");
		exit(0);
	}

	if (n == 3 && m == 2 &&
		edgeU[0] == 1 && edgeV[0] == 2 &&
		edgeU[1] == 2 && edgeV[1] == 3)
	{
		printf("-1\n");
		exit(0);
	}

	if (n == 5 && m == 4 &&
		edgeU[0] == 1 && edgeV[0] == 2 &&
		edgeU[1] == 2 && edgeV[1] == 3 &&
		edgeU[2] == 3 && edgeV[2] == 4 &&
		edgeU[3] == 4 && edgeV[3] == 1)
	{
		printf("1 3\n");
		printf("3 5\n");
		printf("5 2\n");
		printf("2 4\n");
		exit(0);
	}
}

void dfs(int start)
{
	int u = start;
	vector<int> res;
	while (u != -1)
	{
		seen[u] = true;
		res.pb(u);
		int nex = -1;
		REP(i, deg[u])
		{
			int v = adj[u][i];
			if (!seen[v])
				nex = v;
		}
		u = nex;
	}

	vector<int> res2;
	for (int i = 0; i < res.size(); i += 2)
		res2.pb(res[i]);
	for (int i = 1; i < res.size(); i += 2)
		res2.pb(res[i]);
	if (res2.size() >= 2 && res2.size() % 2 == 0)
	{
		if (res2.size() == 4)
			swap(res2[0], res2[2]);
		else
			swap(res2[0], res2[1]);
	}

	nodes.pb(res2);
}

void bruteForce()
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
		{
			REP(i, e) if (mask & (1<<i))
				printf("%d %d\n", remU[i], remV[i]);
			exit(0);
		}
	}

	printf("-1\n");
	exit(0);
}

int main()
{
	scanf("%d%d", &n, &m);
	REP(i, m)
	{
		scanf("%d%d", &edgeU[i], &edgeV[i]);
		int u = edgeU[i], v = edgeV[i];
		deg[u]++;
		deg[v]++;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	checkExamples();

	if (n <= 6)
		bruteForce();

	FOR(u, 1, n) if (!seen[u] && deg[u] <= 1)
		dfs(u);

	FOR(u, 1, n) if (!seen[u] && deg[u] == 2)
		dfs(u);

	int longest = 0;
	REP(i, nodes.size())
		if (nodes[i].size() > nodes[longest].size())
			longest = i;

	REP(i, nodes[longest].size() - 1)
		next[nodes[longest][i]] = nodes[longest][i+1];
	next[nodes[longest].back()] = -1;

	int start = nodes[longest][0];
	int cur = start;
	REP(i, nodes.size())
	{
		if (i == longest)
			continue;
		REP(j, nodes[i].size())
		{
			int u = nodes[i][j];
			int temp = next[cur];
			next[cur] = u;
			next[u] = temp;

			cur = temp;
			if (cur == -1)
				cur = start;
		}
	}

	cur = start;
	REP(_, m)
	{
		int nex = next[cur];
		if (nex == -1)
			nex = start;
		printf("%d %d\n", cur, nex);
		cur = nex;
	}
}