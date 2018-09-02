/*
 *  Scarecrows, INC/ICPC Jakarta 2017
 * Ashar Fuadi
 * Time complexity: O(2^R . R . C)
*/

#include <bits/stdc++.h>

#define REP(i,n) for (int i = 0, _n = n; i < _n; i++)
#define RESET(c,v) memset(c, v, sizeof c)

using namespace std;

/***********************************************************/

const int MOD = 1000000007;
using ll = long long;

int R, C;
char G[15][1005];

int dp[2][15][1<<14][2][2];

void add(int& a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    scanf("%d %d", &R, &C);
    REP(i, R) scanf("%s", G[i]);

    dp[0][0][0][1][0] = 1;
    REP(cc, C) {
        int c = cc&1, nc = 1-c;
        REP(r, R+1) REP(mask, 1<<R) REP(prev, 2) REP(cur, 2) dp[nc][r][mask][prev][cur] = 0;
        REP(r, R) REP(mask, 1<<R) REP(prev, 2) REP(cur, 2) {
            add(dp[c][r+1][mask][prev][cur], dp[c][r][mask][prev][cur]);
            if (G[r][cc] == '.') {
                add(dp[c][r+1][mask|(1<<r)][prev][1], dp[c][r][mask][prev][cur]);
            }
        }
        REP(mask, 1<<R) REP(prev, 2) REP(cur, 2) {
            if (prev || cur) {
                add(dp[nc][0][mask][cur][0], dp[c][R][mask][prev][cur]);
            }
        }
    }
    int res = 0;
    add(res, dp[C&1][0][(1<<R)-1][0][0]);
    add(res, dp[C&1][0][(1<<R)-1][1][0]);

    printf("%d\n", res);
}
