//LENGTH CLASS IMPLEMENTATION

#include<iostream>
using namespace std;

class length
{
	int ft,in;

public:

	length();
	length(int x,int y);
	void getinput();
	length operator+(length l1);
	length operator-(length l1);
	void disp();
};

length::length()
{
	ft=0.0;
	in=0.0;
}

length::length(int x, int y)
{
	ft=x;
	in=y;
}

void length::getinput()
{
	cout<<"\n Enter feet=";
    cin>>ft;
	cout<<"\n Enter inches=";
	cin>>in;
}

length length::operator +(length l1)
{
	length l2;

	l2.in=in+l1.in;
	if(l2.in>=12)
	{
		l2.in-=12;
		l2.ft++;
	}
	l2.ft=l2.ft+l1.ft+ft;

	return l2;
}

length length::operator -(length l1)
{

	length l2;

	 if(ft>l1.ft)
	 {
		 if(in<l1.in)
		 {
			 in+=12;
			 ft--;
		 }
		 
		 l2.ft=ft-l1.ft;
		 l2.in=in-l1.in;
	 }
	 else 
	 {
		 cout<<"\n Length cannot be negative";
	 }

	 return l2;

}

void length::disp()
{
	cout<<"\n Feet="<<ft;
	cout<<"\n Inches="<<in;
}

void main()
{

	length l1,l2(1,11),l3,l4;
	int ch;
	char op;

	do
	{
		cout<<"\n MENU=";
		cout<<"\n 1.INPUT LENGTH";
		cout<<"\n 2.ADD 2 LENGTHS";
		cout<<"\n 3.SUBTRACT 2 LENGTHS";
		cout<<"\n 4.DISPLAY LENGTHS";
		cout<<"\n Enter your choice=";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"\n INPUTTING VALUE=";
               l1.getinput();
			   break;
		case 2:cout<<"\n ADD 2 LENGTH..";
			   l3=l1+l2;
			   l3.disp();
			   break;
		case 3:cout<<"\n SUB 2 LENGTH...";
			   l4=l1-l2;
			   l4.disp();
			   break;
		case 4:cout<<"\n DISPLAYING...";
			 l1.disp();
			 break;
		default:cout<<"\n Wrong Choice";
		}

		cout<<"\n Do you want to continue";
		cin>>op;

	}
	while(op=='y'||op=='Y');

}

