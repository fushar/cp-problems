#include <iostream>
using namespace std;

int N;
int Ma, Mb, Mc;
int Sa, Sb, Sc;
string G[2];

// dp[i][a][p][q] =
//   max number of B's, given columns [i..N), and we've already placed a A's,
//   and the previous column is <i, j> (0 = not placing anything, 1 = A, 2 = B)
int dp[1001][1001][3][3];

int main() {
    cin >> N;
    cin >> Ma >> Mb >> Mc;
    cin >> Sa >> Sb >> Sc;
    cin >> G[0] >> G[1];

    int cntEmpty = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < N; i++) {
            cntEmpty += (G[j][i] == '.');
        }
    }

    for (int i = N-1; i >= 0; i--) {
        for (int a = 0; a <= Ma; a++) {
            for (int p = 0; p < 3; p++) {
                for (int q = 0; q < 3; q++) {
                    for (int p2 = 0; p2 < 3; p2++) {
                        for (int q2 = 0; q2 < 3; q2++) {
                            if (G[0][i] == '#' && p2) continue;
                            if (G[1][i] == '#' && q2) continue;

                            // Forbidden:
                            //   A
                            //   A
                            if (p2 == 1 && q2 == 1) continue;

                            // Forbidden:
                            //  AA
                            if (p == 1 && p2 == 1) continue;
                            if (q == 1 && q2 == 1) continue;

                            // Forbidden:
                            //  B
                            //   B
                            if (p == 2 && q2 == 2) continue;

                            // Forbidden:
                            //   B
                            //  B
                            if (q == 2 && p2 == 2) continue;

                            int cntA = (p2 == 1) + (q2 == 1);
                            int cntB = (p2 == 2) + (q2 == 2);

                            if (a + cntA > Ma) continue;

                            dp[i][a][p][q] = max(dp[i][a][p][q], cntB + dp[i+1][a+cntA][p2][q2]);
                        }
                    }
                }
            }
        }
    }

    int res = 0;
    for (int a = 0; a <= Ma; a++) {
        int cntA = a;
        int cntB = min(Mb, dp[0][a][0][0]);
        int cntC = min(Mc, cntEmpty - cntA - cntB);

        int scoreA = Sa, scoreB = Sb;

        if (scoreB < scoreA) {
            swap(scoreB, scoreA);
            swap(cntB, cntA);
        }

        while (Sc > scoreA && cntC < Mc && cntA) {
            cntA--;
            cntC++;
        }
        
        while (Sc > scoreB && cntC < Mc && cntB) {
            cntB--;
            cntC++;
        }

        res = max(res, cntC*Sc + cntA*scoreA + cntB*scoreB);
    }

    cout << res << endl;
}
