#include "ShleemGame.h"

void ShLeemGame::setSize(int gamesize)
{
	human.setMapSize(gamesize);
	computer.setMapSize(gamesize);
}

void ShLeemGame::showGameMap()
{
	ui.makeRectangle(human.getMapSize());
	human.showMap();
	computer.showSecretMap();
}

void ShLeemGame::showReplayMap()
{
	ui.makeRectangle(human.getMapSize());
	human.showMap();
	computer.showMap();
}

void ShLeemGame::newGame()
{
	human.initMapCheck();
	computer.initMapCheck();
	turn = 0;
	human.setRandomMap();
	ui.showLoading();
	computer.setRandomMap();
}

void ShLeemGame::setTurn(int tempturn)
{
	turn = tempturn;
}

bool ShLeemGame::loadGame()
{
	ifstream fin("backupdata.txt");
	if (!fin.is_open()) {
		cerr << "File Access Fail....\n";
	}
	int size;
	fin >> size;

	if (!(size >= 3 && size <= 9)) {
		newGame();
		return false;
	}

	human.setMapSize(size);
	computer.setMapSize(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int mapvalue;
			fin >> mapvalue;
			human.setMapValue(i,j,mapvalue);
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int mapcheck;
			fin >> mapcheck;
			human.setMapCheck(i, j, mapcheck);
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int mapvalue;
			fin >> mapvalue;
			computer.setMapValue(i, j, mapvalue);
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int mapcheck;
			fin >> mapcheck;
			computer.setMapCheck(i, j, mapcheck);
		}
	}
	int tempturn;
	fin >> tempturn;
	setTurn(tempturn);
	
	history.clear();
	for (int i = 0; i < tempturn; i++) {
		int temphistory;
		fin >> temphistory;
		history.push_back(temphistory);
	}

	ui.showLoading();
	return true;
}

void ShLeemGame::play()
{

	int menuinput = 1;
	while (menuinput != 3) {
		while (true) {
			system("cls");

			menuinput = ui.MenuCtrl(1, 3);
			if (menuinput == 1) {
				int sizeinput;
				sizeinput = ui.SizeCtrl(3, 9);
				setSize(sizeinput);
				newGame();
				backup();
				bool checkquit = gameplay();
				if (checkquit == false)
					break;
				Sleep(1000);
				showReplayMap();
				Sleep(3000);
				ui.showCount(5, human.getMapSize());
				ui.showLoading();
				ui.showReplayTitle(human.getMapSize());
				human.initMapCheck();
				computer.initMapCheck();
				replay();
				ui.showCount(5, human.getMapSize());
				ui.showLoading();
			}
			else if (menuinput == 2) {

				bool checkload = loadGame();
				if (checkload == false) {
					ui.showLoadFail();
					break;
				}

				bool checkquit = gameplay();
				if (checkquit == false)
					break;

				Sleep(1000);
				showReplayMap();
				Sleep(3000);
				ui.showCount(5, human.getMapSize());
				ui.showLoading();
				ui.showReplayTitle(human.getMapSize());
				human.initMapCheck();
				computer.initMapCheck();
				replay();
				ui.showCount(5, human.getMapSize());
				ui.showLoading();
			}
			else if (menuinput == 3) {
				ui.showQuitTitle();
				break;
			}
		}
	}
}

void ShLeemGame::backup()
{
	ofstream fout("backupdata.txt");
	if (!fout.is_open()) {
		cerr << "File Save Fail...." << endl;
		return;
	}
	fout << human.getMapSize() << endl;
	for (int i = 0; i < human.getMapSize(); i++) {
		for (int j = 0; j < human.getMapSize(); j++) {
			fout.width(3);
			fout << human.getMapValue(i,j);
		}
		fout << endl;
	}
	fout << endl;
	for (int i = 0; i < human.getMapSize(); i++) {
		for (int j = 0; j < human.getMapSize(); j++) {
			fout.width(3);
			fout << human.getMapCheck(i, j);
		}
		fout << endl;
	}
	fout << endl;
	for (int i = 0; i < computer.getMapSize(); i++) {
		for (int j = 0; j < computer.getMapSize(); j++) {
			fout.width(3);
			fout << computer.getMapValue(i, j);
		}
		fout << endl;
	}
	fout << endl;
	for (int i = 0; i < computer.getMapSize(); i++) {
		for (int j = 0; j < computer.getMapSize(); j++) {
			fout.width(3);
			fout << computer.getMapCheck(i, j);
		}
		fout << endl;
	}
	fout << endl;
	fout << turn;
	fout << endl;
	for (int i = 0; i < turn; i++) {
		fout.width(3);
		fout << history[i];
	}
	ui.showSaveSuccess();
}

