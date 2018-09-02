#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define REPE(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define RESET(c,v) memset(c, v, sizeof(c))

void printv(vector<int> v)
{
	printf("{");
	REP(i, v.size())
	{
		if (i) printf(", ");
		printf("%d", v[i]);
	}
	printf("}\n");
}

void gen_case(int N, int K)
{
	vector<int> S(N), H(N), T(N);
	REP(i, N)
		S[i] = rand() % 1000000001;
	
	REP(i, N)
		H[i] = rand() % 1000000001;
	
	vector<int> pool(N);
	REP(i, N)
		pool[i] = i;
	
	REP(i, N)
	{
		int id = rand() % (N-i);
		T[i] = pool[id];
		pool.erase(pool.begin() + id);
	}
	
	printv(S);
	printv(H);
	printv(T);
	printf("%d\n", K);
}

void largest_case()
{
	int N = 50, K = 50;
	vector<int> S(N), H(N), T(N);
	REP(i, N)
		S[i] = H[i] = 1000000000;
	
	REP(i, N)
		if (i % 2)
			T[i] = i-1;
		else
			T[i] = i+1;
	printv(S);
	printv(H);
	printv(T);
	printf("%d\n", K);
}

void custom_case1()
{
	int N = 50, K = 50;
	vector<int> S(N), H(N), T(N);
	REP(i, N)
		S[i] = (1<<16) - 1;
	REP(i, N)
		H[i] = (1<<29) - 1 - S[0];
	REP(i, N)
		T[i] = (i+1) % N;
	printv(S);
	printv(H);
	printv(T);
	printf("%d\n", K);
}

void custom_case2()
{
	int N = 50, K = 36;
	vector<int> S(N), H(N), T(N);
	REP(i, N)
		S[i] = rand() % 1000000001;
	
	REP(i, N)
		H[i] = rand() % 1000000001;
	
	vector<int> pool(N);
	REP(i, N)
		pool[i] = i;
	
	REP(i, N)
		if (i == 24)
			T[i] = 0;
		else if (i < 24)
			T[i] = i+1;
		else if (i == 49)
			T[i] = 25;
		else
			T[i] = i+1;
	
	printv(S);
	printv(H);
	printv(T);
	printf("%d\n", K);
}

void custom_case4()
{
	int N = 50, K = 50;
	vector<int> S(N), H(N), T(N);
	REP(i, N)
		S[i] = rand() % 1000000001;
	
	REP(i, N)
		H[i] = rand() % 1000000001;
	
	vector<int> pool(N);
	REP(i, N)
		pool[i] = i;
	
	REP(i, N)
		if (i % 5 == 4)
			T[i] = i-4;
		else
			T[i] = i+1;
	
	printv(S);
	printv(H);
	printv(T);
	printf("%d\n", K);
}

void custom_case5()
{
	int N = 50, K = 47;
	vector<int> S(N), H(N), T(N);
	REP(i, N)
		S[i] = rand() % 1000000001;
	
	REP(i, N)
		H[i] = rand() % 1000000001;
	
	REP(i, N)
		T[i] = i;
	
	int part[] = {0, 2, 5, 10, 17, 28, 41, 50};
	
	REP(k, 8-1)
	{
		T[part[k]] = part[k+1]-1;
		for (int i = part[k]+1; i < part[k+1]; i++)
			T[i] = i-1;
	}
	
	printv(S);
	printv(H);
	printv(T);
	printf("%d\n", K);
}

void custom_case6(int N, int K)
{
	vector<int> S(N), H(N), T(N);
	REP(i, N)
		S[i] = rand() % 2;
	
	REP(i, N)
		H[i] = rand() % 2;
			
	
	vector<int> pool(N);
	REP(i, N)
		pool[i] = i;
	
	REP(i, N)
	{
		int id = rand() % (N-i);
		T[i] = pool[id];
		pool.erase(pool.begin() + id);
	}
	
	
	printv(S);
	printv(H);
	printv(T);
	printf("%d\n", K);
}

int main()
{
	srand(time(NULL));
	
	/*
	gen_case(1, 1);
	gen_case(1, 5);
	gen_case(1, 50);
	gen_case(5, 7);
	gen_case(5, 50);
	gen_case(5, 18);
	gen_case(10, 1);
	gen_case(13, 8);
	gen_case(13, 50);
	gen_case(20, 6);
	gen_case(25, 1);
	gen_case(30, 7);
	gen_case(30, 38);
	gen_case(30, 20);
	gen_case(50, 1);
	gen_case(50, 5);
	gen_case(50, 28);
	gen_case(50, 50);*/
	
	custom_case6(10, 50);
	custom_case6(30, 50);
	custom_case6(40, 50);
	custom_case6(50, 50);
	custom_case6(50, 50);
}
