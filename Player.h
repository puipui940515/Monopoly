#ifndef _PLAYER_H_
#define _PLAYER_H_
#include<string>
using namespace std;

class Player {
public:
	Player();
	void setplayerName(string);
	string getplayerName();

	int getwealth();
	void setwealth(int);
	void addwealth(int);

	int getroll();

	void setplace(int);
	void addplace(int n);
	int getplace();

	int getrealplace();

private:
	string playerName;

	int wealth;
	int place;
};

#endif


