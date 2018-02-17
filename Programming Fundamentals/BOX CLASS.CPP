// BOX CLASS IMPLEMENTATION

#include<iostream>
using namespace std;

class box
{
	int l,b,h;

public:
	box()
	{
		l=b=h=0;
	}

	box(int x)
	{
		l=b=h=x;
	}

	box(int x,int y,int z)
	{
		l=x;
		b=y;
		h=z;
	}

	box(const box & b1)
	{
		l=b1.l;
		b=b1.b;
		h=b1.h;
	}

	int volume()
	{
		int vol;
		vol=l*b*h;

		return(vol);
	}

	int  sa()
	{
		int sa;
		sa=2*(l*b+b*h+h*l);

		return(sa);
	}

	box operator+(box b1)
	{
		box b2;
		b2.l=l+b1.l;
		b2.b=b+b1.b;
		b2.h=h+b1.h;

		return(b2);
	}


	friend int operator==(box b1,box b2)
	{
		if(b1.l==b2.l && b1.b==b2.b && b1.h==b2.h)
			return 1;
		else
			return 0;
	}

	box operator=(box b1)
	{
		l=b1.l;
		b=b1.b;
		h=b1.h;

		return(*this);
	}


	int check()
	{
		if(l==b && b==h && h==l)
			return 1;
		else
			return 0;
	}

	box operator++()
	{
		l++;
		b++;
		h++;

		return(*this);
	}

	box operator++(int)
	{
		box b1(l,b,h);

		l++;
		b++;
		h++;

		return (b1);
	}

	box operator--()
	{
		l--;
		b--;
		h--;

		return(*this);
	}

	box operator--(int)
	{
		box b1(l,b,h);

		l--;
		b--;
		h--;

		return(b1);
	}

	

	void getinput()
	{
		cout<<"\n Enter length=";
		cin>>l;
		cout<<"\n Enter breadth=";
		cin>>b;
		cout<<"\n Enter height=";
		cin>>h;
	}

	void display()
	{
		cout<<"\n LENGHT="<<l;
		cout<<"\n BREADTH="<<b;
		cout<<"\n HEIGHT="<<h;
	}


};


void main()
{
	box b1,b2(4),b3(3,4,5),b4,b5,b6,b7;
	int ch,v,s,flag;
	char op;

	do
	{
	  cout<<"\n MENU :";
	  cout<<"\n 1.INPUT";
	  cout<<"\n 2.CALCULATE VOLUME";
	  cout<<"\n 3.CALCULATE SURFACE AREA:";
      cout<<"\n 4.ADD DIMENSIONS OF TWO BOXES";
	  cout<<"\n 5.TO CHECK EQUALITY OF DIMENSIONS OF TWO BOXES";
	  cout<<"\n 6.INCREMENT DIMENSIONS";
	  cout<<"\n 7.DECREMENT DIMENSIONS";
	  cout<<"\n 8.CHECK FOR CUBE/CUBOID";
	  cout<<"\n 9.DISPLAY";
	  cout<<"\n 10.COPY VALUES";
	  cout<<"\n Enter your choice=";
	  cin>>ch;

	  switch(ch)
	  {
	  case 1:cout<<"\n INPUTTING VALUES";
			 b1.getinput();
		     break;
      case 2:cout<<"\n CALCULATING VOLUME...";
		     v=b1.volume();
			 cout<<"\n VOLUME OF THE BOX B1="<<v;
			 break;
	  case 3:cout<<"\n CALCULATING SURFACE AREA:";
		     s=b1.sa();
			 cout<<"\n SURFACE AREA OF THE BOX B1:"<<s;
			 break;
      case 4:cout<<"\n ADD THE DIMENSIONS OF TWO BOXES=";
		     cout<<"\n Consider another box, BOX 2";
			 b2.display();
			 b4=b1+b2;
			 cout<<"\n RESULT OF ADDING B1 AND B2=";
			 b4.display();
			 break;
	  case 5:cout<<"TO CHECK EQUALITY OF DIMENSIONS OF TWO BOXES";
		     cout<<"\n Consider another box, BOX 2";
			 b2.display();

		     if(b1==b2)
				 cout<<"\n DIMENSIONS OF BOX B1 AND BOX B2 ARE EQUAL";
			 else 
				 cout<<"\n DIMENSIONS OF BOX B1 AND BOX B2 ARE UNEQUAL";
			 break;
	  case 6:cout<<"\n INCREMENT DIMENSIONS:";
		     cout<<"\n USING....";
			 cout<<"\n 1.PRE-INCREMENT";
			 cout<<"\n 2.POST-INCREMENT";
			 cout<<"\n ENTER CHOICE:";
			 cin>>ch;

			 if(ch==1)
			 {
				 ++b1;
				 b1.display();
			 }
			 else if(ch==2)
			 {
				 b6=b1++;
				 cout<<"\n BOX 6 :";
				 b6.display();
				 cout<<"\n BOX 1 :";
				 b1.display();
			 }
			 else
				 cout<<"\n Wrong Choice";
			 break;
      case 7:cout<<"\n DECREMENT DIMENSIONS:";
		     cout<<"\n USING....";
			 cout<<"\n 1.PRE-DECREMENT";
			 cout<<"\n 2.POST-DECREMENT";
			 cout<<"\n ENTER CHOICE:";
			 cin>>ch;

			 if(ch==1)
			 {
				 --b1;
				 b1.display();
			 }
			 else if(ch==2)
			 {
				 b7=b1--;
				 cout<<"\n BOX 7 :";
				 b7.display();
				 cout<<"\n BOX 1 :";
				 b1.display();
			 }
			 else
				 cout<<"\n Wrong Choice";
			 break;
	  case 8: cout << " \n CHECK FOR CUBE/CUBOID " ;
		     flag=b1.check();
			 if(flag)
				 cout<<"\n It is a cube";
			 else
				 cout<<"\n It is cuboid";

			 break;
	  case 9: cout << " \n Displaying.... " ;
		     b1.display();
			 break ;
	  case 10: cout<<" \n copying values=";
		     cout<<"\n Consider another box, BOX 3";
			 b5.display();
			 b5=b1;
			 b5.display();
			 break;

	  default:cout<<"\n Wrong choice";
		      break;
	  }

	  cout<<"\n Do you want to continue=";
	  cin>>op;
	}
	while(op=='Y'||op=='y');

}

		     

