//IMPLEMENT COMPLEX NUMBER CLASS

#include<iostream>
using namespace std;

class cno
{
	int rez,imz;

public:

	cno()
	{
		imz=rez=0;
	}

	void getinput()
	{
		cout<<"\n Enter real part=";
		cin>>rez;

		cout<<"\n Enter Imaginary Part=";
		cin>>imz;

	}

	void disp()
	{
		if(imz)
		{
			cout<<"\n NUMBER="<<rez<<"+i("<<imz<<")";
		}
		else
			cout<<"\n NUNBER="<<rez;
	}

	cno operator+(cno z)
	{
		cno z2;

		z2.imz=imz+z.imz;
		z2.rez=rez+z.rez;

		return(z2);
	}

	cno operator-(cno z)
	{
		cno z2;

		z2.imz=imz-z.imz;
		z2.rez=rez-z.rez;

		return(z2);
	}

	cno operator*(cno z)
	{
		cno z2;

		z2.rez=rez*z.rez-imz*z.imz;
		z2.imz=rez*z.imz+imz*z.rez;
		
		return(z2);
	}

	cno operator/(cno z)
	{
		cno z2;

		z2.rez=(rez*z.rez+imz*z.imz)/(rez*rez+z.rez*z.rez);
		z2.imz=(imz*z.rez-rez*z.imz)/(imz*imz+z.imz*z.imz);

		return(z2);
	}

	int operator==(cno z)
	{
		if(rez==z.rez)
		{
			if(imz==z.imz)
				return 1;
		}
		
		return 0;
	}

	cno operator=(cno z)
	{
		imz=z.imz;
		rez=z.rez;

		return(*this);
	}

			
};

void main()
{

	cno c1,c2,c3,c4,c5,c6,c7;
	int ch;
	char op;

	do
	{

		cout<<"\n MENU=";
		cout<<"\n 1. Enter the values of the complex numbers";
		cout<<"\n 2. Add";
		cout<<"\n 3. Subtract";
		cout<<"\n 4. Multiply";
		cout<<"\n 5. Divide";
		cout<<"\n 6. Assign the value";
		cout<<"\n 7. Check the equality";
		cout<<"\n 8. Display the numbers";

		cout<<"\n Enter your choice=";
		cin>>ch;

		switch(ch)
		{
		case 1: cout<<"\n Enter two complex numbers=";
			    cout<<"\n Complex Number 1:";
				c1.getinput();
				cout<<"\n Complex Number 2:";
				c2.getinput();
				break;
		case 2: cout<<"\n Adding......";
			    c3=c1+c2;
				cout<<"\n Result";
				c3.disp();
				break;
		case 3: cout<<"\n OPTION";
			    cout<<"\n 1. c1-c2";
				cout<<"\n 2. c2-c1";
				cout<<"\n Your Choice=";
				cin>>ch;
       
	       		cout<<"\n Subtracting.....";
		
				if(ch==1)
				{
					c4=c1-c2;
				    c4.disp();
				}
				else if(ch==2)
				{
					c4=c2-c1;
					c4.disp();
				}
				else
					cout<<"\n Wrong Choice";

				break;
		case 4: cout<<"\n Multiplying......";
			    c5=c1*c2;
				c5.disp();
				break;
		case 5: cout<<"\n OPTION";
			    cout<<"\n 1. c1/c2";
				cout<<"\n 2. c2/c1";
				cout<<"\n Your Choice=";
				cin>>ch;

	       		cout<<"\n Dividing.......";
				if(ch==1)
				{
					c5=c1/c2;
					c5.disp();
				}
				else if(ch==2)
				{
					c5=c2/c1;
					c5.disp();
				}
				else
					cout<<"\n Wrong Choice";

				break;
		case 6:cout<<"\n Assigning value....";
			   c7=c1;
			   c7.disp();
			   break;
		case 7:cout<<"\n Checking Equality....";
			   if(c1==c2)
				   cout<<"\n Equal Numbers";
			   else 
				   cout<<"\n Unequal Numbers";

			   break;
		case 8: c1.disp();
			    c2.disp();
				break;

		default: cout<<"\n Wrong Choice";
		}

		cout<<"\n Do you want to continue?";
		cin>>op;
	}
	while(op=='y'|| op=='Y');
}


			    

