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

const char* vowels = "aeiou";
const char* consos = "bcdfghjklmnpqrstvwxyz";

void gen_case(int N, int V)
{
	vector<char> res;
	if (V == -1)
		V = rand() % (N+1);
	
	REP(i, V)
		res.push_back(vowels[rand() % 5]);
	
	REP(i, N-V)
		res.push_back(consos[rand() % 21]);
	
	REP(i, N)
	{
		int id = rand() % (N-i);
		printf("%c", res[id]);
		res.erase(res.begin() + id);
	}
	printf("\n");
}

int main()
{
	srand(time(NULL));
	REP(i, 8)
	{
		gen_case(8, i+1);
		gen_case(8, i+1);
		gen_case(8, i+1);
	}
	REP(i, 10)
		gen_case(rand() % 50, 2);
	
	REP(i, 10)
		gen_case(rand() % 50, -1);
}
