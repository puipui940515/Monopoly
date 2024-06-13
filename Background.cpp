#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include"Block.h"
#include"Player.h"
#include"Background.h"

using namespace std;



int numOf(int a) {
	int total = 0;
	if (a == 0) {
		return 1;
	}
	while (a != 0) {
		a = a / 10;
		total++;
	}
	return total;
}

void Background::buyBlockOrNot(Block p[], int size, Player s[], int num) {
	string choose;
	int ran = 0;
	if (p[s[num].getplace()].getBlockName() == "免費停車" or
		p[s[num].getplace()].getBlockName() == "機會" or
		p[s[num].getplace()].getBlockName() == "繳稅" or
		p[s[num].getplace()].getBlockName() == "命運" or 
		p[s[num].getplace()].getBlockName() == "暫停一次" or 
		p[s[num].getplace()].getBlockName() == "所的稅" or
		p[s[num].getplace()].getBlockName() == "起點" ) {

		if (p[s[num].getplace()].getBlockName() == "機會" || p[s[num].getplace()].getBlockName() == "命運") {
			srand(time(NULL));
			ran = (rand() % 5);
			if (ran == 0) {
				cout << "機會：前往起點，並領取2000元" << endl;
				s[num].addwealth(2000);
				s[num].setplace(0);
			}
			if (ran == 1) {
				cout << "機會：銀行出錯，得到1500元" << endl;
				s[num].addwealth(1500);
			}
			if (ran == 2) {
				cout << "機會：支付學費1500元" << endl;
				s[num].addwealth(-1500);
			}
			if (ran == 3) {
				cout << "機會：繼承遺產，領取1000元" << endl;
				s[num].addwealth(1000);
			}
			if (ran == 4) {
				cout << "機會：從銀行中領取股息3000元" << endl;
				s[num].addwealth(3000);
			}
		}
		if (p[s[num].getplace()].getBlockName() == "繳稅") {
			cout << "繳稅3000元" << endl;
			s[num].addwealth(-3000);
		}
		if (p[s[num].getplace()].getBlockName() == "所的稅") {
			cout << "扣除1/10的財產" << endl;
			s[num].setwealth(s[num].getwealth() * 0.9);
		}
		
	}
	else if (p[s[num].getplace()].getOwner() == "00") {
		while (true) {
			cout << "是否購買" << p[s[num].getplace()].getBlockName() << " " << p[s[num].getplace()].getSell() << "(Y/N)" << endl;
			cin >> choose;
			if ((choose == "Y" or choose == "y") && (s[num].getwealth() >= p[s[num].getplace()].getSell())) {
				p[s[num].getplace()].setOwner(s[num].getplayerName());
				s[num].addwealth(-p[s[num].getplace()].getSell());
				cout << "恭喜購買" << endl;
				cout << "剩" << s[num].getwealth() << "元" << endl;
				break;
			}
			else if (choose == "N" or choose == "n") {
				cout << "OK" << endl;
				break;
			}
			else {
				cout << "不明白意思或餘額不足，請重新輸入 Q_Q" << endl;
			}
		}
	}
}
void Background::buildHouseOrNot(Block p[], int size, Player s[], int num) {
	int pay = 500;
	string choose;
	if (s[num].getrealplace() <= 9) {
		pay = 500;
	}
	else if (s[num].getrealplace() <= 18) {
		pay = 1000;
	}
	else if (s[num].getrealplace() <= 27) {
		pay = 1500;
	}
	else if (s[num].getrealplace() <= 36) {
		pay = 2000;
	}

	if (p[s[num].getplace()].getOwner() == s[num].getplayerName()) {
		while (true) {
			if (p[s[num].getplace()].getNumOfBuild() == 5) {
				cout << "已到達最高建築數量 Q_Q";
			}
			else {
				cout << "已有 " << p[s[num].getplace()].getNumOfBuild() << " 棟 是否花 " << pay << "蓋房子 ? (Y/N)" << endl;
				cin >> choose;
				if ((choose == "Y" or choose == "y") && (s[num].getwealth() >= pay)) {
					p[s[num].getplace()].addNumOfBuild(1);
					s[num].addwealth(-pay);
					cout << "恭喜蓋房" << endl;
					cout << "剩" << s[num].getwealth() << "元" << endl;
					break;
				}
				else if (choose == "N" or choose == "n") {
					cout << "OK" << endl;
					break;
				}
				else {
					cout << "不明白意思或餘額不足，請重新輸入 Q_Q" << endl;
				}
			}
			
		}
	}
}

