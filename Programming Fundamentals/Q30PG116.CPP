//TO REVERSE A GIVEN NUMBER

#include<iostream>
using namespace std;

void main()
{
	long n,rev_n=0,r;

	cout<<"\n Enter a number=";
	cin>>n;

	while(n)
	{
		r=n%10;
		n=n/10;
		rev_n=(rev_n*10)+r;

	}

cout<<"\n Reverse of the number is"<<rev_n<<endl;

}
