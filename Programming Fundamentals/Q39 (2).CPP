//QUES 39 PG 293

#include<iostream>
using namespace std;

void main()
{
	int r,c,i,j;

	cout<<"\n Enter rows=";
	cin>>r;

	cout<<"\n Enter col=";
	cin>>c;

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
	      cout<<"*";
		cout<<endl;
	}
}