#ifndef MONEY_H
#define MONEY_H

class gamemoney
{
public:  //Ŭ�������� static ������ �ݵ�� class ������ �ʱ�ȭ�� �ؾ���.
	static unsigned int money(unsigned int x, int y) // ������ �Լ� (x���� �ݾ� ������, y���� �÷��̾� �迭��ȣ. 0�����ͽ���)
	{
		static int count = 0;
		static unsigned int mon[100];
		if (count == 0)
		{
			for (int i = 0; i < 100; i++)
				mon[i] = 10000;
			count = 1;
		}

		mon[y] = mon[y] + x;
		return mon[y];
	}
};
#endif


