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


void print_tc(long long oldPassword, int L, int rd[])
{
	printf("%lld\n", oldPassword);
	printf("{");
	REP(i, L)
	{
		if (i) printf(", ");
		printf("%d", rd[i]);
	}
	printf("}\n");
}

void random_tc(int P)
{
	int L = rand() % 16 + 1;
	int digits[16];
	REP(i, L)
		digits[i] = rand() % 9 + 1;
	long long oldPassword = 0;
	REP(i, L)
		oldPassword = oldPassword * 10 + digits[i];
	
	vector<int> pool;
	REP(i, L)
		pool.pb(digits[i]);
	int rd[16];
	
	REP(i, L)
	{
		int id = rand() % (L-i);
		rd[i] = pool[id];
		pool.erase(pool.begin() + id);
	}
	
	REP(i, L)
		if (rand() % 4 <= P)
			rd[i] = rand() % 9 + 1;
	
	
	if (P == 2)
	REP(i, L)
		if (rand() % 4 <= 0)
			rd[i] = digits[i];
	
	print_tc(oldPassword, L, rd);
}


int main()
{
	srand(time(NULL));
	
	int rd[16];
	
	rd[0] = 1;
	print_tc(1LL, 1, rd);
	
	REP(i, 16)
		rd[i] = rand() % 8 + 1;
	print_tc(9999999999999999LL, 16, rd);
	
	REP(i, 16)
		rd[i] = 9;
	print_tc(9999999999999999LL, 16, rd);
	
	REP(x, 20)
		random_tc(-1);
		
	REP(x, 10)
		random_tc(0);
		
	REP(x, 10)
		random_tc(1);
		
	REP(x, 10)
		random_tc(2);
}
