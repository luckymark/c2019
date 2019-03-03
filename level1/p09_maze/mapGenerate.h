void dfs(int x, int y)
{
	G[x][y] = ROAD;
	vis[x][y] = 1;

	int rec[4][2];
	for (int s = 0; s < 4; s++)
	{
		rec[s][0] = rand();
		rec[s][1] = s;
	}
	for (int s = 0; s < 4; s++)
	{
		for (int t = s; t < 4; t++)
		{
			if (rec[s][0] > rec[t][0])
			{
				std::swap(rec[s][0], rec[t][0]);
				std::swap(rec[s][1], rec[t][1]);
			}
		}
	}
	for (int s = 0; s < 4; s++)
	{
		int dx = DX[rec[s][1]];
		int dy = DY[rec[s][1]];
		int nextX = x + dx * 2;
		int nextY = y + dy * 2;
		if (nextX < 0 || nextY < 0 || nextX >= W || nextY >= H) continue;
		if (vis[nextX][nextY]) continue;
		G[x + dx][y + dy] = ROAD;
		dfs(nextX, nextY);
	}
}

void generateMap()
{
	clear();
	drawSquare(0, 0, H-1, W-1, WALL);
	dfs(1, 1);
}
