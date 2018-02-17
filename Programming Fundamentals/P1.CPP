//PROGRAM QUES 28 ON PG 116

#include<iostream>
using namespace std;

void main()
{

	float x,y,s,p,total;

	cout<<"\n Enter the value of x=";
	cin>>x;

	cout<<"\n Enter the value of y=";
	cin>>y;

	p=x*y;
	s=x+y;

	total=s*s+p*(s-x)*(p+y);

	cout<<"\n Total Value="<<total<<endl;

}

