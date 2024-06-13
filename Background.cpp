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
	if (p[s[num].getplace()].getBlockName() == "�K�O����" or
		p[s[num].getplace()].getBlockName() == "���|" or
		p[s[num].getplace()].getBlockName() == "ú�|" or
		p[s[num].getplace()].getBlockName() == "�R�B" or 
		p[s[num].getplace()].getBlockName() == "�Ȱ��@��" or 
		p[s[num].getplace()].getBlockName() == "�Ҫ��|" or
		p[s[num].getplace()].getBlockName() == "�_�I" ) {

		if (p[s[num].getplace()].getBlockName() == "���|" || p[s[num].getplace()].getBlockName() == "�R�B") {
			srand(time(NULL));
			ran = (rand() % 5);
			if (ran == 0) {
				cout << "���|�G�e���_�I�A�û��2000��" << endl;
				s[num].addwealth(2000);
				s[num].setplace(0);
			}
			if (ran == 1) {
				cout << "���|�G�Ȧ�X���A�o��1500��" << endl;
				s[num].addwealth(1500);
			}
			if (ran == 2) {
				cout << "���|�G��I�ǶO1500��" << endl;
				s[num].addwealth(-1500);
			}
			if (ran == 3) {
				cout << "���|�G�~�ӿ򲣡A���1000��" << endl;
				s[num].addwealth(1000);
			}
			if (ran == 4) {
				cout << "���|�G�q�Ȧ椤����Ѯ�3000��" << endl;
				s[num].addwealth(3000);
			}
		}
		if (p[s[num].getplace()].getBlockName() == "ú�|") {
			cout << "ú�|3000��" << endl;
			s[num].addwealth(-3000);
		}
		if (p[s[num].getplace()].getBlockName() == "�Ҫ��|") {
			cout << "����1/10���]��" << endl;
			s[num].setwealth(s[num].getwealth() * 0.9);
		}
		
	}
	else if (p[s[num].getplace()].getOwner() == "00") {
		while (true) {
			cout << "�O�_�ʶR" << p[s[num].getplace()].getBlockName() << " " << p[s[num].getplace()].getSell() << "(Y/N)" << endl;
			cin >> choose;
			if ((choose == "Y" or choose == "y") && (s[num].getwealth() >= p[s[num].getplace()].getSell())) {
				p[s[num].getplace()].setOwner(s[num].getplayerName());
				s[num].addwealth(-p[s[num].getplace()].getSell());
				cout << "�����ʶR" << endl;
				cout << "��" << s[num].getwealth() << "��" << endl;
				break;
			}
			else if (choose == "N" or choose == "n") {
				cout << "OK" << endl;
				break;
			}
			else {
				cout << "�����շN��ξl�B�����A�Э��s��J Q_Q" << endl;
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
				cout << "�w��F�̰��ؿv�ƶq Q_Q";
			}
			else {
				cout << "�w�� " << p[s[num].getplace()].getNumOfBuild() << " �� �O�_�� " << pay << "�\�Фl ? (Y/N)" << endl;
				cin >> choose;
				if ((choose == "Y" or choose == "y") && (s[num].getwealth() >= pay)) {
					p[s[num].getplace()].addNumOfBuild(1);
					s[num].addwealth(-pay);
					cout << "���߻\��" << endl;
					cout << "��" << s[num].getwealth() << "��" << endl;
					break;
				}
				else if (choose == "N" or choose == "n") {
					cout << "OK" << endl;
					break;
				}
				else {
					cout << "�����շN��ξl�B�����A�Э��s��J Q_Q" << endl;
				}
			}
			
		}
	}
}

