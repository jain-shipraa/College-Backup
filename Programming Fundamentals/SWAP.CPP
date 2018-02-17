//QUESTION 14

#include<iostream>
using namespace std;

void swap(int* x,int* y);

void main()
{

	int n1,n2;

	cout<<"\n Enter a number=";
	cin>>n1;

	cout<<"\n Enter another number=";
	cin>>n2;

	
	cout<<"\n Swapped Values=";
	cout<<"\n Number 1="<<n1;
	cout<<"\n Number 2="<<n2;
	cout<<endl;

	swap(&n1,&n2);

	cout<<"\n Swapped Values=";
	cout<<"\n Number 1="<<n1;
	cout<<"\n Number 2="<<n2;
	cout<<endl;

}

void swap(int* x,int* y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;

}
