import java.util.*;

public class DengklekGaneshAndChains {
    public String getBestChains(String[] chains, int[] lengths) {
        ArrayList<String> unused = new ArrayList<>(Arrays.asList(chains));
        int N = chains.length;
        int M = lengths.length;
        String res = "";
        for (int i = 0; i < M; i++) {
            List<List<String>> candidates = new ArrayList<>();
            for (int j = 0; j < N-i; j++) {
                List<String> substrings = new ArrayList<>();
                for (int k = i; k < M; k++) {
                    substrings.add(lexicographicallyLargest(unused.get(j), lengths[k]));
                }
                candidates.add(substrings);
            }
            Integer[] idx = new Integer[N-i];
            for (int j = 0; j < N-i; j++) {
                idx[j] = j;
            }
            int cnt = M-i;
            Arrays.sort(idx, (Integer a, Integer b) -> {
                if (candidates.get(a).get(0).compareTo(candidates.get(b).get(0)) > 0) {
                    return -1;
                }
                if (candidates.get(a).get(0).compareTo(candidates.get(b).get(0)) < 0) {
                    return 1;
                }
                for (int j = 1; j < cnt; j++) {
                    if (candidates.get(a).get(j).compareTo(candidates.get(b).get(j)) < 0) {
                        return -1;
                    }
                    if (candidates.get(a).get(j).compareTo(candidates.get(b).get(j)) > 0) {
                        return 1;
                    }
                }
                return 0;
            });

            res += candidates.get(idx[0]).get(0);
            unused.remove((int) idx[0]);
        }

        return res;
    }

    private static String lexicographicallyLargest(String chain, int len) {
        int L = chain.length();
        String combinedChain = chain + chain;

        List<String> substrings = new ArrayList<>();
        for (int i = 0; i < L; i++) {
            substrings.add(combinedChain.substring(i, i+len));
        }
        Collections.sort(substrings);
        return substrings.get(L-1);
    }

    public String checkData(String[] chains, int[] lengths) {
        int N = chains.length;
        if (N < 1 || N > 50) {
            return "chains must contain N elements, where N is between 1 and 50, inclusive.";
        }
        int K = chains[0].length();
        for (int i = 0; i < N; i++) {
            if (chains[i].length() != chains[0].length() || chains[i].length() < 1 || chains[i].length() > 50) {
                return "Each element of chains must contain exactly K characters, where K is between 1 and 50, inclusive.";
            }
            for (char c : chains[i].toCharArray()) {
                if (c < 'a' || c > 'z') {
                    return "Each character of chains must be a lowercase English letter ('a' to 'z').";
                }
            }
        }

        int M = lengths.length;
        if (M < 1 || M > N) {
            return "lengths must contain exactly M characters, where M is between 1 and N, inclusive.";
        }
        for (int len : lengths) {
            if (len < 1 || len > K) {
                return "Each element of lengths must be between 1 and K, inclusive.";
            }
        }

        return "";
    }

    public static void main(String[] args) {
        int[] lengths;
        String[] chains;

        chains = new String[]{"topc", "oder", "open", "twob"};
        lengths = new int[]{2, 1, 3};
        System.out.println(new DengklekGaneshAndChains().getBestChains(chains, lengths));

        chains = new String[]{"ssh", "she", "see", "sea"};
        lengths = new int[]{2, 3, 2, 3};
        System.out.println(new DengklekGaneshAndChains().getBestChains(chains, lengths));

        chains = new String[]{"write", "rwhoa", "reyou"};
        lengths = new int[]{3};
        System.out.println(new DengklekGaneshAndChains().getBestChains(chains, lengths));

        chains = new String[]{"deabc", "abecd", "edbac", "bdeac", "edcba", "ebcda", "cadbe", "dbcae", "aedcb", "baced", "abdce", "baedc", "ebcda", "dabce", "ceadb", "cbdea", "beadc", "edabc", "bdeac", "eadcb", "ebdac", "deacb", "eacbd", "bcaed", "ebcad", "edabc", "eacbd", "badce", "acdbe", "dbeac", "decab", "daebc", "adbce", "becad", "dbeac", "acebd", "cbeda", "ebadc", "eabdc", "eacbd", "bdeac", "acbde", "dcbea", "cabed", "dabce", "ecdba", "ebdac", "dcabe", "adecb", "cbeda"};
        lengths = new int[]{2, 3, 3, 5, 5, 2, 1, 4, 4, 2, 1, 3, 5, 5, 1, 1, 1, 3, 2, 1, 5, 5, 1, 3, 4, 2, 2, 2, 1, 1, 5, 2, 3, 5, 1, 1, 4, 4, 5, 3, 2, 3, 1, 5, 2, 4, 3, 1, 5, 5};
        System.out.println(new DengklekGaneshAndChains().getBestChains(chains, lengths));
    }
}
