#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

int Player::getMapSize()
{
	return mapsize;
}

int Player::getMapValue(int i, int j)
{
	return map[i][j].getValue();
}

int Player::getMapCheck(int i, int j)
{
	return map[i][j].getCheck();
}

void Player::setMapSize(int mapsize)
{
	this->mapsize = mapsize;
	map = make_unique<unique_ptr<Tile[]>[]>(mapsize);
	for (int i = 0; i < mapsize; i++) {
		map[i] = make_unique<Tile[]>(mapsize);
	}
}

void Player::initMapCheck()
{
	for (int i = 0; i < getMapSize(); i++) {
		for (int j = 0; j < getMapSize(); j++) {
			map[i][j].setCheck(0);
		}
	}
	turn = 0;
}

void Player::setRandomMap()
{
	srand((unsigned int)time(NULL));
	int randomvalue = 1;
	for (int i = 0; i < getMapSize(); i++) {
		for (int j = 0; j < getMapSize(); j++) {
			while (true) {
				int randomcolpos = rand() % getMapSize();
				int randomrawpos = rand() % getMapSize();
				if (getMapValue(randomcolpos, randomrawpos) == 0) {
					setMapValue(randomcolpos, randomrawpos, randomvalue++);
					break;
				}
			}
		}
	}
}

void Player::setMapValue(int i, int j, int setting)
{
	map[i][j].setValue(setting);
}

void Player::setMapCheck(int i, int j, int setting)
{
	map[i][j].setCheck(setting);
}

void Player::showMap()
{
	for (int i = 0; i < mapsize; i++) {
		ui.gotoxy(6, 5 + 2 * i);
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

void Player::selectValue(int select)
{
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			if (map[i][j].getValue() == select) {
				setMapCheck(i, j, 1);
			}
		}
	}
}

void Player::selectedValue(int select)
{
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			if (map[i][j].getValue() == select) {
				setMapCheck(i, j, 2);
			}
		}
	}
}

int Player::getCheckByValue(int value)
{
	for (int i = 0; i < getMapSize(); i++) {
		for (int j = 0; j < getMapSize(); j++) {
			if (map[i][j].getValue() == value)
				return map[i][j].getCheck();
		}
	}
}
