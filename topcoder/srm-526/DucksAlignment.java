import java.util.*;

public class DucksAlignment
{
	public int minimumTime(String[] grid)
	{
		int N = grid.length, M = grid[0].length();
		int D = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (grid[i].charAt(j) == 'o')
					D++;
		
		int[] rows = new int[D];
		int[] cols = new int[D];
		int d = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (grid[i].charAt(j) == 'o')
					rows[d++] = i;
		d = 0;
		for (int j = 0; j < M; j++)
			for (int i = 0; i < N; i++)
				if (grid[i].charAt(j) == 'o')
					cols[d++] = j;
		
		int res = 999999999;
		int ans = -32434343, ans2 = 12323;
		// horizontally
		for (int row = 0; row < N; row++)
			for (int col = 0; col+D-1 < M; col++)
			{
				int cur = 0;
				for (int i = 0; i < D; i++)
					cur += Math.abs(rows[i] - row);
				for (int i = 0; i < D; i++)
					cur += Math.abs(cols[i] - (col+i));
				if (cur < res) {res = cur; ans = row; ans2 = col;}
			}
		
		// vertically
		for (int col = 0; col < M; col++)
			for (int row = 0; row+D-1 < N; row++)
			{
				int cur = 0;
				for (int i = 0; i < D; i++)
					cur += Math.abs(cols[i] - col);
				for (int i = 0; i < D; i++)
					cur += Math.abs(rows[i] - (row+i));
				res = Math.min(res, cur);
				if (cur < res) {res = cur; ans = -row; ans2 = -col;}
			}
		System.out.println(ans + " : " + ans2);
		return res;
	}
	
	public String checkData(String[] grid)
	{
		if (grid.length < 1 || grid.length > 50)
			return "grid must contain between 1 and 50 elements, inclusive.";
		if (grid[0].length() < 1 || grid[0].length() > 50)
			return "Each element of grid must contain between 1 and 59 characters, inclusive.";
		int N = grid.length, M = grid[0].length();
		for (int i = 0; i < N; i++)
			if (grid[i].length() != M)
				return "All elements of grid must have the same number of characters.";
		
		int[] rows = new int[N];
		int[] cols = new int[M];
		int total = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				char c = grid[i].charAt(j);
				if (c != 'o' && c != '.')
					return "Each character in grid must be either 'o' or '.'";
				if (c == 'o')
				{
					total++;
					rows[i]++;
					cols[j]++;
					if (rows[i] > 1)
						return "Each row in grid must contain at most one character 'o'.";
					if (cols[j] > 1)
						return "Each column in grid must contain at most one character 'o'.";
				}
			}
		if (total == 0)
			return "grid must contain at least one character 'o'.";
		return "";
	}
	public static void main(String[] args)
	{
		String[] grid = {"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."};
		DucksAlignment obj = new DucksAlignment();
		for (int i = 0; i < 10; i++)
			obj.lho();
		//System.out.println(obj.minimumTime(grid));
	}
	
	public void lho()
	{
		Random o = new Random();
		int N = o.nextInt(50)+1;
		int M = o.nextInt(50)+1;
		
		char[][] grid = new char[N][M];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				grid[i][j] = '.';
		
		ArrayList<Integer> cols = new ArrayList<Integer>();
		for (int i = 0; i < M; i++)
			cols.add(i);
		
		for (int i = 0; i < N; i++)
		{
			if (o.nextInt(2) == 1 && !cols.isEmpty())
			{
				int j = o.nextInt(cols.size());
				grid[i][cols.get(j)] = 'o';
				cols.remove(j);
			}
		}
		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				System.out.print(grid[i][j]);
			System.out.println();
		}*/
		
		System.out.print("{");
		for (int i = 0; i < N; i++)
		{
			if (i > 0) System.out.print(", ");
			System.out.print("\"");
			for (int j = 0; j < M; j++)
				System.out.print(grid[i][j]);
			System.out.print("\"");
		}
		System.out.println("}");
	}
}
