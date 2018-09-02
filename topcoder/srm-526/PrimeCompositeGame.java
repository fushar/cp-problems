import java.util.*;
import java.math.*;

class Pair implements Comparable<Pair>
{
	int index;
	int value;
	
	public Pair(int i, int v)
	{
		index = i;
		value = v;
	}
	
	public int compareTo(Pair other)
	{
		return other.value - value;
	}
}

public class PrimeCompositeGame
{
	void clean(PriorityQueue<Pair> pq, int i, int K)
	{
		while (!pq.isEmpty() && i - pq.peek().index > K)
			pq.poll();
	}
	
	public int theOutcome(int N, int K)
	{
		PriorityQueue<Pair> dpPrimePlus = new PriorityQueue<Pair>();
		PriorityQueue<Pair> dpPrimeMinus = new PriorityQueue<Pair>();
		PriorityQueue<Pair> dpCompositePlus = new PriorityQueue<Pair>();
		PriorityQueue<Pair> dpCompositeMinus = new PriorityQueue<Pair>();
		
		int[] dpPrime = new int[N+1];
		int[] dpComposite = new int[N+1];
		
		boolean[] isPrime = new boolean[N+1];
		for (int i = 2; i <= N; i++)
			isPrime[i] = true;
		for (int i = 2; i*i <= N; i++)
			if (isPrime[i])
				for (int j = i*i; j <= N; j += i)
					isPrime[j] = false;

		for (int i = 1; i <= N; i++)
		{
			clean(dpPrimePlus, i, K);
			clean(dpPrimeMinus, i, K);
			clean(dpCompositePlus, i, K);
			clean(dpCompositeMinus, i, K);
			
			// You
			if (!dpCompositeMinus.isEmpty())
			{
				int temp = dpCompositeMinus.peek().value;
				dpPrime[i] = 1 - temp;
			}
			else if (!dpCompositePlus.isEmpty())
			{
				int temp = dpCompositePlus.peek().value;
				dpPrime[i] = -(1 + temp);
			}
			
			// Mr. Dengklek
			if (!dpPrimeMinus.isEmpty())
			{
				int temp = dpPrimeMinus.peek().value;
				dpComposite[i] = 1 - temp;
			}
			else if (!dpPrimePlus.isEmpty())
			{
				int temp = dpPrimePlus.peek().value;
				dpComposite[i] = -(1 + temp);
			}
			
			// Update
			if (isPrime[i])
			{
				if (dpComposite[i] <= 0)
					dpCompositeMinus.add(new Pair(i, dpComposite[i]));
				else
					dpCompositePlus.add(new Pair(i, dpComposite[i]));
			}
			else if (i != 1 && !isPrime[i])
			{
				if (dpPrime[i] <= 0)
					dpPrimeMinus.add(new Pair(i, dpPrime[i]));
				else
					dpPrimePlus.add(new Pair(i, dpPrime[i]));
			}
			
			//System.out.print("dpPrime[" + i + "] = " + dpPrime[i]);
			//System.out.println(" dpComposite[" + i + "] = " + dpComposite[i]);
			
		}
			long best = 0, ans = 0;
			for (int i = 1; i <= N; i++)
				if (dpPrime[i] > best)
				{
					best = dpPrime[i];
					ans = i;
				}
			System.out.println(ans + ": " + best);
		return dpPrime[N];
	}
	
	public String checkData(int N, int K)
	{
		if (N < 1 || N > 1000000)
			return "N must be between 1 and 1,000,000, inclusive.";
		if (K < 1 || K > N)
			return "K must be between 1 and N, inclusive.";
		return "";
	}
	
	public static void main(String[] args)
	{
		PrimeCompositeGame o = new PrimeCompositeGame();
		System.out.println(o.theOutcome(474747, 100));
		
	}
}
