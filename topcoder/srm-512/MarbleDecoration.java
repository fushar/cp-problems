import java.util.*;

public class MarbleDecoration
{
	public int maximumLength(int R, int G, int B)
	{
		int[] marbles = new int[] {R, G, B};
		Arrays.sort(marbles);
		int res = 2 * marbles[1];
		if (marbles[1] < marbles[2])
			res++;
		return res;
	}
	
	public String checkData(int R, int G, int B)
	{
		if (R < 0 || R > 50)
			return "R must be between 0 and 50, inclusive.";
		if (G < 0 || G > 50)
			return "G must be between 0 and 50, inclusive.";
		if (B < 0 || B > 50)
			return "B must be between 0 and 50, inclusive.";
		return "";
	}
}
