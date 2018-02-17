//MULTIPLICATION USING ADDITION,SUBTRACTION AND COMPARISON

#include<iostream>
using namespace std;
 
class mult
{

public:

	int mul(int n1,int n2)
	{
		if(n2>0)
		{
			return n1+mul(n1,n2-1);
		}
		else
			return 0;
	}
};

void main()
{
	int num1,num2, res;

	mult M;

	cout<<"\n Enter two number to be multiplied=";
	cin>>num1;
	cout<<"\n Enter another number=";
	cin>>num2;

	if(num1>num2)
	{
		res=M.mul(num1,num2);
	}
	else
		res=M.mul(num2,num1);


	cout<<"\n Result of "<<num1<<" * "<<num2 <<" = "<<res<<endl;
}

