#include "stdafx.h"
#include<iostream> 
#include <fstream>
#include <stdlib.h>
#include<string>
using namespace std;
int siz;
bool sign;
int num[10][10], num2[100][100][100];
int main(int argc, char* argv[])
{
	int k, i, j;
	char* in;  //�����ļ� 
	char* out;  //����ļ� 
	int time;   //������Ŀ 

	siz = atoi(argv[2]);  //atoi (ascii to integer)�ǰ��ַ���ת������������һ������ 
					   //ͷ�ļ�Ϊ #include <stdlib.h> 
	time = atoi(argv[4]);

	in = argv[6];
	ifstream infile(in);
	out = argv[8];
	ofstream outfile(out);
	for (k = 0; k < time; k++) {
		char temp[10][10] = { 0 };
		int l = 0;
		for (i = 0; i < siz; i++)
		{
			for (j = 0; j < siz; j++)
			{
				infile >> temp[i][j];
				num[i][j] = temp[i][j] - '0';   // �����ַ��������ASCII��֮��ļ�������
			}
			l++;
		}
		cout << "\n";
		sign = false;    //�˴�ע��һ��Ҫ�ӣ�����
		DFS(0);

		for (i = 0; i < siz; i++)
		{
			for (j = 0; j < siz; j++)
			{
				num2[k][i][j] = num[i][j];
			}
		}

		for (i = 0; i < siz; i++)
		{
			for (j = 0; j < siz; j++)
			{
				cout << num2[k][i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";

		ofstream outfile;
		outfile.open("output.txt", ios::app);   //�Ժ�̷�ʽ���ļ��Ա����д
		for (int i = 0; i < siz; i++) {
			for (int j = 0; j < siz; j++) {
				outfile << num2[k][i][j] << " ";
			}
			outfile << endl;
		}
		outfile << "\n";
		outfile.close();
	}

	/*for ( k = 0; k < time; k++)
	{
		for ( i = 0; i < siz; i++)
		{
			for ( j = 0; j < siz; j++)
			{
				cout << num2[k][i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}*/


	return 0;
}
