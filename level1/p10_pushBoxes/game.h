void game();

int LoadMap(int n, char Map[][15]);

int StartGame();

void EndGame();

void InitCursor();

void SetPosition(int x, int y);

void PrintSpace(int x, int y);

void PrintX(int x, int y);

void PrintO(int x, int y);

void PrintD(int x, int y);

int LoadGame();

int ScoreBoard();

int Gaming(char Map[][15], int i, bool *back, int level);

void SaveScore(int i, int score);

void Save(int i);