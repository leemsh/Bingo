#pragma once
#include "Player.h"
#include "Computer.h"
#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include "ConsoleUI.h"
using namespace std;
class ShLeemGame
{
private:
	ConsoleUI ui;
	Player human;
	Computer computer;
	int turn = 0;
	vector<int> history;
public:
	void setSize(int gamesize);
	void setTurn(int tempturn);
	void showGameMap();
	void showReplayMap();
	void newGame();
	bool loadGame();
	void play();
	void backup();
	bool gameplay();
	void selectByPlayer(int select);
	void selectByComputer(int select);
	void selectReplayPlayer(int select);
	void selectReplayComputer(int select);
	bool checkVictory();
	void replay();
	void upgradeweekAI();
	void setExpectMap();
	int findBestNum();
};

// 능지부분, 각 라인을 따서 각 라인별 이뤄진 개수 파악 후 

