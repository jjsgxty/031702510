#include "stdafx.h"

//判断shu填入n时是否满足条件

bool Check(int n, int shu)
{
	//判断n所在横列是否合法 
	for (int i = 0; i < siz; i++)
	{
		int j = n / siz;    // j为n竖坐标
		if (num[j][i] == shu) return false;
	}

	//判断n所在竖列是否合法 
	for (int i = 0; i < siz; i++)
	{
		int j = n % siz;    //j为n横坐标 
		if (num[i][j] == shu) return false;
	}
	if (siz == 4 || siz == 6 || siz == 8 || siz == 9)
	{
		int a, b;   //a为每个小宫格中横向的格子数，b为纵向格子数 
		switch (siz)
		{
		case 4:
			a = 2, b = 2;
			break;
		case 6:
			a = 3, b = 2;
			break;
		case 8:
			a = 2, b = 4;
			break;
		case 9:
			a = 3, b = 3;
			break;
		}
		int x = n / siz / b * b;     //x为n所在的小宫格左顶点竖坐标

		int y = n % siz / a * a;     //y为n所在的小宫格左顶点横坐标


		//判断n所在的小宫格是否合法 
		for (int i = x; i < x + b; i++)
		{
			for (int j = y; j < y + a; j++)
			{
				if (num[i][j] == shu) return false;
			}
		}
	}
	return true;    //都合法，返回正确

}


//深搜构造数独 
int DFS(int n)
{
	int amount = 0;
	switch (siz)
	{
	case 3:
		amount = 8;
		break;
	case 4:
		amount = 15;
		break;
	case 5:
		amount = 24;
		break;
	case 6:
		amount = 35;
		break;
	case 7:
		amount = 48;
		break;
	case 8:
		amount = 63;
		break;
	case 9:
		amount = 80;
		break;
	}
	//所有的都符合，退出递归 

	if (n > amount)
	{
		sign = true;
		return 0;
	}

	//当前位不为空时跳过
	if (num[n / siz][n % siz] != 0)
	{
		DFS(n + 1);
	}

	else
	{
		//否则对当前位进行枚举测试 
		for (int i = 1; i <= siz; i++)
		{
			//满足条件时填入数字 
			if (Check(n, i) == true)
			{
				num[n / siz][n % siz] = i;
				DFS(n + 1);    // 继续搜索 

				 //返回时如果构造成功，则直接退出 
				if (sign == true) {
					return 0;
				}

				//如果构造不成功，还原当前位 
				num[n / siz][n % siz] = 0;
			}

		}

	}
	return 0;  //此处不加会有警告
}