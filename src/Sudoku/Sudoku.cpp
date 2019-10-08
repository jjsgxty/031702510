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
	char* in;  //输入文件 
	char* out;  //输出文件 
	int time;   //盘面数目 

	siz = atoi(argv[2]);  //atoi (ascii to integer)是把字符串转换成整形数的一个函数 
					   //头文件为 #include <stdlib.h> 
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
				num[i][j] = temp[i][j] - '0';   // 两个字符相减就是ASCII码之间的减法操作
			}
			l++;
		}
		cout << "\n";
		sign = false;    //此处注意一定要加！！！
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
		outfile.open("output.txt", ios::app);   //以后继方式打开文件以便继续写
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
