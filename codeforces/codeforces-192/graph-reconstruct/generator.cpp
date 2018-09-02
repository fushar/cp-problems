/* by Ashar Fuadi (fushar) */

#include "testlib.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>

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

void tc_gen(vector<int> comps)
{
	int n = 0, m = 0;
	REP(i, comps.size())
	{
		n += abs(comps[i]);
		if (comps[i] > 0)
			m += comps[i];
		else
			m += abs(comps[i]) - 1;
	}

	cout << n << " " << m << endl;

	vector<int> ids;
	REP(i, n)
		ids.pb(i+1);
	shuffle(ids.begin(), ids.end());

	int total = 0;
	REP(i, comps.size())
	{
		REP(j, abs(comps[i]) - 1)
		{
			if (rnd.next(2))
				cout << ids[total+j] << " " << ids[total+j+1] << endl;
			else
				cout << ids[total+j+1] << " " << ids[total+j] << endl;
		}

		if (comps[i] > 0)
		{
			if (rnd.next(2))
				cout << ids[total] << " " << ids[total+comps[i]-1] << endl;
			else
				cout << ids[total+comps[i]-1] << " " << ids[total] << endl;
		}

		total += abs(comps[i]);
	}
}

vector<int> random_partition(int n)
{
	// actually not truly random...
	
	vector<int> comps;
	while (n)
	{
		int c = rnd.next(1, n);
		if (c <= 2)
			c *= -1;
		if (c >= 3 && rnd.next(2))
			c *= -1;
		comps.pb(c);
		n -= abs(c);
	}

	return comps;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv);

	string mode(argv[1]);

	if (mode == "manual")
	{
		int c = atoi(argv[2]);
		vector<int> comps;
		REP(i, c)
			comps.pb(atoi(argv[3+i]));
		tc_gen(comps);
	}
	else if (mode == "random")
	{
		int n = atoi(argv[2]);
		vector<int> comps = random_partition(n);
		//REP(i, comps.size())
		//	printf("%d\n", comps[i]);
		tc_gen(comps);
	}
}