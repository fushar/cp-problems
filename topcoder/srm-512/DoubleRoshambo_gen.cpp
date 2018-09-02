#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string gest[] = {"RR", "RP", "RS", "PR", "PP", "PS", "SR", "SP", "SS"};
string win2[] = {"SS", "SR", "SP", "RS", "RR", "RP", "PS", "PR", "PP"};
string win1[] = {"RS", "RR", "RP", "PS", "PR", "PP", "SS", "SR", "SP"};

string A[50], E[50];
	
void print(int N, string S[50])
{
	printf("{");
	for (int i = 0; i < N; i++)
	{
		if (i) printf(", ");
		printf("\"%s\"", S[i].c_str());
	}
	printf("}\n");
}

void print(int N, string A[50], string E[50])
{
	print(N, A);
	print(N, E);
}

void randomize()
{
	int N = rand() % 50 + 1;
	for (int i = 0; i < N; i++)
	{
		A[i] = gest[rand() % 9];
		E[i] = gest[rand() % 9];
	}
	print(N, A, E);
}

int main()
{
	
	srand(time(NULL));	
	
	// smallest case
	print(1, new string[1]{"RS"}, new string[1]{"RS"});
	
	// smallest case
	print(1, new string[1]{"RR"}, new string[1]{"SS"});
	
	// smallest case
	print(1, new string[1]{"PR"}, new string[1]{"PS"});
	
	// beats greedy from left to right
	print(2, new string[2]{"RS", "PS"}, new string[2]{"RP", "PS"});
	
	// beats greedy from left to right
	print(2, new string[2]{"PS", "RS"}, new string[2]{"PS", "RP"});
	
	// all win 2
	print(9, gest, win2);
	
	// result = 3
	print(3, new string[3]{"RR", "PP", "SS"}, new string[3]{"RS", "PR", "SP"});
	
	// result = 6
	print(6, new string[6]{"RR", "RS", "RP", "SR", "SS", "SP"}, new string[6]{"RS", "RP", "RR", "SS", "SP", "SR"});

	// largest case, result = 100
	for (int i = 0; i < 50; i++)
		A[i] = "SS", E[i] = "PP";
	print(50, A, E);
	
	// largest case, result = 50
	for (int i = 0; i < 50; i++)
		A[i] = "SP", E[i] = "SR";
	print(50, A, E);
	
	for (int i = 0; i < 50; i++)
		randomize();
}
