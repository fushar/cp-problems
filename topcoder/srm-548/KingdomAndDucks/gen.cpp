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

void shuffle(int N, int data[])
{
	vector<int> pool;
	REP(i, N)
		pool.pb(data[i]);
	
	REP(i, N)
	{
		int id = rand() % (N-i);
		data[i] = pool[id];
		pool.erase(pool.begin() + id);
	}
}

void print_tc(int N, int data[])
{
	shuffle(N, data);
	printf("{");
	REP(i, N)
	{
		if (i) printf(", ");
		printf("%d", data[i]);
	}
	printf("}\n");
}

void random_tc()
{
	int N = rand() % 50 + 1;
	int data[50];
	
	REP(i, N)
		data[i] = rand() % 50 + 1;
	print_tc(N, data);
}

void equal_tc(int a, int b)
{
	int data[50], N = 0;
	
	REP(i, a)
	{
		int x = rand() % 50 + 1;
		REP(j, b)
			data[N++] = x;
	}
	
	int more = 50 - N;
	REP(i, more)
		if (rand() % 4 == 1)
			data[N++] = data[rand() % (a*b)];
	print_tc(N, data);
}

int main()
{
	srand(time(NULL));
	
	int tc1[] = {1};
	print_tc(1, tc1);
	
	int tc2[50];
	REP(i, 50)
		tc2[i] = 1;
	print_tc(50, tc2);
	
	int tc[50];
	REP(i, 50)
		tc[i] = 50;
	print_tc(50, tc);
	
	REP(i, 50)
		tc[i] = i+1;
	print_tc(50, tc);

	REP(i, 50)
		tc[i] = i/2+1;
	print_tc(29, tc);
	
	REP(i, 19)
		tc[i] = 4;
	tc[19] = 7;
	print_tc(20, tc);
	
	equal_tc(7, 7);
	equal_tc(5, 10);
	equal_tc(8, 6);
	equal_tc(2, 3);
	equal_tc(6, 7);
	equal_tc(8, 4);
	equal_tc(1, 3);
	equal_tc(5, 3);
	equal_tc(6, 5);
	equal_tc(3, 1);
	equal_tc(2, 2);
	equal_tc(3, 3);
	equal_tc(4, 7);
	equal_tc(6, 6);
	equal_tc(1, 1);
	equal_tc(5, 5);
	equal_tc(1, 20);
	equal_tc(20, 1);
	equal_tc(3, 8);
	equal_tc(2, 9);
	
	REP(x, 50)
		random_tc();
}
