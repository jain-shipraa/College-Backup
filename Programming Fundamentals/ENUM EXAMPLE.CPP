//ENUMERATED DATA TYPE

#include<iostream>
using namespace std;

void main()
{
	enum color{red,blue,green,white};

	cout<<"\n RED="<<red;
	cout<<"\n BLUE="<<blue;
	cout<<"\n GREEN="<<green;
	cout<<"\n WHITE="<<white;

	cout<<"\n Type Conversion....";

	int y;
	y=static_cast<color>(2);
	cout<<"\n Value of y="<<y;
}
