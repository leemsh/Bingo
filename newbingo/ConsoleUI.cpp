#include "ConsoleUI.h"

void ConsoleUI::setCursorView(bool visible)
{
	CONSOLE_CURSOR_INFO cursor = { 1,visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void ConsoleUI::gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int ConsoleUI::MenuCtrl(int min, int max)
{
	setCursorView(false);
	gotoxy(30,10);
	int menupointer = min;
	int keycode = 0;
	while (keycode != 13) {
		showTitle();
		showSelectMenu(menupointer);
		if (_kbhit()) {
			system("cls");
			keycode = _getch();
			if (keycode == 224) {
				keycode = _getch();
				switch (keycode) {
				case 72: 
					if (menupointer == min)
						menupointer = max;
					else
						menupointer--;
					break;
				case 80:
					if (menupointer == max)
						menupointer = min;
					else
						menupointer++;
				}
			}
		}
	}
	return menupointer;
}

int ConsoleUI::SizeCtrl(int min, int max)
{
	setCursorView(false);
	gotoxy(30, 10);
	int menupointer = min;
	int keycode = 0;
	while (keycode != 13) {
		showTitle();
		showSelectSize(menupointer);
		if (_kbhit()) {
			system("cls");
			keycode = _getch();
			if (keycode == 224) {
				keycode = _getch();
				switch (keycode) {
				case 72:
					if (menupointer == max)
						menupointer = min;
					else
						menupointer++;
					break;
				case 80:
					if (menupointer == min)
						menupointer = max;
					else
						menupointer--;
				}
			}
		}
	}
	return menupointer;
}


void ConsoleUI::showSelectMenu(int menupointer)
{
	showMyName();
	if (menupointer == 1) {
		gotoxy(30, 10);
		cout << "     ～     " << endl;
		gotoxy(30, 11);
		cout << "  NEW GAME  " << endl;
		gotoxy(30, 12);
		cout << "     ∪     " << endl;
	}
	else if(menupointer == 2) {
		gotoxy(30, 10);
		cout << "     ～     " << endl;
		gotoxy(30, 11);
		cout << " LOAD  GAME " << endl;
		gotoxy(30, 12);
		cout << "     ∪     " << endl;
	}
	else {
		gotoxy(30, 10);
		cout << "     ～     " << endl;
		gotoxy(30, 11);
		cout << "    EXIT    " << endl;
		gotoxy(30, 12);
		cout << "     ∪     " << endl;
	}
}

void ConsoleUI::showTitle()
{
	gotoxy(11, 3);
	cout << "﹥﹥﹥﹥  ﹥﹥﹥  ﹥      ﹥  ﹥﹥﹥﹥  ﹥﹥﹥﹥";
	gotoxy(11, 4);
	cout << "  ﹥  ﹥    ﹥    ﹥﹥    ﹥  ﹥        ﹥    ﹥";
	gotoxy(11, 5);
	cout << "  ﹥﹥﹥    ﹥    ﹥  ﹥  ﹥  ﹥  ﹥﹥  ﹥    ﹥";
	gotoxy(11, 6);
	cout << "  ﹥  ﹥    ﹥    ﹥    ﹥﹥  ﹥    ﹥  ﹥    ﹥";
	gotoxy(11, 7);
	cout << "﹥﹥﹥﹥  ﹥﹥﹥  ﹥      ﹥  ﹥﹥﹥﹥  ﹥﹥﹥﹥";
}

void ConsoleUI::showMyName()
{
	gotoxy(22, 30);
	cout << "KONKUK UNIV. 201911275 歜鼻⑶";
}

void ConsoleUI::showSelectSize(int sizepointer)
{
	if (sizepointer == 3) {
		gotoxy(30, 10);
		cout << "      ～     " << endl;
		gotoxy(30, 11);
		cout << "   3  X  3   " << endl;
		gotoxy(30, 12);
		cout << "      ∪     " << endl;
	}
	else if (sizepointer == 4) {
		gotoxy(30, 10);
		cout << "      ～     " << endl;
		gotoxy(30, 11);
		cout << "   4  X  4   " << endl;
		gotoxy(30, 12);
		cout << "      ∪     " << endl;
	}
	else if(sizepointer == 5) {
		gotoxy(30, 10);
		cout << "      ～     " << endl;
		gotoxy(30, 11);
		cout << "   5  X  5   " << endl;
		gotoxy(30, 12);
		cout << "      ∪     " << endl;
	}
	else if (sizepointer == 6) {
		gotoxy(30, 10);
		cout << "      ～     " << endl;
		gotoxy(30, 11);
		cout << "   6  X  6   " << endl;
		gotoxy(30, 12);
		cout << "      ∪     " << endl;
	}
	else if (sizepointer == 7) {
		gotoxy(30, 10);
		cout << "      ～     " << endl;
		gotoxy(30, 11);
		cout << "   7  X  7   " << endl;
		gotoxy(30, 12);
		cout << "      ∪     " << endl;
	}
	else if (sizepointer == 8) {
		gotoxy(30, 10);
		cout << "      ～     " << endl;
		gotoxy(30, 11);
		cout << "   8  X  8   " << endl;
		gotoxy(30, 12);
		cout << "      ∪     " << endl;
	}
	else {
		gotoxy(30, 10);
		cout << "      ～     " << endl;
		gotoxy(30, 11);
		cout << "   9  X  9   " << endl;
		gotoxy(30, 12);
		cout << "      ∪     " << endl;
	}
	showMyName();
}

void ConsoleUI::showLoading()
{	
	system("cls");
	gotoxy(25, 10);
	cout << "Loading.... ﹤﹤﹤﹤﹤﹤";
	showMyName();
	Sleep(150);
	system("cls");
	gotoxy(25, 10);
	cout << "Loading.... ﹥﹤﹤﹤﹤﹤";
	showMyName();
	Sleep(150);
	system("cls");
	gotoxy(25, 10);
	cout << "Loading.... ﹥﹥﹤﹤﹤﹤";
	showMyName();
	Sleep(150);
	system("cls");
	gotoxy(25, 10);
	cout << "Loading.... ﹥﹥﹥﹤﹤﹤";
	showMyName();
	Sleep(150);
	system("cls");
	gotoxy(25, 10);
	cout << "Loading.... ﹥﹥﹥﹥﹤﹤";
	showMyName();
	Sleep(150);
	system("cls");
	gotoxy(25, 10);
	cout << "Loading.... ﹥﹥﹥﹥﹥﹤";
	showMyName();
	Sleep(150);
	system("cls");
	gotoxy(25, 10);
	cout << "Loading.... ﹥﹥﹥﹥﹥﹥";
	showMyName();
	Sleep(150);
	system("cls");
}

void ConsoleUI::showSaveSuccess()
{
	gotoxy(26, 28);
	cout << "File Save Successful";
}

void ConsoleUI::makeRectangle(int gamesize)
{
	int x = 4;
	int y = 4;
	
	gotoxy(x, y);
	cout << "忙";
	for (int i = 0; i < gamesize; i++) {
		cout << "式式式式";
	}
	cout << "式";
	cout << "忖";
	y++;
	for (int i = 0; i < 2 * gamesize-1; i++) {
		gotoxy(x, y++);
		cout << "弛";
		for (int i = 0; i < gamesize; i++) {
			cout << "    ";
		}
		cout << " ";
		cout << "弛";
	}
	gotoxy(x, y);
	cout << "戌";
	for (int i = 0; i < gamesize; i++) {
		cout << "式式式式";
	}
	cout << "式";
	cout << "戎";
	gotoxy(x + (gamesize * 4 / 2)-2, y + 1);
	cout << "PLAYER ∞";


	x += gamesize * 4 + 5;
	y = 4;
	
	gotoxy(x, y);
	cout << "忙";
	for (int i = 0; i < gamesize; i++) {
		cout << "式式式式";
	}
	cout << "式";
	cout << "忖";
	y++;
	for (int i = 0; i < 2 * gamesize-1; i++) {
		gotoxy(x, y++);
		cout << "弛";
		for (int i = 0; i < gamesize; i++) {
			cout << "    ";
		}
		cout << " ";
		cout << "弛";
	}
	gotoxy(x, y);
	cout << "戌";
	for (int i = 0; i < gamesize; i++) {
		cout << "式式式式";
	}
	cout << "式";
	cout << "戎";
	gotoxy(x + (gamesize * 4 / 2) - 3, y + 1);
	cout << "COMPUTER ≒";
	showQuitbutton(gamesize);
}

int ConsoleUI::selectCursorCtrl(int gamesize)
{
	int pointerx = 0;
	int pointery = 0;
	showGuid(gamesize);
	showSelectCursor(pointerx, pointery);
	setCursorView(false);
	int keycode = 0;
	while (keycode != 13) {
		if (_kbhit()) {
			keycode = _getch();
			if (keycode == 224) {
				keycode = _getch();
				switch (keycode) {
				case 72:
					if (pointery == gamesize)
						eraseQuitCursor(gamesize);
					else
						eraseSelectCursor(pointerx, pointery);
					if (pointery == 0)
						pointery = gamesize;
					else
						pointery--;
					if (pointery == gamesize)
						showQuitCursor(gamesize);
					else
						showSelectCursor(pointerx, pointery);
					break;
				case 80:
					if (pointery == gamesize)
						eraseQuitCursor(gamesize);
					else
						eraseSelectCursor(pointerx, pointery);
					if (pointery == gamesize)
						pointery = 0;
					else
						pointery++;
					if (pointery == gamesize)
						showQuitCursor(gamesize);
					else
						showSelectCursor(pointerx, pointery);
					break;
				case 77:
					if (pointery != gamesize) {
						eraseSelectCursor(pointerx, pointery);
						if (pointerx == gamesize - 1)
							pointerx = 0;
						else
							pointerx++;
						showSelectCursor(pointerx, pointery);
					}
					break;
				case 75:
					if (pointery != gamesize) {
						eraseSelectCursor(pointerx, pointery);
						if (pointerx == 0)
							pointerx = gamesize - 1;
						else
							pointerx--;
						showSelectCursor(pointerx, pointery);
					}
					break;
				}
			}
		}
	}
	if (pointery == gamesize) {
		return 10000;
	}
	else {
		eraseSelectCursor(pointerx, pointery);
		return pointerx * 10 + pointery;
	}
}

void ConsoleUI::showSelectCursor(int x, int y)
{
	gotoxy(6 + 4 * x, 5 + 2 * y);
	cout << "Ⅱ";
}

void ConsoleUI::eraseSelectCursor(int x, int y)
{
	gotoxy(6 + 4 * x, 5 + 2 * y);
	cout << "  ";
}

void ConsoleUI::showReplayTitle(int gamesize)
{
	gotoxy(3 + 4 * gamesize, 3);
	cout << "REPLAY";
}

void ConsoleUI::showWinTitle(int gamesize)
{
	gotoxy(3 + 4 * gamesize, 8 + 2 * gamesize);
	cout << "YOU WIN";
}

void ConsoleUI::showLoseTitle(int gamesize)
{
	gotoxy(3 + 4 * gamesize, 8 + 2 * gamesize);
	cout << "YOU LOSE";
}

void ConsoleUI::showDrawTitle(int gamesize)
{
	gotoxy(3 + 4 * gamesize, 8 + 2 * gamesize);
	cout << "DRAW GAME";
}

void ConsoleUI::showQuitTitle()
{
	gotoxy(26, 25);
	cout << "QUIT GAME";
}

void ConsoleUI::showCount(int sec, int gamesize)
{
	for (int i = 0; i < sec; i++) {
		gotoxy(4 * gamesize - 3, 9 + 2 * gamesize);
		cout << "REMAIN " << sec - i << " seconds";
		Sleep(1000);
	}
}

void ConsoleUI::showLoadFail()
{
	system("cls");
	gotoxy(4 * 5, 5 + 2 * 5);
	cout << "FAIL TO LOAD GAME";
	gotoxy(2+4 * 5, 7 + 2 * 5);
	cout << "FILE IS EMPTY";
	showCount(5, 6);
	showLoading();
}

void ConsoleUI::showAlreadyChoose(int gamesize)
{
	gotoxy(3 + 4 * gamesize, 7 + 2 * gamesize);
	cout << "ALREADY CHOOSE";
	gotoxy(1 + 4 * gamesize, 8 + 2 * gamesize);
	cout << "PLEASE CHOICE AGAIN";
}

void ConsoleUI::eraseAlreadyChoose(int gamesize)
{
	gotoxy(3 + 4 * gamesize, 7 + 2 * gamesize);
	cout << "              ";
	gotoxy(1 + 4 * gamesize, 8 + 2 * gamesize);
	cout << "                   ";
}

void ConsoleUI::showQuitbutton(int gamesize)
{
	gotoxy(6, 11 + 2 * gamesize);
	cout << "QUIT";
}

void ConsoleUI::showQuitCursor(int gamesize)
{
	gotoxy(4, 11 + 2 * gamesize);
	cout << "Ⅱ";
}

void ConsoleUI::eraseQuitCursor(int gamesize)
{
	gotoxy(4, 11 + 2 * gamesize);
	cout << "  ";
}

void ConsoleUI::showGuid(int gamesize)
{
	gotoxy(24 + 4 * gamesize, 9 + 2 * gamesize);
	cout << "           ∟    ";
	gotoxy(24 + 4 * gamesize, 10 + 2 * gamesize);
	cout << "MOVE : ∠  ⊿  ⊥";
	gotoxy(24 + 4 * gamesize, 11 + 2 * gamesize);
	cout << "CHOOSE : ENTER KEY";
}


