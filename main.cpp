/*
SKFP - A self-criticism generator with a lot of garbage
Copyroght (C) 2022 Kiki Tan
This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

Also add information on how to contact you by electronic and paper mail.
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
	int count;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int year=1900+ltm->tm_year;
	cout<<"Copyright (C) "<<year<<" Kiki Tan"<<endl;
        cout<<"SKFP v0.1 Alpha"<<endl;
        cout<<"SKFP没有任何保证，了解更多请到GitHub页面查看更多."<<endl;
        cout<<"这是一个自由软件，欢迎再次分发本程序，但要满足一定条件."<<endl;
        cout<<"请输入检讨的字数：";
	cin>>count;
	
	string a[10240],t,out;
	int i=1,s=0;
	ifstream readfile("source");
	ofstream OutFile("jiantao.txt");
	while(!readfile.eof()){
		readfile>>a[i];
		i++;
		s++;
	}
	i=1;
	readfile.seekg(0,ios::beg);
	int ss=0,r;
	srand((int)time(0)); 
	while(out.length()<=count){
    	r=rand()%s+1;
    	if(a[rand()%s+1]==""){
    		continue;
    	}
    	else{
    		if(a[r]==t){
	   			continue;
	   		}else{
	   			out+=a[r];
	   		}
	    		t=a[r];
	    		ss++;
	    	}
	        cout<<out.length();
	    }
    OutFile<<out;
	readfile.close();
	cout<<"生成完毕，文件保存在目录下的jiantao.txt。感谢你的使用。"<<endl;
	system("pause");
	return 0;
}
