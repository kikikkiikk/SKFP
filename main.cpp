/*
SKFP - A self-criticism generator with a lot of garbage
Copyroght (C) 2022 Kiki Tan
This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

Also add information on how to contact you by electronic and paper mail.
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
using namespace std;

// 宏定义（彩色文字输出）
#ifndef _COLOR_H_
#define _COLOR_H_

#define NONE "\e[0m"		// 清除颜色，即之后的打印为正常输出，之前的不受影响
#define BLACK "\e[0;30m"	// 深黑
#define L_BLACK "\e[1;30m"	// 亮黑，偏灰褐
#define RED "\e[0;31m"		// 深红，暗红
#define L_RED "\e[1;31m"	// 鲜红
#define GREEN "\e[0;32m"	// 深绿，暗绿
#define L_GREEN "\e[1;32m"	// 鲜绿
#define BROWN "\e[0;33m"	// 深黄，暗黄
#define YELLOW "\e[1;33m"	// 鲜黄
#define BLUE "\e[0;34m"		// 深蓝，暗蓝
#define L_BLUE "\e[1;34m"	// 亮蓝，偏白灰
#define PURPLE "\e[0;35m"	// 深粉，暗粉，偏暗紫
#define L_PURPLE "\e[1;35m" // 亮粉，偏白灰
#define CYAN "\e[0;36m"		// 暗青色
#define L_CYAN "\e[1;36m"	// 鲜亮青色
#define GRAY "\e[0;37m"		// 灰色
#define WHITE "\e[1;37m"	// 白色，字体粗一点，比正常大，比bold小
#define BOLD "\e[1m"		// 白色，粗体
#define UNDERLINE "\e[4m"	// 下划线，白色，正常大小
#define BLINK "\e[5m"		// 闪烁，白色，正常大小
#define REVERSE "\e[7m"		// 反转，即字体背景为白色，字体为黑色
#define HIDE "\e[8m"		// 隐藏
#define CLEAR "\e[2J"		// 清除
#define CLRLINE "\r\e[K"	// 清除行

#endif

// 定义变量
int count;
time_t now = time(0);
tm *ltm = localtime(&now);
int year = 1900 + ltm->tm_year;
string a[10240], t, out;
int i = 1, s = 0, ss = 0, r, temp;

// 输出版权信息
void printCopyrightInformation(int yearOfCopyright)
{
	// 名称字符画
	cout << BLUE << "       ----------------------------------" << endl;
	cout << BLUE << "      /  " << L_GREEN << "____   " << L_RED << "_  __ " << L_BLUE << "_____ " << L_PURPLE << "____       " << BLUE << "/" << endl;
	cout << BLUE << "     /  " << L_GREEN << "/ ___| " << L_RED << "| |/ /" << L_BLUE << "|  ___" << L_PURPLE << "| _   \\    " << BLUE << "/" << endl;
	cout << BLUE << "    /   " << L_GREEN << "\\___ \\ " << L_RED << "| ' / " << L_BLUE << "| |_  " << L_PURPLE << "| |_) |   " << BLUE << "/" << endl;
	cout << BLUE << "   /     " << L_GREEN << "___) |" << L_RED << "| . \\ " << L_BLUE << "|  _| " << L_PURPLE << "|  __/   " << BLUE << "/" << endl;
	cout << BLUE << "  /     " << L_GREEN << "|____/ " << L_RED << "|_|\\_\\" << L_BLUE << "|__|  " << L_PURPLE << "|_|     " << BLUE << "/" << endl;
	cout << BLUE << " /                                /" << endl;
	cout << BLUE << "----------------------------------" << endl;

	// 版权（遵循GNU General Public License v2.0）
	cout << NONE << "SKFP v1.0 Release" << endl;
	cout << "Copyright (C) " << yearOfCopyright << " Kiki Tan" << endl;
	cout << "SKFP没有任何保证，了解更多请到GitHub页面查看更多." << endl;
	cout << "这是一个自由软件，欢迎再次分发本程序，但要满足一定条件." << endl;
}

// 获取检讨字数
int getNumberOfWord()
{
	int numberOfWord;
	cout << "请输入检讨的字数：";
	cin >> numberOfWord;
	return numberOfWord;
}

// 读入文件
void readSourceFile(string FileName)
{
	// 定义文件输入流
	ifstream readfile(FileName);
	// 将文件读入数组a
	while (!readfile.eof())
	{
		// 读取文件并存入数组a
		readfile >> a[i];
		// 检测本句开头是否为#（注释），若是，停留在此，等待下一次读入数据的覆盖；若不是，正常读入数据并跳转到下一分量
		// 如果仅有一个#存在，而不存在注释内容，#将被当作正常句子输入
		if (a[i].length() >= 2)
		{
			char theFirstLetter = a[i].at(0);
			if (!(theFirstLetter == '#'))
			{
				i++;
				s++;
			}
		}
		else
		{
			i++;
			s++;
		}
	}
	readfile.close();
}

// 随机抽取并写入变量
void chooseAndWriteToVariable(){
	// 定义随机种子
	srand(time(0));
	
	// 清屏，否则进度条有bug
	system("clear");

	// 抽取并写入变量
	while (out.length() < count)
	{
		// 获取随机数
		r = rand() % s + 1;

		// 如果变量为空，则跳过此变量，否则写入字符串out
		if (a[rand() % s + 1] == "")
		{
			continue;
		}
		else
		{
			// 如果与上一句重复，则跳过，否则写入
			if (a[r] == t)
			{
				continue;
			}
			else
			{
				out += a[r];
			}
			t = a[r];
			ss++;
		}

		// 输出当前字数
		//cout << "当前字数：" << out.length() << endl;
		printf("\033[u");
		printf("\033[s");
		float percent = (float)out.length()/(float)count*100.0;
		cout << "[";
		for(int i_ProgressBar = 0; i_ProgressBar < int(percent) / 5; i_ProgressBar++) cout<<"■";
		for(int i_ProgressBar = 0; i_ProgressBar < 20 - (int(percent) / 5) ; i_ProgressBar++) printf(" ");
		printf("\033[K");
		cout << "]" << percent << "%";
		sleep(0.5);
	}
}
int main()
{
	// 输出版权信息
	printCopyrightInformation(year);

	// 获取检讨字数
	count = getNumberOfWord();

	// 开始计时（计算生成用时）
	clock_t start_time = clock();

	// 读入文件
	readSourceFile("source");

	// 随机抽取并写入变量
	chooseAndWriteToVariable();


	ofstream OutFile("jiantao.txt");
	OutFile << out;
	OutFile.close();
	clock_t end_time = clock();
	cout << endl<<"生成完毕，文件保存在目录下的jiantao.txt。感谢你的使用。" << endl;
	cout << "最终文件字数：" << out.length() << endl;
	cout << "耗时：" << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	cout << "请按回车键继续...";
	getchar();
	cin.get();
	return 0;
}
