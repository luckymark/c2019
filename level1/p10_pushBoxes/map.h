void clearMap()
{
	for (int s = 0; s < H; s++)
	{
		for (int t = 0; t < W; t++)
			G[t][s] = ROAD;
		G[W][s] = '\n';
	}
}

void printMap()
{
	for (int s = 0; s < H; s++)
		for (int t = 0; t < W+1; t++)
			printf("%c", G[t][s]);
}

void loadMap()
{
	clearMap();
	FILE *fp = fopen("maps/map.txt", "r");
	char buf[bufLim];
	fread(buf, 1, bufLim, fp);
	int x = 0, y = 0;
	for (int s = 0; s < bufLim; s++)
	{
		if (buf[s] == WALL) G[x][y] = WALL;
		if (buf[s] == BOX)
		{
			Object tmp;
			tmp.set(x, y, BOX);
			box.push_back(tmp);
			boxTotal++;
		}
		if (buf[s] == TARGET) G[x][y] = TARGET;
		if (buf[s] == PLAYER) player.set(x, y, PLAYER);
		if (buf[s] == '\n')
		{
			x = 0, y++;
			continue;
		}
		if (buf[s] == '!') return;
		x++;
	}
	fclose(fp);
}
