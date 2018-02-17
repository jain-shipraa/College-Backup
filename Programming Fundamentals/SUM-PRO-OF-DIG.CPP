//TO PRINT SUM AND PRODUCT OF THE DIGITS OF AN INTEGER

#include<iostream>
using namespace std;

void main()
{
	int n,r,s=0,p=1;

	cout<<"\n Enter an integer number between 0 to 32767=";
	cin>>n;

	while(n)
	{
		r=n%10;
		s+=r;
		p*=r;
		n/=10;

	}

	cout<<"\n Sum of diigits="<<s;
	cout<<"\n Product of the digits="<<p;

	cout<<endl;

}

