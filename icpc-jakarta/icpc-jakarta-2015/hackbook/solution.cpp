#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> S;

        queue<char> vs, cs;
        for (char c : S) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vs.push(c);
            } else {
                cs.push(c);
            }
        }

        cout << "Case #" << tc << ": ";

        if (vs.size() > cs.size() || vs.size() * 2 < cs.size()) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        while (!vs.empty()) {
            cout << cs.front();
            cs.pop();
            cout << vs.front();
            vs.pop();

            if (vs.size() * 2 < cs.size()) {
                cout << cs.front();
                cs.pop();
            }
        }

        cout << endl;
    }
}
