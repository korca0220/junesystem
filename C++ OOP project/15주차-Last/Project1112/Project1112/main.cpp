#include <iostream>
#include "firstmenu.h"
using namespace std;
int main()
{
	firstmenu *in = new firstmenu(); 
	int gameselect = 0;
	int selectplayer = 0;
	while (1)
	{
		gameselect = in->mainmenu();	//--------------------- ������� 1 : �������. mainmenu()�Լ��� ���ϸ��� ����ǰ� �� �޴���(����)�� ������ ��ȯ�Ѵ�.  ����� 0 ��. [���α׷��� �����Ҷ����� �ݺ�.]
		if (gameselect == 0) return 0;
		do 
		{
			selectplayer = in->personselect(); //-------------- ������� 2 : ���(��ü)�� ����, ������ ����� �迭��ȣ��ȯ
			if (selectplayer == 0) break;
			in->gamestartmenu(gameselect, selectplayer); //---- ������� 3 : ������ ���� ��ȣ�� ����� �迭��ȣ�� ������ ������ �����Ų��. [�ش� ������ �����ϰ��� �Ҷ����� �ݺ�.]
			system("cls");
		} while (!selectplayer == 0);
	}
	delete in;
	return 0;
}

