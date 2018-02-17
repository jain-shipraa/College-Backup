//DESIGN USING FUNCTION 

#include<iostream>
#include<iomanip>
using namespace std;

void design(int r);

void main()
{
	int rows;

	cout<<"\n Enter number of rows=";
	cin>>rows;

	design(rows);

}


void design(int r)
{
	int i=0,j=0,n=1;

	while(i<r)
	{
		if(i<r-1)
		cout<<setw(r-i-1)<<" ";

		j=0;
		while(j<n)
		{
			cout<<"*";
			j++;
		}

		n+=2;
		cout<<endl;
		i++;

	}
}
