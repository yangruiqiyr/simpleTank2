// simpleTank3.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include "tank.h"
#include "unit.h"
#include<stdio.h>
#include<stdlib.h>


int main()
{
	setsometing();
	ShowCursor();
	SetWindowSize("坦克大战", 150, 50);
	char f5[30] = "欢迎进入坦克大战\n";
	char f8[30] = "该功能尚未开发完毕\n";
	PrintCHar(24, 20, f5, 7);
	char f6[30] = "作者：杨睿琦\n";
	PrintCHar(30, 22, f6, 7);
	char f7[30] = "来源：15PB\n";
	PrintCHar(30, 23, f7, 7);
	getchar();
	system("cls");
	int fina = 0;
	int temp = 0;
	while (1) {
		int nNum = -1;
		system("cls");
		PrintCHar(24, 20, "*******************************", 7);
		PrintCHar(24, 21, "*1.地图编辑                   *", 7);
		PrintCHar(24, 22, "*2.开始游戏                   *", 7);
		PrintCHar(24, 23, "*3.继续游戏                   *", 7);
		PrintCHar(24, 24, "*4.退出游戏                   *", 7);
		PrintCHar(24, 25, "*******************************", 7);
		scanf_s("%d", &nNum);
		if (nNum == 4)
			return 0;
		switch (nNum)
		{
		case 1:
			system("cls");
			initMap();
			DrawMap();
			MessageLoop();
			temp = 1;
			break;
		case 2:
			system("cls");
			if(temp==0)initMap();
			DrawMap();
			printMap();
			pGameIntroduce();
			allTank *aTank = NULL;
			allBullet* aBullet = NULL;
			initTank(&aTank);
			initPlayerTank(aTank, 18, 47, 6, 2, 2);
			initCompuTank(aTank, 1, 5, 4);
			initBullet(&aBullet);
			printAllpTank(aTank);
			fina = run(aTank, aBullet);
			system("cls");
			if (fina == 6)
			{
				char f[30] = "失败，你老家炸了\n";
				PrintCHar(24, 20, f, 7);
				getchar();
				getchar();
			}
			if (fina == 5)
			{
				char f[30] = "玩家胜利\n";
				PrintCHar(24, 20, f, 7);
				getchar();
				getchar();
			}
			if (fina == 4)
			{
				char f[30] = "玩家和敌人都被摧毁，游戏结束\n";
				PrintCHar(24, 20, f, 7);
				getchar();
				getchar();
			}
			if (fina == 3)
			{
				char f[30] = "玩家被摧毁，游戏失败\n";
				PrintCHar(24, 20, f, 7);
				getchar();
				getchar();
			}
			break;
		}
	}
	getchar();
	return 0;
}


