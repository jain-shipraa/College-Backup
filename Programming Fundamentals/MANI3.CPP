//MANIPULATOR SETW AND SETFILL

#include<iostream>
#include<iomanip>
using namespace std;

void main()
{
	int x=4,y=10;

	cout<<x;

	cout<<setw(4)<<endl;

	cout<<x; // it sets width to 4 and right allignment so 3 spaces appear

	cout<<setfill('*'); //it fills empty space with '*'

	cout<<setw(10)<<endl;//width becomes 10

	cout<<x;
	
	cout<<setw(1)<<endl<<y;//it bypasses our condition of having width=1

}