void Background::payToll(Block p[], int size, Player s[], int num) {
	if (p[s[num].getplace()].getBlockName() == "免費停車" or
		p[s[num].getplace()].getBlockName() == "機會" or
		p[s[num].getplace()].getBlockName() == "繳稅" or
		p[s[num].getplace()].getBlockName() == "命運" or
		p[s[num].getplace()].getBlockName() == "暫停一次" or
		p[s[num].getplace()].getBlockName() == "起點" or
		p[s[num].getplace()].getBlockName() == "所的稅" or
		p[s[num].getplace()].getOwner() == s[num].getplayerName()) {




	}
	else{
		cout << "到了 " << p[s[num].getplace()].getOwner() << "的" << p[s[num].getplace()].getBlockName() << "支付 " << p[s[num].getplace()].getToll() << "元" << endl;
		s[num].addwealth(-p[s[num].getplace()].getToll());
		if (p[s[num].getplace()].getOwner() == "A ") {
			s[0].addwealth(p[s[num].getplace()].getToll());
		}
		if (p[s[num].getplace()].getOwner() == "B ") {
			s[1].addwealth(p[s[num].getplace()].getToll());
		}
		if (p[s[num].getplace()].getOwner() == "C ") {
			s[2].addwealth(p[s[num].getplace()].getToll());
		}
		if (p[s[num].getplace()].getOwner() == "D ") {
			s[3].addwealth(p[s[num].getplace()].getToll());
		}
	}
}

