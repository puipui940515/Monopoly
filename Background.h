#ifndef _BACKGROUND_
#define _BACKGROUND_
#include<string>
using namespace std;

class Background {

public:
    void setMap(Block p[], int size);
    void print(Block p[], int size, Player s[], int size2);

    void buyBlockOrNot(Block p[], int size, Player s[], int num);
    void buildHouseOrNot(Block p[], int size, Player s[], int num);
    void payToll(Block p[], int size, Player s[], int num);

    bool nomoney(Player s[], int size);
};

#endif

