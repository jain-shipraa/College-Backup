//COMPUTE POWER USING RECURSION 
#include<iostream>
using namespace std;

class power 
{
public:

	long pow(int num,int p);
};

long power::pow(int num,int p)
	{

		if(p==0)
		{
			return 1;
		}
		else
			return num*pow(num,p-1);
	}


void main()
{
	power P;
	int n,p;
	long result;

	cout<<"\n Enter the base=";
	cin>>n;

	cout<<"\n Enter the power=";
	cin>>p;



	result=P.pow(n,p);

	cout<<"\n Result="<<result;
	cout<<"\n ";
}

