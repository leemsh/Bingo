#pragma once
#include <iostream>
#include <memory>
#include "Tile.h"
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "ConsoleUI.h"
using namespace std;
class Player
{
private:
	ConsoleUI ui;
	int mapsize;
	int turn = 0;
	unique_ptr<unique_ptr<Tile[]>[]> map;
public:
	Player();
	~Player();
	int getMapSize();
	int getMapValue(int i, int j);
	int getMapCheck(int i, int j);
	virtual void setMapSize(int mapsize);
	void initMapCheck();
	void setRandomMap();
	void setMapValue(int i, int j, int setting);
	void setMapCheck(int i, int j, int setting);
	virtual void showMap();
	virtual void selectValue(int select);
	virtual void selectedValue(int select);
	int getCheckByValue(int value);

	friend class Computer;
};

