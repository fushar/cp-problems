public class EasyHomework
{
	public String determineSign(int[] numbers)
	{
		int zeroes = 0, negatives = 0;
		for (int i = 0; i < numbers.length; i++)
		{
			if (numbers[i] == 0)
				zeroes++;
			else if (numbers[i] < 0)
				negatives++;
		}
		if (zeroes > 0)
			return "ZERO";
		else if (negatives % 2 == 0)
			return "POSITIVE";
		else
			return "NEGATIVE";
	}

	public String checkData(int[] numbers)
	{
		if (numbers.length < 1 || numbers.length > 50)
			return "numbers must contain between 1 and 50 elements, inclusive.";
		for (int i = 0; i < numbers.length; i++)
			if (numbers[i] < -1000000000 || numbers[i] > 1000000000)
				return "Each element of numbers must be between -1,000,000,000 and 1,000,000,000, inclusive.";
		return "";
	}
}