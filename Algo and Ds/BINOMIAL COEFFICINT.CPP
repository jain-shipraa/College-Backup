//BINOMIAL COEFFICIENT 

#include<iostream>
using namespace std;

class bin
{
public:

int bin_coeff(int n,int k)
{
	if(k==0 || k==n)
		return 1;
	else
		return bin_coeff(n-1,k-1)+bin_coeff(n-1,k);
}
};

void main()
{
	bin B;
	int res,n,r;

	cout<<"\n Enter n=";
	cin>>n;

	cout<<"\n Enter r=";
	cin>>r;

	res=B.bin_coeff(n,r);

	cout<<"\n RESULT:"<<res;
}

