import java.util.*;

public class CheatingQuiz
{
	public int[] howMany(String answers)
	{
		int N = answers.length();
		int[] num = new int[3];
		for (int i = 0; i < N; i++)
			num[answers.charAt(i) - 'A']++;
		int[] res = new int[N];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 3; j++)
				if (num[j] > 0)
					res[i]++;
			num[answers.charAt(i) - 'A']--;
		}
		return res;
	}
	
	public String checkData(String answers)
	{
		if (answers.length() < 1 || answers.length() > 50)
			return "answers must contain between 1 and 50 characters, inclusive.";
		for (int i = 0; i < answers.length(); i++)
		{
			char c = answers.charAt(i);
			if (c != 'A' && c != 'B' && c != 'C')
				return "Each character of answers must be 'A', 'B', or 'C'.";
		}
		return "";
	}
	
	public static void main(String[] arg)
	{
		Random o = new Random();
		for (int i = 0; i < 20; i++)
		{
			int N = 50;
			System.out.print("\"");
			for (int j = 0; j < N; j++)
			{
				int c = o.nextInt(3);
				char[] lho = {'A', 'B', 'C'};
				System.out.print(lho[c]);
			}
			System.out.println("\"");
		}
	}
}
