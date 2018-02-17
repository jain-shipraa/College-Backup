//MANIPULATION OF REALS
#include<iostream>
#include<iomanip>
using namespace std;

void main()
{
	float x=14.8967f;

	cout<<x;

	cout<<fixed<<setprecision(2)<<endl;//fixed and setp are in permanent effect

	cout<<x;

	cout<<setprecision(0)<<endl;//effect of setprecision 0 comes in scope

	cout<<x;

	cout<<showpoint<<endl;

	cout<<x;

}
