#ifndef GAWI_H
#define GAWI_H

class gawi
{
private:
	int user; //������ �÷����� user(player)����
	int com; //������ ������ �ϰԵ� computer
	int count; //�¸��� ���� üũ
	int enter; //�Է� ����
	int realMoney; //�� user�� �����ִ� ���� �������� ����
public:
	void gawiPrint(int pp);
	int run(int p);
	int money(int a, int b);
};
#endif