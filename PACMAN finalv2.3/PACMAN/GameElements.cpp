#include "GameElements.h"

Move::Move()
{
	h = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Move::move(Field & obj, IPersona& obj1, int direction)
{
	tmp_x = obj1.GetX();
	tmp_y = obj1.GetY();

	switch (direction)
	{
	case 0://left
		if (obj.GetBlock(tmp_y, tmp_x - 1)->GetPassability())
		{
			obj1.SetX(tmp_x - 1);
		}
		break;
	case 1: // up
		if (obj.GetBlock(tmp_y - 1, tmp_x)->GetPassability())
		{
			obj1.SetY(tmp_y - 1);
		}
		break;
	case 2: // right
		if (obj.GetBlock(tmp_y, tmp_x + 1)->GetPassability())
		{
			obj1.SetX(tmp_x + 1);
		}
		break;
	case 3:// down
		if (obj.GetBlock(tmp_y + 1, tmp_x)->GetPassability())
		{
			obj1.SetY(tmp_y + 1);
		}
		break;
	}
	SetConsoleTextAttribute(h, WhiteF);
	SetConsoleCursorPosition(h, COORD{ (short)tmp_x, (short)tmp_y });
	obj.GetBlock(tmp_y, tmp_x)->Show();
	obj1.Show();
}

bool GameStatus::CheckDeath(IPersona& player, IPersona& obj1, IPersona& obj2, IPersona& obj3, IPersona& obj4)
{
	if (player.GetX() == obj1.GetX() && player.GetY() == obj1.GetY() || player.GetX() == obj2.GetX() && player.GetY() == obj2.GetY() || player.GetX() == obj3.GetX() && player.GetY() == obj3.GetY() || player.GetX() == obj4.GetX() && player.GetY() == obj4.GetY())
	{
		return true;
	}
	return false;
}
bool GameStatus::CheckScore(IScore & obj)
{
	return obj.GetScore() == MAX_SCORE;
}

CollectScore::CollectScore()
{
	h = GetStdHandle(STD_OUTPUT_HANDLE);
}
void CollectScore::Collect(IScore&obj, Field  &field, int x , int y)
{

	if (dynamic_cast <Item *> (field.GetBlock(x, y)))
	{
		obj.SetScore(obj.GetScore() + 1);
		field.ChangeBlockToPass(x, y);
	}
}
void CollectScore :: ShowScore(IScore&obj,int x,int y)
{
	SetConsoleTextAttribute(h, WhiteF);
	SetConsoleCursorPosition(h, COORD{ (short)x, (short)y });
	cout <<"SCORE: " <<obj.GetScore();
}
