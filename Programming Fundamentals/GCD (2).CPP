//TO PRINT THE GCD OF THE TWO NUMBERS

#include<iostream>
using namespace std;

void main()
{

	int n,n2,i,gcd;

	cout<<"\n Enter one number=";
	cin>>n;

	cout<<"\n Enter another number=";
	cin>>n2;


	if(n>=n2)
		i=n/2;
	else if(n2<n)
		i=n2/2;
	else
		i=1;



	while(i)
	{
		if(n%i==0 && n2%i==0)
		{
			gcd=i;
			break;

		}

	i--;
	}

	cout<<"\n The GCD is ="<<gcd;

	cout<<endl;

}
