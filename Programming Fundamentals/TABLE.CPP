//TABLE 3
#include<iostream>
#include<iomanip>
using namespace std;

void main()
{

	int i=1;
	cout<<"\n TABLE OF 3"<<endl;
	while(i<=10)
	{

		cout<<setw(4)<<"3*"<<setw(2)<<i<<"="<<setw(4)<<(3*i)<<endl;
		i++;

	}

}
