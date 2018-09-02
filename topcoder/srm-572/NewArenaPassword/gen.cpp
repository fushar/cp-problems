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

void print_tc(char oldPassword[], int N, int K)
{
	printf("\"");
	for (int i = 0; i < N; i++)
		printf("%c", oldPassword[i]);
	printf("\"\n");
	printf("%d\n", K);
}

void random_case()
{
	int N = rand() % 50 + 1;
	char S[N];
	for (int i = 0; i < N; i++)
		S[i] = 'a' + (rand() % 26);
	int K = rand() % N + 1;
	if (rand() % 2)
		K = max(1, N - (rand() % 5));
	print_tc(S, N, K);
}

void largest_case()
{
	int N = 50;
	char S[N];
	for (int i = 0; i < N; i++)
		S[i] = 'a' + (i % 26);
	int K = 25;
	print_tc(S, N, K);
}

void smallest_case()
{
	char S[] = {'a'};
	int K = 1;
	print_tc(S, 1, K);
}

void same_letters_case(int N, int K, int probDiff)
{
	char S[N];
	char c = 'a' + rand() % 26;
	for (int i = 0; i < N; i++)
		if (rand() % 100 < probDiff)
			S[i] = 'a' + rand() % 26;
		else
			S[i] = c;
	print_tc(S, N, K);
}

void diff_letters_case(int N, int K, int probDiff)
{
	char S[N];
	for (int i = 0; i < N; i++)
		if (rand() % 100 < probDiff)
			S[i] = 'a' + rand() % 26;
		else
			S[i] = 'a' + i % 26;
	for (int i = 1; i < N; i++)
		swap(S[i], S[rand() % i]);
	print_tc(S, N, K);
}

void tricky_cases()
{
	cout << "\"aa\"" << endl << 1 << endl;
	cout << "\"ab\"" << endl << 1 << endl;
	cout << "\"aa\"" << endl << 2 << endl;
	cout << "\"ab\"" << endl << 2 << endl;
	cout << "\"aba\"" << endl << 2 << endl;
	cout << "\"abab\"" << endl << 3 << endl;
	cout << "\"aabb\"" << endl << 4 << endl;
	cout << "\"aabb\"" << endl << 3 << endl;
	cout << "\"aacbbbcca\"" << endl << 3 << endl;
	cout << "\"aacbbbaaa\"" << endl << 3 << endl;
	cout << "\"aaabbbcaa\"" << endl << 3 << endl;
	cout << "\"aaabbbccc\"" << endl << 3 << endl;
}

int main()
{
	srand(time(NULL));
	
	smallest_case();
	largest_case();
	same_letters_case(10, 10, 0);
	same_letters_case(50, 20, 0);
	same_letters_case(50, 40, 0);
	same_letters_case(50, 49, 0);
	same_letters_case(50, 50, 0);
	same_letters_case(50, 40, 30);
	same_letters_case(50, 25, 40);
	same_letters_case(50, 26, 20);
	REP(x, 10)
	{
		int N = rand() % 50 + 1;
		int K = rand() % N + 1;
		same_letters_case(N, K, 75-x);
	}

	diff_letters_case(10, 10, 0);
	diff_letters_case(50, 20, 0);
	diff_letters_case(50, 40, 0);
	diff_letters_case(50, 49, 0);
	diff_letters_case(50, 50, 0);
	diff_letters_case(50, 40, 30);
	diff_letters_case(50, 25, 40);
	diff_letters_case(50, 26, 20);
	REP(x, 10)
	{
		int N = rand() % 50 + 1;
		int K = rand() % N + 1;
		diff_letters_case(N, K, 75-x);
	}

	tricky_cases();


	REP(x, 60)
		random_case();
}
