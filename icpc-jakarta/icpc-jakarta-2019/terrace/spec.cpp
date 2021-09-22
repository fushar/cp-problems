#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

#define REP(i,n) for (int i = 0, _n = n; i < _n; i++)

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, K, G1, G2, G3;
    string S;

    int res;

    void InputFormat() {
        LINE(N, K, G1, G2, G3);
        LINE(S);
    }

    void OutputFormat() {
        LINE(res);
    }

    void Constraints() {
        CONS(1 <= N && N <= 100000);
        CONS(0 <= K && K <= N);
        CONS(0 <= G1 && G1 <= 1000);
        CONS(0 <= G2 && G2 <= 1000);
        CONS(0 <= G3 && G3 <= 1000);
        CONS(validString());
    }

private:
    bool validString() {
        if (S.size() != N) {
            return false;
        }
        for (char c : S) {
            if (c != '.' && c != '#') {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "6 4 10 25 40",
            "..#..."
        });
        Output({
            "75"
        });
    }

    void SampleTestCase2() {
        Input({
            "6 4 10 100 40",
            "..#..."
        });
        Output({
            "210"
        });
    }

    void SampleTestCase3() {
        Input({
            "7 2 30 10 100",
            "..#...#"
        });
        Output({
            "160"
        });
    }

    void TestCases() {
        // no tiles
        CASE(N = 1, K = 0, G1 = 1, G2 = 4, G3 = 7, S = ".");
        CASE(N = 1, K = 1, G1 = 1, G2 = 4, G3 = 7, S = "#");

        // A##A
        CASE(N = 4, K = 4, G1 = 1, G2 = 4, G3 = 7, S = ".##.");

        // A
        CASE(N = 1, K = 1, G1 = 1, G2 = 4, G3 = 7, S = ".");

        // A.
        CASE(N = 2, K = 1, G1 = 5, G2 = 4, G3 = 7, S = "..");

        // AA
        CASE(N = 2, K = 2, G1 = 3, G2 = 4, G3 = 7, S = "..");

        // BB
        CASE(N = 2, K = 2, G1 = 1, G2 = 4, G3 = 7, S = "..");

        // A#A#.
        CASE(N = 5, K = 2, G1 = 3, G2 = 9, G3 = 2, S = ".#.#.");

        // CCC#A
        CASE(N = 5, K = 2, G1 = 3, G2 = 9, G3 = 7, S = ".#.#.");

        // CCCACCC
        CASE(N = 7, K = 2, G1 = 3, G2 = 1, G3 = 7, S = ".#...#.");

        // .#BBCCC
        CASE(N = 7, K = 0, G1 = 3, G2 = 9, G3 = 7, S = ".#...#.");

        // A#AAA#.
        CASE(N = 7, K = 4, G1 = 3, G2 = 1, G3 = 2, S = ".#...#.");

        // CCCBBCCC
        CASE(N = 8, K = 0, G1 = 3, G2 = 2, G3 = 9, S = ".#....#.");

        // .#BBBB#.
        CASE(N = 8, K = 0, G1 = 3, G2 = 9, G3 = 2, S = ".#....#.");

        // A#AAAA#.
        CASE(N = 8, K = 5, G1 = 100, G2 = 9, G3 = 2, S = ".#....#.");

        // A#AABB#A
        CASE(N = 8, K = 5, G1 = 100, G2 = 101, G3 = 2, S = ".#....#.");

        // G1*2 < G2
        CASE(N = 1000, K = 20, randomString(N, 10), G1 = 123, G2 = 456, G3 = 789);

        int g[] = {234, 456, 789};
        do {
            CASE(N = 1000, K = 345, randomString(N, 50), G1 = g[0], G2 = g[1], G3 = g[2]);
        } while (next_permutation(g, g+3));


        CASE(N = 100000, K = 10, randomString(N, 50), G1 = 234, G2 = 456, G3 = 345);
        CASE(N = 100000, K = 55, randomString(N, 50), G1 = 234, G2 = 456, G3 = 345);
        CASE(N = 100000, K = 5, randomString(N, 50), G1 = 456, G2 = 234, G3 = 123);
        CASE(N = 100000, K = 15, randomString(N, 50), G1 = 456, G2 = 234, G3 = 789);
    }

private:
    void randomString(int n, int m) {
        S = "";
        REP(i, m) S += "#";
        REP(i, n-m) S += ".";
        rnd.shuffle(S.begin(), S.end());
    }
};
