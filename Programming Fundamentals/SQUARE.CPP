// TO PRNT SQUARE 1-10
#include<iostream>
#include<iomanip>
using namespace std;

void main()
{
	int i=1;

	while(i<=10)
	{
		cout<<"SQUARE OF"<<setw(3)<<i<<"="<<setw(3)<<(i*i)<<endl;
		i++;
	}
}


