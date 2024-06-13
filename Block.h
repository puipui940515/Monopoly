#ifndef _BLOCH_H_
#define _BLOCH_H_
#include<string>
using namespace std;

class Block {
public:
	Block();
	void setOwner(string);
	void setBlockName(string);
	void setSell(int);
	void setNumOfBuild(int);
	void addNumOfBuild(int);
	void setDefaultToll(int);
	void setToll();
	string getOwner();
	string getBlockName();
	int getSell();
	int getNumOfBuild();
	int getDefaultToll();
	int getToll();
private:
	string owner;
	string blockName;
	int sell;
	int numOfBuild;
	int defaultToll;
	int toll;
};

#endif

