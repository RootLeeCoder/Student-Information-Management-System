//operation.h
#include <iostream>
#include <string.h>
#ifndef _OPERATION_H_
#define _OPERATION_H_
using namespace std;

class Student {
public:
	Student(){};
	~Student(){};
	char ID[7];
    char name[60];
    int score;
    int score_Computer;
    int score_Math;
    int score_English;
};

void menu();//主菜单
int Read(class Student st[]);//文件读取 
void Save(class Student st[]);//文件保存
void Back();//返回
void Exit();//退出 

void Add_1(); //添加
void Del_2();//删除
void DeleteID();//删除学号
void DeleteName();//删除姓名  
void Data_3();//统计成绩
void Search_4();//查找
void SearchID();//查找学号 
void SearchName();//查找姓名 
void Change_5();//修改 
void ChangeID(); //修改学号
void ChangeName();//修改姓名
void Creator_6();//关于作者

class Student st[300]; //定义结构体变量 
int Number=0; //信息总数 

int Read(class Student st[])
{
    FILE *fp=NULL;
    int i=0;
    fp=fopen("student.dat","rb");
    while(fread(&st[i],sizeof(class Student),1,fp))
        i++;
    fclose(fp);
    return i;
}

void Save(class Student *st)
{
    FILE *fp=NULL;
    fp=fopen("student.dat","ab+");
    fwrite(st,sizeof(class Student),1,fp);
    fclose(fp);
}

void Back()
{
    cout << "Press Enter to return to the main menu" << endl;
}

void Exit()
{
    cout << "Goodbye! Thanks for using!" << endl;
}

void Add_1()
{
    int AddNumber=0;//增加学生的个数 
    int i=0;
    class Student temp;
    cout << "Please input the number of the increase students: ";
    cin >> AddNumber;
    for(i=0;i<AddNumber;i++)
    {
        cout << "Please input Student " << i+1 << " 's information: " << endl;
        cout << "ID: ";
        cin >> temp.ID;
        cout << "Name: ";
        cin >> temp.name;
        cout << "Computer Score: ";
        cin >> temp.score_Computer;
        cout << "Math Score: ";
        cin >> temp.score_Math;
        cout << "English Score: ";
        cin >> temp.score_English;
        temp.score=temp.score_Computer+temp.score_Math+temp.score_English;
        st[Number++]=temp;
        Save(&temp);
    }
    cout << "Add Successfully!" << endl;
}

void Del_2()
{
    int n=0;
    cout << "1. Delete by name" << endl;
    cout << "2. Delete by ID" << endl;
    cin >> n;
    switch(n)
    {
	    case 1: DeleteName();break;
	    case 2: DeleteID();break;
    }
}

void DeleteID()
{
    FILE *fp=NULL;
    char id[60];
    int i=0;
    int j=0;
    cout << "Please enter the student ID to delete" << endl;
    cin >> id;
    for(i=0;i<Number;i++)
    {
        if (strcmp(id,st[i].ID)==0)
        {
            for (j=i;j<Number-1;j++)
            {
                st[j]=st[j+1];
            }
            Number--;
        }
    }
    fp=fopen("C://student.dat","wb");
    for (i=0;i<Number;i++)
    {
        fwrite(&st[i],sizeof(class Student),1,fp);
    }
    fclose(fp);
    cout << "Delete Successfully!" << endl;
}

void DeleteName()
{
    FILE *fp=NULL;
    char name[60];
    int i=0;
    int j=0;
    cout << "Please enter the name of the student to be deleted: " << endl;
    cin >> name;
    for(i=0;i<Number;i++)
    {
        if(strcmp(name,st[i].name)==0)
        {
            for (j=i;j<Number-1;j++)
            {
                st[j]=st[j+1];//删除某信息 
            }
            Number--;
        }
    }
    fp=fopen("C://student.dat","wb");
    for (i=0;i<Number;i++)
    {
        fwrite(&st[i],sizeof(class Student),1,fp);
    }
    fclose(fp);
    cout << "Delete Successfully" << endl;
}

