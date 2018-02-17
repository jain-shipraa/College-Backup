//POLYGON CLASSES
#include<math.h>
#include<iostream>
using namespace std;

class polygon
{
protected:
	float area,peri;
public:

	polygon()
	{
		area=peri=0.0;
	}

	void printarea()
	{
		cout<<"\n AREA="<<area;
	}

	void printperi()
	{
		cout<<"\n PERIMETER="<<peri;
	}

};

class rectangle:public polygon
{
	int l,b;

public:


	void getinput()
	{
		cout<<"\n LENGTH=";
		cin>>l;
		cout<<"\n BREADTH=";
		cin>>b;

	}

	rectangle()
	{
		l=b=0;
	}

	void calcarea()
	{
		area=l*b;
	}

	void calcperi()
	{
		peri=2*(l+b);
	}

	void display()
	{
		cout<<"\n LENGTH="<<l;
		cout<<"\n BREADTH="<<b;
		printarea();
		printperi();
	}


};

class square:public polygon
{
	int s;

public:
	
	void getinput()
	{
		cout<<"\n SIDE=";
		cin>>s;
	}
	
	square()
	{
		s=0;
	}

	void calcarea()
	{
		area=s*s;
	}

	void calcperi()
	{
		peri=4*s;
	}

	void display()
	{
		cout<<"\n SIDE="<<s;
		printarea();
		printperi();
	}
};

class triangle:public polygon
{
	int s1,s2,s3;

public:

	void getinput()
	{
		cout<<"\n Enter sides=";
		cout<<"\n Side 1=";
		cin>>s1;
		cout<<"\n Side 2=";
		cin>>s2;
		cout<<"\n Side 3=";
		cin>>s3;
	}

	triangle()
	{
		s1=s2=s3=0;
	}

	void calcarea()
	{
		float s;
		s=(s1+s2+s3)/2;
		area=pow(s*(s-s1)*(s-s2)*(s-s3),0.5);

	}

	void calcperi()
	{
		peri=s1+s2+s3;
	}

	void display()
	{
		cout<<"\n SIDES=";
		cout<<"\n s1="<<s1;
		cout<<"\n s2="<<s2;
		cout<<"\n s3="<<s3;
		printarea();
		printperi();
	}
};

void main()
{

	rectangle r;
	square s;
	triangle t;
	int op;
	char ch;

	do
	{
		cout<<"\n MENU";
		cout<<"\n 1. INPUT VALUES=";
		cout<<"\n 2. CALCULATE AREA";
		cout<<"\n 3. CALCULATE PERIMETER";
		cout<<"\n 4. DISPLAY";
		cout<<"\n ENTER CHOICE";
		cin>>op;

		switch(op)
		{
		case 1:r.getinput();
			   s.getinput();
			   t.getinput();
			   break;
		case 2:r.calcarea();
			   s.calcarea();
			   t.calcarea();
			   break;
		case 3:r.calcperi();
			   s.calcperi();
			   t.calcperi();
			   break;
		case 4:r.display();
			   s.display();
			   t.display();
			   break;
		default:cout<<"\n Wrong Choice";
		}

		cout<<"\n Do you want to continue?";
		cin>>ch;
	}
	while(ch=='y'||ch=='Y');
}