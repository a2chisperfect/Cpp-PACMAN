#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;


//������� ����
const int LEVEL_HEIGHT = 25;
const int LEVEL_WIDTH = 28;
//������� ���� �������
const int WINDOW_HEIGHT = 30;
const int WINDOW_WIDTH = 28;

#define MAX_SCORE 271

enum Colors
{
	WhiteF = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY,
	YellowF = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY,
	RedF = FOREGROUND_RED | FOREGROUND_INTENSITY,
	PinkF = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	BlueF = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	OrangeF = FOREGROUND_GREEN | FOREGROUND_RED
};
