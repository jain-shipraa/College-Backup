//QUESTION 38 PG 293

#include<iostream>
#include<iomanip>
using namespace std;

void main()
{

	int i,j,r;

	cout<<"\n Enter no of rows=";
	cin>>r;

	for(i=0;i<r;i++)
	{
		cout<<endl;
		for(j=0;j<r-i;j++)
			cout<<setw(3)<<j+1;
	}
}