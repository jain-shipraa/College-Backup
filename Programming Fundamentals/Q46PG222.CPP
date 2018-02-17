//QUESTION 46 PG 222

#include<iostream>
using namespace std;

void main()
{
	int x,y,z;

	cout<<"\n Enter the value of x=";
	cin>>x;
	cout<<"\n Enter the value of y=";
	cin>>y;

	if(x>0)
	{
		y=x-1;
		z=2*x;
	}
	else
	{
		if(y>0)
		z=y;
        else
		{
			z=x;
			y=x+1;
		}
		z=z+1;
	}
	cout<<"\n Values="<<x<<"\t"<<y<<"\t"<<z;

	cout<<endl;
}

