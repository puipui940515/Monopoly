#include<iostream>
#include<string>
#include"Block.h"
#include"Player.h"
#include"Background.h"
using namespace std;

int countDigits(int number) {
	string numStr = to_string(number);
	return numStr.length();
}

void printplayerinformation(Player s[],int size) {
	cout << "-----------------" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "-" << s[i].getplayerName() << "���]��: " << s[i].getwealth();
		for (int a = 5 - countDigits(s[i].getwealth()); a > 0; a--) {
			cout << " ";
		}
		cout << "-" << endl;
	}
	cout << "-----------------" << endl;
}

int main() {
	string word;
	int r;
	Block n[36];
	Player s[4];
	Background a;
	s[0].setplayerName("A ");
	s[1].setplayerName("B ");
	s[2].setplayerName("C ");
	s[3].setplayerName("D ");
	a.setMap(n, 36);
	printplayerinformation(s, 4);
	a.print(n, 36, s, 4);
	while (true) {
		for (int i = 0; i < 4; i++) {
			cout << "��J������Y��l" << endl;
			cin >> word;
			cout << "/////////////////////////" << endl;
			cout << "/////////////////////////" << endl;
			r = s[i].getroll();
			cout << s[i].getplayerName() << "��X: " << r << endl;
			cout << "/////////////////////////" << endl;
			cout << "/////////////////////////" << endl;
			s[i].addplace(r);


			a.buildHouseOrNot(n, 36, s, i);
			a.buyBlockOrNot(n, 36, s, i);
			a.payToll(n, 36, s, i);

			printplayerinformation(s, 4);
			a.print(n, 36, s, 4);
			if (a.nomoney(s, 4) == false){
				break;
			}
		}
		if (a.nomoney(s, 4) == false) {
			break;
		}
	}
	
	while (true) {
		cout << "�C���n����" << endl;
		cin >> word;
	}
	

}