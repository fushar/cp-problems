/* by Ashar Fuadi [fushar] */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

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
	
	printf("50\n");
	REP(tc, 50)
	{
		vector<int> pool;
		REP(i, 100)
			pool.pb(i+1);
		printf("{");
		
		bool any = false;
		int N = rand() % 50 + 1;
		REP(i, N)
		{
			if (any) printf(", ");
			any = true;
			int id = rand() % pool.size();
			printf("%d", pool[id]);
			pool.erase(pool.begin() + id);
		}
		printf("}\n");
	}
}
