#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
using namespace std;

void print(int S[], int N)
{
	printf("{");
	for (int i = 0; i < N; i++)
	{
		if (i) printf(", ");
		printf("%d", S[i]);
	}
	printf("}\n");
}

void smallest_case()
{
	int S[] = {1, 2};
	print(S, 2);
}

void largest_case()
{
	int S[50];
	for (int i = 0; i < 50; i++)
		S[i] = 100000000-i;
	print(S, 50);
}

bool comp[1000005];

void manual_case()
{
	int S[50];
	
	for (int i = 0; i < 50; i++)
		S[i] = i+1;
	print(S, 50);
	
	for (int i = 0; i < 27; i++)
		S[i] = 1<<i;
	print(S, 27);
	
	S[0] = 1, S[1] = 2;
	for (int i = 2; i < 38; i++)
		S[i] = S[i-1] + S[i-2];
	print(S, 38);
	
	for (int i = 2; i*i <= 1000000; i++) if (!comp[i])
		for (int j = i*i; j <= 1000000; j += i)
			comp[j] = true;
	
	int p = 1000000;
	for (int i = 50-1; i >= 0; i--)
	{
		while (comp[p]) p--;
		S[i] = p;
	}
	print(S, 50);
	
}

void random_case()
{
	int N = rand() % 49 + 2;
	int S[50];
	for (int i = 0; i < N; i++)
	{
		bool fail = true;
		while (fail)
		{
			fail = false;
			S[i] = rand() % 100000000 + 1;
			for (int j = 0; j < i; j++)
				if (S[i] == S[j])
					fail = true;
		}
	}
	print(S, N);
}

void cool_case(int a1, int b1, int a2, int b2)
{
	set<int> lho;
	lho.insert(a1);
	lho.insert(b1);
	lho.insert(a2);
	lho.insert(b2);
	
	while (true)
	{
		int x = a1+b1;
		if (x > 100000000) break;
		lho.insert(x);
		a1 = b1;
		b1 = x;
		
	}
	while (true)
	{
		int x = a2+b2;
		if (x > 100000000) break;
		lho.insert(x);
		a2 = b2;
		b2 = x;
	}
	
	int X = min(50, (int)lho.size());
	int Y = 0;
	if (X > 20)
		Y = rand() % 6;
	
	int S[50];
	vector<int> wow(lho.begin(), lho.end());
	for (int i = 0; i < X-Y; i++)
	{
		int id = rand() % wow.size();
		S[i] = wow[id];
		wow.erase(wow.begin() + id);
	}
	
	for (int i = X-Y; i < X; i++)
	{
		bool fail = true;
		while (fail)
		{
			fail = false;
			S[i] = rand() % 100000000 + 1;
			for (int j = 0; j < i; j++)
				if (S[i] == S[j])
					fail = true;
		}
	}
	print(S, X);
}

int main()
{
	srand(time(NULL));
	smallest_case();
	largest_case();
	manual_case();
	
	for (int i = 0; i < 10; i++)
		random_case();
	
	for (int i = 0; i < 10; i++)
	{
		int W = 20;
		int a1 = rand() % W + 1;
		int b1 = rand() % W + 1;
		int a2 = rand() % W + 1;
		int b2 = rand() % W + 1;
		
		cool_case(a1, b1, a2, b2);
	}
	for (int i = 0; i < 10; i++)
	{
		int W = 1000;
		int a1 = rand() % W + 1;
		int b1 = rand() % W + 1;
		int a2 = rand() % W + 1;
		int b2 = rand() % W + 1;
		
		cool_case(a1, b1, a2, b2);
	}
}
