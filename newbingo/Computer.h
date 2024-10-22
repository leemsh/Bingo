#pragma once
#include "Player.h"
#include "Expect.h"
#include <vector>
class Computer :
    public Player
{
private:
    unique_ptr<unique_ptr<Expect[]>[]> expectedValue;
public:
    void setMapSize(int mapsize);
    void selectValue(int select);
    void selectedValue(int select);
    int getDig(int i, int j);
    int getInvDig(int i, int j);
    int getHor(int i, int j);
    int getVer(int i, int j);
    void setDig(int i, int j, int exp);
    void setInvDig(int i, int j, int exp);
    void setHor(int i, int j, int exp);
    void setVer(int i, int j, int exp);
    void showMap();
    void showSecretMap();
    Expect getExpectedValue(int i, int j);
    void showExp();
    friend class Player;
};

