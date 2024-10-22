#include "Expect.h"

int Expect::getDigonal()
{
    return digonal;
}

int Expect::getInvDigonal()
{
    return inversedigonal;
}

int Expect::getHorizontal()
{
    return horizontal;
}

int Expect::getVertical()
{
    return vertical;
}

void Expect::setDigonal(int exp)
{
    digonal = exp;
}

void Expect::setInvDigonal(int exp)
{
    inversedigonal = exp;
}

void Expect::setHorizontal(int exp)
{
    horizontal = exp;
}

void Expect::setVertical(int exp)
{
    vertical = exp;
}

bool operator<(Expect ex, Expect exp)
{
    vector<pair<int, int>> temp1(4);
    temp1[0] = { ex.digonal,1 };
    temp1[1] = { ex.inversedigonal,1 };
    temp1[2] = { ex.horizontal,0 };
    temp1[3] = { ex.vertical,0 };
    vector<pair<int, int>> temp2(4);
    temp2[0] = { exp.digonal,1 };
    temp2[1] = { exp.inversedigonal,1 };
    temp2[2] = { exp.horizontal,0 };
    temp2[3] = { exp.vertical,0 };

    sort(temp1.begin(), temp1.end(), greater<>());
    sort(temp2.begin(), temp2.end(), greater<>());
    return temp1 < temp2;
}
