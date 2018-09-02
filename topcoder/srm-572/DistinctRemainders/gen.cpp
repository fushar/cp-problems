#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define REPE(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define RESET(c,v) memset(c, v, sizeof(c))

long long randll()
{
	long long a = rand();
	long long b = rand();
	return (a << 32LL) + b;
}

void random_case(long long N, int K)
{
	cout << randll() % N + 1 << endl;
	cout << rand() % K + 1 << endl;
}

void largest_case()
{
	long long N = 1000000000000000000LL;
	int K = 50;
	cout << N << endl;
	cout << K << endl;
}

void smallest_case()
{
	long long N = 1LL;
	int K = 1;
	cout << N << endl;
	cout << K << endl;
}

void maybe_tricky_cases()
{
	cout << 14 << endl << 7 << endl;
	cout << 7 << endl << 14 << endl;
	cout << 15 << endl << 15 << endl;
	cout << 97 << endl << 23 << endl;
	cout << 23 << endl << 97 << endl;
	cout << 1 << endl << 20 << endl;
	cout << 1 << endl << 50 << endl;
}

int main()
{
	srand(time(NULL));
	
	smallest_case();
	largest_case();
	maybe_tricky_cases();
	
	REP(x, 2)
	{
		random_case(10LL, 10);
		random_case(100LL, 20);
		random_case(1000LL, 30);
		random_case(10000LL, 30);
		random_case(100000LL, 40);
		random_case(1000000LL, 50);
		random_case(10000000LL, 40);
		random_case(100000000LL, 30);
		random_case(1000000000LL, 10);
		random_case(10000000000LL, 40);
		random_case(100000000000LL, 30);
		random_case(1000000000000LL, 20);
		random_case(10000000000000LL, 10);
		random_case(100000000000000LL, 5);
		random_case(1000000000000000LL, 50);
		random_case(10000000000000000LL, 40);
		random_case(100000000000000000LL, 50);
		random_case(1000000000000000000LL, 50);
	}

	REP(x, 50)
		random_case(1000000000000000000LL, 50);
}
