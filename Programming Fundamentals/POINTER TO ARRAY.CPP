//POINTER TO ARRAY

#include<iostream>
using namespace std;

void asc(int a[],int n)
{

	int *p[10],*min,*temp,pos,i,j;

	for(i=0;i<n;i++)
	{
		p[i]=&a[i];
	}


	for(i=0;i<n;i++)
	{
		min=p[i];
		pos=i;

		for(j=i+1;j<n;j++)
		{

			if(*min>*p[j])
			{
				pos=j;
				min=p[j];
			}
		}


	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;
	
	}


	for(i=0;i<n;i++)
		cout<<*p[i]<<" ";
}


void dsc(int a[],int n)
{

	int *p[10],*max,*temp,pos,i,j;

	for(i=0;i<n;i++)
	{
		p[i]=&a[i];
	}


	for(i=0;i<n;i++)
	{
		max=p[i];
		pos=i;

		for(j=i+1;j<n;j++)
		{

			if(*max<*p[j])
			{
				pos=j;
				max=p[j];
			}
		}


	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;
	
	}

	
for(i=0;i<n;i++)
		cout<<*p[i]<<" ";
}

void main()
{

	int arr[10],n,i;

	cout<<"\n Enter size:";
	cin>>n;

	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	asc(arr,n);
	cout<<endl;
	dsc(arr,n);	

}




