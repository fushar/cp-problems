import java.util.Random;

public class TCGen
{
	public static Random rand;
	
	public static void print(int[] points, String[] description)
	{
		System.out.print("{");
		for (int i = 0; i < points.length; i++)
		{
			if (i > 0)
				System.out.print(", ");
			System.out.print(points[i]);
		}
		System.out.println("}");
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
		print(new int[]{25000, 45000, 90000}, new String[]{"YYY"});
		print(new int[]{30000, 60000, 110000}, new String[]{"NNN"});
	}
	
	public static void largest_cases()
	{
		String[] description = new String[20];
		for (int i = 0; i < 20; i++)
			description[i] = "YYY";
		print(new int[]{30000, 60000, 110000}, description);
		for (int i = 0; i < 20; i++)
			description[i] = "NNN";
		print(new int[]{30000, 60000, 110000}, description);
	}
	
	public static void random_case(int N)
	{
		String[] description = new String[N];
		for (int i = 0; i < N; i++)
		{
			description[i] = "";
			for (int j = 0; j < 3; j++)
			{
				int r = rand.nextInt() % 2;
				if (r == 0)
					description[i] += "N";
				else
					description[i] += "Y";
			}
		}
		
		int[] points = new int[3];
		points[0] = rand.nextInt(30000-25000+1) + 25000;
		points[1] = rand.nextInt(60000-45000+1) + 45000;
		points[2] = rand.nextInt(110000-90000+1) + 90000;
		
		print(points, description);
	}
	
	public static void tricky_cases()
	{
		
	}
	
	public static void main(String[] arg)
	{
		rand = new Random();
		
		smallest_cases();
		largest_cases();
		
		tricky_cases();
		
		for (int i = 1; i <= 20; i++)
		{
			random_case(i);
			//random_case(i);
		}
	}
}
