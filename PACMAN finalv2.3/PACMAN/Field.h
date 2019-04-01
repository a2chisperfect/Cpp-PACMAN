#pragma once
#include "Constants.h"

class IBlock
{
public:
	virtual void Show() =0;
	virtual bool GetPassability()=0;
};

class Wall : public IBlock
{
	bool _pass;
public:
	Wall(){ _pass = false; }
	virtual void Show();
	virtual bool GetPassability();
};

class Passage : public IBlock
{
	bool _pass;
public:
	Passage(){ _pass = true; }
	virtual void Show();
	virtual bool GetPassability();
};

class Item : public IBlock
{
	bool _pass;
public:
	Item() { _pass = true; }
	virtual void Show();
	virtual bool GetPassability();
};

class Field
{
	IBlock *** map;

public:
	void CreateFiled();
	IBlock* GetBlock(int x, int y){ return map[x][y]; }
	void ChangeBlockToPass(int x, int y);
	~Field();
};