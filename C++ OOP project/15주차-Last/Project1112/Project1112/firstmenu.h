#ifndef FIRSTMENU_H
#define FIRSTMENU_H
class firstmenu
{
private:
	int player;
	int selectplayer;
	int realMoney;
	int gamecount;
public:
	int mainmenu(); //1��. ���θ޴��� ����ְ� ������ �޴��� ��ȯ�ϴ� �Լ�
	int personselect(); //2��. ���ϴ¸�ŭ �÷��̾� ���� �� ������ �÷��̾��� �迭��ȣ ��ȯ
	int checkfirstgame; //ó�� �������� üũ
	void gamestartmenu(int game, int y); //3��. �޴���, �÷��̾� �迭��ȣ�� �Ѱܹ޾� ���ӽ���.
	int lastmenu(std::string gamename);
	int lastmenu2(std::string gamename);
	void Givemoney(int mon); // �� ���ӿ��� ��ȯ�� ���� �÷��̾ �Ѱܼ�����
	firstmenu *person[100]; 
	virtual void startgame(int y);
};

class lottogame : public firstmenu
{
public:
	void startgame(int y);
};

class gawigame : public firstmenu
{
public:
	void startgame(int y);
};

class russiangame : public firstmenu
{
public:
	void startgame(int y);
};

#endif