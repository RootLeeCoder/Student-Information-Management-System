#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "menu.h"
#include "operation.h"
using namespace std;

int main()
{
	FILE *fp;
	char input[20];
    int service=0;//选择数字 
    if((fp=fopen("student.dat","rb"))==NULL)//新建student.dat
    {
        cout << "File Not Found! Do you want to create a new file? [Y/N]" << endl;
        cin >> input;
        if(strcmp(input,"Y")==0||strcmp(input,"y")==0)
        {
            fp=fopen("student.dat","wb");
            fclose(fp);//关闭文件保存 
        }
        else
            exit(0);//正常退出 
    }
    else
    {
        Number=Read(st);
    }
    system("cls");//清屏 
    while(1)
    {
        menu();
        cout << "Please Select a Service: ";
        cin >> service;
        system("cls");
        switch(service)
        {
	        case 0: exit(0);Back();break;
	        case 1: Add_1();Back();break;
	        case 2: Del_2();Back();break;
	        case 3: Data_3();Back();break;
	        case 4: Search_4();Back();break;
	        case 5: Change_5();Back();break;
	        case 6: Creator_6();Back();break;
	        case 7: Exit();exit(0);Back();break;
	        case 8: Exit();exit(0);Back();break;
	        case 9: Exit();exit(0);Back();break;
	        default:break;
        }
        fflush(stdin);//清空输入缓冲区 
        getchar();//直到用户按回车为止 
        system("cls");
    }
    return 0;
}
