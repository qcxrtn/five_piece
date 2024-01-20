#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int map[19][19];
int flag;
void init();
int isWin(int x, int y);
int playerMove(int x, int y);
void menuView();
void gameView_ShowMap();
void winView();
void gameView();
int main()
{
	init();
	menuView();
	system("pause");
	return 0;
}
void init() 
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			map[i][j] = 0;
		}	
		flag = 0;
	}	
}
int isWin(int x, int y)		//�ж��������ʤ������
{
	if ((map[x][y] == map[x - 1][y] && map[x][y] == map[x - 2][y] && map[x][y] == map[x - 3][y]&& map[x][y] == map[x - 4][y])
		||//���һ�ӣ����������
		(map[x][y] == map[x + 1][y] && map[x][y] == map[x - 1][y] && map[x][y] == map[x - 2][y] && map[x][y] == map[x - 3][y])
		||//���һ�ӣ����������
		(map[x][y] == map[x + 2][y] && map[x][y] == map[x + 1][y] && map[x][y] == map[x - 1][y] && map[x][y] == map[x - 2][y])
		||//���һ�ӣ����������
		(map[x][y] == map[x + 3][y] && map[x][y] == map[x + 2][y] && map[x][y] == map[x + 1][y] && map[x][y] == map[x - 1][y])
		||//���һ�ӣ�����ڶ���
		(map[x][y] == map[x + 4][y] && map[x][y] == map[x + 3][y] && map[x][y] == map[x + 2][y] && map[x][y] == map[x + 1][y])
		||//���һ�ӣ������һ��
		(map[x][y] == map[x][y + 1] && map[x][y] == map[x][y + 2] && map[x][y] == map[x][y + 3] && map[x][y] == map[x][y + 4])
		||//���һ�ӣ����������
		(map[x][y] == map[x][y + 1] && map[x][y] == map[x][y + 2] && map[x][y] == map[x][y + 3] && map[x][y] == map[x][y - 1])
		||//���һ�ӣ����������
		(map[x][y] == map[x][y + 1] && map[x][y] == map[x][y + 2] && map[x][y] == map[x][y - 1] && map[x][y] == map[x][y - 2])
		||//���һ�ӣ����������
		(map[x][y] == map[x][y + 1] && map[x][y] == map[x][y - 1] && map[x][y] == map[x][y - 2] && map[x][y] == map[x][y - 3])
		||//���һ�ӣ�����ڶ���
		(map[x][y] == map[x][y - 1] && map[x][y] == map[x][y - 2] && map[x][y] == map[x][y - 3] && map[x][y] == map[x][y - 4])
		||//���һ�ӣ������һ��
		(map[x][y] == map[x + 1][y + 1] && map[x][y] == map[x + 2][y + 2] && map[x][y] == map[x + 3][y + 3]&& map[x][y] == map[x + 4][y + 4]) 
		||//���һ�ӣ������������µ�����
		(map[x][y] == map[x + 1][y + 1] && map[x][y] == map[x + 2][y + 2] && map[x][y] == map[x + 3][y + 3]&& map[x][y] == map[x - 1][y - 1]) 
		||//���һ�ӣ������������µ�����
		(map[x][y] == map[x + 1][y + 1] && map[x][y] == map[x + 2][y + 2] && map[x][y] == map[x - 1][y - 1]&& map[x][y] == map[x - 2][y - 2]) 
		||//���һ�ӣ������������µ�����
		(map[x][y] == map[x + 1][y + 1] && map[x][y] == map[x - 1][y - 1] && map[x][y] == map[x - 2][y - 2]&& map[x][y] == map[x - 3][y - 3]) 
		||//���һ�ӣ������������µڶ���
		(map[x][y] == map[x - 1][y - 1] && map[x][y] == map[x - 2][y - 2] && map[x][y] == map[x - 3][y - 3]&& map[x][y] == map[x - 4][y - 4]) 
		||//���һ�ӣ������������µ�һ��
		(map[x][y] == map[x - 1][y + 1] && map[x][y] == map[x - 2][y + 2] && map[x][y] == map[x - 3][y + 3]&& map[x][y] == map[x - 4][y + 4]) 
		||//���һ�ӣ������������µ�����
		(map[x][y] == map[x - 1][y + 1] && map[x][y] == map[x - 2][y + 2] && map[x][y] == map[x - 3][y + 3]&& map[x][y] == map[x + 1][y - 1]) 
		||//���һ�ӣ������������µ�����
		(map[x][y] == map[x - 1][y + 1] && map[x][y] == map[x - 2][y + 2] && map[x][y] == map[x + 1][y - 1]&& map[x][y] == map[x + 2][y - 2]) 
		||//���һ�ӣ������������µ�����
		(map[x][y] == map[x - 1][y + 1] && map[x][y] == map[x + 1][y - 1] && map[x][y] == map[x + 2][y - 2]&& map[x][y] == map[x + 3][y - 3]) 
		||//���һ�ӣ������������µڶ���
		(map[x][y] == map[x + 1][y - 1] && map[x][y] == map[x + 2][y - 2] && map[x][y] == map[x + 3][y - 3]&& map[x][y] == map[x + 4][y - 4])
		)//���һ�ӣ������������µ�һ��
		return 1;
	else
		return 0;
}

int playerMove(int x, int y) //����������������ϵĲ���
{
	int type;
	if (flag % 2 == 0) 
	{
		type = 1;
	}
	else
		type = 2;

	if (map[x][y] == 0) 
	{
		map[x][y] = type;
		return 1;
	}
	else return 0;
}

void menuView() //��Ϸ��ʼ�˵�
{
	int a = 0;
	cout << "��ӭ����������������Ϸ����ѡ�������1-3����"<<endl;
	cout << "1.������Ϸ" << endl;    //չʾѡ��
	cout << "2.��������" << endl;
	cout << "3.�˳���Ϸ" << endl;
	cin >> a;
	if (a == 1)
		gameView();
	if (a == 2)
		cout << "�����ڴ�...";
	if (a == 3)
		exit(0);
}

void gameView_ShowMap()		//��Ϸ����չʾ
{
	cout << "-------------------------------------------------" << endl;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void winView()			//��Ϸʤ������
{
	if (flag % 2 == 0)
		cout << "���巽��ʤ��" << endl;
	else
		cout << "���巽��ʤ��" << endl;
	system("pause");
	menuView();
}

void gameView() 
{
	int x, y;
	init(); 
	while (1) {
		gameView_ShowMap();
		if (flag % 2 == 0)
			cout << "���غ�Ϊ�ڷ����ӣ�" << endl;
		else
			cout << "���غ�Ϊ�׷����ӣ�" << endl;
		cin >> x >> y;
		while (x < 0 || y < 0 || x > 18 || y > 18) {
			cout << "���겻�����̷�Χ�ڣ�����������:"<<endl;
			cin >> x >> y;
		}
		while (playerMove(x, y) == 0) {
			cout << "�˴��Ѿ������ӣ�����������:"<<endl;
			cin >> x >> y;
		}
		if (isWin(x, y)) {
			gameView_ShowMap();
			winView();
		}
		flag++;
	}
}