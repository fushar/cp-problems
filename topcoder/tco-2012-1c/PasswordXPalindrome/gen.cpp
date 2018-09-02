#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

void gen_valid(int N)
{
	vector<char> lho;
	for (char c = 'a'; c <= 'z'; c++)
		lho.push_back(c);
	
	vector<char> pool;
	for (int i = 0; i < (N+1)/2; i++)
	{
		int id = rand() % lho.size();
		pool.push_back(lho[id]);
		pool.push_back(lho[id]);
		lho.erase(lho.begin() + id);
	}
	
	printf("\"");
	for (int i = 0; i < N; i++)
	{
		int id = rand() % (N-i);
		printf("%c", pool[id]);
		pool.erase(pool.begin() + id);
	}
	printf("\"\n");
}

void gen_random()
{
	int N = rand() % 50 + 1;
	printf("\"");
	for (int i = 0; i < N; i++)
		printf("%c", rand() % 26 + 'a');
	printf("\"\n");
}

int main()
{
	srand(time(NULL));
	
	for (int i = 0; i < 20; i++)
		gen_valid(rand() % 50 + 1);
	for (int i = 0; i < 10; i++)
		gen_valid(50);
	for (int i = 0; i < 3; i++)
		gen_valid(49);
	
	for (int i = 0; i < 5; i++)
		gen_random();
}
