#ifndef LOTTO_H
#define LOTTO_H
class lotto  // lotto Ŭ���� ����
{
private:
	int menu; // �Է¹޴� �޴��� �������
	int count; // ��÷���� Ȯ���ϴ� �������
	int bonusnum; // �����ӿ��� ����ϴ� ���ʽ���ȣ �������
public:
	int simul3(int player); // 3�� ���� ���߱� �Լ�
	int simul6(int player); // �Ϲ� �ζǽùĵ����� �Լ�
	int chart(); // ��÷�ݾ���Ʈ �����ִ� �Լ�
	void endprint(); // �ǳ��� �����ִ� ���� �Լ�
	int remenu; // �޴��� ���ư��� �������
	int mainmenu(int player); //���θ޴����� �� �Է¹޴� �Լ�

};
#endif