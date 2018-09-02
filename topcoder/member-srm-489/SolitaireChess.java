public class SolitaireChess
{
	private static final int INF = 99999999;
	private static final int[] DX = {-2, -1, 1, 2, 2, 1, -1, -2};
	private static final int[] DY = {1, 2, 2, 1, -1, -2, -2, -1};
	private int[] N;
	private int[][] posX, posY;
	private char[][] type;
	private int[][][][] dist;
	private int[][] cost;
	private int[] dp;
	
	private void parse(int id, String[] board)
	{
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (board[i].charAt(j) != '.')
				{
					type[id][N[id]] = board[i].charAt(j);
					posX[id][N[id]] = i;
					posY[id][N[id]] = j;
					N[id]++;
				}
	}
	
	private void bfs(int x0, int y0)
	{
		int[] queue = new int[8*8*3];
		int qf = 0, qb = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				dist[x0][y0][i][j] = -1;
		
		dist[x0][y0][x0][y0] = 0;
		queue[qb++] = x0;
		queue[qb++] = y0;
		
		while (qf < qb)
		{
			int x = queue[qf++];
			int y = queue[qf++];
			
			for (int i = 0; i < 8; i++)
			{
				int nx = x+DX[i], ny = y+DY[i];
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
					if (dist[x0][y0][nx][ny] == -1)
					{
						dist[x0][y0][nx][ny] = dist[x0][y0][x][y]+1;
						queue[qb++] = nx;
						queue[qb++] = ny;
					}
			}
		}
	}
	
	public int transform(String[] board1, String[] board2)
	{
		N = new int[2];
		posX = new int[2][20];
		posY = new int[2][20];
		type = new char[2][20];
		dist = new int[8][8][8][8];
		cost = new int[20][20];
		
		parse(0, board1);
		parse(1, board2);
		
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				bfs(i, j);
		
		if (N[0] != N[1])
			return -1;
		
		int n = N[0];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (type[0][i] == 'N' && type[1][j] == 'N')
					cost[i][j] = dist[posX[0][i]][posY[0][i]][posX[1][j]][posY[1][j]];
				else if (type[0][i] == 'P' && type[1][j] == 'P' && posX[0][i] >= posX[1][j] && posY[0][i]==posY[1][j])
					cost[i][j] = posX[0][i]-posX[1][j];
				else if (type[0][i] == 'P' && type[1][j] == 'N')
					cost[i][j] = posX[0][i]+dist[0][posY[0][i]][posX[1][j]][posY[1][j]];
				else
					cost[i][j] = -1;
		dp = new int[1<<n];
		
		for (int mask = 1; mask < (1<<n); mask++)
		{
			int i = n-Integer.bitCount(mask);
			dp[mask] = INF;
			
			for (int j = 0; j < n; j++)
				if ((mask & (1<<j)) > 0 && cost[i][j] != -1)
					dp[mask] = Math.min(dp[mask], cost[i][j] + dp[mask & ~(1<<j)]);
		}
		if (dp[(1<<n)-1] != INF)
			return dp[(1<<n)-1];
		return -1;
	}
	
	private String checkData(String[] board, String name)
	{
		if (board.length != 8)
			return name + " must contain exactly 8 elements.";
		for (int i = 0; i < 8; i++)
			if (board[i].length() != 8)
				return "Each element of " + name + " must contain exactly 8 characters.";
		int pieces = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (board[i].charAt(j) != 'P' && board[i].charAt(j) != 'N' && board[i].charAt(j) != '.')
					return "Each character in " + name + " must be one of '.', 'P', and 'N'.";
				else if (board[i].charAt(j) != '.')
					pieces++;
		if (pieces > 20)
			return name + " must contain at most 20 pieces.";
		for (int j = 0; j < 8; j++)
			if (board[0].charAt(j) == 'P')
				return "Element 0 of " + name + " must not contain the character 'P'.";
		return "";
	}
	public String checkData(String[] board1, String[] board2)
	{
		String b1 = checkData(board1, "board1");
		String b2 = checkData(board2, "board2");
		if (!b1.equals(""))
			return b1;
		if (!b2.equals(""))
			return b2;
		return "";
	}
}