void Background::setMap(Block p[], int size) {
	//===================================blockname set
	{
		int i = 0;
		p[i].setBlockName("免費停車"); i++;		//i = 0
		p[i].setBlockName("成功路"); i++;		//
		p[i].setBlockName("機會"); i++;			// 2
		p[i].setBlockName("和平西路"); i++;
		p[i].setBlockName("民生東路"); i++;
		p[i].setBlockName("三合街"); i++;
		p[i].setBlockName("和平東路"); i++;
		p[i].setBlockName("基隆路"); i++;
		p[i].setBlockName("南京東路"); i++;
		p[i].setBlockName("繳稅"); i++;			//right up corner 9
		p[i].setBlockName("中山北路"); i++;
		p[i].setBlockName("羅斯福路"); i++;
		p[i].setBlockName("石牌路"); i++;
		p[i].setBlockName("命運"); i++;			// 13
		p[i].setBlockName("命運"); i++;			// 14
		p[i].setBlockName("光復南路"); i++;
		p[i].setBlockName("承德路"); i++;
		p[i].setBlockName("復興南路"); i++;
		p[i].setBlockName("延壽街"); i++;
		p[i].setBlockName("信義路"); i++;
		p[i].setBlockName("新生北路"); i++;
		p[i].setBlockName("忠孝東路"); i++;
		p[i].setBlockName("辛亥路"); i++;
		p[i].setBlockName("所的稅"); i++;		// 23
		p[i].setBlockName("廈門街"); i++;
		p[i].setBlockName("敦化南路"); i++;
		p[i].setBlockName("繳稅"); i++;		//left down corner 26
		p[i].setBlockName("吳興街"); i++;
		p[i].setBlockName("機會"); i++;			// 28
		p[i].setBlockName("萬大街"); i++;
		p[i].setBlockName("林森北路"); i++;
		p[i].setBlockName("內湖路"); i++;
		p[i].setBlockName("康寧路"); i++;
		p[i].setBlockName("命運"); i++;			// 33
		p[i].setBlockName("木柵路"); i++;
		p[i].setBlockName("起點"); i++;			//i = 35
	}
	//===================================sellprice set
	{
		int a = 0;

		p[a].setSell(0); a++;		//免費停車 0
		p[a].setSell(2200); a++;
		p[a].setSell(0); a++;		//機會 2
		p[a].setSell(2200); a++;
		p[a].setSell(2400); a++;
		p[a].setSell(2400); a++;
		p[a].setSell(2600); a++;
		p[a].setSell(2600); a++;
		p[a].setSell(2800); a++;
		p[a].setSell(0); a++;		// 繳稅 9
		p[a].setSell(2200); a++;
		p[a].setSell(3000); a++;
		p[a].setSell(1800); a++;
		p[a].setSell(0); a++;		// 命運 13
		p[a].setSell(0); a++;		// 命運 14
		p[a].setSell(3000); a++;
		p[a].setSell(1800); a++;
		p[a].setSell(3200); a++;
		p[a].setSell(1600); a++;
		p[a].setSell(3500); a++;
		p[a].setSell(1400);	a++;
		p[a].setSell(3500); a++;
		p[a].setSell(1400);	a++;
		p[a].setSell(0); a++;		// 所的稅 23
		p[a].setSell(1200); a++;
		p[a].setSell(4000); a++;
		p[a].setSell(0); a++;		// 暫停一次 26
		p[a].setSell(1200); a++;
		p[a].setSell(0); a++;		// 機會 28
		p[a].setSell(1000); a++;
		p[a].setSell(1000);	 a++;
		p[a].setSell(1000); a++;
		p[a].setSell(600); a++;
		p[a].setSell(0); a++;// 命運 33
		p[a].setSell(600); a++;
		p[a].setSell(0); a++;// 起點 35
	}
	//===================================owner set
	{
		for (int o = 0; o < 36; o++) {
			p[o].setOwner("00");
		}
	}
	//===================================setNumOfBuild set
	{
		for (int o = 0; o < 36; o++) {
			p[o].setNumOfBuild(0);
		}
	}
	//===================================setdefaultToll
	{
		for (int i = 0; i < 36; i++) {
			p[i].setDefaultToll(p[i].getSell() * 0.1);
		}
	}
	//===================================Toll
	{
		for (int i = 0; i < 36; i++) {
			p[i].setToll();
		}
	}
}

