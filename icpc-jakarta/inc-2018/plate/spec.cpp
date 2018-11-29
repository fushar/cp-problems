#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;
using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    ll A, B;
    ll O, E;

    void InputFormat() {
        LINE(A, B);
    }

    void OutputFormat() {
        LINE(O, E);
    }

    void Constraints() {
        CONS(1 <= A && A <= B && B <= (ll)1e16);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "1 10"
        });
        Output({
            "6 4"
        });
    }

    void SampleTestCase2() {
        Input({
            "296 311"
        });
        Output({
            "10 6"
        });
    }
    void SampleTestCase3() {
        Input({
            "946 1073"
        });
        Output({
            "72 56"
        });
    }

    void TestCases() {
        CASE(A = 1, B = 1);
        CASE(A = 1, B = 2);
        CASE(A = (ll)1, B = (ll)1e15);
        CASE(A = (ll)1, B = (ll)1e16);
        CASE(A = (ll)1e15, B = (ll)1e16);
        CASE(A = (ll)1e15, B = (ll)1e16-1);
        CASE(A = (ll)1e16-2, B = (ll)1e16);
        CASE(A = (ll)1e16-1, B = (ll)1e16);
        CASE(A = (ll)1e16, B = (ll)1e16);
        CASE(A = 17, B = 81945);
        CASE(A = 123, B = 100200300);
        CASE(A = 201820182018LL, B = 201920192019LL);
        CASE(A = 1234567890123LL, B = 9876543210987LL);
        CASE(A = 1111111111111111LL, B = 9999999999999999LL);
        CASE(A = 2718281828459045LL, B = 3141592653589793LL);
    }
};
