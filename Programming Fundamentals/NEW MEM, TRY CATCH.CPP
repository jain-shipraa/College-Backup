//ALLOCATE MEMORY USING NEW OPERATOR AND HANDLING THE EXCEPTION
#include<exception>
#include<iostream>
#include<string>
using namespace std;

int* f(int x)
{

	int *p;
	try
	{
		p=new int(x);
		return p;
	}
	catch(exception &err)
	{
		cout<<err.what();
	}
}

float* f(float x)
{

	float *p;
	try
	{
		p=new float(x);
		return p;
	}
	catch(exception &err)
	{
		cout<<err.what();
	}
}

void main()
{

	int *i1;
	float *f1;
	int c;

	cout<<"\n WHAT TYPE OF MEMORY YOU WANT TO ALLOCATE:";
	cout<<"\n 1. INTEGER";
	cout<<"\n 2. FLOAT";
	cin>>c;


	switch(c)
	{
	case 1:int x;
		   cout<<"\n Enter an integer value:";
		   cin>>x;

		   i1=f(x);

		   cout<<"\n VALUE:"<<*i1;
		   break;
    case 2:float y;
		   cout<<"\n Enter a float value:";
		   cin>>y;

		   f1=f(y);

		   cout<<"\n VALUE:"<<*f1;
		   break;
	default: cout<<"\n Wrong Choice";

	}

}
