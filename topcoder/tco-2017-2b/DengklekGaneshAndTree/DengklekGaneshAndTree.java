import java.util.*;

public class DengklekGaneshAndTree {
    static final int MOD = 1000000007;

    int N;
    int L;
    String labels;
    int[] parents;
    List<Interval> intervals;
    boolean[] seen;
    int[][] dp;

    public int getNumberOfWays(String labels, int[] parents) {
        this.N = labels.length();
        this.labels = labels;
        this.parents = parents;

        computeIntervals();

        return solve();
    }

    void computeIntervals() {
        intervals = new ArrayList<>();
        seen = new boolean[N];

        dfs(0, 0);
    }

    int solve() {
        int M = intervals.size();
        Collections.sort(intervals);

        dp = new int[M+1][L+2];
        dp[0][0] = 1;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j <= L+1; j++) {
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;

                if (j >= intervals.get(i).from) {
                    int nextj = Math.max(j, intervals.get(i).to + 1);
                    dp[i+1][nextj] = (dp[i+1][nextj] + dp[i][j]) % MOD;
                }
            }
        }
        return dp[M][L+1];
    }

    void dfs(int u, int level) {
        L = Math.max(L, level);
        if (!seen[u]) {
            int to = dfsInterval(u, labels.charAt(u), level);
            intervals.add(new Interval(level, to));
        }
        for (int v = 1; v < N; v++) {
            if (parents[v-1] == u) {
                dfs(v, level+1);
            }
        }
    }

    int dfsInterval(int u, char label, int level) {
        seen[u] = true;
        int to = level;
        for (int v = 1; v < N; v++) {
            if (parents[v-1] == u && label == labels.charAt(v)) {
                to = Math.max(to, dfsInterval(v, label, level+1));
            }
        }
        return to;
    }

    public String checkData(String labels, int[] parents) {
        int N = labels.length();
        if (N < 1 || N > 1000) {
            return "labels must contain between 1 and 1,000 characters, inclusive.";
        }
        for (char c : labels.toCharArray()) {
            if (c < 'a' || c > 'z') {
                return "Each character of labels must be a lowercase English letter ('a' to 'z').";
            }
        }
        if (parents.length != N-1) {
            return "parents must contain exactly N - 1 elements, where N is the number of character of labels.";
        }
        for (int u : parents) {
            if (u < 0 || u > N-1) {
                return "Each element of parents must be between 0 and N - 1, inclusive, where N is the number of character of labels.";
            }
        }
        for (int i = 0; i < N-1; i++) {
            if (parents[i] < 0 || parents[i] > i) {
                return "For each i, parents[i] must be between 0 and i, inclusive.";
            }
        }
        return "";
    }
}

class Interval implements Comparable<Interval> {
    int from;
    int to;

    Interval(int from, int to) {
        this.from = from;
        this.to = to;
    }

    @Override
    public int compareTo(Interval other) {
        return Integer.compare(from, other.from);
    }
}
