#include <iostream>
#include <time.h>
#include "lotto.h"
#include "money.h"
using namespace std;
gamemoney G2;

int lotto::mainmenu(int player)
{

	do
	{
		cout << "========== �ζ� ���� ���� �޴�==========" << endl;
		cout << "1. ���� 3�� ���߱� \t" << "�����ݾ� : " << G2.money(0, player - 1) << endl;
		cout << "2. �ζ� �ùķ�����" << endl;
		cout << "3. ��÷�� ����" << endl;
		cout << "4. �����޴��� ������" << endl;
		cout << "\n �ش� ���ڸ� �Է��ϼ���." << endl;
		cout << "===================================" << endl;
		if (G2.money(0, player - 1) < 10)
		{
			system("cls");
			return 0;
		}
		if (G2.money(0, player - 1) < 1000)
		{
			system("cls");
			cout << "�������� �����ϹǷ� �ζǰ��ӿ� �����ϽǼ� �����ϴ�. ���θ޴��� ���ư��ϴ�." << endl;
			return 0;
		}
		do
		{
			cin >> menu;
			if (menu < 1 || 4 < menu)
			{
				cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���" << endl;
			}
		} while (menu < 1 || 4 < menu); // 1���� �۰ų� 4���� ū�� �Է��ϸ� ��� �ݺ�
		switch (menu)
		{
		case 1:
			do { simul3(player); } while (remenu == 2);
			break;
		case 2:
			do { simul6(player); } while (remenu == 2);
			break;
		case 3:
			chart();
			break;
		case 4:
			system("cls");
			remenu = 4;
			return remenu;
			break;
		default: // �߰��޴� �̱���
			break;
		}
	} while (remenu == 1);
	return 0;
}
void lotto::endprint()
{
	cout << endl;
	cout << "�ζ� ���� ���� �޴��� ���ư��÷��� 1��" << endl;
	cout << "�ٽ� ���� �Ͻ÷��� 2��" << endl;
	cout << "���� �޴��� ���ư��÷��� �ƹ����ڳ� �Է����ּ���." << endl;
}
int lotto::simul3(int player)
{
	int usernum3[3];
	int lonum3[3];
	G2.money(-500, player - 1);
	system("cls");
	cout << "���� ��� 500 ���� �����˴ϴ�.  �ܿ� ������: " << G2.money(0, player - 1) << endl;
	cout << "1~10 ������ ���� 3���� ���ʷ� �Է����ּ���." << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> usernum3[i]; // �迭�� ���� 3�� �Է¹ޱ�
	}
	system("cls");
	cout << "-------------------�̹�ȸ�� ��÷ ��ȣ��-------------------" << endl;  // ���Ŀ� 1ȸ�� 2ȸ��.. �̷��� ���̰� ����.
	for (int i = 0; i < 3; i++)
	{
		lonum3[i] = rand() % 10 + 1;
		for (int j = 0; j < i; j++)
		{
			if (lonum3[j] == lonum3[i])
			{
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < 3; i++) //�ζ� ��÷ ��ȣ ����ϱ�
	{
		cout << lonum3[i] << "\t";
	}

	cout << "�Դϴ�." << endl;
	cout << endl;
	for (int i = 0; i < 3; i++) //���� �Է��Ѱ� �Ϸķ� �����ؼ� �����ֱ�
	{
		cout << usernum3[i] << "\t";
	}
	count = 0; // ������� ī��Ʈ �ʱ�ȭ
	cout << "<- ���� ������ ��ȣ" << endl;

	for (int i = 0; i < 3; i++)  //��� ��ġ�ϴ��� üũ
	{
		for (int j = 0; j < 3; j++)
		{
			if (usernum3[i] == lonum3[j]) //�Է°��� ��÷��ȣ�� ������ Ȯ���ϰ�
			{
				count++;  // ���ٸ� ī��Ʈ���� +1 �߰� (��÷��ȣ����)
				break;
	cout << endl;
			}
		}
	}

	cout << "��ȣ�� �� " << count << "�� ��ġ. ";
	switch (count) //��÷������ ��÷�ݾ� �����ִ� ���� ����ϱ�.
	{
	case 1:
		cout << "3�� �Դϴ�.  ��÷��: 1,000 ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		G2.money(1000, player - 1);
		cout << "������: " << G2.money(0, player - 1) << " ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		break;
	case 2:
		cout << "2�� �Դϴ�.  ��÷��: 5,000 ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		G2.money(5000, player - 1);
		cout << "������: " << G2.money(0, player - 1) << " ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		break;
	case 3:
		cout << "1�� �Դϴ�.  ��÷��: 10,000 ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		G2.money(10000, player - 1);
		cout << "������: " << G2.money(0, player - 1) << " ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		break;
	default:
		cout << "��. ��÷�Դϴ�." << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "������: " << G2.money(0, player - 1) << " ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		break;
	}

	cout << endl;
	endprint();
	cin >> remenu;
	system("cls");  // �ý��� ���ȭ�� �����	
	return remenu;
}
int lotto::simul6(int player)
{
	int usernum6[6];
	int lonum6[7]; // �����ӿ��� ���ʽ���ȣ������ �ϳ��߰�
	G2.money(-1000, player - 1);
	system("cls");
	cout << "���� ��� 1000 ���� �����˴ϴ�.  �ܿ� ������: " << G2.money(0, player - 1) << endl;
	cout << "1~45 ������ ���� 6���� ���ʷ� �Է����ּ���." << endl;
	for (int i = 0; i < 6; i++) // 1-1. �Է��� 6���� �ް�,
	{
		cin >> usernum6[i]; // �迭�� ���� 3�� �Է¹ޱ�
	}
	system("cls");
	cout << "-------------------�̹�ȸ�� ��÷ ��ȣ��-------------------" << endl;  // ���Ŀ� 1ȸ�� 2ȸ��.. �̷��� ���̰� ����.
	for (int i = 0; i < 7; i++) // 1-2. ������ ���ʽ� ��ȣ���� 7���� �صд�.
	{
		lonum6[i] = rand() % 45 + 1;
		for (int j = 0; j < i; j++)
		{
			if (lonum6[j] == lonum6[i])
			{
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < 6; i++) //�ζ� ��÷ ��ȣ ����ϱ�
	{
		cout << lonum6[i] << "\t";
	}

	cout << "�Դϴ�." << endl;
	cout << "2�� ���ʽ� ��ȣ�� " << lonum6[6] << " �Դϴ�." << endl; //���ʽ���ȣ �������
	cout << endl;
	for (int i = 0; i < 6; i++) //���� �Է��Ѱ� �Ϸķ� �����ؼ� �����ֱ�
	{
		cout << usernum6[i] << "\t";
	}
	count = 0; // ������� ī��Ʈ �ʱ�ȭ
	cout << "<- ���� ������ ��ȣ" << endl;
	for (int i = 0; i < 6; i++)  //��� ��ġ�ϴ��� üũ
	{
		for (int j = 0; j < 6; j++)
		{
			if (usernum6[i] == lonum6[j]) //�Է°��� ��÷��ȣ�� ������ Ȯ���ϰ�
			{
				count++;  // ���ٸ� ī��Ʈ���� +1 �߰� (��÷��ȣ����)
				break;
			}
		}
	}
	cout << endl;
	cout << "��ȣ�� �� " << count << "�� ��ġ. ";
	bonusnum = 0;//���ʽ���ȣ��ġ���� �ʱ�ȭ
	if (count == 5) //���ʽ���ȣ ��ġ�ϸ� 1�� �ٲ��ֱ�
	{
		for (int i = 0; i < 6; i++)
		{
			if (usernum6[i] == lonum6[7])
				bonusnum = 1;
			else
				bonusnum = 0;
		}
	}

	switch (count) //��÷������ ��÷�ݾ� �����ִ� ���� ����ϱ�.
	{
	case 3:
		cout << "5�� �Դϴ�.  ��÷��: 5,000 ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		G2.money(5000, player - 1);
		cout << "������: " << G2.money(0, player - 1) << " ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		break;
	case 4:
		cout << "4�� �Դϴ�.  ��÷��: 50,000 ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		G2.money(50000, player - 1);
		cout << "������: " << G2.money(0, player - 1) << " ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		break;
	case 5:
		if (bonusnum == 1)
		{
			cout << "2�� �Դϴ�.  ��÷��: 40,000,000 ��" << endl;
			cout << "----------------------------------------------------------" << endl;
			G2.money(40000000, player - 1);
			cout << "������: " << G2.money(0, player - 1) << " ��" << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
		else
		{
			cout << "3�� �Դϴ�.  ��÷��: 1,000,000 ��" << endl;
			cout << "----------------------------------------------------------" << endl;
			G2.money(1000000, player - 1);
			cout << "������: " << G2.money(0, player - 1) << " ��" << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
	case 6:
		cout << "1�� �Դϴ�.  ��÷��: 2,000,000,000 ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		G2.money(2000000000, player - 1);
		cout << "������: " << G2.money(0, player - 1) << " ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		break;
	default:
		cout << "��. ��÷�Դϴ�." << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "������: " << G2.money(0, player - 1) << " ��" << endl;
		cout << "----------------------------------------------------------" << endl;
		break;
	}
	cout << endl;
	endprint();
	cin >> remenu;
	system("cls");  // �ý��� ���ȭ�� �����
	return remenu;
}
int lotto::chart()
{
	system("cls");
	cout << "-----��÷ �ݾ�-----" << endl;
	cout << "3�� ���� ���߱�" << endl;
	cout << "1�� 10,000 ��" << endl;
	cout << "2�� 5,000 ��" << endl;
	cout << "3�� 1,000 ��" << endl;
	cout << "-------------------" << endl;
	cout << "�ζ� �ù�" << endl;
	cout << "1�� 2,000,000,000 ��" << endl;
	cout << "2�� 40,000,000 ��" << endl;
	cout << "3�� 1,000,000 ��" << endl;
	cout << "4�� 50,000 ��" << endl;
	cout << "5�� 5,000 ��" << endl;
	cout << endl;
	cout << "-------------------" << endl;
	cout << "�޴��� ���ư��÷��� �ƹ����ڳ� �Է����ּ���." << endl;
	cin >> remenu;
	system("cls");  // �ý��� ���ȭ�� �����
	return 0;
}
