#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

class ConsoleUI
{
private:
	int x = 0;
	int y = 0;
public:
	void setCursorView(bool visible);
	void gotoxy(int x, int y);
	int MenuCtrl(int min, int max);
	int SizeCtrl(int min, int max);
	void showSelectMenu(int menupointer);
	void showTitle();
	void showMyName();
	void showSelectSize(int sizepointer);
	void showLoading();
	void showSaveSuccess();
	void makeRectangle(int gamesize);
	int selectCursorCtrl(int gamesize);
	void showSelectCursor(int x, int y);
	void eraseSelectCursor(int x, int y);
	void showReplayTitle(int gamesize);
	void showWinTitle(int gamesize);
	void showLoseTitle(int gamesize);
	void showDrawTitle(int gamesize);
	void showQuitTitle();
	void showCount(int sec, int gamesize);
	void showLoadFail();
	void showAlreadyChoose(int gamesize);
	void eraseAlreadyChoose(int gamesize);
	void showQuitbutton(int gamesize);
	void showQuitCursor(int gamesize);
	void eraseQuitCursor(int gamesize);
	void showGuid(int gamesize);
};

