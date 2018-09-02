public class PrinceXToastbook
{
	public double eat(int[] prerequisite)
	{
		int N = prerequisite.length;
		double[] fact = new double[N+1];
		fact[0] = 1;
		for (int i = 1; i <= N; i++)
			fact[i] = i * fact[i-1];
			
		double res = 0;
		for (int i = 0; i < N; i++)
		{
			boolean[] seen = new boolean[N+1];
			int cur = i;
			int len = 0;
			while (true)
			{
				len++;
				seen[cur] = true;
				cur = prerequisite[cur];
				if (cur == -1)
				{
					res += 1 / fact[len];
					break;
				}
				else if (seen[cur])
					break;
			}
		}
		return res;
	}
	
	public static void main(String[] args)
	{
		int[] preq = {1, -1, 1};
		PrinceXToastbook o = new PrinceXToastbook();
		System.out.println(o.eat(preq));
	}
}
