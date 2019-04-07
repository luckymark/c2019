

const int inputSize = 100;
const int mapSize = 9;
int mapData[mapSize][mapSize] = {};
const char elementChar[] = " xO#?*!";

#define nothingValue	0	//' '
#define youValue		1	//'x'
#define boxValue		2	//'O'
#define wallValue		3	//'#'
#define destValue		4	//'?'
#define destYouValue	5	//'*'
#define destBoxValue	6	//'!'
//dest: value >= 4
//you : value % dest == you

struct point {
	int column;
	int row;

	point(int c = 0, int r = 0)
	{
		column = c;
		row = r;
	}

	bool isValid()
	{
		return
			column >= 0 &&
			column < mapSize &&
			row >= 0 &&
			row < mapSize;
	}

	//Please guarantee the validity of the point
	int & intValue()
	{
		return mapData[column][row];
	}

	char charValue()
	{
		return elementChar[mapData[column][row]];

	}

	point operator + (const point &b)
	{
		return point{ this->column + b.column, this->row + b.row };
	}

	bool operator == (const point &b)
	{
		return (this->column == b.column && this->row == b.row);
	}

};

point you, exi, dire;

bool moveStep();

const point dire_up = { -1, 0 },
dire_down = { 1, 0 },
dire_left = { 0, -1 },
dire_right = { 0, 1 };

int unfinished = 0;