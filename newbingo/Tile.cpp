#include "Tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

int Tile::getValue()
{
	return value;
}

int Tile::getCheck()
{
	return check;
}

void Tile::setValue(int setting)
{
	value = setting;
}

void Tile::setCheck(int setting)
{
	check = setting;
}
