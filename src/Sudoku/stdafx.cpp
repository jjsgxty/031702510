#include "stdafx.h"

//�ж�shu����nʱ�Ƿ���������

bool Check(int n, int shu)
{
	//�ж�n���ں����Ƿ�Ϸ� 
	for (int i = 0; i < siz; i++)
	{
		int j = n / siz;    // jΪn������
		if (num[j][i] == shu) return false;
	}

	//�ж�n���������Ƿ�Ϸ� 
	for (int i = 0; i < siz; i++)
	{
		int j = n % siz;    //jΪn������ 
		if (num[i][j] == shu) return false;
	}
	if (siz == 4 || siz == 6 || siz == 8 || siz == 9)
	{
		int a, b;   //aΪÿ��С�����к���ĸ�������bΪ��������� 
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
		int x = n / siz / b * b;     //xΪn���ڵ�С�����󶥵�������

		int y = n % siz / a * a;     //yΪn���ڵ�С�����󶥵������


		//�ж�n���ڵ�С�����Ƿ�Ϸ� 
		for (int i = x; i < x + b; i++)
		{
			for (int j = y; j < y + a; j++)
			{
				if (num[i][j] == shu) return false;
			}
		}
	}
	return true;    //���Ϸ���������ȷ

}


//���ѹ������� 
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
	//���еĶ����ϣ��˳��ݹ� 

	if (n > amount)
	{
		sign = true;
		return 0;
	}

	//��ǰλ��Ϊ��ʱ����
	if (num[n / siz][n % siz] != 0)
	{
		DFS(n + 1);
	}

	else
	{
		//����Ե�ǰλ����ö�ٲ��� 
		for (int i = 1; i <= siz; i++)
		{
			//��������ʱ�������� 
			if (Check(n, i) == true)
			{
				num[n / siz][n % siz] = i;
				DFS(n + 1);    // �������� 

				 //����ʱ�������ɹ�����ֱ���˳� 
				if (sign == true) {
					return 0;
				}

				//������첻�ɹ�����ԭ��ǰλ 
				num[n / siz][n % siz] = 0;
			}

		}

	}
	return 0;  //�˴����ӻ��о���
}