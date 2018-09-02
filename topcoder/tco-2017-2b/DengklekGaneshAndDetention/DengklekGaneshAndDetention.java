public class DengklekGaneshAndDetention {
    int N;
    int[] lamps;
    double[] probHeads;
    double[] probTails;

    public double getExpected(int N, int valInit, int valMul, int valAdd, int valMod) {
        this.N = N;

        long[] val = new long[N];
        val[0] = valInit;
        for (int i = 1; i < N; i++) {
            val[i] = (val[i-1] * valMul + valAdd) % valMod;
        }

        lamps = new int[N];
        probHeads = new double[N];
        probTails = new double[N];
        for (int i = 0; i < N; i++) {
            lamps[i] = (int)(val[i] % 2);
            int prob = (int)(val[i] % 101);
            probHeads[i] = prob / 100.0;
            probTails[i] = 1 - probHeads[i];
        }

        return getExpectedImpl();
    }

    double getExpectedImpl() {
        int[] suffixLampsSum = new int[N+1];
        suffixLampsSum[N] = 0;
        for (int i = N-1; i >= 0; i--) {
            suffixLampsSum[i] = lamps[i] + suffixLampsSum[i+1];
        }

        double[][] expFlipsFromLeft = new double[N+1][2];
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                int on = lamps[i] ^ j;
                int toFlip = (j == 1) ? suffixLampsSum[i+1] : N-1-i - suffixLampsSum[i+1];
                if (on == 1) {
                    expFlipsFromLeft[i][j] += probHeads[i] * expFlipsFromLeft[i+1][j];
                    expFlipsFromLeft[i][j] += probTails[i] * (toFlip + expFlipsFromLeft[i+1][j^1]);
                } else {
                    expFlipsFromLeft[i][j] += expFlipsFromLeft[i+1][j];
                }
            }
        }

        double[][] expLeftFlips = new double[N+1][2];
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                int on = lamps[i] ^ j;
                if (on == 1) {
                    expLeftFlips[i][j] += probHeads[i] * (1 + expLeftFlips[i+1][j]);
                    expLeftFlips[i][j] += probTails[i] * expLeftFlips[i+1][j^1];
                } else {
                    expLeftFlips[i][j] += expLeftFlips[i+1][j];
                }
            }
        }

        double[][] probEvenLeftFlips = new double[N+1][2];
        double[][] probOddLeftFlips = new double[N+1][2];

        probEvenLeftFlips[N][0] = probEvenLeftFlips[N][1] = 1;
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                int on = lamps[i] ^ j;
                if (on == 1) {
                    probEvenLeftFlips[i][j] += probHeads[i] * probOddLeftFlips[i+1][j];
                    probEvenLeftFlips[i][j] += probTails[i] * probEvenLeftFlips[i+1][j^1];
                    probOddLeftFlips[i][j] += probHeads[i] * probEvenLeftFlips[i+1][j];
                    probOddLeftFlips[i][j] += probTails[i] * probOddLeftFlips[i+1][j^1];
                } else {
                    probEvenLeftFlips[i][j] += probEvenLeftFlips[i+1][j];
                    probOddLeftFlips[i][j] += probOddLeftFlips[i+1][j];
                }
            }
        }

        double[][] expFlipsFromRight = new double[N+1][2];
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                int on = lamps[i] ^ j;
                if (on == 1) {
                    expFlipsFromRight[i][j] += probHeads[i] * ((expLeftFlips[i+1][j] - probOddLeftFlips[i+1][j])/2 + expFlipsFromRight[i+1][j]);
                    expFlipsFromRight[i][j] += probTails[i] * ((expLeftFlips[i+1][j^1] - probOddLeftFlips[i+1][j^1])/2 + expFlipsFromRight[i+1][j^1]);
                } else {
                    expFlipsFromRight[i][j] += (expLeftFlips[i+1][j] + probOddLeftFlips[i+1][j])/2 + expFlipsFromRight[i+1][j];
                }
            }
        }

        return expFlipsFromLeft[0][0] + expFlipsFromRight[0][0];
    }

    public double getExpectedBruteForce(int[] lamps, int[] probs) {
        return getExpectedBruteForceImpl(0, lamps, probs);
    }

    private double getExpectedBruteForceImpl(int i, int[] lamps, int[] probs) {
        int N = lamps.length;
        if (i == N) return 0.0;
        if (lamps[i] == 0) return getExpectedBruteForceImpl(i+1, lamps, probs);

        double res = 0;

        // left
        int flips = 0;
        for (int j = 0; j < i; j++) {
            if (lamps[j] == 0) flips++;
            lamps[j] = 1 - lamps[j];
        }
        res += (probs[i] / 100.0) * (flips + getExpectedBruteForceImpl(i+1, lamps, probs));
        for (int j = 0; j < i; j++) {
            lamps[j] = 1 - lamps[j];
        }

        // right
        flips = 0;
        for (int j = i+1; j < N; j++) {
            if (lamps[j] == 0) flips++;
            lamps[j] = 1 - lamps[j];
        }
        res += (1 - probs[i] / 100.0) * (flips + getExpectedBruteForceImpl(i+1, lamps, probs));
        for (int j = i+1; j < N; j++) {
            lamps[j] = 1 - lamps[j];
        }

        return res;
    }

    public String checkData(int N, int valInit, int valMul, int valAdd, int valMod) {
        if (N < 1 || N > 1000000) {
            return "N must be between 1 and 1,000,000, inclusive.";
        }
        if (valMod < 1 || valMod > 1000000000) {
            return "valMod must be between 1 and 1,000,000,000, inclusive.";
        }
        if (valInit < 0 || valInit >= valMod) {
            return "valInit must be between 0 and valMod - 1, inclusive.";
        }
        if (valMul < 0 || valMul >= valMod) {
            return "valMul must be between 0 and valMod - 1, inclusive.";
        }
        if (valAdd < 0 || valAdd >= valMod) {
            return "valAdd must be between 0 and valMod - 1, inclusive.";
        }
        return "";
    }

    public String checkAnswer(int N, int valInit, int valMul, int valAdd, int valMod, double compAns, double refAns) {
        double EPS = 1e-6;

        if (Double.isNaN(compAns)) {
            return "Your answer is NaN (not a number).";
        }

        if (Math.abs(compAns - refAns) > EPS && Math.abs(compAns - refAns) > EPS * refAns) {
            return "Your answer has both absolute and relative error greater than 1e-6.";
        }

        return "";
    }
}
