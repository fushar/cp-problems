#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int MAXN = 1000;
    const int MAXM = 1000;
    const int MAXS = 100000;

    int N;
    int Ma, Mb, Mc;
    int Sa, Sb, Sc;
    vector<vector<char>> G;

    int res;

    void InputFormat() {
        LINE(N);
        LINE(Ma, Mb, Mc);
        LINE(Sa, Sb, Sc);
        GRID(G) % SIZE(2, N);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(0 <= Ma && Ma <= MAXM);
        CONS(0 <= Mb && Mb <= MAXM);
        CONS(0 <= Mc && Mc <= MAXM);
        CONS(1 <= Sa && Sa <= MAXS);
        CONS(1 <= Sb && Sb <= MAXS);
        CONS(1 <= Sc && Sc <= MAXS);
        CONS(validGrid());
    }

private:
    bool validGrid() {
        for (const vector<char>& r : G) {
            for (char c : r) {
                if (c != '.' && c != '#') {
                    return false;
                }
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
private:
    const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

protected:
    void SampleTestCase1() {
        Input({
            "7",
            "4 4 3",
            "10 30 20",
            "#.#..#.",
            ".#...#."
        });
        Output({
            "200"
        });
    }

    void SampleTestCase2() {
        Input({
            "7",
            "4 4 3",
            "40 20 30",
            "#.#..#.",
            ".#...#."
        });
        Output({
            "290"
        });
    }

    void SampleTestCase3() {
        Input({
            "2",
            "1 1 1",
            "10 10 10",
            "..",
            ".."
        });
        Output({
            "30"
        });
    }

    void BeforeTestCase() {
        G.clear();
    }

    void TestCases() {
        // ans: 0
        CASE(
            Ma = Mb = Mc = 1,
            Sa = 1, Sb = 1, Sc = 1,
            grid(
                "#",
                "#")
        );

        // ans: 0
        CASE(
            Ma = Mb = Mc = 0,
            Sa = 1, Sb = 1, Sc = 1,
            grid(
                ".",
                ".")
        );

        // A
        CASE(
            Ma = Mb = Mc = 1,
            Sa = 2, Sb = 1, Sc = 1,
            grid(
                ".",
                "#")
        );

        // B
        CASE(
            Ma = Mb = Mc = 1,
            Sa = 1, Sb = 3, Sc = 1,
            grid(
                ".",
                "#")
        );

        // C
        CASE(
            Ma = Mb = Mc = 1,
            Sa = 1, Sb = 1, Sc = 4,
            grid(
                ".",
                "#")
        );

        // BBBBBBBBBBB
        CASE(
            Ma = Mb = Mc = MAXM,
            Sa = 5, Sb = 20, Sc = 5,
            grid(
                "...........",
                "###########"
            )
        );

        // CCCCCCCCCCC
        CASE(
            Ma = Mb = Mc = MAXM,
            Sa = 5, Sb = 5, Sc = 30,
            grid(
                "...........",
                "###########"
            )
        );

        // ABABABABABA
        CASE(
            Ma = Mc = MAXM,
            Mb = 5,
            Sa = 10, Sb = 25, Sc = 5,
            grid(
                "...........",
                "###########"
            )
        );

        // BABABABABAB
        CASE(
            Ma = Mc = MAXM,
            Mb = 6,
            Sa = 10, Sb = 25, Sc = 5,
            grid(
                "...........",
                "###########"
            )
        );

        // ACACACACACA
        CASE(
            Ma = Mb = Mc = MAXM,
            Sa = 35, Sb = 10, Sc = 15,
            grid(
                "...........",
                "###########"
            )
        );

        // CACACACACAC  OR  ACACACACACC
        CASE(
            Ma = Mb = MAXM,
            Mc = 6,
            Sa = 15, Sb = 10, Sc = 36,
            grid(
                "...........",
                "###########"
            )
        );

        // A#A#A#A#A#A
        // #A#A#A#A#A#
        CASE(
            Ma = Mb = Mc = MAXM,
            Sa = 50, Sb = 30, Sc = 15,
            grid(
                ".#.#.#.#.#.",
                "#.#.#.#.#.#"
            )
        );

        // C#C#C#C#C#C
        // #C#C#C#C#C#
        CASE(
            Ma = Mb = Mc = MAXM,
            Sa = 30, Sb = 10, Sc = 60,
            grid(
                ".#.#.#.#.#.",
                "#.#.#.#.#.#"
            )
        );

        // B#B#B#B#B#B
        // #A#A#A#A#A#
        CASE(
            Ma = Mb = Mc = MAXM,
            Sa = 20, Sb = 70, Sc = 15,
            grid(
                ".#.#.#.#.#.",
                "#.#.#.#.#.#"
            )
        );

        // A#A#A#A#A#A
        // #B#B#B#B#B#
        CASE(
            Ma = 6,
            Mb = Mc = MAXM,
            Sa = 50, Sb = 30, Sc = 15,
            grid(
                ".#.#.#.#.#.",
                "#.#.#.#.#.#"
            )
        );

        // B#B#B#B#B#B
        // #A#A#A#A#A#
        CASE(
            Ma = 5,
            Mb = Mc = MAXM,
            Sa = 50, Sb = 30, Sc = 15,
            grid(
                ".#.#.#.#.#.",
                "#.#.#.#.#.#"
            )
        );

        // B#B#B#B#B#B
        // #C#C#C#C#C#
        CASE(
            Ma = Mb = Mc = MAXM,
            Sa = 19, Sb = 70, Sc = 21,
            grid(
                ".#.#.#.#.#.",
                "#.#.#.#.#.#"
            )
        );

        // C#C#C#C#C#C  O  B#B#B#B#B#C
        // #B#B#B#B#B#  R  #C#C#C#C#C#
        CASE(
            Ma = Mb = MAXM,
            Mc = 6,
            Sa = 19, Sb = 70, Sc = 80,
            grid(
                ".#.#.#.#.#.",
                "#.#.#.#.#.#"
            )
        );

        // random cases where Sc is the smallest among Sa, Sb, Sc

        CASE(
            N = 100,
            Ma = Mb = Mc = 200,
            Sa = 93000, Sb = 92000, Sc = 91000,
            randomGrid(20)
        );
        CASE(
            N = 100,
            Ma = Mb = Mc = 200,
            Sa = 92000, Sb = 94000, Sc = 91000,
            randomGrid(20)
        );
        CASE(
            N = 1000,
            Ma = Mb = Mc = 1000,
            Sa = 93000, Sb = 92000, Sc = 91000,
            randomGrid(10)
        );
        CASE(
            N = 1000,
            Ma = Mb = Mc = 1000,
            Sa = 93000, Sb = 92000, Sc = 91000,
            randomGrid(30)
        );
        CASE(
            N = 1000,
            Ma = Mb = Mc = 1000,
            Sa = 93000, Sb = 92000, Sc = 91000,
            randomGrid(70)
        );
        CASE(
            N = 1000,
            Ma = Mb = Mc = 1000,
            Sa = 92000, Sb = 93000, Sc = 91000,
            randomGrid(10)
        );
        CASE(
            N = 1000,
            Ma = Mb = Mc = 1000,
            Sa = 92000, Sb = 93000, Sc = 91000,
            randomGrid(30)
        );
        CASE(
            N = 1000,
            Ma = Mb = Mc = 1000,
            Sa = 92000, Sb = 93000, Sc = 91000,
            randomGrid(70)
        );
        
        CASE(
            N = 1000,
            Ma = 123, Mb = 234, Mc = 50,
            Sa = 92000, Sb = 93000, Sc = 91000,
            randomGrid(5)
        );
        CASE(
            N = 1000,
            Ma = 234, Mb = 123, Mc = 50,
            Sa = 92000, Sb = 93000, Sc = 91000,
            randomGrid(5)
        );
        CASE(
            N = 1000,
            Ma = 123, Mb = 234, Mc = 50,
            Sa = 93000, Sb = 92000, Sc = 91000,
            randomGrid(5)
        );
        CASE(
            N = 1000,
            Ma = 234, Mb = 123, Mc = 50,
            Sa = 93000, Sb = 92000, Sc = 91000,
            randomGrid(5)
        );
    }

private:
    void grid(string r1, string r2) {
        N = r1.size();
        G.push_back(vector<char>(r1.begin(), r1.end()));
        G.push_back(vector<char>(r2.begin(), r2.end()));
    }

    void randomGrid(int percentageWall) {
        for (int i = 0; i < 2; i++) {
            vector<char> row;
            for (int j = 0; j < N; j++) {
                row.push_back(rnd.nextInt(100) < percentageWall ? '#' : '.');
            }
            G.push_back(row);
        }
    }
};
