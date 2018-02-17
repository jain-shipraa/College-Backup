//TO PRINT ODD NUMBERS FROM N TO 1

#include<iostream>
using namespace std;

class prn
{
public:
	void prnodd(int n)
	{
		if(n%2==0)
			n--;
		if(n>=1 && n%2==1)
		{   
			cout<<" "<<n;
			prnodd(n-2);
	
		}
	}
};

void main()
{
	int max;
	prn P;

	cout<<"\n Enter the number =";
	cin>>max;

	P.prnodd(max);

}
	
