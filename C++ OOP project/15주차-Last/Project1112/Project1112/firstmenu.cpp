#include <iostream>
#include <string>
#include "firstmenu.h"
#include "money.h"
#include "lotto.h"
#include "russian.h"
#include "gawi.h"
using namespace std;
gamemoney G;
lotto L;
rus R;
gawi W;

// ������� 1-1.
int firstmenu::mainmenu()  // 1-1. �޴��� ����ش�.
{
	checkfirstgame = 0;
	while(1)
	{
		int gameselect = 0;
		cout << "������ ���� 1 ������������ ���� 2 ������������ ���� 3 ������" << endl;
		cout << "��                ����                ����                ��" << endl;
		cout << "��    �ζǰ���    ����   ���þȷ귿   ����   ����������   ��" << endl;
		cout << "��                ����                ����                ��" << endl;
		cout << "������������������������������������������������������������" << endl;
		cout << "=============================================================" << endl;
		cout << "   ������ ���� ���ּ���. [ �����Ͻ÷��� 4 ���� �Է��ϼ���. ] " << endl;
		cout << "=============================================================" << endl;
		cin >> gameselect;

		if(gameselect >=1 && gameselect <=3)
			return gameselect;
		else if (gameselect == 4 )
			return 0;
		else 
			system("cls");
			cout << "�߸� �Է��ϼ̽��ϴ�." <<endl;
	}
}

// ������� 2-1.
int firstmenu::personselect()
{
	system("cls");
	Re:
	firstmenu *in = new firstmenu();
	if (checkfirstgame == 0) // checkfirstgame -> ó�� �����ϴ� ������ �˻��Ѵ�. 0 �ϰ�� ó�� ���� �޴�.
	{
		cout << " ���ϴ� ��ŭ �÷��̾��� ���� �Է��Ͻʽÿ�." << endl;
		cin >> player;
		while (player <= 0)
		{
			system("cls");
			cout << "���� ������ �Է��ϽǼ� �ֽ��ϴ�. �ٽ� �Է����ּ���." << endl;
			cin >> player;
		}
		system("cls");
		cout << " ���� �޴��� ���÷��� 0 ���� �Է��ϼ���.  " << endl;
		cout << " �����Ͻ� �÷��̾� ��ȣ�� �Է����ּ���. " << endl;
		for (int i = 0; i < player; i++)
		{
			person[i] = in;
			cout << "��������������������������������������������������������������" << endl;
			printf("�� %2d �� �÷��̾� // �ڱ� : %-29d ����\n", i + 1,  person[i]->realMoney = G.money(0, i));
			cout << "��������������������������������������������������������������" << endl;
		}
		checkfirstgame = 1; // ó�� ���� üũ���� 1�� ����
	}
	else
	{
		cout << " ���� �޴��� ���÷��� 0 ���� �Է��ϼ���.  " << endl;
		cout << " �����Ͻ� �÷��̾� ��ȣ�� �Է����ּ���. " << endl;
		for (int i = 0; i < player; i++)
		{
			cout << "��������������������������������������������������������������" << endl;
			printf("�� %2d �� �÷��̾� // �ڱ� : %-29d ����\n", i + 1, person[i]->realMoney = G.money(0, i));
			cout << "��������������������������������������������������������������" << endl;
		}
	}
	cin >> selectplayer;
	if (selectplayer == 0)
	{
		for (int i = 0; i < player; i++)
		{
			int resetmoney = 0;
			resetmoney = G.money(0, i);
			G.money(-resetmoney, i);
			G.money(10000, i);
		}
	}
	else if (selectplayer > player || selectplayer < 0)
	{
		system("cls");
		cout << "�߸� �Է� �ϼ̽��ϴ�. ��Ͽ� �ִ� �÷��̾��� �������ּ���." << endl;
		goto Re;
	}
	system("cls");
	delete in;
	return selectplayer;
}

// ������� 3-1.
void firstmenu::gamestartmenu(int game, int y) //3.1  �Է¹��� �޴������� ���� �������Ѵ�.
{                      
	firstmenu *fir = new firstmenu;
	switch (game)
	{
		case 1: {
			string gamename = "�ζ�";
			fir = new lottogame[lastmenu(gamename)];
			(fir+lastmenu2(gamename)-1)->startgame(y); 
			Givemoney(y-1);
			delete[] fir;
			break; }
		case 2: {
			string gamename = "���þ� �귿";
			fir = new russiangame[lastmenu(gamename)];
			(fir+lastmenu2(gamename)-1)->startgame(y); 
			Givemoney(y-1);
			delete[] fir;
			break; }
		case 3: {
			string gamename = "����������";
			fir = new gawigame[lastmenu(gamename)];
			(fir+lastmenu2(gamename)-1)->startgame(y); 
			Givemoney(y-1);
			delete[] fir;
			break; }
		default: {
			system("cls");
			cout << "�߸��� ���� �Է��ϼ̽��ϴ�." << endl;
			delete fir;
			break; }
	}
}

int firstmenu::lastmenu(string gamename)
{
	system("cls");
	cout << "��� "<< gamename <<" ������ ���� �Ͻðڽ��ϱ�?" <<endl;
	cin >> gamecount;
	while (gamecount <= 0)
	{
		system("cls");
		cout << "���� ������ �Է��ϽǼ� �ֽ��ϴ�. �ٽ� �Է����ּ���."<<endl;
		cin >> gamecount;
	}
	return gamecount;
}

int firstmenu::lastmenu2(string gamename)
{
	int selectgame;
	cout << "���°�� " << gamename << " �������� �����Ͻðڽ��ϱ�?" <<endl;
	cin >> selectgame;

	while (selectgame > gamecount || selectgame <= 0)
	{
		cout<<"������ ���� ������ ������ ������ϴ�."<<endl;
		cout<< "���� " <<gamecount << " ���� " << gamename << " ������ ���� �Ǿ��ֽ��ϴ�. " <<endl;
		cout<<"�ٽ� �������ּ���."<<endl;
		cin >> selectgame;
	}
	system("cls");
	cout<<gamecount<<" ���� " << gamename << " �����߿� "<<selectgame<<" ��° " << gamename << " �������� �����մϴ�. " <<endl;
	return selectgame;
}

void firstmenu::Givemoney(int mey)
{
	person[mey]->realMoney = G.money(0, mey);
}

// ������
void firstmenu::startgame(int y)
{
	system("cls");
	cout << "��������(���,�ҽ�)�� �߰����ּ���." << endl;
};

void lottogame::startgame(int y)
{
	L.mainmenu(y);
};

void russiangame::startgame(int y)
{
	R.russian(y);
};

void gawigame::startgame(int y)
{
	W.run(y);
};