//PATTERN(LOWER TRIANGLE) Q25 PG 72

#include<iostream>
using namespace std;

void main()
{
	int i=0,j;

	while(i<4)
	{
		j=0;

		while(j<=i)
		{
			cout<<"*";
			j++;
		}
		i++;
		cout<<endl;
	}

	cout<<endl;
}
