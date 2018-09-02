public class SRMCodingPhase
{
	public int countScore(int[] points, int[] skills, int luck)
	{
		int best = 0;
		
		for (int a = 0; a < skills[0] && a <= luck; a++)
		for (int b = 0; b < skills[1] && a + b <= luck; b++)
		for (int c = 0; c < skills[2] && a + b + c <= luck; c++)
		{
			int t[] = {skills[0]-a, skills[1]-b, skills[2]-c};
			int c[] = {2, 4, 8};
			
			for (int mask = 0; mask < 1<<3; mask++)
			{
				int totalTime = 0, totalScore = 0;
				for (int i = 0; i < 3; i++)
					if ((mask & (1<<i)) > 0)
					{
						totalTime += t[i];
						totalScore += points[i] - c[i]*t[i];
					}
				if (totalTime <= 75)
					best = Math.max(best, totalScore);
			}
		}
		return best;
	}
	
	public String checkData(int[] points, int[] skills, int luck)
	{
		if (points.length != 3)
			return "points must contain exactly 3 elements.";
		if (points[0] < 250 || points[0] > 300)
			return "points[0] must be between 250 and 300, inclusive.";
		if (points[1] < 450 || points[1] > 600)
			return "points[1] must be between 450 and 600, inclusive.";
		if (points[2] < 900 || points[2] > 1100)
			return "points[2] must be between 900 and 1100, inclusive.";
		
		if (skills.length != 3)
			return "skills must contain exactly 3 elements.";
		for (int i = 0; i < 3; i++)
			if (skills[i] < 1 || skills[i] > 100)
				return "Each element of skills must be between 1 and 100, inclusive.";
		if (luck < 0 || luck > 100)
			return "luck must be between 0 and 100, inclusive.";
		return "";
	}
	
	public static void main(String[] ar)
	{
		SRMCodingPhase lho = new SRMCodingPhase();
		int[] points = {250, 450, 1100};
		int[] skills = {50, 70, 90};
		int luck = 20;
		System.out.println(lho.countScore(points, skills, luck));
	}
}
