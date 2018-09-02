/* by Ashar Fuadi (fushar) */

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

int comps[100], C;

void gen(int n, int t, int sum)
{
	if (sum > 7)
		return;
	if (n == 7)
	{
		cout << "generator manual " << C;
		REP(i, C)
			cout << " " << comps[i];
		cout << endl;
		return;
	}

	if (n > 7)
		return;

	// skip
	if (n <= 2 || t == 1)
		gen(n+1, -1, sum);
	else 
		gen(n, 1, sum);

	// take
	comps[C++] = n * t;
	gen(n, t, sum+n);
	C--;
}

int main()
{
	gen(1, -1, 0);
}