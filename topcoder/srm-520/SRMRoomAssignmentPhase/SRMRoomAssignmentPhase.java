import java.util.*;

public class SRMRoomAssignmentPhase
{
	public int countCompetitors(int[] ratings, int K)
	{
		int me = ratings[0];
		int N = ratings.length;
		Arrays.sort(ratings);
		for (int i = 0; i < N; i++)
			if (ratings[i] == me)
				return (N - i - 1) / K;
		return -1;
	}
	
	
	public String checkData(int[] ratings, int K)
	{
		int N = ratings.length;
		if (N < 1 || N > 50)
			return "ratings must contain between 1 and 50 elements, inclusive.";
		if (K < 1 || K > N)
			return "K must be between 1 and the number of elements of ratings, inclusive.";
		for (int i = 0; i < N; i++)
			if (ratings[i] < 0 || ratings[i] > 1199)
				return "Each element of ratings must be between 0 and 1199, inclusive.";
		
		int[] cnt = new int[1200];
		for (int i = 0; i < N; i++)
		{
			cnt[ratings[i]]++;
			if (cnt[ratings[i]] > 1)
				return "All elements of ratings must be distinct.";
		}
		return "";
	}
	
	public static void main(String[] arg)
	{
		SRMRoomAssignmentPhase lho = new SRMRoomAssignmentPhase();
		int[] ratings = {20, 742, 152, 1106, 854, 524, 594, 683, 992, 803, 209, 432, 1084, 118, 72, 975, 688, 146, 883, 937, 19, 1090, 676, 246}
;
		int K = 5;
		System.out.println(lho.countCompetitors(ratings, K));
	}
}
