//ASCII VALUE PROGRAMME

#include<iostream>
#include<iomanip>
using namespace std;


void main()
{
	int x;
	char ch='a';

	while(ch<='z')
	{
	x=ch;
	cout<<ch<<"="<<x<<"\t";
	ch++;
	}


	cout<<endl;

	ch='A';
	while(ch<='Z')
	{
		x=ch;
		cout<<ch<<"="<<x<<"\t";
		ch++;
	}

	cout<<endl;

}