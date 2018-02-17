// FIB SERIES NTH TERM

#include<iostream>
using namespace std;

class Fib
{

public:

	int fib(int n)
	{
		if (n==1 || n==2)
		{
			return (n-1);
		}
		else
			return fib(n-1)+fib(n-2);

	}

};


void main()
{
	Fib F;

	int n,res;


	cout<<"\n Which term to display=";
	cin>>n;


	res=F.fib(n);

	cout<<"\n RESULT:"<<res;
}