bool ShLeemGame::gameplay()
{
	showGameMap();
	ui.showMyName();
	if (checkVictory() == true)
		return true;
	int posselect;
	int select;
	while (true) {
		posselect = ui.selectCursorCtrl(human.getMapSize());
		if (posselect == 10000) {
			history.clear();
			return false;
		}
		int posx = posselect / 10;
		int posy = posselect % 10;
		if (human.getMapCheck(posy, posx) == 0) {
			ui.eraseAlreadyChoose(human.getMapSize());
			select = human.getMapValue(posy, posx);
			break;
		}
		ui.showAlreadyChoose(human.getMapSize());
	}
	selectByPlayer(select);
	history.push_back(select);
	turn++;
	backup();
	if (checkVictory() == true)
		return true;

	Sleep(2000);
	system("cls");

	upgradeweekAI();
	backup();
	if (checkVictory() == true)
		return true;
	Sleep(2000);
	system("cls");
	gameplay();
}

void ShLeemGame::selectByPlayer(int select)
{
	human.selectValue(select);
	computer.selectedValue(select);
	showGameMap();
	ui.showMyName();
}

void ShLeemGame::selectByComputer(int select)
{
	computer.selectValue(select);
	human.selectedValue(select);
	showGameMap();
	ui.showMyName();
}

void ShLeemGame::selectReplayPlayer(int select)
{
	human.selectValue(select);
	computer.selectedValue(select);
	ui.showReplayTitle(human.getMapSize());
	showReplayMap();
	ui.showMyName();
}

void ShLeemGame::selectReplayComputer(int select)
{
	computer.selectValue(select);
	human.selectedValue(select);
	ui.showReplayTitle(human.getMapSize());
	showReplayMap();
	ui.showMyName();
}

bool ShLeemGame::checkVictory()
{	
	int humanbingocount = 0;
	int computerbingocount = 0;
	int digonalchecktemp = 0;
	for (int i = 0; i < human.getMapSize(); i++) {
		if (human.getMapCheck(i, i) != 0) {
			digonalchecktemp++;
		}
	}
	if (digonalchecktemp == human.getMapSize()) {
		humanbingocount++;
	}
	digonalchecktemp = 0;
	for (int i = 0; i < human.getMapSize(); i++) {
		if (human.getMapCheck(human.getMapSize() - (i + 1), i) != 0) {
			digonalchecktemp++;
		}
	}
	if (digonalchecktemp == human.getMapSize()) {
		humanbingocount++;
	}
	for (int i = 0; i < human.getMapSize(); i++) {
		int checktemp = 0;
		for (int j = 0; j < human.getMapSize(); j++) {
			if (human.getMapCheck(i, j) != 0) {
				checktemp++;
			}
		}
		if (checktemp == human.getMapSize()) {
			humanbingocount++;
		}
	}
	for (int i = 0; i < human.getMapSize(); i++) {
		int checktemp = 0;
		for (int j = 0; j < human.getMapSize(); j++) {
			if (human.getMapCheck(j, i)!= 0) {
				checktemp++;
			}
		}
		if (checktemp == human.getMapSize()) {
			humanbingocount++;
		}
	}
	digonalchecktemp = 0;
	for (int i = 0; i < computer.getMapSize(); i++) {
		if (computer.getMapCheck(i, i) != 0) {
			digonalchecktemp++;
		}
	}
	if (digonalchecktemp == computer.getMapSize()) {
		computerbingocount++;
	}
	digonalchecktemp = 0;
	for (int i = 0; i < computer.getMapSize(); i++) {
		if (computer.getMapCheck(computer.getMapSize() - (i + 1), i) != 0) {
			digonalchecktemp++;
		}
	}
	if (digonalchecktemp == computer.getMapSize()) {
		computerbingocount++;
	}
	for (int i = 0; i < computer.getMapSize(); i++) {
		int checktemp = 0;
		for (int j = 0; j < computer.getMapSize(); j++) {
			if (computer.getMapCheck(i, j) != 0) {
				checktemp++;
			}
		}
		if (checktemp == computer.getMapSize()) {
			computerbingocount++;
		}
	}
	for (int i = 0; i < computer.getMapSize(); i++) {
		int checktemp = 0;
		for (int j = 0; j < computer.getMapSize(); j++) {
			if (computer.getMapCheck(j, i) != 0) {
				checktemp++;
			}
		}
		if (checktemp == computer.getMapSize()) {
			computerbingocount++;
		}
	}
	if (humanbingocount == 0 && computerbingocount == 0) {
		return false;
	}
	else if (humanbingocount == computerbingocount) {
		if (humanbingocount == (human.getMapSize()*2 + 2)) {
			ui.showDrawTitle(human.getMapSize());
			return true;
		}
		return false;
	}
	else if (humanbingocount > computerbingocount) {
		ui.showWinTitle(human.getMapSize());
		return true;
	}
	else {
		ui.showLoseTitle(human.getMapSize());
		return true;
	}
}

