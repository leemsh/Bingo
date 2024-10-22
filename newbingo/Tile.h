#pragma once
class Tile
{
private:
	int value = 0;
	int check = 0;
public:
	Tile();
	~Tile();
	int getValue();
	int getCheck();
	void setValue(int setting);
	void setCheck(int setting);
};

