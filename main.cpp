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
    int service=0;//ѡ������ 
    if((fp=fopen("student.dat","rb"))==NULL)//�½�student.dat
    {
        cout << "File Not Found! Do you want to create a new file? [Y/N]" << endl;
        cin >> input;
        if(strcmp(input,"Y")==0||strcmp(input,"y")==0)
        {
            fp=fopen("student.dat","wb");
            fclose(fp);//�ر��ļ����� 
        }
        else
            exit(0);//�����˳� 
    }
    else
    {
        Number=Read(st);
    }
    system("cls");//���� 
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
        fflush(stdin);//������뻺���� 
        getchar();//ֱ���û����س�Ϊֹ 
        system("cls");
    }
    return 0;
}
