//RECURSIVE FUNCTION TO CALCULATE NTH TERM OF SERIES 1+1/2+1/3....

#include<iostream>
using namespace std;


class series
{
public:

long pow(int num,int p)
{
		if(p==0)
		{
			return 1;
		}
		else
			return num*pow(num,p-1);
}

float ser(int n)
{
 if(n==1)
	 return 1;
 else 
	 return  pow(-1,n)*(1.0/n)+ser(n-1);
}


};

void main()
{
	float res;
	int max;
	series S;

	cout<<"\n Maximum series upto=";
	cin>>max;

	res=S.ser(max);

	cout<<"\n RESULT:"<<res;
}

