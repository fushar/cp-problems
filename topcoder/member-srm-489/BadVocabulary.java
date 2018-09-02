public class BadVocabulary
{
	public int count(String badPrefix, String badSuffix, String badSubstring, String[] vocabulary)
	{
		int res = 0;
		for (int i = 0; i < vocabulary.length; i++)
		{
			String s = vocabulary[i];
			String mid = "";
			if (s.length() > 1)
				mid = vocabulary[i].substring(1, vocabulary[i].length()-1);
			if (s.startsWith(badPrefix) || s.endsWith(badSuffix) || mid.indexOf(badSubstring) >= 0)
				res++;
		}
		return res;
	}
	
	public String checkData(String bad, String name)
	{
		if (bad.length() < 1 || bad.length() > 50)
			return name + " must contain between 1 and 50 characters, inclusive.";
		for (int i = 0; i < bad.length(); i++)
			if (bad.charAt(i) < 'a' || bad.charAt(i) > 'z')
				return "Each character of " + name + " must be between 'a' and 'z', inclusive.";
		return "";
	}
	public String checkData(String badPrefix, String badSuffix, String badSubstring, String[] vocabulary)
	{
		String s;
		if ((s = checkData(badPrefix, "badPrefix")).length() > 0) return s;
		if ((s = checkData(badSuffix, "badSuffix")).length() > 0) return s;
		if ((s = checkData(badSubstring, "badSubstring")).length() > 0) return s;
		
		for (int i = 0; i < vocabulary.length; i++)
			if ((s = checkData(vocabulary[i], "each element of vocabulary")).length() > 0) return s;
		
		for (int i = 0; i < vocabulary.length; i++)
			for (int j = i+1; j < vocabulary.length; j++)
				if (vocabulary[i].equals(vocabulary[j]))
					return "All elements of vocabulary must be distinct.";
		return "";
	}
}

