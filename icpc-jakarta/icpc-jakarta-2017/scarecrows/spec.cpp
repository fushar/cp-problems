#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

#define REP(i,n) for (int i = 0, _n = n; i < _n; i++)

class ProblemSpec : public BaseProblemSpec {
protected:
    int R, C;
    vector<vector<char>> G;
    int res;

    void InputFormat() {
        LINE(R, C);
        GRID(G) % SIZE(R, C);
    }

    void OutputFormat() {
        LINE(res);
    }

    void Constraints() {
        CONS(1 <= R && R <= 16);
        CONS(1 <= C && C <= 1000);
        CONS(validGrid());
    }

private:
    bool validGrid() {
        REP(i, R) REP(j, C) {
            if (G[i][j] != '.' && G[i][j] != 'v') return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2 2",
            "v.",
            ".."
        });
        Output({
            "3"
        });
    }

    void SampleTestCase2() {
        Input({
            "1 3",
            "..."
        });
        Output({
            "5"
        });
    }

    void SampleTestCase3() {
        Input({
            "2 3",
            "vvv",
            "..."
        });
        Output({
            "0"
        });
    }

    void SampleTestCase4() {
        Input({
            "3 3",
            "...",
            ".v.",
            "..."
        });
        Output({
            "145"
        });
    }

    void BeforeTestCase() {
        G.clear();
    }

    void TestCases() {
        // Smallest cases
        CASE(R = C = 1, G = {{'.'}});
        CASE(R = C = 1, G = {{'v'}});

        // Impossible cases
        CASE(R = 1, C = 2, G = {{'v', 'v'}});
        CASE(R = 2, C = 1, G = {
            {'v'},
            {'v'}
        });

        // Unique cases
        CASE(R = C = 3, G = {
            {'.', 'v', 'v'},
            {'v', '.', 'v'},
            {'v', 'v', '.'}
        });
        CASE(R = C = 3, G = {
            {'v', 'v', '.'},
            {'v', '.', 'v'},
            {'.', 'v', 'v'}
        });

        // Largest cases
        CASE(R = 16, C = 1000, randomGrid("."));
        CASE(R = 16, C = 1000, randomGrid("v"));

        // Random cases
        CASE(R = 10, C = 100, randomGrid(".v"));
        CASE(R = 11, C = 100, randomGrid(".v"));
        CASE(R = 12, C = 100, randomGrid("..v"));
        CASE(R = 13, C = 100, randomGrid(".vv"));

        CASE(R = 16, C = 1000, randomGrid(".v"));
        CASE(R = 16, C = 1000, randomGrid("..v"));
        CASE(R = 16, C = 1000, randomGrid("...v"));
    }

private:
    void randomGrid(string pool) {
        int k = pool.size();
        REP(i, R) {
            vector<char> row;
            REP(j, C) {
                row.push_back(pool[rnd.nextInt(k)]);
            }
            G.push_back(row);
        }
    }
};
