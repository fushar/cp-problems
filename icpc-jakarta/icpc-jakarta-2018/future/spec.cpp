#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<string> S;

    int res;

    void InputFormat() {
        LINE(N);
        LINES(S) % SIZE(N);
    }

    void OutputFormat() {
        LINE(res);
    }

    void Constraints() {
        CONS(1 <= N && N <= 15);
        CONS(eachElementHasLengthBetween(S, 1, 15));
        CONS(eachElementContainsBetween(S, 'A', 'Z'));
    }

private:
    bool eachElementHasLengthBetween(const vector<string>& v, int lo, int hi) {
        for (const string& s : v) {
            if (s.size() < lo || s.size() > hi) {
                return false;
            }
        }
        return true;
    }

    bool eachElementContainsBetween(const vector<string>& v, char lo, char hi) {
        for (const string& s : v) {
            for (char c : s) {
                if (c < lo || c > hi) {
                    return false;
                }
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3",
            "KARIM",
            "PARBUDI",
            "CHANDRA",
        });
        Output({
            "16"
        });
    }

    void SampleTestCase2() {
        Input({
            "3",
            "AARON",
            "AARON",
            "RON"
        });
        Output({
            "12"
        });
    }

    void SampleTestCase3() {
        Input({
            "7",
            "HAVE",
            "FUN",
            "IN",
            "ICPC",
            "JAKARTA",
            "TWENTY",
            "EIGHTEEN"
        });
        Output({
            "25"
        });
    }

    void BeforeTestCase() {
        S.clear();
    }

    void TestCases() {
        edgeCases();
        impossibleCases();
        trickyCases();
        randomPermutationCases();
        randomCases();
    }

private:
    void edgeCases() {
        CASE(N = 1, S = {"A"});
        CASE(N = 1, S = {"AAAAAAAAAAAAAAA"});
        CASE(N = 1, S = {"ABCDEFGHIJKLMNO"});
        CASE(N = 15, S = {
            "A", "B", "C", "D", "E",
            "F", "G", "H", "I", "J",
            "K", "L", "M", "N", "O"
        });
        CASE(N = 15, S = {
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO",
            "ABCDEFGHIJKLMNO"
        });
        CASE(N = 15, S = {
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAA"
        });
    }

    void impossibleCases() {
        CASE(N = 2, S = {
            "B",
            "B"
        });
        CASE(N = 2, S = {
            "B",
            "A"
        });
        CASE(N = 4, S = {
            "CBA",
            "CBA",
            "CB",
            "C",
        });
        CASE(N = 5, S = {
            "ZZZZZBZZZZ",
            "ZZCZZZZZZ",
            "ZZZZDZZZZZZZ",
            "ZZEZZZZZZ",
            "ZZZZZAZZ"
        });
        CASE(N = 9, S = {
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
        });
        CASE(N = 8, S = {
            "ABC",
            "ABC",
            "ABC",
            "ABC",
            "ABC",
            "ABC",
            "ABC",
            "ABC"
        });
        CASE(N = 10, S = {
            "JKAQWF",
            "KSDFBSDFDD",
            "BOQJDFSDF",
            "ABKJHADCC",
            "XXXXXXXXXX",
            "V",
            "WWSFJHSKF",
            "JHPPDSSD",
            "YYYYYYY",
            "ZXZXZXZXZX"
        });
    }

    void trickyCases() {
        // there is only one way (AZ*, BZ*, CZ*, ...)
        CASE(N = 7, S = {
            "ZZZZZAZZZZ",
            "ZZBZZZZZZ",
            "ZZZZCZZZZZZZ",
            "ZZDZZZZZZ",
            "ZZZZZEZZ",
            "F",
            "Z"
        });

        // stair-like pattern
        CASE(N = 8, S = {
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
            "XXXXXXXX",
        });

        // all possible masks
        CASE(N = 7, S = {
            "ABC",
            "ABC",
            "ABC",
            "ABC",
            "ABC",
            "ABC",
            "ABC"
        });
    }

    void randomPermutationCases() {
        CASE(randomPermutationCase(13));
        CASE(randomPermutationCase(14));
        CASE(randomPermutationCase(15));
        CASE(randomPermutationCase(15));
        CASE(randomPermutationCase(15));
    }

    void randomPermutationCase(int n) {
        N = n;
        for (int i = 0; i < n; i++) {
            string s = "ABCDEFGHIJKLMNO";
            rnd.shuffle(s.begin(), s.end());
            S.push_back(s);
        }
    }

    void randomCases() {
        CASE(randomCase(10, 15));
        CASE(randomCase(15, 10));
        CASE(randomCase(15, 15));
        CASE(randomCase(15, 15));
    }

    void randomCase(int n, int len) {
        N = n;
        for (int i = 0; i < n; i++) {
            string s = "";
            int l = len/2 + rnd.nextInt(len/2);
            for (int j = 0; j < l; j++) {
                s += 'A' + rnd.nextInt(26);
            }
            S.push_back(s);
        }
    }
};
