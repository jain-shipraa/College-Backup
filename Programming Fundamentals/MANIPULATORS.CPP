//MANIPULATORS	
#include<iostream>
using namespace std;

void main()
{
	int x=4,y=10;

	cout<<x<<y;
	//endl usage
	cout<<endl<<x<<endl<<y<<endl;

	//hexadecimal; effect

	cout<<hex<<x<<"\t"<<y;

	int z=25;

	cout<<endl<<z;//effect of hex continues


	//effect of octal

	cout<<oct<<"\n"<<x<<"\t"<<y<<"\t"<<z;

	//effect of decimal

	cout<<endl<<dec<<x<<"\t"<<y<<"\t"<<z;

	

}

