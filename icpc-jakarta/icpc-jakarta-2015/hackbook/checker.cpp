// MODIFY IT ACCORDING TO PC^2 SPEC


#include <bits/stdc++.h>
using namespace std;

ifstream fout, fcontestant;

int T;
string res, ans;

void wa() {
    printf("WA\n");
    exit(0);
}

void ac() {
    printf("AC\n");
    exit(0);
}

bool is_anagram(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool is_valid(string s) {
    int i = 0;
    int n = s.size();
    while (i < n) {
        if (is_vowel(s[i])) {
            return false;
        }

        i++;
        if (i >= n || !is_vowel(s[i])) {
            return false;
        }

        i++;
        if (i < n && !is_vowel(s[i]) && (i+1 == n || (i+1 < n && !is_vowel(s[i+1])))) {
            i++;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    fout.open(argv[1]);
    fcontestant.open(argv[2]);

    string caze, casenum, ans;
    while (fout >> caze >> casenum >> ans) {
        string caze2, casenum2;
        if (!(fcontestant >> caze2 >> casenum2 >> res)) {
            wa();
        }

        if (caze != caze2 || casenum != casenum2) {
            wa();
        }

        if (ans == "IMPOSSIBLE") {
            if (res != ans) {
                wa();
            } else {
                continue;
            }
        }

        if (!is_anagram(ans, res)) {
            wa();
        }

        if (!is_valid(res)) {
            wa();
        }
    }

    ac();
}
