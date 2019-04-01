#include "GameElements.h"
#include <conio.h>
#include <time.h>

void main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	cursor.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

	SMALL_RECT window;
	window.Top = 0;
	window.Left = 0;
	window.Bottom = WINDOW_HEIGHT;
	window.Right = WINDOW_WIDTH;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &window);

	Field field;
	field.CreateFiled();
	GameStatus Check;
	Move move;
	CollectScore Score;

	Player pacman(1, 1, YellowF, 1);
	pacman.Show();
	Score.ShowScore(pacman, 1, 27);
	Ghost bot(12, 12, RedF, 1);
	bot.Show();
	Ghost bot1(12, 13, PinkF, 1);
	bot1.Show();
	Ghost bot2(12, 14, BlueF, 1);
	bot2.Show();
	Ghost bot3(12, 15, OrangeF, 1);
	bot3.Show();


	int key;
	//game loop
	while (1)
	{
		for (int i = 0; !_kbhit(); i++)
		{
			if (i % 5000 == 0)
			{
				move.move(field, bot, rand() % 4);
				move.move(field, bot1, rand() % 4);
				move.move(field, bot2, rand() % 4);
				move.move(field, bot3, rand() % 4);
				if (Check.CheckDeath(pacman, bot, bot1, bot2, bot3))
				{
					system("cls");
					SetConsoleTextAttribute(h, WhiteF);
					cout << "GAME OVER" << endl;
					Score.ShowScore(pacman, 0, 3);
					cout << endl;
					return;
				}
			}
		}
		key = _getch();
		if (key == 224)
			key = _getch();
		switch (key)
		{
		case 75:
			move.move(field, pacman, 0);
			break;
		case 72:
			move.move(field, pacman, 1);
			break;
		case 77:
			move.move(field, pacman, 2);
			break;
		case 80:
			move.move(field, pacman, 3);
			break;
		}
		Score.Collect(pacman, field, pacman.GetY(), pacman.GetX());
		if (Check.CheckScore(pacman))
		{
			system("cls");
			SetConsoleTextAttribute(h, WhiteF);
			cout << "Congratulations you won =)" << endl;
			Score.ShowScore(pacman, 0, 3);
			cout << endl;
			return;
		}
		Score.ShowScore(pacman, 1, 27);
		if (Check.CheckDeath(pacman, bot, bot1, bot2, bot3))
		{
			system("cls");
			SetConsoleTextAttribute(h, WhiteF);
			cout << "GAME OVER" << endl;
			Score.ShowScore(pacman, 0, 3);
			cout << endl;
			return;
		}

	}
}
