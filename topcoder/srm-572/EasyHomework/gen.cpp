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

void random_case(int P, int N, int Z)
{
	vector<int> numbers;
	REP(i, P)
		numbers.push_back(rand() % 1000000000 + 1);
	REP(i, N)
		numbers.push_back(-(rand() % 1000000000 + 1));
	REP(i, Z)
		numbers.push_back(0);

	REP(i, P+N+Z) if (i)
		swap(numbers[i], numbers[rand() % i]);
	printv(numbers);
}

void largest_cases()
{
	vector<int> numbers(50);
	REP(i, 50)
		numbers[i] = 0;
	printv(numbers);
	
	REP(i, 50)
		numbers[i] = 1000000000;
	printv(numbers);
	
	REP(i, 50)
		numbers[i] = -1000000000;
	printv(numbers);
}

void tricky_case()
{
	vector<int> numbers;
	numbers.push_back(1000000000);
	numbers.push_back(1000000000);
	numbers.push_back(1000000000);
	printv(numbers);
}

int main()
{
	srand(time(NULL));
	
	// largest_cases();
	// tricky_case();
	// random_case(1, 0, 0);
	// random_case(0, 1, 0);
	// random_case(0, 0, 1);
	// random_case(2, 0, 0);
	// random_case(0, 2, 0);
	// random_case(0, 0, 2);
	// random_case(1, 0, 0);
	// random_case(1, 1, 0);
	// random_case(1, 1, 1);
	// random_case(0, 1, 1);
	// random_case(1, 0, 1);
	random_case(50, 0, 0);
	random_case(0, 0, 50);
	random_case(0, 50, 0);
	random_case(25, 25, 0);
	random_case(25, 0, 25);
	random_case(0, 25, 25);
	random_case(10, 10, 0);
	random_case(11, 12, 0);
	random_case(12, 12, 0);
	random_case(20, 20, 0);
	random_case(13, 30, 0);
	random_case(5, 5, 40);
	random_case(1, 10, 0);
	random_case(1, 49, 0);
	random_case(49, 1, 0);
	random_case(3, 10, 0);
}