void Data_3()
{
	Student t;
    int i=0,max,min,count=0;
    int count_Computer=0, count_Math=0, count_English=0;
    int max_Computer, min_Computer, max_Math, min_Math, max_English, min_English;
    double sum=0.0,sum_Computer=0.0,sum_Math=0.0,sum_English=0.0;
    max=st[0].score; min=st[0].score;
    max_Computer=st[0].score_Computer;min_Computer=st[0].score_Computer;
    max_Math=st[0].score_Math;min_Math=st[0].score_Math;
    max_English=st[0].score_English;min_English=st[0].score_English;
    
    for (int k=0; k<i-1; k++)
	{
		for (int j=0; j<i-k-1; j++)
		{
			if (st[j].score<st[j+1].score)
			{t=st[j];st[j]=st[j+1];st[j+1]=t;}
		}
	}
    
	for(i=0;i<Number;i++)
    {
        cout << "Rank: " << i+1 << " ID: " << st[i].ID << " Name: " << st[i].name << endl << "Computer Score: " << st[i].score_Computer << " Math Score: " 
		<< st[i].score_Math << " English Score: " << st[i].score_English << endl << "Sum: " << st[i].score << endl << endl;
    }
    cout << endl;
    for(i=0;i<Number;i++)
    {
    	if (st[i].score_Computer>max_Computer)
    		max_Computer=st[i].score_Computer;
    	if (st[i].score_Computer<min_Computer)
    		min_Computer=st[i].score_Computer;
    	if (st[i].score_Math>max_Math)
    		max_Math=st[i].score_Math;
    	if (st[i].score_Math<min_Math)
    		min_Math=st[i].score_Math;
		if (st[i].score_English>max_English)
    		max_English=st[i].score_English;
    	if (st[i].score_English<min_English)
    		min_English=st[i].score_English;
		if (st[i].score>max)
    		max=st[i].score;
    	if (st[i].score<min)
    		min=st[i].score;
    	if (st[i].score_Computer>=60)
    		count_Computer++;
    	if (st[i].score_Math>=60)
    		count_Math++;
    	if (st[i].score_English>=60)
    		count_English++;
        sum_Computer+=st[i].score_Computer;
		sum_Math+=st[i].score_Math;
		sum_English+=st[i].score_English;
		sum+=st[i].score;
    }
    cout << "Computer: " << endl;
    cout << "Max: " << max_Computer;
    cout << " Min: " << min_Computer ;
    cout << " Average: " << sum_Computer/Number;
    cout << " Pass Rate: " << 100*(double)count_Computer/Number << "%" << endl;
    cout << "Math: " << endl;
    cout << "Max: " << max_Math;
    cout << " Min: " << min_Math ;
    cout << " Average: " << sum_Math/Number;
    cout << " Pass Rate: " << 100*(double)count_Math/Number << "%" << endl;
    cout << "English: " << endl;
    cout << "Max: " << max_English;
    cout << " Min: " << min_English ;
    cout << " Average: " << sum_English/Number;
    cout << " Pass Rate: " << 100*(double)count_English/Number << "%" << endl;
    cout << endl;
}

void Search_4()
{
    int n=0;
    cout << "Please select the way to search" << endl;
    cout << "1. By name" << endl;
    cout << "2. By ID" << endl;
    cin >> n;
    switch(n)
    {
	    case 1: SearchName();break;
	    case 2: SearchID();break;
	    default: cout << "Error,exit!" << endl;
	    break;
    }
}

void SearchID()
{
    char id[7];
    int i=0;
    cout << "Please enter the student number to find" << endl;
    cin >> id;
    system("cls");
    for(i=0;i<Number;i++)
    {
        if (strcmp(id,st[i].ID)==0)
        {
            cout << "ID: " << st[i].ID << " Name: " << st[i].name << " Score: " << st[i].score << endl;
        }
    }
}

void SearchName()
{
    char name[7];
    int i=0;
    cout << "Please enter the student name to find: " << endl;
    cin >> name;
    system("cls");
    for (i=0;i<Number;i++)
    {
        if (strcmp(name,st[i].name)==0)
        {
            cout << "ID: " << st[i].ID << " Name: " << st[i].name << " Score: " << st[i].score << endl;
        }
    }
}

void Change_5()
{
    int way=0;
    cout << "Please select the way to change" << endl;
    cout << "1. By name" << endl;
    cout << "2. By ID" << endl;
    cin >> way;
    switch(way)
    {
	    case 1: ChangeName();break;
	    case 2: ChangeID();break;
	    default: cout << "Error,exit!" << endl;
		break;
    }
}

void ChangeID()
{
    FILE *fp=NULL;
    char id[60];
    int i=0;
    int changeIndex=0;
    int index=0;
    cout << "Please input the student number you want to change: ";
    cin >> id;
    for (i=0;i<Number;i++)
    {
        if (strcmp(id,st[i].ID))
        {
            changeIndex=i;
        }
        break;
    }
    cout << endl << "ID: " << st[changeIndex].ID << " Name: " << st[changeIndex].name << " Score:" << st[changeIndex].score << endl;
    cout << "Please re-enter the student information" << endl;
	cout << "ID: ";
	cin >> st[changeIndex].ID;
	cout << "Name: ";
	cin >> st[changeIndex].name;
	cout << "Score: ";
	cin >> st[changeIndex].score;

    fp=fopen("C://student.dat","wb");
    for (i=0;i<Number;i++)
    {
        fwrite(&st[i],sizeof(class Student),1,fp);
    }
    fclose(fp);
    cout  << "Revised Successfully!" << endl;
}

void ChangeName()
{
    FILE *fp=NULL;
    char name[60];
    int i=0;
    int changeIndex=0;
    int index=0;
    cout << "Please input the student's name you want to change: ";
    cin >> name;
    for (i=0;i<Number;i++)
    {
        if (strcmp(name,st[i].name))
        {
            changeIndex=i; //修改索引 
        }
        break;
    }
    cout << "ID: " << st[changeIndex].ID << "Name: " << st[changeIndex].name << "Score:" << st[changeIndex].score << endl;
    cout << "Please re-enter the student's information";
	cout << "ID: ";
	cin >> st[changeIndex].ID;
	cout << "Name: ";
	cin >> st[changeIndex].name;
	cout << "Score: ";
	cin >> st[changeIndex].score;

    fp=fopen("C://student.dat","wb");
    for (i=0;i<Number;i++)
    {
        fwrite(&st[i],sizeof(class Student),1,fp);
    }
    fclose(fp);
}

void Creator_6()
{
	cout << "#######################################################" << endl;
	cout << "       Student Information Management System           " << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "                 Created by Li Gen                     " << endl;
	cout << "                  ID:20151308062                       " << endl;
	cout << "                All Rights Reserved.                   " << endl;
	cout << "#######################################################" << endl;
}

#endif
