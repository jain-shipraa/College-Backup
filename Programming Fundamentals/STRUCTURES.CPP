//QUESTION STRUCTURE STUDENT 

#include<cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;


struct student
{

	int rno,cls,yr;
	char nam[25];
	long total;
}s[10];

void input(int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		system("cls");
		cout<<"\n Enter Details";
		cout<<"\n Enter rollno=";
		cin>>s[i].rno;
		cout<<"\n Enter Name=";
		cin>>s[i].nam;
		cout<<"\n Enter Class=";
		cin>>s[i].cls;
		cout<<"\n Enter Year=";
		cin>>s[i].yr;
		cout<<"\n Enter Total Marks=";
		cin>>s[i].total;

	}
}

void disp(int size)
{

	cout<<"\n ROLLNO"<<" "<<setw(25)<<"NAME"<<" "<<setw(10)<<"CLASS"<<" "<<"YEAR"<<" "<<"TOTAL MARKS"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<setw(7)<<s[i].rno;
		cout<<" "<<setw(25)<<s[i].nam;
		cout<<" "<<setw(10)<<s[i].cls;
		cout<<" "<<s[i].yr;
		cout<<" "<<setw(11)<<s[i].total<<endl;
	}
}

void main()
{
	int size;

	cout<<"\n How many records do you want to enter ?";
	cin>>size;

	input(size);
	disp(size);
}
