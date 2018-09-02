#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

void print(int S[], int N)
{
	ostringstream sout;
	for (int i = 0; i < N; i++)
	{
		sout << S[i];
		if (i != N-1)
			sout << " ";
	}
	
	string s = sout.str();
	
	printf("{");
	bool any = false;
	int L = s.size();
	int pos = 0;
	while (pos < L)
	{
		if (any) printf(", ");
		any = true;
		
		int M = min(L-pos, 50);
		cout << "\"" << s.substr(pos, M) << "\"";
		pos += M;
	}
	printf("}\n");
}

void smallest_case()
{
	int S[] = {1};
	print(S, 1);
}

void largest_case()
{
	int S[200];
	for (int i = 0; i < 200; i++)
		S[i] = 1000000000;
	print(S, 200);
}

bool comp[1000005];

void manual_case()
{
	int S[200];
	
	for (int i = 0; i < 200; i++)
		S[i] = i+1;
	print(S, 200);
	
	for (int i = 0; i < 200; i++)
		S[i] = 1;
	print(S, 200);
	
	for (int i = 0; i < 30; i++)
		S[i] = 1<<i;
	print(S, 30);
	
	S[0] = S[1] = 1;
	for (int i = 2; i <= 43; i++)
		S[i] = S[i-1] + S[i-2];
	print(S, 44);
	
	for (int i = 2; i*i <= 1000000; i++) if (!comp[i])
		for (int j = i*i; j <= 1000000; j += i)
			comp[j] = true;
	
	int p = 1000000;
	for (int i = 200-1; i >= 0; i--)
	{
		while (comp[p]) p--;
		S[i] = p;
	}
	print(S, 200);
	
	for (int i = 0; i < 200; i++)
		S[i] = 1000000000 - i;
	print(S, 200);
}

void random_case()
{
	int N = rand() % 200 + 1;
	int S[200];
	for (int i = 0; i < N; i++)
		S[i] = rand() % 1000000000 + 1;
	print(S, N);
}

int main()
{
	srand(time(NULL));
	smallest_case();
	largest_case();
	manual_case();
	
	for (int i = 0; i < 42; i++)
		random_case();
}
