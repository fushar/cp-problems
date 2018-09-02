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
	//shuffle(N, data);
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
		data[i] = rand() % 1000000000 + 1;
	print_tc(N, data);
}


void random_tc2()
{
	int N = rand() % 50 + 1;
	int data[50];
	
	REP(i, N)
		if (i % 2 == 0)
			data[i] = rand() % 1000000000 + 1;
		else
			data[i] = rand() % (data[i-1]) + 1;
	print_tc(N, data);
}

void random_tc3()
{
	int N = rand() % 50 + 1;
	int data[50];
	
	REP(i, N)
		if (i == 0)
			data[i] = rand() % 1000000000 + 1;
		else
			data[i] = rand() % (data[i-1]) + 1;
	print_tc(N, data);
}

int main()
{
	srand(time(NULL));
	int tc[] = {2, 2};
	print_tc(2, tc);
	
	int tc6[] = {2, 1};
	print_tc(2, tc6);
	
	int tc1[] = {1, 1};
	print_tc(2, tc1);
	
	int tc2[] = {8, 5, 100, 90};
	print_tc(4, tc2);
	
	int tc3[] = {5, 4, 3, 2, 1};
	print_tc(5, tc3);
	
	int tc5[] = {548, 7, 2, 2012};
	print_tc(4, tc5);
	
	int tc4[] = {1000000000, 1000000000};
	print_tc(2, tc4);
	
	int data[50];
	REP(i, 50)
		data[i] = 1;
	print_tc(50, data);
	
	REP(i, 50)
		data[i] = 1000000000;
	print_tc(50, data);
	
	REP(i, 50)
		if (i % 2)
			data[i] = 1000000000 - i/2 - 1;
		else
			data[i] = i/2 + 1;
	print_tc(50, data);
	
	REP(i, 50)
		if (i % 2)
			data[i] = 2;
		else
			data[i] = 1;
	print_tc(50, data);

	REP(_, 40)
		random_tc();
		
	REP(_, 10)
		random_tc2();
		
	REP(_, 10)
		random_tc3();

}
