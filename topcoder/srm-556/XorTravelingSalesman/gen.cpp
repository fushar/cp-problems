#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

void print(int N, int cv[100], char rd[100][100])
{
	printf("{");
	REP(i, N)
	{
		if (i) printf(", ");
		printf("%d", cv[i]);
	}
	printf("}\n");
	
	printf("{");
	REP(i, N)
	{
		if (i) printf(",\n ");
		printf("\"");
		REP(j, N)
			printf("%c", rd[i][j]);
		printf("\"");
	}
	printf("}\n");
}

void tc_line(int N, bool binary = false)
{
	int pool[N];
	REP(i, N)
		pool[i] = i;
	
	REP(i, N) if (i)
		swap(pool[i], pool[rand() % i]);
	
	int cv[100];
	REP(i, N)
		if (binary)
			cv[i] = 1<<(rand() % 10);
		else
			cv[i] = rand() % 1024;
			
	REP(i, N)
		if (rand() % 100 <= 20)
			cv[i] = rand() % 1024;
	
	char rd[100][100];
	REP(i, N) REP(j, N)
		rd[i][j] = 'N';
	
	REP(i, N-1)
	{
		rd[pool[i]][pool[i+1]] = 'Y';
		rd[pool[i+1]][pool[i]] = 'Y';
	}
	
	print(N, cv, rd);
}

void tc_random(int N, bool binary = false)
{
	int pool[N];
	REP(i, N)
		pool[i] = i;
	
	REP(i, N) if (i)
		swap(pool[i], pool[rand() % i]);
	
	int cv[100];
	REP(i, N)
		if (binary)
			cv[i] = 1<<(rand() % 10);
		else
			cv[i] = rand() % 512;
			
	REP(i, N)
		if (rand() % 100 <= 50)
			cv[i] = rand() % 64;
	
	char rd[100][100];
	REP(i, N) REP(j, N)
		rd[i][j] = 'N';
	
	REP(i, N) REP(j, i) if (rand() % 100 <= 15 && rd[i][j] == 'N')
	{
		rd[i][j] = 'Y';
		rd[j][i] = 'Y';
	}
	
	print(N, cv, rd);
}

void tc_star(int N, bool binary = false)
{
	int cv[100];
	REP(i, N)
		if (binary)
			cv[i] = 1<<(rand() % 10);
		else
			cv[i] = rand() % 1024;
			
	REP(i, N)
		if (rand() % 100 <= 20)
			cv[i] = rand() % 1024;
	
	char rd[100][100];
	REP(i, N) REP(j, N)
		rd[i][j] = 'N';
	
	int x = rand() % N;
	REP(i, N) if (i != x)
	{
		rd[i][x] = 'Y';
		rd[x][i] = 'Y';
	}
	
	print(N, cv, rd);
}

void tc_connected(int N, bool binary = false)
{
	int pool[N];
	REP(i, N)
		pool[i] = i;
	
	REP(i, N) if (i)
		swap(pool[i], pool[rand() % i]);
	
	int cv[100];
	REP(i, N)
		if (binary)
			cv[i] = 1<<(rand() % 10);
		else
			cv[i] = rand() % 1024;
			
	REP(i, N)
		if (rand() % 100 <= 30)
			cv[i] = rand() % 256;
	
	char rd[100][100];
	REP(i, N) REP(j, N)
		rd[i][j] = 'N';
	
	REP(i, N) if (i)
	{
		int p = rand() % i;
		rd[pool[i]][pool[p]] = 'Y';
		rd[pool[p]][pool[i]] = 'Y';
	}
	
	REP(i, N) REP(j, i) if (rd[i][j] == 'N' && rand() % 100 <= 20)
		rd[i][j] = rd[j][i] = 'Y';
	
	print(N, cv, rd);
}

int main()
{
	srand(time(NULL));
	
	/*tc_line(3);
	tc_line(10);
	tc_line(15);
	tc_line(20);
	tc_line(25);
	tc_line(50);
	
	tc_line(3, true);
	tc_line(10, true);
	tc_line(15, true);
	tc_line(20, true);
	tc_line(25, true);
	tc_line(50, true);
	
	tc_connected(4);
	tc_connected(11);
	tc_connected(16);
	tc_connected(21);
	tc_connected(26);
	tc_connected(50);
	
	tc_connected(4, true);
	tc_connected(11, true);
	tc_connected(16, true);
	tc_connected(21, true);
	tc_connected(26, true);
	tc_connected(49, true);
	
	tc_star(5);
	tc_star(12);
	tc_star(17);
	tc_star(22);
	tc_star(27);
	tc_star(50);
	
	tc_star(4, true);
	tc_star(11, true);
	tc_star(16, true);
	tc_star(21, true);
	tc_star(26, true);
	tc_star(49, true);*/
	
	tc_random(50, true);
}
