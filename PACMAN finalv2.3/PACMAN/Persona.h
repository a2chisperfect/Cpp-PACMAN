#pragma once
#include "Constants.h"

class IScore // интерфейс для сбора очков
{
public:
	virtual int GetScore() = 0;
	virtual void SetScore(int score) = 0;
};

class IPersona
{
public:
	virtual void Show()=0;
	virtual void SetX(int x) = 0;
	virtual void SetY(int y) = 0;
	virtual int GetX() = 0;
	virtual int GetY() = 0;
};

class Ghost : public IPersona// Персонаж
{
	HANDLE h;
	int _x,_y;
	short _color;
	char _symb;
public:
	Ghost(int x, int y, short color, char symb);
	virtual void Show();
	virtual void SetX(int x){ _x = x; }
	virtual void SetY(int y){ _y = y; }
	virtual int GetX(){ return _x; }
	virtual int GetY(){ return _y; }
};

class Player :public Ghost, public IScore // Прсонаж реализующий интерфейс IScore
{
	int _score;
public:
	Player(int x, int y, short color, char symb) :Ghost(x, y, color, symb){ _score = 0; }
	virtual int GetScore(){ return _score; };
	virtual void SetScore(int score){ _score = score; }
};