void Background::payToll(Block p[], int size, Player s[], int num) {
	if (p[s[num].getplace()].getBlockName() == "�K�O����" or
		p[s[num].getplace()].getBlockName() == "���|" or
		p[s[num].getplace()].getBlockName() == "ú�|" or
		p[s[num].getplace()].getBlockName() == "�R�B" or
		p[s[num].getplace()].getBlockName() == "�Ȱ��@��" or
		p[s[num].getplace()].getBlockName() == "�_�I" or
		p[s[num].getplace()].getBlockName() == "�Ҫ��|" or
		p[s[num].getplace()].getOwner() == s[num].getplayerName()) {




	}
	else{
		cout << "��F " << p[s[num].getplace()].getOwner() << "��" << p[s[num].getplace()].getBlockName() << "��I " << p[s[num].getplace()].getToll() << "��" << endl;
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
		p[i].setBlockName("�K�O����"); i++;		//i = 0
		p[i].setBlockName("���\��"); i++;		//
		p[i].setBlockName("���|"); i++;			// 2
		p[i].setBlockName("�M�����"); i++;
		p[i].setBlockName("���ͪF��"); i++;
		p[i].setBlockName("�T�X��"); i++;
		p[i].setBlockName("�M���F��"); i++;
		p[i].setBlockName("�򶩸�"); i++;
		p[i].setBlockName("�n�ʪF��"); i++;
		p[i].setBlockName("ú�|"); i++;			//right up corner 9
		p[i].setBlockName("���s�_��"); i++;
		p[i].setBlockName("ù���ָ�"); i++;
		p[i].setBlockName("�۵P��"); i++;
		p[i].setBlockName("�R�B"); i++;			// 13
		p[i].setBlockName("�R�B"); i++;			// 14
		p[i].setBlockName("���_�n��"); i++;
		p[i].setBlockName("�Ӽw��"); i++;
		p[i].setBlockName("�_���n��"); i++;
		p[i].setBlockName("���ص�"); i++;
		p[i].setBlockName("�H�q��"); i++;
		p[i].setBlockName("�s�ͥ_��"); i++;
		p[i].setBlockName("�����F��"); i++;
		p[i].setBlockName("�����"); i++;
		p[i].setBlockName("�Ҫ��|"); i++;		// 23
		p[i].setBlockName("�H����"); i++;
		p[i].setBlockName("���ƫn��"); i++;
		p[i].setBlockName("ú�|"); i++;		//left down corner 26
		p[i].setBlockName("�d����"); i++;
		p[i].setBlockName("���|"); i++;			// 28
		p[i].setBlockName("�U�j��"); i++;
		p[i].setBlockName("�L�˥_��"); i++;
		p[i].setBlockName("�����"); i++;
		p[i].setBlockName("�d���"); i++;
		p[i].setBlockName("�R�B"); i++;			// 33
		p[i].setBlockName("��]��"); i++;
		p[i].setBlockName("�_�I"); i++;			//i = 35
	}
	//===================================sellprice set
	{
		int a = 0;

		p[a].setSell(0); a++;		//�K�O���� 0
		p[a].setSell(2200); a++;
		p[a].setSell(0); a++;		//���| 2
		p[a].setSell(2200); a++;
		p[a].setSell(2400); a++;
		p[a].setSell(2400); a++;
		p[a].setSell(2600); a++;
		p[a].setSell(2600); a++;
		p[a].setSell(2800); a++;
		p[a].setSell(0); a++;		// ú�| 9
		p[a].setSell(2200); a++;
		p[a].setSell(3000); a++;
		p[a].setSell(1800); a++;
		p[a].setSell(0); a++;		// �R�B 13
		p[a].setSell(0); a++;		// �R�B 14
		p[a].setSell(3000); a++;
		p[a].setSell(1800); a++;
		p[a].setSell(3200); a++;
		p[a].setSell(1600); a++;
		p[a].setSell(3500); a++;
		p[a].setSell(1400);	a++;
		p[a].setSell(3500); a++;
		p[a].setSell(1400);	a++;
		p[a].setSell(0); a++;		// �Ҫ��| 23
		p[a].setSell(1200); a++;
		p[a].setSell(4000); a++;
		p[a].setSell(0); a++;		// �Ȱ��@�� 26
		p[a].setSell(1200); a++;
		p[a].setSell(0); a++;		// ���| 28
		p[a].setSell(1000); a++;
		p[a].setSell(1000);	 a++;
		p[a].setSell(1000); a++;
		p[a].setSell(600); a++;
		p[a].setSell(0); a++;// �R�B 33
		p[a].setSell(600); a++;
		p[a].setSell(0); a++;// �_�I 35
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
					cout << "����" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "����" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "����" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "����" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 9 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "����" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "����" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "����" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "����" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 16 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "����" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "����" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "����" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "����" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 23 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "����" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "����" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "����" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "����" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 30 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "����" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "����" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "����" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "����" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 37 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "����" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "����" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "����" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "����" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 44 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "����" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "����" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "����" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "����" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 51 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "����" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "����" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "����" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "����" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 58 and j % 63 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "����" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "����" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "����" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "����" << p[count].getSell();
				}
				j += 3;
				count++;
			}
			else if (i == 65 and j % 7 == 1) {
				if (numOf(p[count].getSell()) == 1) {
					cout << "����" << "000" << p[count].getSell();

				}
				if (numOf(p[count].getSell()) == 2) {
					cout << "����" << "00" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 3) {
					cout << "����" << "0" << p[count].getSell();
				}
				if (numOf(p[count].getSell()) == 4) {
					cout << "����" << p[count].getSell();
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
			else if (i == 3 and j == 1) {                             /// �Ҧb�a (���a) (0)(���W)
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
			cout << "���a" << s[i].getplayerName() << "�w�}��" << endl;
			cout << "���a" << s[i].getplayerName() << "�w�}��" << endl;
			cout << "���a" << s[i].getplayerName() << "�w�}��" << endl;
			cout << "---------------------------------" << endl;
			max = s[0].getwealth();
			winner = s[0].getplayerName();
			for (int j = 0; j < 4; j++) {
				if (s[j].getwealth() > max) {
					max = s[j].getwealth();
					winner = s[j].getplayerName();
				}
			}
			cout << "��Ӫ��O���a:" << winner << "�@��" << max << "��" << endl;

			return false;
		}
	}
	return true;
}