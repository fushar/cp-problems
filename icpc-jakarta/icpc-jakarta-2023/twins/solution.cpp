/*
 * Author's official solution.
 * Ashar Fuadi (fushar), 2023.
 */

#include <iostream>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

string A, B;

int cntA[27], cntB[27];
ll prefA[27];

ll fact[100005];
ll ifact[100005];

ll dp[27][100005];
ll dp_sum[27][100005];

ll mod_pow(ll n, ll p) {
    if (!p) {
        return 1;
    }
    if (p%2) {
        return n * mod_pow(n, p-1) % MOD;
    }
    ll x = mod_pow(n, p/2);
    return x*x % MOD;
}

ll comb(ll n, ll k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int main() {
    cin >> A;
    for (char c : A) {
        cntA[c-'A']++;
    }

    cin >> B;
    for (char c : B) {
        cntB[c-'A']++;
    }

    // Prefix sum of the letter counts in A (in decreasing order).
    for (int c = 25; c >= 0; c--) {
        prefA[c] = cntA[c] + prefA[c+1];
    }

    // i! (mod MOD)
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = i * fact[i-1] % MOD;
    }

    // (i!)^-1 (mod MOD)
    ifact[100000] = mod_pow(fact[100000], MOD-2);
    for (int i = 100000-1; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i+1) % MOD;
    }

    // dp[c][cnt_c_used]
    // = the number of ways, considering only letters [c..26),
    //   and cnt_c_used characters of letter c in B are already used
    //   (to match the previous letter (c-1) in A).

    // Base case.
    dp[26][0] = 1;

    // We process the letters in A alphabetically, in decreasing order.
    for (int c = 25; c >= 0; c--) {
        // We want to match the cntA[c] characters of the letter c, with cntA[c] characters from B.

        if (false) {
            // Quadratic solution.

            // cnt_c_used = how many of this letter already used for B.
            for (int cnt_c_used = 0; cnt_c_used <= cntB[c]; cnt_c_used++) {
                // If we use letter c for A, we can use letter c or (c+1) for B.
                // We brute-force how many characters of both letters to use.
                for (int cnt_c_to_use = 0; cnt_c_to_use <= cntA[c]; cnt_c_to_use++) {
                    // Here, we use cnt_c_to_use letter c, and cnt_c_plus_1_to_use letter (c+1),
                    // where cnt_c_to_use + cnt_c_plus_1_to_use = cntA[c].
                    int cnt_c_plus_1_to_use = cntA[c] - cnt_c_to_use;

                    // Make sure that we have enough characters of both letters in B.
                    if (cnt_c_used + cnt_c_to_use <= cntB[c] && cnt_c_plus_1_to_use <= cntB[c+1]) {
                        // Now, we count how many ways to permute the cnt[A] PAIRS of characters (in A and B).
                        ll ways = 1;

                        // The number of ways to choose the positions of the cntA[c] characters in A.
                        // Assuming we only used letters [c..26), there are prefA[c] positions.
                        ways = ways * comb(prefA[c], cntA[c]) % MOD;

                        // The number of ways to match
                        //   the (cnt_c_to_use characters of letter c) and (cnt_c_plus_1_to_use characters of letter c+1) in B,
                        //   with the corresponding characters of letter c in A.
                        ways = ways * comb(cntA[c], cnt_c_plus_1_to_use) % MOD;

                        // The DP transition; we go to the next letter.
                        ways = ways * dp[c+1][cnt_c_plus_1_to_use] % MOD;

                        // Add this result to the current state.
                        dp[c][cnt_c_used] = (dp[c][cnt_c_used] + ways) % MOD;
                    }
                }
            }
        } else {
            // Linear solution, using prefix sum for the DP.

            for (int cnt_c_plus_1_to_use = 0; cnt_c_plus_1_to_use <= cntB[c+1]; cnt_c_plus_1_to_use++) {
                ll cur = comb(cntA[c], cnt_c_plus_1_to_use) * dp[c+1][cnt_c_plus_1_to_use] % MOD;
                dp_sum[c+1][cnt_c_plus_1_to_use+1] = (dp_sum[c+1][cnt_c_plus_1_to_use] + cur) % MOD;
            }

            for (int cnt_c_used = 0; cnt_c_used <= cntB[c]; cnt_c_used++) {
                int min_cnt_c_plus_1_to_use = max(0, cntA[c] - (cntB[c]-cnt_c_used));
                int max_cnt_c_plus_1_to_use = min(cntA[c], cntB[c+1]);

                if (min_cnt_c_plus_1_to_use <= max_cnt_c_plus_1_to_use) {
                    ll sum_transition = (dp_sum[c+1][max_cnt_c_plus_1_to_use+1] - dp_sum[c+1][min_cnt_c_plus_1_to_use] + MOD) % MOD;
                    dp[c][cnt_c_used] = comb(prefA[c], cntA[c]) * sum_transition % MOD;
                }
            }
        }
    }

    cout << dp[0][0] << endl;
}
