//QUESTION 32 EXPLICIT CONVERSION OF DATA TYPES

#include<iostream>
#include<iomanip>
using namespace std;

void main()
{
	int n;
	char ch;
	float f;

	cout<<"\n Enter any number=";
	cin>>n;

	cout<<"\n Using Explicit Conversion ";
	cout<<"\n The number as a character= "<<((char)n);
    cout<<"\n The number as a decimal= "<<((int)n);
	cout<<"\n The number as a float= "<<fixed<<setprecision(2)<<((float)n);

	cout<<endl;


	ch=n;
	f=n;

	cout<<"\n Using Assignment";
    cout<<"\n The number as a character= "<<ch;
    cout<<"\n The number as a decimal= "<<n;
	cout<<"\n The number as a float= "<<f;

	cout<<endl;
}