void ShLeemGame::replay()
{
	selectReplayPlayer(history.front());
	history.erase(history.begin());
	if (checkVictory() == true)
		return;

	Sleep(2000);
	system("cls");

	selectReplayComputer(history.front());
	history.erase(history.begin());
	if (checkVictory() == true)
		return;

	Sleep(2000);
	system("cls");

	replay();
}

void ShLeemGame::upgradeweekAI()
{
	setExpectMap();
	int select = findBestNum();
	selectByComputer(select);
	history.push_back(select);
	turn++;
	setExpectMap();
}

void ShLeemGame::setExpectMap()
{
	for (int i = 0; i < computer.getMapSize(); i++) {
		for (int j = 0; j < computer.getMapSize(); j++) {
			int checktemp = 0;
			if (i == j) { //대각선 체크
				for (int ii = 0; ii < computer.getMapSize(); ii++) {
					if (computer.getMapCheck(ii, ii) != 0) {
						checktemp++;
					}
				}
				computer.setDig(i, j, checktemp);
			}
			checktemp = 0;
			if (computer.getMapSize() - (i + 1) == j) { //역 대각선 체크
				for (int ii = 0; ii < computer.getMapSize(); ii++) {
					if (computer.getMapCheck(computer.getMapSize() - (ii + 1), ii) != 0) {
						checktemp++;
					}
				}
				computer.setInvDig(i, j, checktemp);
			}

			//수평 체크
			checktemp = 0;
			for (int ii = 0; ii < computer.getMapSize(); ii++) {
				if (computer.getMapCheck(i, ii) != 0) {
					checktemp++;
				}
			}
			computer.setHor(i, j, checktemp);

			// 수직 체크
			checktemp = 0;
			for (int ii = 0; ii < computer.getMapSize(); ii++) {
				if (computer.getMapCheck(ii, j) != 0) {
					checktemp++;
				}
			}
			computer.setVer(i, j, checktemp);
		}
	}
}

int ShLeemGame::findBestNum()
{
	int besti=0;
	int bestj=0;
	for (int i = 0; i < computer.getMapSize(); i++) {
		for (int j = 0; j < computer.getMapSize(); j++) {
			/*if (i != 0 && j != 0) {
				besti = i;
				bestj = j;
				break;
			}*/
			if (computer.getMapCheck(i, j) == 0) {
				besti = i;
				bestj = j;
				break;
			}
		}
	}
	for (int i = 0; i < computer.getMapSize(); i++) {
		for (int j = 0; j < computer.getMapSize(); j++) {
			if (computer.getMapCheck(i, j) == 0) {
				if (computer.getExpectedValue(besti, bestj) < computer.getExpectedValue(i, j)) {
					besti = i;
					bestj = j;
				}
			}
		}
	}
	return computer.getMapValue(besti,bestj);
}
