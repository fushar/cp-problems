#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdio>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;

typedef int ll;
int N, V;

int hash(string s, int b, int e)
{
	if (b == e)
		return s[b]-'0';
	int res = 0;
	for (int i = b; i <= e; i++)
		res += s[i]-'0';
	int m = (b+e)/2;
	res += max(hash(s, b, m), hash(s, m+1, e));
	return res;
}

int n[4];
vector<int> val[4][51];
int val2[4][1<<13];
int lho[4][51][203];

inline int max(int a, int b) {return a > b ? a : b;}

ll calc(int l, int r, int k, int vmin, int vmax)
{
	vmin -= k, vmax -= k;
	ll res = 0;
	
	// now max(hash(l), hash(r)) in [vmin..vmax]. how?
	
	// left > right
	REP(mask, 1<<n[l])
	{
		int kl = __builtin_popcount(mask);
		if (kl > k) continue;
		int kr = k - kl, v = val2[l][mask];
		
		ll cur;
		
		cur = lho[r][kr][vmax+1] - lho[r][kr][max(v+1, vmin)];
		res += max(cur, 0);
		if (v < vmin || v > vmax)
			continue;
		cur = lho[r][kr][v-1+1] - lho[r][kr][0];
		//upper_bound(val[r][kr].begin(), val[r][kr].end(), val2[l][mask]-1)-
			//	 lower_bound(val[r][kr].begin(), val[r][kr].end(), 0);
		res += max(cur, 0);
		cur = lho[r][kr][v+1] - lho[r][kr][v];
		res += max(cur, 0);
	}
	return res;
	/*
	// left < right
	REP(mask, 1<<n[l])
	{
		int kl = __builtin_popcount(mask);
		if (kl > k) continue;
		int kr = k - kl, v = val2[l][mask];
		
		//upper_bound(val[r][kr].begin(), val[r][kr].end(), vmax)-
			//	 lower_bound(val[r][kr].begin(), val[r][kr].end(), max(val2[l][mask]+1, vmin));
		res += max(cur, 0ll);
	}
	// left == right
	REP(mask, 1<<n[l])
	{
		int kl = __builtin_popcount(mask);
		if (kl > k) continue;
		int kr = k - kl, v = val2[l][mask];
		if (v < vmin || v > vmax)
			continue;
		
		//upper_bound(val[r][kr].begin(), val[r][kr].end(), val2[l][mask])-
			//	 lower_bound(val[r][kr].begin(), val[r][kr].end(), val2[l][mask]);
		res += max(cur, 0ll);
	}
	
	return res;*/
}

ll solve()
{
	int n01 = (N+1)/2, n23 = N - n01;
	n[0] = (n01+1)/2, n[1] = n01 - n[0];
	n[2] = (n23+1)/2, n[3] = n23 - n[2];
	REP(i, 4) REP(k, n[i]+1) val[i][k].clear();
	REP(i, 4)
	{
		if (!n[i]) continue;
		REP(mask, 1<<n[i])
		{
			int k = __builtin_popcount(mask);
			string s;
			REP(j, n[i])
				if (mask & (1<<j)) s = "1" + s;
				else s = "0" + s;
			int c = hash(s, 0, n[i]-1);	
			lho[i][k][c+1]++;
			val2[i][mask] = c;
		}
		REP(k, n[i]+1) REP(c, 100)
			lho[i][k][c+1] += lho[i][k][c];
		//REP(k, n[i]+1) REP(c, 8)
			//printf("lho[%d][%d][%d] = %d\n", i, k, c, lho[i][k][c]);
	}
	
	cout << "AAAAAAAAAA" << endl;
	
	ll res = 0;
	REP(k01, n01+1) REP(k23, n23+1)
	{
		if (V < k01 + k23)
			continue;
		int v = V - (k01+k23);
		// now max(hash(left), hash(right)) == v
		
		// left = v, right < v
		res += calc(0, 1, k01, v, v) * calc(2, 3, k23, 0, v-1);
		
		// left < v, right = v
		res += calc(0, 1, k01, 0, v-1) * calc(2, 3, k23, v, v);
		
		// left = v, right = v
		res += calc(0, 1, k01, v, v) * calc(2, 3, k23, v, v);
		
		
	}
	return res;
}

ll zzz[100];

ll bf()
{
	ll res = 0;
	REP(k, 1<<N)
	{
		string s;
		REP(i, N)
			if (k & (1<<i)) s = "1" + s;
			else s = "0" + s;
		
		if (hash(s, 0, N-1) == V) res++;
		//zz[hash(s, 0, N-1)]++;
	}
	return res;
	REP(k, 3*N) if (zzz[k])
	{
		V = k;
		cout << zzz[k] << " " << solve() << endl;
	}
	return res;
}

int main()
{
	cin >> N >> V;
	//cout << bf() << endl;
	cout << solve() << endl;
}
