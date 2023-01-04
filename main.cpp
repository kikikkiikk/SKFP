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
using namespace std;

// 定义变量
int count;
time_t now = time(0);
tm *ltm = localtime(&now);
int year = 1900 + ltm->tm_year;
string a[10240], t, out;
int i = 1, s = 0;

// 输出版权信息
void printCopyrightInformation(int yearOfCopyright)
{
	cout << "Copyright (C) " << yearOfCopyright << " Kiki Tan" << endl;
	cout << "SKFP v0.1 Alpha" << endl;
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
void readSourceFile(string FileName){
	// 定义文件输入流
	ifstream readfile(FileName);
	// 将文件读入数组a
	while (!readfile.eof())
	{
		// 读取文件并存入数组a
		readfile >> a[i];
		// 检测本句开头是否为#（注释），若是，停留在此，等待下一次读入数据的覆盖；若不是，正常读入数据并跳转到下一分量
		// 如果仅有一个#存在，而不存在注释内容，#将被当作正常句子输入
		if (a[i].length() >= 2){
			char theFirstLetter = a[i].at(0);
			if (!(theFirstLetter == '#')){
				i++;
				s++;
			}
		}
		else{
			i++;
			s++;
		}
	}
	readfile.close();
}
int main()
{
	// 输出版权信息
	printCopyrightInformation(year);

	// 获取检讨字数
	count = getNumberOfWord();

	//读入文件
	readSourceFile("source");

	int ss = 0, r;
	srand((int)time(0));
	while (out.length() <= count)
	{
		r = rand() % s + 1;
		if (a[rand() % s + 1] == "")
		{
			continue;
		}
		else
		{
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
		cout << "当前字数：" << out.length() << endl;
		;
	}
	ofstream OutFile("jiantao.txt");
	OutFile << out;
	cout << "生成完毕，文件保存在目录下的jiantao.txt。感谢你的使用。" << endl;
	cout << "最终文件字数：" << out.length() << endl;
	system("pause");
	return 0;
}
