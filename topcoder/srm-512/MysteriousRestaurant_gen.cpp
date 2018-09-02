#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstdio>

using namespace std;

void print(int N, string prices[], int budget)
{
	cout << "{";
	for (int i = 0; i < N; i++)
	{
		if (i) cout << ", ";
		cout << "\"" << prices[i] << "\"";
	}
	cout << "}" << endl;
	cout << budget << endl;
}

string prices[50];

void randomize(int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		prices[i] = "";
		for (int j = 0; j < M; j++)
			prices[i] += " ";
		
		for (int j = 0; j < M; j++)
		{
			int p = rand() % 62;
			
			if (p < 10)
				prices[i][j] = '0' + p;
			else if (p < 36)
				prices[i][j] = 'A' + p-10;
			else
				prices[i][j] = 'a' + p-36;
		}
	}
	
	int budget = rand() % 10001;
	print(N, prices, budget);
}

int main()
{
	srand(time(NULL));
	
	// smallest case
	print(1, new string[1]{"0"}, 0);
	
	// smallest case
	for (int i = 0; i < 50; i++)
		prices[i] = "0";
	print(50, prices, 0);
	
	// smallest case
	prices[0] = "";
	for (int i = 0; i < 50; i++)
		prices[0] += "0";
	print(1, prices, 0);
	
	// smallest case
	for (int i = 0; i < 50; i++)
	{
		prices[i] = "";
		for (int j = 0; j < 50; j++)
			prices[i] += "0";
	}
	print(50, prices, 0);
	
	// -------------------------------
	
	// largest case
	print(1, new string[1]{"z"}, 10000);
	
	// largest case
	for (int i = 0; i < 50; i++)
		prices[i] = "z";
	print(50, prices, 10000);
	
	// largest case
	prices[0] = "";
	for (int i = 0; i < 50; i++)
		prices[0] += "z";
	print(1, prices, 10000);
	
	// largest case
	for (int i = 0; i < 50; i++)
	{
		prices[i] = "";
		for (int j = 0; j < 50; j++)
			prices[i] += "z";
	}
	print(50, prices, 10000);
	
	// beats simple wrong greedy
	for (int i = 0; i < 7; i++)
	{
		prices[i] = "97";
		prices[i+7] = "19";
	}
	print(14, prices, 15);
	
	// beats even simple wrong solution
	print(8, new string[8]{"49", "49", "49", "49", "49", "49", "49", "97"}, 35);

	// beat letter case error
	print(1, new string[1]{"abc"}, 11);
	
	// beat letter case error
	print(2, new string[2]{"ABC", "DEF"}, 37);
	
	// one-man show
	print(1, new string[1]{"X"}, 33);
	
	for (int i = 0; i < 20; i++)
		randomize(rand() % 50 + 1, rand() % 50 + 1);
		
}