void Background::print(Block p[], int size, Player s[], int size2) {
	int n = 0;
	int count = 0;
	int own = 0;
	int b = 0;
	int t = 0;
	for (int i = 0; i < 71; i++) {
		for (int j = 0; j < 71; j++) {
			//=======================blockname display
			if (i == 1 and j % 7 == 1) {   //1
				cout << p[n].getBlockName();
				j += (p[n].getBlockName().size() / 2) - 1;
				n++;
			}
			else if (i == 8 and j % 63 == 1) {   //2
				cout << p[n].getBlockName();
				j += (p[n].getBlockName().size() / 2) - 1;
				n++;
			}
			else if (i == 15 and j % 63 == 1) {   //3
				cout << p[n].getBlockName();
				j += (p[n].getBlockName().size() / 2) - 1;
				n++;
			}
			else if (i == 22 and j % 63 == 1) {   //4
				cout << p[n].getBlockName();
				j += (p[n].getBlockName().size() / 2) - 1;
				n++;
			}
			else if (i == 29 and j % 63 == 1) {   //5
				cout << p[n].getBlockName();
				j += (p[n].getBlockName().size() / 2) - 1;
				n++;
			}
			else if (i == 36 and j % 63 == 1) {   //6
				cout << p[n].getBlockName();
				j += (p[n].getBlockName().size() / 2) - 1;
				n++;
			}
			else if (i == 43 and j % 63 == 1) {   //7
				cout << p[n].getBlockName();
				j += (p[n].getBlockName().size() / 2) - 1;
				n++;
			}
			else if (i == 50 and j % 63 == 1) {   //8
				cout << p[n].getBlockName();
				j += (p[n].getBlockName().size() / 2) - 1;
				n++;
			}
			else if (i == 57 and j % 63 == 1) {   //9
				cout << p[n].getBlockName();
				j += (p[n].getBlockName().size() / 2) - 1;
				n++;
			}
			else if (i == 64 and j % 7 == 1) {   //10
				cout << p[n].getBlockName();
				j += (p[n].getBlockName().size() / 2) - 1;
				n++;
			}
			//= ====================== sell display
			else if (i == 2 and j % 7 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "價格" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "價格" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "價格" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "價格" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 9 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "價格" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "價格" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "價格" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "價格" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 16 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "價格" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "價格" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "價格" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "價格" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 23 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "價格" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "價格" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "價格" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "價格" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 30 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "價格" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "價格" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "價格" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "價格" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 37 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "價格" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "價格" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "價格" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "價格" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 44 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "價格" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "價格" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "價格" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "價格" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 51 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "價格" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "價格" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "價格" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "價格" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 58 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "價格" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "價格" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "價格" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "價格" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 65 and j % 7 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "價格" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "價格" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "價格" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "價格" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			//= ====================== owner display
			else if (i == 6 and j % 7 == 6) {
				cout << p[own].getOwner();
				own++;
				j += 0;
			}
			else if (i == 13 and j % 63 == 6) {
				cout << p[own].getOwner();
				own++;
				j += 0;
			}
			else if (i == 20 and j % 63 == 6) {
				cout << p[own].getOwner();
				own++;
				j += 0;
			}
			else if (i == 27 and j % 63 == 6) {
				cout << p[own].getOwner();
				own++;
				j += 0;
			}
			else if (i == 34 and j % 63 == 6) {
				cout << p[own].getOwner();
				own++;
				j += 0;
			}
			else if (i == 41 and j % 63 == 6) {
				cout << p[own].getOwner();
				own++;
				j += 0;
			}
			else if (i == 48 and j % 63 == 6) {
				cout << p[own].getOwner();
				own++;
				j += 0;
			}
			else if (i == 55 and j % 63 == 6) {
				cout << p[own].getOwner();
				own++;
				j += 0;
			}
			else if (i == 62 and j % 63 == 6) {
				cout << p[own].getOwner();
				own++;
				j += 0;
			}
			else if (i == 69 and j % 7 == 6) {
				cout << p[own].getOwner();
				own++;
				j += 0;
			}
			//= ====================== NumOfBuild display
			else if (i == 6 and j % 7 == 1) {
				cout << "b" << p[b].getNumOfBuild();
				b++;
				j += 0;
			}
			else if (i == 13 and j % 63 == 1) {
				cout << "b" << p[b].getNumOfBuild();
				b++;
				j += 0;
			}
			else if (i == 20 and j % 63 == 1) {
				cout << "b" << p[b].getNumOfBuild();
				b++;
				j += 0;
			}
			else if (i == 27 and j % 63 == 1) {
				cout << "b" << p[b].getNumOfBuild();
				b++;
				j += 0;
			}
			else if (i == 34 and j % 63 == 1) {
				cout << "b" << p[b].getNumOfBuild();
				b++;
				j += 0;
			}
			else if (i == 41 and j % 63 == 1) {
				cout << "b" << p[b].getNumOfBuild();
				b++;
				j += 0;
			}
			else if (i == 48 and j % 63 == 1) {
				cout << "b" << p[b].getNumOfBuild();
				b++;
				j += 0;
			}
			else if (i == 55 and j % 63 == 1) {
				cout << "b" << p[b].getNumOfBuild();
				b++;
				j += 0;
			}
			else if (i == 62 and j % 63 == 1) {
				cout << "b" << p[b].getNumOfBuild();
				b++;
				j += 0;
			}
			else if (i == 69 and j % 7 == 1) {
				cout << "b" << p[b].getNumOfBuild();
				b++;
				j += 0;
			}
			//= ====================== defaultToll display
			else if (i == 5 and j % 7 == 2) {
				if (numOf(p[t].getToll()) == 1) {
					cout << "  ";
				}
				if (numOf(p[t].getToll()) == 2) {
					cout << "    " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 3) {
					cout << "   " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 4) {
					cout << "  " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 5) {
					cout << " " << p[t].getToll();
					j += 2;
				}
				t++;
			}
			else if (i == 12 and j % 63 == 2) {
				if (numOf(p[t].getToll()) == 1) {
					cout << "  ";
				}
				if (numOf(p[t].getToll()) == 2) {
					cout << "    " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 3) {
					cout << "   " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 4) {
					cout << "  " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 5) {
					cout << " " << p[t].getToll();
					j += 2;
				}
				t++;
			}
			else if (i == 19 and j % 63 == 2) {
				if (numOf(p[t].getToll()) == 1) {
					cout << "  ";
				}
				if (numOf(p[t].getToll()) == 2) {
					cout << "    " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 3) {
					cout << "   " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 4) {
					cout << "  " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 5) {
					cout << " " << p[t].getToll();
					j += 2;
				}
				t++;
			}
			else if (i == 26 and j % 63 == 2) {
				if (numOf(p[t].getToll()) == 1) {
					cout << "  ";
				}
				if (numOf(p[t].getToll()) == 2) {
					cout << "    " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 3) {
					cout << "   " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 4) {
					cout << "  " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 5) {
					cout << " " << p[t].getToll();
					j += 2;
				}
				t++;
			}
			else if (i == 33 and j % 63 == 2) {
				if (numOf(p[t].getToll()) == 1) {
					cout << "  ";
				}
				if (numOf(p[t].getToll()) == 2) {
					cout << "    " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 3) {
					cout << "   " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 4) {
					cout << "  " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 5) {
					cout << " " << p[t].getToll();
					j += 2;
				}
				t++;
			}
			else if (i == 40 and j % 63 == 2) {
				if (numOf(p[t].getToll()) == 1) {
					cout << "  ";
				}
				if (numOf(p[t].getToll()) == 2) {
					cout << "    " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 3) {
					cout << "   " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 4) {
					cout << "  " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 5) {
					cout << " " << p[t].getToll();
					j += 2;
				}
				t++;
			}
			else if (i == 47 and j % 63 == 2) {
				if (numOf(p[t].getToll()) == 1) {
					cout << "  ";
				}
				if (numOf(p[t].getToll()) == 2) {
					cout << "    " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 3) {
					cout << "   " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 4) {
					cout << "  " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 5) {
					cout << " " << p[t].getToll();
					j += 2;
				}
				t++;
			}
			else if (i == 54 and j % 63 == 2) {
				if (numOf(p[t].getToll()) == 1) {
					cout << "  ";
				}
				if (numOf(p[t].getToll()) == 2) {
					cout << "    " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 3) {
					cout << "   " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 4) {
					cout << "  " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 5) {
					cout << " " << p[t].getToll();
					j += 2;
				}
				t++;
			}
			else if (i == 61 and j % 63 == 2) {
				if (numOf(p[t].getToll()) == 1) {
					cout << "  ";
				}
				if (numOf(p[t].getToll()) == 2) {
					cout << "    " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 3) {
					cout << "   " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 4) {
					cout << "  " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 5) {
					cout << " " << p[t].getToll();
					j += 2;
				}
				t++;
			}
			else if (i == 68 and j % 7 == 2) {
				if (numOf(p[t].getToll()) == 1) {
					cout << "  ";
				}
				if (numOf(p[t].getToll()) == 2) {
					cout << "    " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 3) {
					cout << "   " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 4) {
					cout << "  " << p[t].getToll();
					j += 2;
				}
				if (numOf(p[t].getToll()) == 5) {
					cout << " " << p[t].getDefaultToll();
					j += 2;
				}
				t++;
			}
			/// place
			else if (i == 3 and j == 1) {                             /// 所在地 (玩家) (0)(左上)
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 0) {
						cout << s[c].getplayerName();
						j++;
					}
					else if( c == 3 ) {
						cout <<  "  ";
					}

				}
			}
			else if (i == 3 and j == 8) {							/// 1
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 1) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 3 and j == 15) {							/// 2
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 2) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 3 and j == 22) {							/// 3
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 3) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 3 and j == 29) {							/// 4
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 4) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 3 and j == 36) {							/// 5
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 5) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 3 and j == 43) {							/// 6
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 6) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 3 and j == 50) {							/// 7
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 7) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 3 and j == 57) {							/// 8
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 8) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 3 and j == 64) {							/// 9
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 9) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 10 and j == 1) {							/// 10
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 10) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 10 and j == 64) {							/// 11
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 11) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 17 and j == 1) {							/// 12
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 12) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 17 and j == 64) {							/// 13
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 13) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 24 and j == 1) {							/// 14
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 14) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 24 and j == 64) {							/// 15
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 15) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 31 and j == 1) {							/// 16
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 16) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 31 and j == 64) {							/// 17
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 17) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 38 and j == 1) {							/// 18
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 18) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 38 and j == 64) {							/// 19
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 19) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 45 and j == 1) {							/// 20
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 20) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 45 and j == 64) {							/// 21
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 21) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 52 and j == 1) {							/// 22
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 22) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 52 and j == 64) {							/// 23
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 23) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 59 and j == 1) {							/// 24
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 24) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 59 and j == 64) {							/// 25
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 25) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 66 and j == 1) {							/// 26
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 26) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 66 and j == 8) {							/// 27
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 27) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 66 and j == 15) {							/// 28
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 28) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 66 and j == 22) {							/// 29
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 29) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 66 and j == 29) {							/// 30
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 30) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 66 and j == 36) {							/// 31
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 31) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 66 and j == 43) {							/// 32
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 32) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 66 and j == 50) {							/// 33
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 33) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 66 and j == 57) {							/// 34
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 34) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}
			else if (i == 66 and j == 64) {							/// 35
				for (int c = 0; c < 4; c++) {
					if (s[c].getplace() == 35) {
						cout << s[c].getplayerName();
						j++;
					}
					else if (c == 3) {
						cout << "  ";
					}
				}
			}

			


				


			else if (i % 7 == 0 or j % 7 == 0) {
				cout << ". ";
			}
			else {
				cout << "  ";
			}
		}




		cout << endl;
	}
}
bool Background::nomoney(Player s[], int size) {
	int max = 0;
	string winner;
	for (int i = 0; i < 4; i++) {
		if (s[i].getwealth() < 0) {
			cout << "---------------------------------" << endl;
			cout << "玩家" << s[i].getplayerName() << "已破產" << endl;
			cout << "玩家" << s[i].getplayerName() << "已破產" << endl;
			cout << "玩家" << s[i].getplayerName() << "已破產" << endl;
			cout << "---------------------------------" << endl;
			max = s[0].getwealth();
			winner = s[0].getplayerName();
			for (int j = 0; j < 4; j++) {
				if (s[j].getwealth() > max) {
					max = s[j].getwealth();
					winner = s[j].getplayerName();
				}
			}
			cout << "獲勝的是玩家:" << winner << "共有" << max << "元" << endl;

			return false;
		}
	}
	return true;
}