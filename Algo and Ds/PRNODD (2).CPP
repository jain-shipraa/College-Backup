//PRINT ODD NUMBERS 1 TO N

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
			prnodd(n-2);
			cout<<" "<<n;
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
	
