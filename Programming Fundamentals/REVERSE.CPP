//REVERSE ARRAY

#include<iostream>
using namespace std;

void reverse(int *p,int n)
{
	int temp,i,j;

	for(i=0,j=n-1;i<n/2;i++,j--)
	{
		temp=*(p+i);
		*(p+i)=*(p+j);
		*(p+j)=temp;
	}
}

void main()
{

	int arr[10],n,i;

	cout<<"\n Enter number of elements entered=";
	cin>>n;

	for(i=0;i<n;i++)
		cin>>arr[i];

	reverse(arr,n);

	cout<<"\n Revresed Elements are........";

	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";

}

