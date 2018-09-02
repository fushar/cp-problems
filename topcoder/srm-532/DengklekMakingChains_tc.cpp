/* by Ashar Fuadi [fushar] */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define REPE(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define RESET(c,v) memset(c, v, sizeof(c))

typedef long long ll;

#define pb push_back
#define mp make_pair

void print(vector<string> v)
{
	int n = v.size();
	cout << "{";
	REP(i, n)
	{
		if (i) cout << ", ";
		cout << "\"" + v[i] + "\"";
	}
	cout << "}" << endl;
}

void custom_cases()
{
	vector<string> v;
	
	v = vector<string>(50);
	REP(i, 50) v[i] = "...";
	print(v);
	
	REP(i, 50) v[i] = "000";
	print(v);
	
	REP(i, 50) v[i] = "999";
	print(v);
	
	REP(i, 50) v[i] = "1.1";
	print(v);
}

int main()
{
	srand(time(NULL));
	custom_cases();
	REP(T, 46)
	{
		int n = rand() % 50 + 1;
		vector<string> v(n);
		REP(i, n) REP(j, 3)
		{
			if (rand() % 2)
				v[i] += ".";
			else
			{
				char c = '0' + (rand() % 10);
				v[i] += c;
			}
		}
		print(v);
	}
}
