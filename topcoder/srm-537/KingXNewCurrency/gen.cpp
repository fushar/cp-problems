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

void custom_case(int A, int B, int X)
{
	printf("%d\n%d\n%d\n", A, B, X);
}

void random_case()
{
	int A = rand() % 200 + 1;
	int B = rand() % 200 + 1;
	int X = rand() % 200 + 1;
	if (A == B) return;
	printf("%d\n%d\n%d\n", A, B, X);
}

int main()
{
	srand(time(NULL));

	REP(i, 20)
		random_case();
}
