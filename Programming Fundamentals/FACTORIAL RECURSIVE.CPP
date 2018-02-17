//FACTORIAL RECURSIVE

#include<iostream>
using namespace std;

int fact(int n)
{
	if(n==0)
	{

		return 1;
	}
	else
	{
		return (n*fact(n-1));
	}
}

void main()
{

	int fac,num;

	cout<<"\n Enter a number whose factorial is to be calculated";
	cin>>num;
	fac=fact(num);
	cout<<"\n Factorial="<<fac;
	cout<<endl;
}

