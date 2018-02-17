//QUESTION 41 PG 293

#include<iostream>
using namespace std;

void main()
{
	int i,j,r;

	cout<<"\n Enter number of rows=";
	cin>>r;

	for(i=1;i<=r;i++)
	{
		for(j=1;j<=(2*i-1);j++)
			cout<<"*";
		cout<<endl;
	}

}
