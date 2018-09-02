import java.util.*;

class IvanArrangement {
    int N;
    int[] types;

    class State {
        int[] blockCount;
        int curBlockSize;
        int curPos;

        public State() {
            blockCount = new int[N + 1];
            curBlockSize = 1;
            curPos = 0;
        }

        public State clone() {
            return new State(blockCount, curBlockSize, curPos);
        }

        public State(int[] blockCount, int curBlockSize, int curPos) {
            this.blockCount = blockCount.clone();
            this.curBlockSize = curBlockSize;
            this.curPos = curPos;
        }

        public boolean equals(Object other) {
            State otherState = (State)other;
            return (Arrays.equals(this.blockCount, otherState.blockCount) &&
                    curBlockSize == otherState.curBlockSize);
        }

        public int hashCode() {
            int res = 0;
            for (int x : blockCount)
                res = 37 * res + x;

            return 37 * res + curBlockSize;
        }
    }

    long[][] C;

    Map<State, Integer> memo = new HashMap<State, Integer>();
    final int MOD = 1000000007;

    int solve(State cur) {
        if (cur.curBlockSize == N + 1)
            return 0;

        if (cur.curPos == N)
            return 1;

        if (memo.containsKey(cur))
            return memo.get(cur);

        State next = cur.clone();
        next.curBlockSize++;
        long res = solve(next);

        for (int nextPos = cur.curPos + 1; nextPos <= N; nextPos++) {
            if (types[nextPos - 1] != types[cur.curPos] ||
                    nextPos - cur.curPos > cur.blockCount[cur.curBlockSize])
                break;

            next = cur.clone();
            next.blockCount[cur.curBlockSize] -= nextPos - cur.curPos;
            next.blockCount[cur.curBlockSize - 1] += nextPos - cur.curPos;
            next.curPos = nextPos;
            next.curBlockSize++;
            if (nextPos == N || types[nextPos] != types[cur.curPos]) next.curBlockSize = 1;

            res += solve(next) * C[cur.blockCount[cur.curBlockSize]][nextPos - cur.curPos];
            res %= MOD;
        }

        memo.put(cur, (int)res);
        return (int)res;
    }

    public int howMany(int[] types, int[] blocks) {
        this.N = types.length;
        this.types = types;

        Arrays.sort(types);

        State start = new State();
        for (int len : blocks)
            start.blockCount[len]++;

        C = new long[N+1][N+1];
        for (int i=0; i<=N; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<i; j++)
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }

        long res = solve(start);

        for (int len : blocks)
            for (int i=1; i<=len; i++)
                res = (res * i) % MOD;

        return (int)res;
    }
}

public class RabbitsArrangement
{
	int N;
	boolean[] isBeginning;
	long[][] comb;
	long[] fact;
	HashMap<ArrayList<Integer>, Integer> dp;
	final long MOD = 1000000007;
	
	long DP(ArrayList<Integer> state)
	{
		if (!dp.containsKey(state))
		{
			int pos = N;
			int pos2 = state.get(0);
			for (int i = 1; i <= N; i++)
				pos -= i * state.get(i);
			if (pos == N)
				dp.put(state, 1);
			else if (pos2 == N+1)
				dp.put(state, 0);
			else
			{
				long res = 0;
				ArrayList<Integer> temp = new ArrayList<Integer>();
				for (int i = 0; i <= N; i++)
					temp.add(state.get(i));
				
				int rem = 1;
				for (int i = pos+1; i <= N; i++)
					if (!isBeginning[i])
						rem++;
					else
						break;
				int available = state.get(pos2);
				for (int i = 0; i <= available && i <= rem; i++)
				{
					if (i > 0 && isBeginning[pos+i])
						temp.set(0, 1);
					else
						temp.set(0, pos2+1);
					temp.set(pos2, available - i);
					if (pos2 > 1)
						temp.set(pos2 - 1, temp.get(pos2 - 1) + i);
						
					long cur = 1;
					cur = (cur * comb[available][i]) % MOD;
					cur = (cur * fact[i]) % MOD; 
					cur = (cur * comb[rem][i]) % MOD;
					cur = (cur * DP(temp)) % MOD;
					temp.set(0, state.get(0));
					res = (res + cur) % MOD;
					temp.set(pos2, available);
					if (pos2 > 1)
						temp.set(pos2 - 1, temp.get(pos2 - 1) - i);
				}
				
				dp.put(state, (int)res);
			}
		}
		//System.out.println(state.toString() + ": " + dp.get(state));
		return dp.get(state);
	}
	
	public int howMany(int[] types, int[] blocks)
	{
		N = types.length;
		isBeginning = new boolean[N+1];
		
		int cur = 0;
		for (int i = 0; i < blocks.length; i++)
		{
			isBeginning[cur] = true;
			cur += blocks[i];
		}
		isBeginning[cur] = true;
		
		fact = new long[N+1];
		fact[0] = 1;
		for (int i = 1; i <= N; i++)
			fact[i] = (fact[i-1] * i) % MOD;
		
		comb = new long[N+1][N+1];
		for (int i = 0; i <= N; i++)
		{
			comb[i][0] = 1;
			for (int j = 1; j <= i; j++)
				comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
		}
		
		int[] cnt = new int[30+1];
		for (int i = 0; i < N; i++)
			cnt[types[i]]++;
			
		ArrayList<Integer> initState = new ArrayList<Integer>();
		for (int i = 0; i <= N; i++)
			initState.add(0);
		for (int i = 1; i <= 30; i++)
			initState.set(cnt[i], initState.get(cnt[i]) + 1);
		initState.set(0, 1);
		dp = new HashMap<ArrayList<Integer>, Integer>();
		return (int)DP(initState);
	}
	
	public String checkData(int[] types, int[] blocks)
	{
		int N = types.length;
		if (N < 1 || N > 30)
			return "types must contain between 1 and 30 elements, inclusive.";
		for (int i = 0; i < N; i++)
			if (types[i] < 1 || types[i] > 30)
				return "Each element of types must be between 1 and 30, inclusive.";
		
		int M = blocks.length;
		if (M < 1 || M > 30)
			return "blocks must contain between 1 and 30 elements, inclusive.";
		for (int i = 0; i < M; i++)
			if (blocks[i] < 1 || blocks[i] > 30)
				return "Each element of blocks must be between 1 and 30, inclusive.";
				
		int sum = 0;
		for (int i = 0; i < M; i++)
			sum += blocks[i];
		if (sum != N)
			return "The sum of all numbers in blocks must be the same as the number of elements of types.";
		return "";	
	}
	
	public static void main(String[] args)
	{
		RabbitsArrangement o = new RabbitsArrangement();
		IvanArrangement ivan = new IvanArrangement();
		int[] types = {21, 13, 21, 13, 1, 7, 9, 9, 1, 3, 5, 5, 5, 3, 16, 1};
		int[] blocks = {1, 1, 2, 4, 3, 4, 1};
		System.out.println(o.howMany(types, blocks));
		System.out.println(ivan.howMany(types, blocks));
		
	}
}
