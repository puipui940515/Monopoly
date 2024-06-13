#include<iostream>
#include<string>
#include"Block.h"
using namespace std;

Block::Block() {
	owner = "  ";
	sell = 500;
	defaultToll = 300;
	blockName = "文化大學";
	numOfBuild = 0;
}
void Block::setOwner(string o) {
	owner = o;
}
void Block::setBlockName(string b) {
	blockName = b;
}
void Block::setSell(int s) {
	sell = s;
}
void Block::setNumOfBuild(int n) {
	numOfBuild = n;
}
void Block::addNumOfBuild(int a) {
	numOfBuild += a;
}
void Block::setDefaultToll(int d) {
	defaultToll = d;
}
void Block::setToll() {
	if (numOfBuild == 0) {
		toll = defaultToll;
	}
	if (numOfBuild == 1) {
		toll = defaultToll * 5;
	}
	if (numOfBuild == 2) {
		toll = defaultToll * 5 * 3;
	}
	if (numOfBuild == 3) {
		toll = defaultToll * 5 * 3 * 2;
	}
	if (numOfBuild == 4) {
		toll = defaultToll * 5 * 3 * 2 * 1.5;
	}
	if (numOfBuild == 5) {
		toll = defaultToll * 5 * 3 * 2 * 1.5 * 1.2;
	}
}
// get
string Block::getOwner() {
	return owner;
}
string Block::getBlockName() {
	return blockName;
}
int Block::getSell() {
	return sell;
}
int Block::getNumOfBuild() {
	return numOfBuild;
}
int Block::getDefaultToll() {
	return defaultToll;
}
int Block::getToll() {
	if (numOfBuild == 0) {
		return defaultToll;
	}
	if (numOfBuild == 1) {
		toll = defaultToll * 5;
		return toll;
	}
	if (numOfBuild == 2) {
		toll = defaultToll * 5 * 3;
		return toll;
	}
	if (numOfBuild == 3) {
		toll = defaultToll * 5 * 3 * 2;
		return toll;
	}
	if (numOfBuild == 4) {
		toll = defaultToll * 5 * 3 * 2 * 1.5;
		return toll;
	}
	if (numOfBuild == 5) {
		toll = defaultToll * 5 * 3 * 2 * 1.5 * 1.2;
		return toll;
	}
}



