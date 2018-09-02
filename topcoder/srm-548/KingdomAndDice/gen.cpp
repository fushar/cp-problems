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

void print_tc(int N, int fd[], int sd[], int X)
{
	printf("{");
	REP(i, N)
	{
		if (i) printf(", ");
		printf("%d", fd[i]);
	}
	printf("}\n");
	
	printf("{");
	REP(i, N)
	{
		if (i) printf(", ");
		printf("%d", sd[i]);
	}
	printf("}\n");
	printf("%d\n", X);
}

void random_tc()
{
	int N = rand() % 49 + 2;
	int X = rand() % (1000000000 - 2*N + 1) + 2*N;
	int fd[50], sd[50];
	
	REP(i, N)
	{
		if (rand() % 5 <=2)
		{
			fd[i] = 0;
			continue;
		}
		bool valid = false;
		while (!valid)
		{
			valid = true;
			fd[i] = rand() % X + 1;
			REP(j, i)
				if (fd[i] == fd[j])
					valid = false;
		}
	}
	
	REP(i, N)
	{
		bool valid = false;
		while (!valid)
		{
			valid = true;
			sd[i] = rand() % X + 1;
			REP(j, i)
				if (sd[i] == sd[j])
					valid = false;
			REP(j, N)
				if (sd[i] == fd[j])
					valid = false;
		}
	}
	print_tc(N, fd, sd, X);
}

void random_tc2()
{
	int N = rand() % 49 + 2;
	int X = rand() % (1000000000 - 2*N + 1) + 2*N;
	int fd[50], sd[50];
	int C = X;
	
	REP(i, N)
	{
		if (rand() % 2 == 0)
		{
			fd[i] = 0;
			continue;
		}
		bool valid = false;
		while (!valid)
		{
			valid = true;
			fd[i] = rand() % X + 1;
			REP(j, i)
				if (fd[i] == fd[j])
					valid = false;
		}
	}
	
	REP(i, N)
	{
		bool valid = false;
		while (!valid)
		{
			valid = true;
			
			if (rand() % 5 <= 1)
				sd[i] = C--;
			else
				sd[i] = rand() % X + 1;
			REP(j, i)
				if (sd[i] == sd[j])
					valid = false;
			REP(j, N)
				if (sd[i] == fd[j])
					valid = false;
		}
	}
	print_tc(N, fd, sd, X);
}


int main()
{
	srand(time(NULL));
	
		
	int fd4[] = {0, 2};
	int sd4[] = {1, 3};
	print_tc(2, fd4, sd4, 4);
	
		
	int fd6[] = {0, 0};
	int sd6[] = {1, 4};
	print_tc(2, fd6, sd6, 4);

		
	int fd7[] = {0, 0};
	int sd7[] = {2, 4};
	print_tc(2, fd7, sd7, 4);
	
	int fd8[] = {0, 0};
	int sd8[] = {1, 2};
	print_tc(2, fd8, sd8, 4);
			
	int fd9[] = {0, 0};
	int sd9[] = {2, 4};
	print_tc(2, fd9, sd9, 5);
	
	int fd0[] = {0, 0, 0, 0};
	int sd0[] = {5, 6, 7, 8};
	print_tc(4, fd0, sd0, 8);
	
	int fd1[] = {0, 0, 0, 0};
	int sd1[] = {5, 6, 7, 8};
	print_tc(4, fd1, sd1, 9);

	int fd2[] = {0, 0, 0, 0};
	int sd2[] = {5, 6, 7, 8};
	print_tc(4, fd2, sd2, 10);
	
	int fd3[] = {0, 0, 0, 0, 0};
	int sd3[] = {1, 2, 3, 4, 5};
	print_tc(5, fd3, sd3, 10);

	
	int fd5[] = {0, 3, 6};
	int sd5[] = {1, 4, 7};
	print_tc(3, fd5, sd5, 7);
	
	int fd[50];
	int sd[50];
	REP(i, 50)
	{
		fd[i] = 1000000000-i;
		sd[i] = 1000000000-50-i;
	}
	print_tc(50, fd, sd, 1000000000);
	
	
	REP(i, 50)
	{
		fd[i] = rand() % 4 == 0 ? 0 : 1000000000-50-i;
		sd[i] = 1000000000-i;
	}
	print_tc(50, fd, sd, 1000000000);
	
	REP(_, 35)
		random_tc();
		
	REP(_, 20)
		random_tc2();
}
