public class DengklekXScrabble
{
	boolean isVowel(char c)
	{
		return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
	}
	public boolean isValid(String name)
	{
		if (name.length() != 8)
			return false;
		char vowel = '?';
		for (int i = 0; i < 8; i++)
		{
			if (isVowel(name.charAt(i)))
			{
				if (vowel == '!')
					return false;
				if (vowel == '?')
					vowel = name.charAt(i);
				else if (vowel != name.charAt(i))
					return false;
				else
					vowel = '!';
			}
		}
		return true;
	}
	
	public String checkData(String name)
	{
		if (name.length() != 8)
			return "name must contain between 1 and 50 characters, inclusive.";
		for (int i = 0; i < 8; i++)
			if (name.charAt(i) < 'a' || name.charAt(i) > 'z')
				return "Each character of name must be one of 'a'-'z'.";
		return "";
	}
}
