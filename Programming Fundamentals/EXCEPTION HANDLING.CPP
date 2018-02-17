//EXCEPTION HANDLING 

#include<iostream>
using namespace std;

class error
{
public:

	virtual void handle()
	{
		cout<<"\n Error:tyoe error";
	}
};

class divbyzero:public error
{
public:

	virtual void handle()
	{
		cout<<"\n Error:division by zero!!!";
	}
};

class divbyneg:public error
{
public:
	virtual void handle()
	{
		cout<<"\n Error: division by negative number!!!!";
	}
};

class badoperator:public error
{
public:

	virtual void handle()
	{
		cout<<"\n Error: bad operator!!!";
	}
};

int operate(char op,int dvd,int dvs)
{
	char ch='y';
	int y=dvs;

	while(ch=='y')
	{
		try
		{
			switch(op)
			{
		     case '/':if(y==0)
					  {
				       throw divbyzero();
					  }
				       if(y<0)
					   {
						   throw divbyneg();
					   }
				      return dvd/y;
			 default:throw badoperator();
			}
		}
		catch(divbyzero &d)
		{
			d.handle();
			cout<<"\n Enter divisor again:";
			cin>>y;
		}

		catch(divbyneg &d)
		{
			d.handle();
			cout<<"\n Enter divisor again";
			cin>>y;
		}
	}
}


void main()
{
	int div,divs;
	char opr;
	cout<<"\n Enter divident:";
	cin>>div;
	cout<<"\n Enter divisor:";
	cin>>divs;
	cout<<"\n Enter opertor";
	cin>>opr;

	try
	{
		int x=operate(opr,div,divs);
		cout<<x;
	}
	catch(badoperator &e)
	{
		e.handle();
	}
}




