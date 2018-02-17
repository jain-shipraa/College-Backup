// PRIME NO - USING FUNCTIONS

#include<iostream>
using namespace std;

void prime(int n);

void main()
{
	 int num;
	 cout<<"\n Enter number=";
	 cin>>num;

	 prime(num);

}

void prime(int n)
{
	 
	int flag=0,i=2;


	while(i<=n/2)
	{

		if(n%i==0)
		{
			flag=1;
			break;
		}

		i++;
	}

	if(flag)
    	cout<<"\n Number is not prime";
	else
		cout<<"\n Number is prime";
}

