//FIBONACCI SERIES USING RECURSIVE FUNCTION

#include<iostream>
using namespace std;

int fib (int n)
{
	if(n==0 || n==1)
	{
		return n;
	}
	else
		return fib(n-1)+fib(n-2);
}

void main()
{
	int size,n,i;

	cout<<"\n How many Elements do you want to display=";
	cin>>size;

	for(i=0;i<size;i++)
	{
		n=fib(i);
		cout<<n<<" ";
	}

	cout<<endl;
}

