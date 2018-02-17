//EVEN NO FROM 1 TO 100

#include<iostream>
#include<iomanip>
using namespace std;
void main()
{

	int i=0;

	cout<<"Even numbers:"<<endl;
	while(i<=100)
	{
		cout<<setw(5)<<i;
		i+=2;

	}

	cout<<endl;

}
