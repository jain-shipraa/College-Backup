//EVEN ODD
#include<iostream.h>

void main()
{

	int i=1,n;

	cout<<"\n Enter the no upto which series is to be displayed=";
	cin>>n;

	while(i<=n)
	{

		if(i%2==0)
			cout<<"\n"<<i<<"is even";
		else
			cout<<"\n"<<i<<"is odd";

		i++;

	}


}