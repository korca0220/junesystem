#include <iostream>
#include <time.h>
#include <math.h>
#include "money.h"
#include "russian.h"
using namespace std;

void rus::end()
{
	cout << "�ٽ� ���� �Ͻ÷��� 2��" << endl;
	cout << "���� �޴��� ���ư��÷��� �ƹ����ڳ� �Է����ּ���" << endl;
}

int rus::russian(int player)
{
	gamemoney G;
	system("cls");
	int i = 0;
	char enter;
	srand((unsigned)time(0));
	if (G.money(0, player - 1) < 1000)
	{
		return 0;
	}
	cout << "���þ� �귿 ������ �����մϴ�.\n������ ���� ���� ���մϴ�.\n���͸� ������ ��Ƽ踦 ���ϴ�.\n\n";
	cout << "���� ������ �޼��Ҽ��� ���� ���� ����ϴ�." << endl;
	cout << "���� ��� ������ ���� �Ұ� �˴ϴ�." << endl << endl;
Re1:
	if (G.money(0, player - 1) == 0)
	{
		while ((enter = getchar()) != '\n');
		cout << "�������� 0���̸� ������ �� �� �����ϴ�. ���θ޴��� ���ư��ϴ�.";
		while ((enter = getchar()) != '\n');
		system("cls");
		return 0;
	}
	Score = 0;
	cout << "������ : " << G.money(0, player - 1) << endl;
	cout << "������ �ݾ� : ";
	do {
		cin >> bet;
		if (bet > G.money(0, player - 1))
			cout << "�������� �����մϴ�" << endl;
	} while (bet > G.money(0, player - 1));
	G.money(0 - bet, player - 1);
	cout << endl;
Re2:
	Coin = rand() % 2 + 1;
	Bullet = rand() % 6;
	cout << "������ ��� ���� �����Ͻðڽ��ϱ�?(��=1, ��=2)\n";
	cin >> Select;

	if (Select == 1)
	{
		if (Coin == 1)
		{
			while ((enter = getchar()) != '\n');
			cout << "�ո��� ���Խ��ϴ�.\n\n";
			while ((enter = getchar()) != '\n');
			system("cls");
			for (i = 0; i <= 5; i++)
			{
				cout << i + 1 << "��° ����\n";
				if ((i % 2) == 0)
					cout << "����� �����Դϴ�. ��Ƽ踦 ���ʽÿ�.\n";
				else
					cout << "�� �����Դϴ�. ��Ƽ踦 ���ڽ��ϴ�.\n";
				while ((enter = getchar()) != '\n');

				if (i == Bullet)
				{
					cout << "�Ѽ��� ��������ϴ�.\n\n";
					if ((i % 2) == 0)
					{
						cout << "����� �׾����ϴ�.\n\n";
						//cout << Score << "�����ϼ̽��ϴ�.\n\n";
						end();
						cin >> Select;
						if (Select == 2)
						{
							cout << "���� ������ �����մϴ�.\n";
							system("cls");
							goto Re1;
						}
						system("cls");
						return 0;
					}
					else
					{
						cout << "����� �¸��߽��ϴ�.\n\n";
						Score++;
						cout << Score << "���� ��\n";
						cout << bet * pow(2, Score) << "���� ���� �� �ֽ��ϴ�." << endl;
						end();
						cin >> Select;
						if (Select == 2)
						{
							cout << "���� ������ �����մϴ�.\n";
							system("cls");
							goto Re2;
						}
						G.money(bet * pow(2, Score), player - 1);
						system("cls");
						return 0;
					}

				}
				else
				{
					cout << "�ƹ��ϵ� �Ͼ�� �ʾҽ��ϴ�.\n\n";
					while ((enter = getchar()) != '\n');
					system("cls");
				}
			}
		}
		else
		{
			while ((enter = getchar()) != '\n');
			cout << "�޸��� ���Խ��ϴ�.\n\n";
			while ((enter = getchar()) != '\n');
			system("cls");
			for (i = 0; i <= 5; i++)
			{
				cout << i + 1 << "��° ���\n";
				if ((i % 2) == 0)
					cout << "�� �����Դϴ�. ��Ƽ踦 ���ڽ��ϴ�.\n";
				else
					cout << "����� �����Դϴ�. ��Ƽ踦 ���ʽÿ�.\n";
				while ((enter = getchar()) != '\n');

				if (i == Bullet)
				{
					cout << "�Ѽ��� ��������ϴ�.\n\n";
					if ((i % 2) == 0)
					{
						cout << "����� �¸��߽��ϴ�.\n\n";
						Score++;
						cout << Score << "���� ��\n";
						cout << bet * pow(2, Score) << "���� ���� �� �ֽ��ϴ�." << endl;
						end();
						cin >> Select;
						if (Select == 2)
						{
							cout << "���� ������ �����մϴ�.\n";
							system("cls");
							goto Re2;

						}
						G.money(bet * pow(2, Score), player - 1);
						system("cls");
						return 0;
					}
					else
					{
						cout << "����� �׾����ϴ�.\n\n";
						//cout << Score << "�����ϼ̽��ϴ�.\n";
						end();
						cin >> Select;
						if (Select == 2)
						{
							cout << "���� ������ �����մϴ�.\n";
							system("cls");
							goto Re1;
						}
						system("cls");
						return 0;
					}
				}
				else
				{
					cout << "�ƹ��ϵ� �Ͼ�� �ʾҽ��ϴ�.\n\n";
					while ((enter = getchar()) != '\n');
					system("cls");
				}
			}
		}

	}
	else if (Select == 2)
	{
		if (Coin == 1)
		{
			while ((enter = getchar()) != '\n');
			cout << "�ո��� ���Խ��ϴ�.\n\n";
			while ((enter = getchar()) != '\n');
			system("cls");
			for (i = 0; i <= 5; i++)
			{
				cout << i + 1 << "��° ���\n";
				if ((i % 2) == 0)
					cout << "�� �����Դϴ�. ��Ƽ踦 ���ڽ��ϴ�.\n";
				else
					cout << "����� �����Դϴ�. ��Ƽ踦 ���ʽÿ�.\n";
				while ((enter = getchar()) != '\n');

				if (i == Bullet)
				{
					cout << "�Ѽ��� ��������ϴ�.\n\n";
					if ((i % 2) == 0)
					{
						cout << "����� �¸��߽��ϴ�.\n\n";
						Score++;
						cout << Score << "���� ��\n";
						cout << bet * pow(2, Score) << "���� ���� �� �ֽ��ϴ�." << endl;
						end();
						cin >> Select;
						if (Select == 2)
						{
							cout << "���� ������ �����մϴ�.\n";
							system("cls");
							goto Re2;
						}
						G.money(bet * pow(2, Score), player - 1);
						system("cls");
						return 0;
					}
					else
					{
						cout << "����� �׾����ϴ�.\n\n";
						//cout << Score << "�����ϼ̽��ϴ�.\n";
						end();
						cin >> Select;
						if (Select == 2)
						{
							cout << "���� ������ �����մϴ�.\n";
							system("cls");
							goto Re1;

						}
						system("cls");
						return 0;
					}
				}
				else
				{
					cout << "�ƹ��ϵ� �Ͼ�� �ʾҽ��ϴ�.\n\n";
					while ((enter = getchar()) != '\n');
					system("cls");
				}
			}
		}
		else
		{
			while ((enter = getchar()) != '\n');
			cout << "�޸��� ���Խ��ϴ�.\n\n";
			while ((enter = getchar()) != '\n');
			system("cls");
			for (i = 0; i <= 5; i++)
			{
				cout << i + 1 << "��° ���\n";
				if ((i % 2) == 0)
					cout << "����� �����Դϴ�. ��Ƽ踦 ���ʽÿ�.\n";
				else
					cout << "�� �����Դϴ�. ��Ƽ踦 ���ڽ��ϴ�.\n";
				while ((enter = getchar()) != '\n');

				if (i == Bullet)
				{
					cout << "�Ѽ��� ��������ϴ�.\n\n";
					if ((i % 2) == 0)
					{
						cout << "����� �׾����ϴ�.\n\n";
						//	cout << Score << "�����ϼ̽��ϴ�.\n\n";
						end();
						cin >> Select;
						if (Select == 2)
						{
							cout << "���� ������ �����մϴ�.\n";
							system("cls");
							goto Re1;
						}
						system("cls");
						return 0;
					}
					else
					{
						cout << "����� �¸��߽��ϴ�.\n\n";
						Score++;
						cout << Score << "���� ��\n";
						cout << bet * pow(2, Score) << "���� ���� �� �ֽ��ϴ�." << endl;
						end();
						cin >> Select;
						if (Select == 2)
						{
							cout << "���� ������ �����մϴ�.\n";
							system("cls");
							goto Re2;
						}
						G.money(bet * pow(2, Score), player - 1);
						system("cls");
						return 0;
					}
				}
				else
				{
					cout << "�ƹ��ϵ� �Ͼ�� �ʾҽ��ϴ�.\n\n";
					while ((enter = getchar()) != '\n');
					system("cls");
				}
			}
		}
	}
	else
	{
		printf("�ٽ� �Է��Ͻʽÿ�.\n");
		goto Re2;
	}
	return 0;
}