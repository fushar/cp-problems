import java.util.*;

public class TCGen
{
	public static Random rand;
	
	public static void print(String[] cA, String[] cC)
	{
		System.out.print("{");
		for (int i = 0; i < cA.length; i++)
		{
			if (i > 0)
				System.out.print(", ");
			System.out.print("\"" + cA[i] + "\"");
		}
		System.out.println("}");
		
		
		System.out.print("{");
		for (int i = 0; i < cC.length; i++)
		{
			if (i > 0)
				System.out.print(", ");
			System.out.print("\"" + cC[i] + "\"");
		}
		System.out.println("}");
	}
	
	public static String[] ojek(boolean[] data)
	{
		int M = data.length;
		String[] res = new String[(M+49)/50];
		
		int p = 0;
		for (int i = 0; i < M; i += 50)
		{
			String cur = "";
			for (int j = 0; j < 50; j++)
				if (i + j < M)
					cur += data[i+j] ? "Y" : "N";
			res[p++] = cur;
		}
		
		return res;
	}
	
	public static String[] ojeksss(boolean[] data)
	{
		int N = rand.nextInt(50) + 1;
		
		ArrayList<String> res = new ArrayList<String>();
		
		int pos = 0;
		
		for (int i = 0; i < N; i++)
		{
			int R = data.length - pos;
			
			if (R == 0)
				break;
			
			int take = rand.nextInt(R) + 1;
			
			if (i == N-1)
				take = R;
			
			String cur = "";
			for (int j = 0; j < take; j++)
				cur += (data[pos+j] ? "Y" : "N");
			res.add(cur);
			pos += take;
		}
		
		String[] wow = new String[res.size()];
		for (int i = 0; i < res.size(); i++)
			wow[i] = res.get(i);
		return wow;
	}
	
	public static void random_case(int N, int Cr, int both, int Ce)
	{
		ArrayList<Integer> lho = new ArrayList<Integer>();
		for (int i = 0; i < N; i++)
			lho.add(i);
				
		boolean[] attempted = new boolean[N];
		boolean[] challenged = new boolean[N];
		
		for (int i = 0; i < both; i++)
		{
			int id = rand.nextInt(lho.size());
			attempted[lho.get(id)] = true;
			challenged[lho.get(id)] = true;
			
			lho.remove(id);	
		}
		
		for (int i = 0; i < Cr; i++)
		{
			int id = rand.nextInt(lho.size());
			attempted[lho.get(id)] = true;
			
			lho.remove(id);	
		}
		
		for (int i = 0; i < Ce; i++)
		{
			int id = rand.nextInt(lho.size());
			challenged[lho.get(id)] = true;
			
			lho.remove(id);	
		}
		
		
		String[] codersAttempted = ojek(attempted);
		String[] codersChallenged = ojek(challenged);
		
		print(codersAttempted, codersChallenged);
	}
	
	public static void wow_case(int X)
	{
		int N = rand.nextInt(X) + 1;
		int Cr = rand.nextInt(N+1);
		int both = rand.nextInt(N-Cr+1);
		int Ce = rand.nextInt(N-Cr-both+1);
		
		random_case(N, Cr, both, Ce);
	}
	
	public static void main(String[] arg)
	{
		rand = new Random();
		
		
		random_case(1, 0, 1, 0);
		random_case(1, 1, 0, 0);
		random_case(1, 0, 0, 1);
		random_case(1, 0, 1, 0);
		
		random_case(2500, 2500, 0, 0);
		random_case(2500, 1000, 500, 1000);
		random_case(2500, 1250, 1250, 0);
		
		for (int i = 0; i < 10; i++)
			wow_case(100);
		for (int i = 0; i < 40; i++)
			wow_case(2500);
		
	}
}
