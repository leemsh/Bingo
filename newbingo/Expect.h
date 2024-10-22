#pragma once
#include<algorithm>
#include <vector>

using namespace std;
class Expect
{
private:
	int digonal=-1;
	int inversedigonal=-1;
	int horizontal=0;
	int vertical=0;
public:
	int getDigonal();
	int getInvDigonal();
	int getHorizontal();
	int getVertical();
	void setDigonal(int exp);
	void setInvDigonal(int exp);
	void setHorizontal(int exp);
	void setVertical(int exp);

	friend bool operator<(Expect ex, Expect exp);
};

