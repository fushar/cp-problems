import java.util.Random;

public class TCGen
{
	public static Random rand;
	
	public static void print(String[] description)
	{
		System.out.print("{");
		for (int i = 0; i < description.length; i++)
		{
			if (i > 0)
				System.out.print(", ");
			System.out.print("\"" + description[i] + "\"");
		}
		System.out.println("}");
	}
	
	public static void smallest_cases()
	{
		print(new String[]{"YYY"});
		print(new String[]{"NNN"});
	}
	
	public static void largest_cases()
	{
		String[] description = new String[50];
		for (int i = 0; i < 50; i++)
			description[i] = "YYY";
		print(description);
		for (int i = 0; i < 50; i++)
			description[i] = "NNN";
		print(description);
	}
	
	public static void random_case(int N)
	{
		String[] description = new String[N];
		String[] opt = {"NNY", "NYN", "NYY", "YNN", "YNY", "YYN", "YYY"};
		for (int i = 0; i < N; i++)
		{
			description[i] = opt[rand.nextInt(7)];
		}
		print(description);
	}
	
	public static void tricky_cases()
	{
		String[] description = {"YNN", "NYN", "NNY"};
		print(description);
		
	}
	
	public static void main(String[] arg)
	{
		rand = new Random();
		
		smallest_cases();
		largest_cases();
		
		tricky_cases();
		
		for (int i = 1; i <= 50; i++)
		{
			random_case(i);
			if (i > 30)
			random_case(i);
		}
	}
}
