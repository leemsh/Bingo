#include "Computer.h"



void Computer::setMapSize(int mapsize)
{
	this->mapsize = mapsize;
	map = make_unique<unique_ptr<Tile[]>[]>(mapsize);
	expectedValue = make_unique<unique_ptr<Expect[]>[]>(mapsize);
	for (int i = 0; i < mapsize; i++) {
		map[i] = make_unique<Tile[]>(mapsize);
		expectedValue[i] = make_unique<Expect[]>(mapsize);
	}
}

void Computer::selectValue(int select)
{
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			if (map[i][j].getValue() == select) {
				setMapCheck(i, j, 2);
			}
		}
	}
}

void Computer::selectedValue(int select)
{
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			if (map[i][j].getValue() == select) {
				setMapCheck(i, j, 1);
			}
		}
	}
}

int Computer::getDig(int i, int j)
{
	return expectedValue[i][j].getDigonal();
}

int Computer::getInvDig(int i, int j)
{
	return expectedValue[i][j].getInvDigonal();
}

int Computer::getHor(int i, int j)
{
	return expectedValue[i][j].getHorizontal();
}

int Computer::getVer(int i, int j)
{
	return expectedValue[i][j].getVertical();
}

void Computer::setDig(int i, int j, int exp)
{
	expectedValue[i][j].setDigonal(exp);
}

void Computer::setInvDig(int i, int j, int exp)
{
	expectedValue[i][j].setInvDigonal(exp);
}

void Computer::setHor(int i, int j, int exp)
{
	expectedValue[i][j].setHorizontal(exp);
}

void Computer::setVer(int i, int j, int exp)
{
	expectedValue[i][j].setVertical(exp);
}

void Computer::showMap()
{
	for (int i = 0; i < mapsize; i++) {
		ui.gotoxy(mapsize * 4 + 11, 5 + 2*i);
		for (int j = 0; j < mapsize; j++) {
			cout.width(4);
			if (map[i][j].getCheck() == 0) {
				cout << map[i][j].getValue();
			}
			else if (map[i][j].getCheck() == 1) {
				cout << "¡Û";
			}
			else if (map[i][j].getCheck() == 2) {
				cout << "¡Ü";
			}
		}
	}
}

void Computer::showSecretMap()
{
	for (int i = 0; i < mapsize; i++) {
		ui.gotoxy(mapsize * 4 + 11, 5 + 2 * i);
		for (int j = 0; j < mapsize; j++) {
			cout.width(4);
			if (map[i][j].getCheck() == 0) {
				cout << "??";
			}
			else if (map[i][j].getCheck() == 1) {
				cout << "¡Û";
			}
			else if (map[i][j].getCheck() == 2) {
				cout << "¡Ü";
			}
		}
	}
}

Expect Computer::getExpectedValue(int i, int j)
{
	return expectedValue[i][j];
}

void Computer::showExp()
{
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			cout.width(3);
			cout << expectedValue[i][j].getHorizontal();
		}
		cout << endl;
	}
}

