#include "tcframe/runner.hpp"
using namespace tcframe;

#include <bits/stdc++.h>
using namespace std;

class Problem : public BaseProblem {
protected:
    int T;
    int N, A, B;
    vector<int> D;

    string caze, caseNum;
    int K;
    vector<int> result;

    void Config() {
        setSlug("no-statement");
        setMultipleTestCasesCount(T);
    }

    void InputFormat() {
        LINE(N, A, B);
        LINE(D % SIZE(N));
    }

    void OutputFormat() {
        LINE(caze, caseNum);
        LINE(K);
        LINE(result % SIZE(K));
    }

    void MultipleTestCasesConstraints() {
        CONS(1 <= T && T <= 20);
    }

    void Constraints() {
        CONS(1 <= A && A <= B && B <= N && N <= 100000);
        CONS(eachElementBetween(D, -2, 2));
    }

private:
    bool eachElementBetween(const vector<int>& v, int lo, int hi) {
        for (int x : v) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }
};

class Generator : public BaseGenerator<Problem> {
protected:
    void SampleTestCases() {
        SAMPLE_CASE({
            "7 1 4",
            "2 1 1 -2 -1 2 0"
        });
        SAMPLE_CASE({
            "4 1 1",
            "1 -2 2 -1"
        });
        SAMPLE_CASE({
            "4 3 4",
            "1 -1 1 -1"
        });
        SAMPLE_CASE({
            "4 3 4",
            "1 -1 1 -1"
        });
    }

    void TestCases() {
        // result must be 0 because # non-zeros < A
        CASE(N = 5, A = 3, B = 4, D = {0, 2, 0, 0, -1});
        CASE(N = 70000, A = 40000, B = 50000, buildArray({5000, 5000, 50000, 5000, 5000}));

        // result can only be negative or 0, so choose the one with 0 result
        CASE(N = 3, A = N-1, B = N, D = {2, 0, -1});
        CASE(N = 90000, A = N-1, B = N, buildArray({1, 0, 1, N/2, N-2-N/2}));

        // result must be negative because A = B = N & there are odd # of negatives
        CASE(N = 4, A = N, B = A, D = {-1, -2, -1, 1});
        CASE(N = 5, A = N, B = A, D = {-1, -2, -1, 1, 2});
        CASE(N = 100000, A = N, B = A, buildArray({10000, 10001, 0, 50000, N-10000-10001-50000}));
        CASE(N = 99999, A = N, B = A, buildArray({10000, 10001, 0, 50000, N-10000-10001-50000}));

        // result must be negative because A = B = odd & all numbers are negatives
        CASE(N = 5, A = 3, B = A, D = {-1, -2, -1, -2, -2});
        CASE(N = 30000, A = 10000, B = A, buildArray({10000, 20000, 0, 0, 0}));

        // kill greedy solutions that pick 2 -> 2 first instead of (-2, -2)
        CASE(N = 5, A = 1, B = 3, D = {2, 2, 1, -2, -2});

        // ultimately kill greedy solutions without brute force:
        CASE(N = 3, A = N-1, B = N-1, D = {2, -1, -2});
        CASE(N = 5, A = N-1, B = N-1, D = {2, -1, -1, -2, -2});

        // kill greedy solutions that try to pick as many as nonnegative integers without considering zeros
        CASE(N = 6, A = 1, B = 4, D = {2, 1, -2, 0, 2, 0});

        // kill greedy solutions that try to pick as many as nonnegative integers without considering >= A
        CASE(N = 4, A = 4, B = 4, D = {-2, -2, -1, 2});

        // just random ones....
        CASE(N = 100, A = 30, B = 60, buildArray({20, 20, 20, 20, 20}));
        CASE(N = 100, A = 30, B = 60, buildArray({19, 20, 20, 21, 20}));
        CASE(N = 100000, A = 40000, B = 80000, buildArray({5000, 5000, 20000, 30000, 40000}));
        CASE(N = 100000, A = N, B = N, buildArray({N, 0, 0, 0, 0}));
        CASE(N = 100000, A = N, B = N, buildArray({0, 0, 0, 0, N}));
    }

private:
    void buildArray(initializer_list<int> nums) {
        D.clear();
        int idx = 0;
        for (int x : nums) {
            for (int j = 0; j < x; j++) {
                D.push_back(-2 + idx);
            }
            idx++;
        }

        rnd.shuffle(D.begin(), D.end());
    }
};

int main(int argc, char* argv[]) {
    Runner<Problem> runner(argc, argv);

    runner.setGenerator(new Generator());
    return runner.run();
}
