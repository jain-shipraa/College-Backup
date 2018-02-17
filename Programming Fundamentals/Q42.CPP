// QUESTION 42 PG 293

#include<iostream>
using namespace std;

void main()
{

	int i,j,r,c;

	cout<<"\n Enter no of rows=";
	cin>>r;	

	cout<<"\n Enter no of col=";
    cin>>c;

	for(i=0;i<r;i++)
	{
		for(j=0;j<(c-2*i);j++)
			cout<<"*";
		cout<<endl;
	}

}
