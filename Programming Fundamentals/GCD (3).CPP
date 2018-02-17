//GCD RECURSIVE FUNCTION 

#include<iostream>
using namespace std;

int gcd(int dvd,int dvs)
{
	int gd;
	if(dvs==0)
		return 1;
	else if(dvd%dvs==0)
		return dvs;
	else
		gd=gcd(dvs,dvd%dvs);

	return gd;
}


void main()
{
	int gcd1,n1,n2;
	
	cout<<"\n Enter number 1:";
	cin>>n1;
	cout<<"\n Enter number 2:";
	cin>>n2;
	
	if(n1>n2)
		gcd1=gcd(n1,n2);
	else 
		gcd1=gcd(n2,n1);
	

	cout<<"\n GCD=";
	cout<<gcd1;
}

