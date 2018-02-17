//GCD USING RECURSION 

#include<iostream>
using namespace std;

class GCD
{
public:
	int gcd(int n1, int n2)
	{
		if(n1%n2==0)
		{
			return n2;
		} 
		else if(n2==0)
		{
			return 1;
		}
		else
			return gcd(n2,n1%n2);
	}

};

void main()
{

	GCD G;
	int num1,num2,res;

	cout<<"\n Enter first nmuber=";
	cin>>num1;

	cout<<"\n Enter second number=";
	cin>>num2;

	if(num1>num2)
		res=G.gcd(num1,num2);
	else
		res=G.gcd(num2,num1);

	cout<<"\n RESULT="<<res;

	cout<<endl;

}


