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
int isWin(int x, int y)		//判断五子棋的胜利规则
{
	if ((map[x][y] == map[x - 1][y] && map[x][y] == map[x - 2][y] && map[x][y] == map[x - 3][y]&& map[x][y] == map[x - 4][y])
		||//最后一子：横向第五子
		(map[x][y] == map[x + 1][y] && map[x][y] == map[x - 1][y] && map[x][y] == map[x - 2][y] && map[x][y] == map[x - 3][y])
		||//最后一子：横向第四子
		(map[x][y] == map[x + 2][y] && map[x][y] == map[x + 1][y] && map[x][y] == map[x - 1][y] && map[x][y] == map[x - 2][y])
		||//最后一子：横向第三子
		(map[x][y] == map[x + 3][y] && map[x][y] == map[x + 2][y] && map[x][y] == map[x + 1][y] && map[x][y] == map[x - 1][y])
		||//最后一子：横向第二子
		(map[x][y] == map[x + 4][y] && map[x][y] == map[x + 3][y] && map[x][y] == map[x + 2][y] && map[x][y] == map[x + 1][y])
		||//最后一子：横向第一子
		(map[x][y] == map[x][y + 1] && map[x][y] == map[x][y + 2] && map[x][y] == map[x][y + 3] && map[x][y] == map[x][y + 4])
		||//最后一子：列向第五子
		(map[x][y] == map[x][y + 1] && map[x][y] == map[x][y + 2] && map[x][y] == map[x][y + 3] && map[x][y] == map[x][y - 1])
		||//最后一子：列向第四子
		(map[x][y] == map[x][y + 1] && map[x][y] == map[x][y + 2] && map[x][y] == map[x][y - 1] && map[x][y] == map[x][y - 2])
		||//最后一子：列向第三子
		(map[x][y] == map[x][y + 1] && map[x][y] == map[x][y - 1] && map[x][y] == map[x][y - 2] && map[x][y] == map[x][y - 3])
		||//最后一子：列向第二子
		(map[x][y] == map[x][y - 1] && map[x][y] == map[x][y - 2] && map[x][y] == map[x][y - 3] && map[x][y] == map[x][y - 4])
		||//最后一子：列向第一子
		(map[x][y] == map[x + 1][y + 1] && map[x][y] == map[x + 2][y + 2] && map[x][y] == map[x + 3][y + 3]&& map[x][y] == map[x + 4][y + 4]) 
		||//最后一子：从右上往左下第五子
		(map[x][y] == map[x + 1][y + 1] && map[x][y] == map[x + 2][y + 2] && map[x][y] == map[x + 3][y + 3]&& map[x][y] == map[x - 1][y - 1]) 
		||//最后一子：从右上往左下第四子
		(map[x][y] == map[x + 1][y + 1] && map[x][y] == map[x + 2][y + 2] && map[x][y] == map[x - 1][y - 1]&& map[x][y] == map[x - 2][y - 2]) 
		||//最后一子：从右上往左下第三子
		(map[x][y] == map[x + 1][y + 1] && map[x][y] == map[x - 1][y - 1] && map[x][y] == map[x - 2][y - 2]&& map[x][y] == map[x - 3][y - 3]) 
		||//最后一子：从右上往左下第二子
		(map[x][y] == map[x - 1][y - 1] && map[x][y] == map[x - 2][y - 2] && map[x][y] == map[x - 3][y - 3]&& map[x][y] == map[x - 4][y - 4]) 
		||//最后一子：从右上往左下第一子
		(map[x][y] == map[x - 1][y + 1] && map[x][y] == map[x - 2][y + 2] && map[x][y] == map[x - 3][y + 3]&& map[x][y] == map[x - 4][y + 4]) 
		||//最后一子：从左上往右下第五子
		(map[x][y] == map[x - 1][y + 1] && map[x][y] == map[x - 2][y + 2] && map[x][y] == map[x - 3][y + 3]&& map[x][y] == map[x + 1][y - 1]) 
		||//最后一子：从左上往右下第四子
		(map[x][y] == map[x - 1][y + 1] && map[x][y] == map[x - 2][y + 2] && map[x][y] == map[x + 1][y - 1]&& map[x][y] == map[x + 2][y - 2]) 
		||//最后一子：从左上往右下第三子
		(map[x][y] == map[x - 1][y + 1] && map[x][y] == map[x + 1][y - 1] && map[x][y] == map[x + 2][y - 2]&& map[x][y] == map[x + 3][y - 3]) 
		||//最后一子：从左上往右下第二子
		(map[x][y] == map[x + 1][y - 1] && map[x][y] == map[x + 2][y - 2] && map[x][y] == map[x + 3][y - 3]&& map[x][y] == map[x + 4][y - 4])
		)//最后一子：从左上往右下第一子
		return 1;
	else
		return 0;
}

int playerMove(int x, int y) //玩家下棋子在棋盘上的操作
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

void menuView() //游戏初始菜单
{
	int a = 0;
	cout << "欢迎您，来到五子棋游戏！请选择操作（1-3）："<<endl;
	cout << "1.进入游戏" << endl;    //展示选项
	cout << "2.进入设置" << endl;
	cout << "3.退出游戏" << endl;
	cin >> a;
	if (a == 1)
		gameView();
	if (a == 2)
		cout << "敬请期待...";
	if (a == 3)
		exit(0);
}

void gameView_ShowMap()		//游戏棋盘展示
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

void winView()			//游戏胜利界面
{
	if (flag % 2 == 0)
		cout << "黑棋方获胜！" << endl;
	else
		cout << "白棋方获胜！" << endl;
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
			cout << "本回合为黑方落子：" << endl;
		else
			cout << "本回合为白方落子：" << endl;
		cin >> x >> y;
		while (x < 0 || y < 0 || x > 18 || y > 18) {
			cout << "坐标不在棋盘范围内，请重新输入:"<<endl;
			cin >> x >> y;
		}
		while (playerMove(x, y) == 0) {
			cout << "此处已经有棋子，请重新输入:"<<endl;
			cin >> x >> y;
		}
		if (isWin(x, y)) {
			gameView_ShowMap();
			winView();
		}
		flag++;
	}
}