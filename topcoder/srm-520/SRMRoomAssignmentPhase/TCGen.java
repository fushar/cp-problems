import java.util.*;

public class TCGen
{
	public static Random rand;
	
	public static void print(int[] ratings, int K)
	{
		System.out.print("{");
		for (int i = 0; i < ratings.length; i++)
		{
			if (i > 0)
				System.out.print(", ");
			System.out.print(ratings[i]);
		}
		System.out.println("}");
		System.out.println(K);
	}
	
	public static void smallest_cases()
	{
		print(new int[]{0, 1}, 2);
		print(new int[]{1199, 1198}, 2);
	}
	
	public static void largest_cases()
	{
		int N = 50;
		int[] ratings = new int[N];
		for (int i = 0; i < N; i++)
			ratings[i] = 1200-i-1;
		
		int K = 7;
		print(ratings, K);
		print(ratings, N);
	}
	
	public static void random_case(int N, int K, int ans)
	{
		if (ans > (N-1)/K)
		{
			System.out.println("bad testcase!");
			return;
		}
		
		int[] ratings = new int[N];
		int[] sorted = new int[N];
		ArrayList<Integer> lho = new ArrayList<Integer>();
		for (int i = 0; i < 1200; i++)
			lho.add(i);
		
		for (int i = 0; i < N; i++)
		{
			int c = rand.nextInt(1200-i);
			int d = lho.get(c);
			ratings[i] = d;
			sorted[i] = d;
			lho.remove(c);
		}
		
		Arrays.sort(sorted);
		for (int i = 0; i < N/2; i++)
		{
			int temp = sorted[i];
			sorted[i] = sorted[N-1-i];
			sorted[N-1-i] = temp;
		}
		
		ArrayList<Integer> mes = new ArrayList<Integer>();
		for (int i = 0; i < N; i++)
			if (i/K == ans)
				mes.add(sorted[i]);
			
		int me = mes.get(rand.nextInt(mes.size()));
		
		for (int i = 0; i < N; i++)
			if (ratings[i] == me)
			{
				ratings[i] = ratings[0];
				ratings[0] = me;
			}
		print(ratings, K);
	}
	
	public static void main(String[] arg)
	{
		rand = new Random();
		
		smallest_cases();
		largest_cases();
		
		random_case(2, 2, 0);
		random_case(3, 1, 2);
		random_case(4, 2, 1);
		random_case(5, 1, 4);
		random_case(6, 2, 2);
		random_case(7, 5, 0);
		random_case(8, 2, 3);
		random_case(9, 2, 4);
		random_case(10, 9, 1);
		random_case(11, 1, 8);
		random_case(12, 2, 5);
		random_case(13, 2, 6);
		random_case(14, 7, 1);
		random_case(15, 15, 0);
		random_case(16, 4, 3);
		random_case(17, 3, 5);
		random_case(18, 9, 1);
		random_case(19, 7, 2);
		random_case(20, 18, 0);
		random_case(21, 15, 1);
		random_case(22, 10, 2);
		random_case(23, 21, 1);
		random_case(24, 2, 8);
		random_case(25, 5, 4);
		random_case(26, 4, 5);
		random_case(27, 3, 8);
		random_case(28, 1, 27);
		random_case(29, 2, 9);
		random_case(30, 2, 9);
		random_case(31, 10, 3);
		random_case(32, 5, 5);
		random_case(33, 30, 1);
		random_case(34, 15, 1);
		random_case(35, 6, 5);
		random_case(36, 2, 12);
		random_case(37, 4, 5);
		random_case(38, 11, 3);
		random_case(39, 31, 1);
		random_case(40, 4, 3);
		random_case(41, 5, 2);
		random_case(42, 4, 10);
		random_case(43, 7, 3);
		random_case(44, 10, 4);
		random_case(45, 9, 4);
		random_case(46, 1, 44);
		random_case(47, 1, 31);
		random_case(48, 10, 3);
		random_case(49, 2, 24);
		random_case(50, 1, 49);
		
	}
}
