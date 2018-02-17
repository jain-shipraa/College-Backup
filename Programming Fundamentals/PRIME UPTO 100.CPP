// PRIME NUMBERS UPTO 100 USING FUNCTION

#include<iostream>
using namespace std;

void prn_prime(int);

void main()
{
	int range;

	cout<<"\n Enter range upto which you want prime numbers:";
	cin>>range;

	prn_prime(range);

}

void prn_prime(int rng=100)
{

	int i,j=2,n,flag;

		while(j<=rng)
		{
			flag=0;

			n=j;
			i=2;

			while(i<=n/2)
			{
				if(n%i==0)
				{
					flag=1;
					break;
				}

				i++;

			}

			if(!flag)
			{
				cout<<j<<"\t";
			}

			j++;
		}

		cout<<"\n ";

}	