#include "tcframe/runner.hpp"
using namespace tcframe;

#include <bits/stdc++.h>
using namespace std;

class Problem : public BaseProblem {
protected:
    int T;
    string S;

    string caze, caseNum, result;

    void Config() {
        setSlug("hackbook");
        setMultipleTestCasesCount(T);
    }

    void InputFormat() {
        LINE(S);
    }

    void OutputFormat() {
        LINE(caze, caseNum, result);
    }

    void MultipleTestCasesConstraints() {
        CONS(1 <= T && T <= 20);
    }

    void Constraints() {
        CONS(1 <= S.size() && S.size() <= 100);
        CONS(eachCharacterBetween(S, 'a', 'z'));
    }

private:
    bool eachCharacterBetween(const string& S, char lo, char hi) {
        for (char x : S) {
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
            "aeosmg"
        });
        SAMPLE_CASE({
            "slolo"
        });
        SAMPLE_CASE({
            "ek"
        });
        SAMPLE_CASE({
            "jakarta"
        });
        SAMPLE_CASE({
            "icpc"
        });
    }

    void TestCases() {
        CASE(S = "a");
        CASE(S = "z");
        CASE(randomString(1, 1));
        CASE(randomString(1, 2));
        CASE(randomString(1, 3));
        CASE(randomString(2, 0));
        CASE(randomString(2, 1));
        CASE(randomString(2, 2));
        CASE(randomString(2, 3));
        CASE(randomString(2, 4));
        CASE(randomString(2, 5));
        CASE(randomString(50, 50));
        CASE(randomString(30, 60));
        CASE(randomString(50, 49));
        CASE(randomString(100, 0));
        CASE(randomString(0, 100));
        CASE(randomString(33, 66));
        CASE(randomString(66, 33));
        CASE(randomString(20, 80));
        CASE(randomString(80, 20));
    }

private:
    void randomString(int vowelsCount, int consonantsCount) {
        string vowels = "aeiou";
        string consonants = "bcdfghjklmnpqrstvwxyz";

        S = "";
        for (int i = 0; i < vowelsCount; i++) {
            S += vowels[rnd.nextInt(vowels.size())];
        }
        for (int i = 0; i < consonantsCount; i++) {
            S += consonants[rnd.nextInt(consonants.size())];
        }
        rnd.shuffle(S.begin(), S.end());
    }
};

int main(int argc, char* argv[]) {
    Runner<Problem> runner(argc, argv);

    runner.setGenerator(new Generator());
    return runner.run();
}
