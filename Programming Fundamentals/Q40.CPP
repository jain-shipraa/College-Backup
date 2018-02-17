//QUESTION 40 PAGE 293

#include<iostream>
#include<iomanip>
using namespace std;

void main()
{

	int r,i,j;

	cout<<"\n Enter no of rows=";
	cin>>r;

	for(i=0;i<r;i++)
	{
		cout<<endl;
		if(i==0||i==r-1)
		{
			for(j=0;j<11;j++)
				cout<<"=";
		}
		else
			cout<<"*"<<setw(10)<<"*";
	}

}
