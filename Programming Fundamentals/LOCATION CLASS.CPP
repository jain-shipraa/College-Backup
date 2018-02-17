//IMPLEMENTING CLASS LOCATION

#include<iostream>
using namespace std;

class location
{
private:
	float latitude,longitude;
public:
	location()
	{
		latitude=longitude=0.0;
	}

	location(float x)
	{
		latitude=longitude=x;
	}

	location(float x,float y)
	{
		latitude=x;
		longitude=y;
	}

	friend location operator+(location ob,int x);

	friend location operator+(int x,location ob);

	location operator++()
	{
		latitude++;
		longitude++;

		return(*this);
	}

	location operator++(int)
	{
		location ob1(latitude,longitude);

		latitude++;
		longitude++;

		return(ob1);
	}

	location operator--()
	{
		latitude--;
		longitude--;

		return(*this);
	}

	location operator--(int)
	{
		location ob1(latitude,longitude);

		latitude--;
		longitude--;

		return(ob1);
	}

	void getinput()
	{
		cout<<"\n LATITUDE=";
		cin>>latitude;
		cout<<"\n LONGITUDE";
		cin>>longitude;
	}

	void disp()
	{
		cout<<"\n LATITUDE="<<latitude;
		cout<<"\n LONGITUDE="<<longitude;
	}

};

location operator+(location ob,int x)
{
		location ob1;

		ob1.latitude=ob.latitude+x;
		ob1.longitude=ob.longitude+x;

		return ob1;
}

location operator+(int x,location ob)
{
		location ob1;

		ob1.latitude=ob.latitude+x;
		ob1.longitude=ob.longitude+x;

		return ob1;
}


void main()
{

	location l1,l2,l3,l4,l5,l6;
	int ch,z;
	char op;


	do
	{
		cout<<"\n MENU";
		cout<<"\n 1. INPUT VALUE";
		cout<<"\n 2. DEMONSTRATE OB+Z";
		cout<<"\n 3. DEMONSTRATE Z+OB";
		cout<<"\n 4. INCREMENT VALUE ";
		cout<<"\n 5. DECREMENT VALUE";
		cout<<"\n 6. DISPLAY";

		cout<<"\n Enter your choice=";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"\n INPUTTING VALUES";
			   l1.getinput();
			   break;

		case 2:cout<<"\n DEMONSTRATE OB+Z";
			   cout<<"\n Enter an integer value to be added";
			   cin>>z;
			   l2=l1+z;
			   l2.disp();
			   break;
		case 3:cout<<"\n DEMONSTRATE Z+OB;
			   cout<<"\n Enter an integer value to be added";
			   cin>>z;
			   l3=z+l1;
			   l3.disp();
			   break;
		case 4:cout<<"\n INCREMENT VALUE";
			   cout<<"\n CHOOSE ONE OPTION...";
			   cout<<"\n 1. PREFIX";
			   cout<<"\n 2. POSTFIX";
			   cout<<"\n ENTER YOUR CHOICE";
			   cin>>ch;

			   if(ch==1)
			   {
				   ++l1;
				   l1.disp();
			   }
			   else if(ch==2)
			   {
				   l4=l1++;
				   cout<<"\n RESULT OF L4=L1++"; 
				   l4,disp();
				   cout<<"\n HOWEVER L1:";
				   l1.disp();
			   }
			   else
				   cout<<"\n Wrong choice";

			   break;
		case 5:cout<<"\n DECREMENT VALUE";
			   cout<<"\n CHOOSE ONE OPTION...";
			   cout<<"\n 1. PREFIX";
			   cout<<"\n 2. POSTFIX";
			   cout<<"\n ENTER YOUR CHOICE";
			   cin>>ch;

			   if(ch==1)
			   {
				   --l1;
				   l1.disp();
			   }
			   else if(ch==2)
			   {
				   l4=l1--;
				   cout<<"\n RESULT OF L4=L1--"; 
				   l4,disp();
				   cout<<"\n HOWEVER L1:";
				   l1.disp();
			   }
			   else
				   cout<<"\n Wrong choice";

			   break;
		case 6:cout<<"\n DISPLAYING...";
			   l1.disp();
			   break;

		default:cout<<"\n Wrong choice";
			    break;
		}

		cout<<"\n Do you want to continue?";
		cin>>op;

	}
	while(op=='Y'||op=='y');
}




