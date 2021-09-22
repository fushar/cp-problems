#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> A;
    vector<int> B;

    int ans;

    void InputFormat() {
        LINE(N);
        LINE(A % SIZE(N));
        LINE(B % SIZE(N));
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= N && N <= 1000);
        CONS(eachElementBetween(A, 1, 1000));
        CONS(eachElementBetween(B, 1, 10));
    }

private:
    bool eachElementBetween(const vector<int>& X, int lo, int hi) {
        for (int x : X) {
            if (x < lo || x > hi) {
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
            "6",
            "3 1 1 1 1 2",
            "1 5 3 3 7 4"
        });
        Output({
            "13"
        });
    }

    void SampleTestCase2() {
        Input({
            "2",
            "2 1",
            "1 1"
        });
        Output({
            "4"
        });
    }

    void BeforeTestCase() {
        A.clear();
        B.clear();
    }

    void TestCases() {
        // small edge cases
        CASE(N = 1, A = {1}, B = {1});
        CASE(N = 2, A = {10, 1}, B = {1, 10});

        // kill solutions which greedily make Budi finish as fast as possible
        CASE(
            N = 6,
            A = {1, 2, 1, 1, 1, 1},
            B = {1, 2, 3, 2, 2, 1}
            /**
             * GREEDY (fail)        OPTIMAL
             * Andi | Budi          Andi | Budi
             * -----+-----          -----+-----
             *      | 1                  | 1
             *  1   | 2               1  | 3
             *      | 2               2  | 3
             *  2   | 4               2  | 3
             *  2   | 4               3  | 5
             *  3   | 6               4  | 5
             *  4   |                 5  | 6
             *  5   |                 6  |
             *  6   | 
             */
        );

        // A[i] = 1
        CASE(N = 100, randomA(1, 1), randomB(1, 1));
        CASE(N = 100, randomA(1, 1), randomB(1, 10));
        CASE(N = 100, randomA(1, 1), randomB(1, 10));
        CASE(N = 1000, randomA(1, 1), randomB(1, 1));
        CASE(N = 1000, randomA(1, 1), randomB(1, 10));
        CASE(N = 1000, randomA(1, 1), randomB(1, 10));

        // random cases A[i] <= 10
        CASE(N = 100, randomA(1, 10), randomB(1, 10));
        CASE(N = 100, randomA(1, 10), randomB(1, 2));
        CASE(N = 100, randomA(1, 10), randomB(8, 10));
        CASE(N = 100, randomA(8, 10), randomB(8, 10));
        CASE(N = 100, randomA(9, 10), randomB(9, 10));
        CASE(N = 1000, randomA(1, 10), randomB(1, 10));
        CASE(N = 1000, randomA(8, 10), randomB(8, 10));
        CASE(N = 1000, randomA(9, 10), randomB(9, 10));

        // random cases with "mines" in B
        // not always optimal to try to always pick 1s
        // B = 9 9 1 1 1 9 1 9 1 ...
        CASE(N = 100, randomA(1, 2), randomBWithMines());
        CASE(N = 100, randomA(1, 2), randomBWithMines());
        CASE(N = 100, randomA(1, 10), randomBWithMines());
        CASE(N = 100, randomA(1, 10), randomBWithMines());
        CASE(N = 100, randomA(8, 10), randomBWithMines());
        CASE(N = 100, randomA(1, 100), randomBWithMines());
        CASE(N = 1000, randomA(1, 1000), randomBWithMines());

        // max cases
        CASE(N = 1000, randomA(999, 1000), randomB(9, 10));
        CASE(N = 1000, randomA(999, 1000), randomB(9, 10));
        CASE(N = 1000, randomA(1000, 1000), randomB(10, 10));
        CASE(N = 1000, randomA(1, 1000), randomB(1, 10));
        CASE(N = 1000, randomA(1, 1000), randomB(1, 10));
    }
private:
    void randomA(int minA, int maxA) {
        for (int i = 0; i < N; i++) {
            A.push_back(rnd.nextInt(minA, maxA));
        }
    }

    void randomB(int minB, int maxB) {
        for (int i = 0; i < N; i++) {
            B.push_back(rnd.nextInt(minB, maxB));
        }
    }

    void randomBWithMines() {
        for (int i = 0; i < N; i++) {
            if (rnd.nextInt(2)) {
                B.push_back(9 + rnd.nextInt(2));
            } else {
                B.push_back(1 + rnd.nextInt(2));
            }
        }
    }
};
