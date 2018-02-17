//defining stmt used for making constants

#include<iostream>
using namespace std;
#define PI 3.14

void main()
{
	float r,area;

	cout<<"\n Enter Radius=";
	cin>>r;

	area=PI*r*r;

	cout<<"\n Area="<<area;

	cout<<endl;
}