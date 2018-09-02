import java.util.Random;

public class TCGen
{
	public static Random rand;
	
	public static void print(int[] points, int[] skills, int luck)
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
		for (int i = 0; i < skills.length; i++)
		{
			if (i > 0)
				System.out.print(", ");
			System.out.print(skills[i]);
		}
		System.out.println("}");
		System.out.println(luck);
	}
	
	
	public static void random_case()
	{
		int[] points = new int[3];
		int[] skills = new int[3];
		
		points[0] = rand.nextInt(300-250+1) + 250;
		points[1] = rand.nextInt(600-450+1) + 450;
		points[2] = rand.nextInt(1100-900+1) + 900;
		
		for (int i = 0; i < 3; i++)
			skills[i] = rand.nextInt(100) + 1;
		
		int luck = rand.nextInt(101);
		print(points, skills, luck);
	}
	
	
	public static void main(String[] arg)
	{
		rand = new Random();
			
		for (int i = 1; i <= 50; i++)
		{
			random_case();
		}
	}
}
