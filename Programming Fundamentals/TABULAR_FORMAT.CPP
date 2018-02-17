//TABULAR FORMAT OF DATA

#include<iostream>
#include<iomanip>

using namespace std;

void main()
{

	char nam,ch='y';
	int rno;
	float m1,m2,m3,sum=0.00,avg=0.00;

	cout<<setw(4)<<"RNO."<<setw(4)<<"NAME"<<setw(6)<<"M1"<<setw(6)<<"M2"<<setw(6)<<"M3"<<setw(8)<<"TM"<<setw(8)<<"AVG"<<endl;

	cout<<fixed<<setprecision(2);

	while (ch=='y'|| ch=='Y')
	{
		cout<<"\n Enter your Name's first alphabet=";
		cin>>nam;
		cout<<"\t Enter Rollno=";
		cin>>rno;
		cout<<"\tEnter Marks 1=";
		cin>>m1;
		cout<<"\tMarks 2=";
		cin>>m2;
		cout<<"\t Marks 3=";
		cin>>m3;

		sum=m1+m2+m3;
		avg=sum/3;
        cout<<"\n"<<setw(4)<<rno<<setw(4)<<nam<<setw(6)<<m1<<setw(6)<<m2<<setw(6)<<m3<<setw(8)<<sum<<setw(8)<<avg<<endl;

		cout<<"Do you want to continue?";
		cin>>ch;

	}

	cout<<endl;
}