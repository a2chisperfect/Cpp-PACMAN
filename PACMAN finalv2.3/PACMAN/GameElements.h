#pragma once
#include "Field.h"
#include "Persona.h"

class Move // передвежение любых объектов реализуюзих интерфейс Persona
{
	HANDLE h;
	int tmp_x, tmp_y;
public:
	Move();
	void move(Field & obj, IPersona& obj1, int direction);
};

class GameStatus 
{
public:
	bool CheckDeath(IPersona& player, IPersona& obj1, IPersona& obj2, IPersona& obj3, IPersona& obj4);
	bool CheckScore(IScore & obj);
};

class CollectScore // —бор очков
{
	HANDLE h;
public:
	CollectScore();
	void Collect(IScore&obj, Field & field, int x, int y);
	void ShowScore(IScore&obj, int x, int y);
};

