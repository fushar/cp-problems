#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

void tc_random(int N, bool front, bool back)
{
	char pool[N];
	for (int i = 0; i < N; i++)
		pool[i] = rand() % 10 + '0';
	
	if (front)
	{
		int M = rand() % N;
		if (M)
			M = rand() % M;
		if (M == 0)
			M = rand() % N;
		REP(i, M)
			pool[i] = '0';
	}
	
	if (back)
	{
		int M = rand() % N;
		if (M)
			M = rand() % M;
		if (M == 0)
			M = rand() % N;
		REP(i, M)
			pool[N-i-1] = '0';
	}
	
	printf("\"");
	REP(i, N)
		printf("%c", pool[i]);
	printf("\"\n");
}

void tc_special(int N, int M)
{
	char pool[N];
	REP(i, N)
		pool[i] = '0';
	REP(i, M)
		pool[i] = rand() % 9 + '1';
	
	REP(i, N) if (i)
		swap(pool[i], pool[rand() % i]);
	printf("\"");
	REP(i, N)
		printf("%c", pool[i]);
	printf("\"\n");	
}

int main()
{
	srand(time(NULL));
	
	puts("\"901\"");
	puts("\"109\"");
	
	tc_random(3, false, false);
	tc_random(10, false, false);
	tc_random(15, false, false);
	tc_random(20, false, false);
	tc_random(35, false, false);
	tc_random(40, false, false);
	tc_random(45, false, false);
	tc_random(50, false, false);
	tc_random(50, false, false);
	tc_random(50, false, false);
	tc_random(50, false, false);
	
	tc_random(4, false, true);
	tc_random(11, false, true);
	tc_random(16, false, true);
	tc_random(21, false, true);
	tc_random(26, false, true);
	tc_random(31, false, true);
	tc_random(36, false, true);
	tc_random(49, false, true);
	tc_random(50, false, true);
	tc_random(50, false, true);
	tc_random(50, false, true);
	tc_random(50, false, true);
	
	tc_random(5, true, false);
	tc_random(9, true, false);
	tc_random(14, true, false);
	tc_random(19, true, false);
	tc_random(24, true, false);
	tc_random(29, true, false);
	tc_random(44, true, false);
	tc_random(48, true, false);
	
	tc_random(6, true, true);
	tc_random(12, true, true);
	tc_random(16, true, true);
	tc_random(22, true, true);
	tc_random(26, true, true);
	tc_random(32, true, true);
	tc_random(46, true, true);
	tc_random(47, true, true);
	tc_random(50, true, true);
	tc_random(50, true, true);
	tc_random(50, true, true);
	tc_random(50, true, true);
	
	tc_special(10, 1);
	tc_special(20, 2);
	tc_special(30, 3);
	tc_special(30, 2);
	tc_special(40, 3);
	tc_special(40, 5);
	tc_special(50, 5);
	tc_special(50, 5);
	tc_special(50, 1);
	tc_special(50, 10);
	tc_special(50, 15);
	tc_special(50, 20);
	tc_special(50, 30);
}
