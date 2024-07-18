#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int MAXN = 100000;

    string A, B;
    int res;

    void InputFormat() {
        LINE(A);
        LINE(B);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= A.size() && A.size() <= B.size() && B.size() <= MAXN);
        CONS(validString(A));
        CONS(validString(B));
    }

private:
    bool validString(string s) {
        for (char c : s) {
            if (c < 'A' || c > 'Z') {
                return false;
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
            "AMA",
            "ANAB"
        });
        Output({
            "9"
        });
    }

    void SampleTestCase2() {
        Input({
            "BINUS",
            "BINANUSA"
        });
        Output({
            "120"
        });
    }

    void SampleTestCase3() {
        Input({
            "BINUSUNIVERSITY",
            "BINANUSANTARAUNIVERSITYJAKARTA"
        });
        Output({
            "810042666"
        });
    }

    void SampleTestCase4() {
        Input({
            "ANDI",
            "BUDI"
        });
        Output({
            "0"
        });
    }

    void TestCases() {
        // ans = 0
        CASE(A = "X", B = "Z");
        CASE(A = "Z", B = "A");
        CASE(A = "BC", B = "ABEF");

        // ans = 1
        CASE(A = "X", B = "X");
        CASE(A = "X", B = "Y");
        CASE(A = "XX", B = "YY");

        // ans = 3!
        CASE(A = "ABC", B = "CBA");
        CASE(A = "AAB", B = "ABB");
        
        // ans = 26!
        CASE(A = ALPHABET, B = ALPHABET);

        // random cases
        CASE(randomCase(10, 20, 2));
        CASE(randomCase(100, 200, 26));
        CASE(randomCase(500, 1000, 2));
        CASE(randomCase(500, 1000, 26));
        CASE(randomCase(1000, 1000, 26));
        CASE(randomCase(1000, 1000, 26));
        CASE(randomCase(900, 1000, 13));

        // random cases
        CASE(randomCase(10000, 20000, 2));
        CASE(randomCase(10000, 20000, 26));
        CASE(randomCase(50000, 100000, 2));
        CASE(randomCase(50000, 100000, 26));
        CASE(randomCase(100000, 100000, 26));
        CASE(randomCase(100000, 100000, 26));
        CASE(randomCase(90000, 100000, 13));
    }

private:
    void randomCase(int nA, int nB, int uniqueLetters) {
        string alph = ALPHABET;
        rnd.shuffle(alph.begin(), alph.end());

        A = alph.substr(0, uniqueLetters);
        while (A.size() < nA) {
            A.push_back(alph[rnd.nextInt(alph.size())]);
        }

        // Make sure there's a solution
        B = A; 

        // For each character in B, maybe replace it with the next letter in the alphabet
        for (int i = 0; i < B.size(); i++) {
            if (rnd.nextInt(2) && B[i] != ALPHABET.back()) {
                B[i]++;
            }
        }

        // Add the remaining nB-nA characters
        // with the unique letters, or from the entire alphabet.
        while (B.size() < nB) {
            char c;
            if (rnd.nextInt(2)) {
                c = alph[rnd.nextInt(alph.size())];
            } else {
                c = ALPHABET[rnd.nextInt(ALPHABET.size())];
            }
            B.push_back(c);
        }

        rnd.shuffle(A.begin(), A.end());
        rnd.shuffle(B.begin(), B.end());
    }
};
