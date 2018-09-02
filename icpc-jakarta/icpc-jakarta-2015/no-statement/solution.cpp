#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int T;

int N, A, B;

// negative integers
int nX;
pair<int, int> X[MAXN];
int prefixSumX[MAXN], suffixSumX[MAXN];

// nonnegative integers
int nY, nYPositiveOnly;
pair<int, int> Y[MAXN];
int prefixSumY[MAXN], suffixSumY[MAXN];
bool isPrefixSumY0[MAXN], isSuffixSumY0[MAXN];

typedef tuple<int, int, int> result_t;

result_t odd_negatives() {
    // we want pick an odd number of negative integers
    // so, the result will be nonpositive
    // so, we want to minimize the product of the nonnegative integers.

    result_t res = make_tuple(-1000000000, 0, 0);

    for (int cntX = 1; cntX <= nX && cntX <= A; cntX += 2) {
        int cntY = min(nY, A - cntX);

        if (cntX + cntY < A) {
            continue;
        }

        int sumX = prefixSumX[cntX];
        int sumY = prefixSumY[cntY];

        int logg = isPrefixSumY0[cntY] ? 0 : -(1 + sumX + sumY);
        res = max(res, make_tuple(logg, cntX, cntY));
    }

    return res;
}

result_t even_negatives() {
    // we want pick an even number of negative integers
    // so, the result will be non-negative
    // so, we want to maximize the product of the non-negative integers.

    result_t res = make_tuple(-1000000000, 0, 0);

    for (int cntX = 0; cntX <= nX && cntX <= B; cntX += 2) {
        int cntY = min(nYPositiveOnly, B - cntX);

        if (cntX + cntY < A) {
            cntY = min(nY, B - cntX);
        }

        if (cntX + cntY < A) {
            continue;
        }

        int sumX = suffixSumX[cntX];
        int sumY = suffixSumY[cntY];

        int logg = isSuffixSumY0[cntY] ? 0 : 1 + sumX + sumY;
        res = max(res, make_tuple(logg, cntX, cntY));
    }

    return res;
}

vector<int> solve() {
    // sort and compute prefix and suffix sums

    sort(X+1, X+nX+1);
    sort(Y+1, Y+nY+1);

    for (int i = 1; i <= nX; i++) {
        prefixSumX[i] = prefixSumX[i-1] + X[i].first;
        suffixSumX[i] = suffixSumX[i-1] + X[nX-i+1].first;
    }

    for (int i = 1; i <= nY; i++) {
        prefixSumY[i] = prefixSumY[i-1] + Y[i].first;
        suffixSumY[i] = suffixSumY[i-1] + Y[nY-i+1].first;
        isPrefixSumY0[i] = (Y[i].first == 0) || isPrefixSumY0[i-1];
        isSuffixSumY0[i] = (Y[nY-i+1].first == 0) || isSuffixSumY0[i-1];
    }

    result_t result_for_odd = odd_negatives();
    result_t result_for_even = even_negatives();

    vector<int> res;
    if (result_for_odd > result_for_even) {
        for (int i = 1; i <= get<1>(result_for_odd); i++) {
            res.push_back(X[i].second);
        }
        for (int i = 1; i <= get<2>(result_for_odd); i++) {
            res.push_back(Y[i].second);
        }
    } else {
        for (int i = 1; i <= get<1>(result_for_even); i++) {
            res.push_back(X[nX-i+1].second);
        }
        for (int i = 1; i <= get<2>(result_for_even); i++) {
            res.push_back(Y[nY-i+1].second);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> A >> B;

        nX = nY = nYPositiveOnly = 0;

        for (int i = 1; i <= N; i++) {
            int d;
            cin >> d;
            if (d < 0) {
                X[++nX] = make_pair(abs(d)-1, i);
            } else {
                Y[++nY] = make_pair(d-1, i);

                if (d > 0) {
                    nYPositiveOnly++;
                }
            }
        }

        vector<int> res = solve();

        cout << "Case #" << tc << ":" << endl;
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " \n"[i == res.size()-1];
        }
    }
}
