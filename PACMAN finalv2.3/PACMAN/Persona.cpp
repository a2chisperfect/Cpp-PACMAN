#include "Persona.h"

Ghost::Ghost(int x, int y, short color, char symb)
{
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	_x = x;
	_y = x;
	_color = color;
	_symb = symb;
}
void Ghost::Show()
{
	SetConsoleTextAttribute(h, _color);
	SetConsoleCursorPosition(h, COORD{ (short)_x, (short)_y });
	cout << (char)_symb;
}

