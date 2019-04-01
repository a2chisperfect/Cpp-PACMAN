#include "Field.h"

void Wall::Show()
{
	cout << char(219);
}
void Passage::Show()
{
	cout << char(32);
}
void Item::Show()
{
	cout << char(46);
}

bool Wall::GetPassability()
{
	return _pass;
};

bool Passage::GetPassability()
{
	return _pass;
};
bool Item::GetPassability()
{
	return _pass;
};

void Field::CreateFiled()
{
	char levelMap[LEVEL_HEIGHT][LEVEL_WIDTH + 1] = {
		"0000000000000000000000000000",
		"0 *************************0",
		"0*0000*00000*00*00000*0000*0",
		"0**************************0",
		"0*0000*00000*00*00000*0000*0",
		"0**************************0",
		"0*0000*00000*00*00000*0000*0",
		"0**************************0",
		"000000*00000*00*00000*000000",
		"     0 00**********00 0     ",
		"     0 00 000  000 00 0     ",
		"     0 00 0      0 00 0     ",
		"     0                0     ",
		"     0 00 0      0 00 0     ",
		"     0 00 000  000 00 0     ",
		"     0 00**********00 0     ",
		"000000*00000*00*00000*000000",
		"0**************************0",
		"0*0000*00000*00*00000*0000*0",
		"0**************************0",
		"0*0000*00000*00*00000*0000*0",
		"0**************************0", 
		"0*0000*00000*00*00000*0000*0",
		"0**************************0",
		"0000000000000000000000000000", };
		
	map = new IBlock**[LEVEL_HEIGHT];

	for (size_t i = 0; i < LEVEL_HEIGHT; i++)
	{
		map[i] = new IBlock*[LEVEL_WIDTH];
	}
	for (int i = 0; i < LEVEL_HEIGHT; i++)
	{
		for (int j = 0; j < LEVEL_WIDTH; j++)
		{
			switch (levelMap[i][j])
			{
			case '0':
				map[i][j] = new Wall;
				break;
			case' ':
				map[i][j] = new Passage;
				break;
			case '*':
				map[i][j] = new Item;
				break;

			}
			map[i][j]->Show();
		}
		cout << endl;
	}
}

void Field::ChangeBlockToPass(int x, int y)
{
	delete map[x][y];
	map[x][y] = new Passage;
}

Field::~Field()
{
	for (int i = 0; i < LEVEL_HEIGHT; i++)
	{
		delete map[i];
	}
	delete[]map;
}
