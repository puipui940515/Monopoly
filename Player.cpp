#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include"Player.h"
using namespace std;

Player::Player() {
	playerName = "A ";
	wealth = 20000;
	place = 0;
}
void Player::setplayerName(string str) {
	playerName = str;
}
string Player::getplayerName() {
	return playerName;
}
int Player::getwealth() {
	return wealth;
}
void Player::setwealth(int num) {
	wealth = num;
}
void Player::addwealth(int num) {
	wealth += num;
}
int Player::getroll() {
	srand(time(NULL));
	return (rand() % 6) + 1;
}
void Player::setplace(int p) {
	place = p;
}
void Player::addplace(int r) {
	place += r;
	if (place > 35) {
		place -= 36;
		if (place == 0) {
			cout << "��n�b�_�I�L�k��o2000�� Q_Q" << endl;
		}
		else {
			cout << "�q�L�_�I��o2000�� >_<" << endl;
			addwealth(2000);
		}
	}
}
int Player::getplace() {                 /// place �� Block
	if (place >= 0 && place <= 9) {
		return (35 - place);
	}
	else if (place >= 18 && place <= 27) {
		return (place - 18);
	}
	else if (place >= 10 && place <= 17) {
		return  (10 + (17 - place) * 2);
	}
	else if (place >= 28 && place <= 35) {
		return  (11 + (place - 28) * 2);
	}
	else {
		return 0;
	}
}

int Player::getrealplace() {
	return place;
}
