#include "gawi.h"
#include "money.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
gamemoney GM;

void gawi::gawiPrint(int pp) //���������� �޴� ���
{
	cout << "[[ �����ݾ� : " << GM.money(0, pp - 1) << " ]]" << endl;
	cout << "     ����� �� " << count << " �� ������!" << endl;
	cout << " 500���� ���� �˴ϴ�! ���½� ������!!" << endl;
	cout << "������������������������������������������" << endl;
	cout << "��(1) ����                              ��" << endl;
	cout << "��(2) ����                              ��" << endl;
	cout << "��(3) ��                                ��" << endl;
	cout << "��(4) ������ ȯ���ϱ�                   ��" << endl;
	cout << "��(5) ���θ޴� ����                    ��" << endl;
	cout << "������, ����, �� �� ���ڸ� �Է��ϼ���!! ��" << endl;
	cout << "������������������������������������������" << endl;
}
int gawi::money(int a, int b) //���������� ���ӿ��� ���� �帧
{
	int i, c;
	c = a;
	for (i = 0; i<b - 1; i++)
		c = c*a;

	return c;
}
int gawi::run(int p) //���� ���� ����
{
	count = 0;
	if (GM.money(0, p - 1) < 1000)
	{
		return 0;
	}
	while (1)
	{
	GAWI: //goto �б���
		gawiPrint(p);
		srand((unsigned)time(NULL)); //�������� �̿�

		cin >> user;
		if (GM.money(0, p - 1) < 1000) //������ üũ
		{
			system("cls");
			cout << "�������� �����ϹǷ� ���ӿ� �����ϽǼ� �����ϴ�. ���θ޴��� ���ư��ϴ�." << endl;
			cout << "Press any key to continue";
			_getch();
			system("cls");
			return 0;
		}
		switch (user) //���������� ���ӿ� ���� ����� ���� �̿�
		{
		case 1:
			GM.money(-500, p - 1);
			cout << "����";
			break;
		case 2:
			GM.money(-500, p - 1);
			cout << "����";
			break;
		case 3:
			GM.money(-500, p - 1);
			cout << "��";
			break;
		case 4: //���� �¼��� ���� ȯ�� 
			if (count == 1)
			{
				GM.money(500, p - 1);
				realMoney = +500;
			}
			else
			{
				realMoney = money(50, count);
				GM.money(realMoney, p - 1);
			}
			count = 0;
			cout << realMoney << "���� ȯ��Ǿ����ϴ�!!" << endl;
			_getch();
			system("cls");
			goto GAWI;
			break;
		case 5:
			system("cls");
			return GM.money(0, p - 1);
		}
		cout << "\n��ǻ��:";

		com = (rand() % 3) + 1;
		switch (com) //��ǻ�ʹ� ����,����,�� ���߿� �������� �ϳ��� ���� ��
		{
		case 1:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "��";
			break;
		}
		cout << endl;

		if (com == user) // ��ǻ�Ϳ� ������ ��, ���� üũ
		{
			cout << "Draw game" << endl;
		}
		else if (com == 1 && user == 2)
		{
			cout << "Win!" << endl;
			count++;
		}
		else if (com == 1 && user == 3)
		{
			cout << "Lose.." << endl;
			count = 0;
		}
		else if (com == 2 && user == 1)
		{
			cout << "Lose.." << endl;
			count = 0;
		}
		else if (com == 2 && user == 3)
		{
			cout << "Win!" << endl;
			count++;
		}
		else if (com == 3 && user == 1)
		{
			cout << "Win!" << endl;
			count++;
		}
		else if (com == 3 && user == 2)
		{
			cout << "Lose.." << endl;
			count = 0;
		}
		cout << endl;
		cout << "Press enter key to continue";
		enter = _getch();
		if (enter == 13)
		{
			system("cls");
			goto GAWI;
		}
		system("cls");
	}
}