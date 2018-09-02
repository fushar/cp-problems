#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)

void print(vector<string> v)
{
	printf("{");
	REP(i, v.size())
	{
		if (i) printf(", ");
		printf("\"");
		REP(j, v[i].size())
			printf("%c", v[i][j]);
		printf("\"");
	}
	printf("}\n");
}

void gen_case(int X, int N, int M)
{
	vector<bool> is_chosen(M);
	vector<int> wow(M);
	REP(i, M)
		wow[i] = i;
	
	REP(i, X)
	{
		int id = rand() % wow.size();
		is_chosen[wow[id]] = true;
		wow.erase(wow.begin() + id);
	}
	
	vector<string> res(N);
	
	REP(j, M)
	{
		if (is_chosen[j])
		{
			vector<char> pool(10);
			REP(i, 10)
				pool[i] = '0' + i;
			
			int Y = rand() % 9 + 1;
			vector<char> lho(Y);
			REP(i, Y)
			{
				int id = rand() % pool.size();
				lho[i] = pool[id];
				pool.erase(pool.begin() + id);
			}
			
			REP(i, N)
				res[i] += lho[rand() % Y];
		}
		else
		{
			char c = rand() % 10 + '0';
			REP(i, N)
				res[i] += c;
		}
	}
	
	print(res);
}

void gen_case2(int N, int M, bool zzz)
{
	vector<bool> is_col(M);
	vector<bool> is_row(M);
	vector<int> wow(M);
	REP(i, M)
		wow[i] = i;
	
	REP(i, 2)
	{
		int id = rand() % wow.size();
		is_col[wow[id]] = true;
		wow.erase(wow.begin() + id);
	}
	is_row[rand() % N] = true;
	
	vector<string> res(N);
	
	REP(j, M)
	{
		
		char c = rand() % 10 + '0';
		REP(i, N)
		{
			if (is_row[i] && is_col[j])
				res[i] += (rand() % 10 + '0');
			else
				res[i] += c;
		}
	}
	
	if (zzz)
		res[rand()%N][rand()%M] = (rand() % 10 + '0');
	
	print(res);
}

int main()
{
	srand(time(NULL));
	
	gen_case(0, 50, 50);
	REP(i, 10)
	{
		int N = rand() % 50 + 1;
		int M = rand() % 50 + 1;
		
		gen_case(0, N, M);
	}
	
	gen_case(1, 50, 50);
	REP(i, 10)
	{
		int N = rand() % 50 + 1;
		int M = rand() % 49 + 2;
		gen_case(1, N, M);
	}
	
	gen_case2(50, 50, false);
	REP(i, 8)
	{
		int N = rand() % 50 + 1;
		int M = rand() % 49 + 2;
		gen_case2(N, M, false);
	}
	REP(i, 2)
	{
		int N = rand() % 50 + 1;
		int M = rand() % 49 + 2;
		gen_case2(N, M, true);
	}
	
	gen_case(3, 50, 50);
	REP(i, 4)
	{
		int N = rand() % 50 + 1;
		int X = rand() % 49 + 2;
		int M;
		if (X == 50)
			M = 50;
		else
			M = rand() % (51-X) + X;
		gen_case(X , N, M);
	}
}
