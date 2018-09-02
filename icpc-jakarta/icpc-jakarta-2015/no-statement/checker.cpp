// MODIFY IT ACCORDING TO PC^2 SPEC


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

ifstream fin, fout, fcontestant;

int T;
int N, A, B;
int D[MAXN];

void wa() {
    printf("WA\n");
    exit(0);
}

void ac() {
    printf("AC\n");
    exit(0);
}

int valueOf(ifstream& f) {
    int k;
    if (! (f >> k)) {
        wa();
    }

    if (k < A || k > B) {
        wa();
    }

    int res = 1;
    int sign = 1;

    int lastIndex = 0;
    for (int i = 0; i < k; i++) {
        int d;
        if (! (f >> d)) {
            wa();
        }

        if (d <= lastIndex || d > N) {
            wa();
        }

        lastIndex = d;

        if (D[d] == 0) {
            return 0;
        } else if (D[d] > 0) {
            res += D[d]-1;
        } else {
            res += abs(D[d])-1;
            sign *= -1;
        }
    }

    return sign * res;
}

int main(int argc, char* argv[]) {
    fin.open(argv[1]);
    fout.open(argv[2]);
    fcontestant.open(argv[3]);

    fin >> T;

    string caze, casenum;
    for (int tc = 1; tc <= T; tc++) {
        fin >> N >> A >> B;
        for (int i = 1; i <= N; i++) {
            fin >> D[i];
        }

        fout >> caze >> casenum;

        if (! (fcontestant >> caze >> casenum)) {
            wa();
        }

        // Note <=, not !=.
        if (valueOf(fout) <= valueOf(fcontestant)) {
            wa();
        }
    }

    ac();
}
