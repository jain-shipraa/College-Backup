// MERGE 2 ORDERED ARRAYS

#include<iostream>
using namespace std;

void main()
{

	int n1,arr1[10],n2,arr2[10],size,mer[20],i,j,k,n=0;

    cout<<"\n Enter number of elements u want=";
	cin>>n1;

	cout<<"\n Enter elements of array 1 :";
	for(i=0;i<n1;i++)
		cin>>arr1[i];

	cout<<"\n Enter number of elements u want in array 2:";
	cin>>n2;

	cout<<"\n Enter elements of an array :";
	for(j=0;j<n2;j++)
		cin>>arr2[j];

 if(n1<n2) 
    size=n2;
 else
    size=n1;

	for(k=0,i=0,j=0;i<size && j<size; )
	{
		if(arr1[i]<arr2[j])
		{
			mer[k]=arr1[i];
			k++;
			i++;
		}
		else if(arr1[i]>arr2[j])
		{
			mer[k]=arr2[j];
			k++;
			j++;
		}
		else
		{
			mer[k]=arr1[i];
			i++;
			j++;
			k++;
			n++;
		}
	}

	if(i<n1)
	{
		for(k=size+1;i<n1;k++,i++)
			mer[k]=arr1[i];
	}
	else if(j<n2)
	{
		for(k=size+1;j<n2;k++,j++)
			mer[k]=arr2[j];
	}

	cout<<"\n Mergered Array Looks like ......";
	for(k=0;k<((n1+n2)-n);k++)
		cout<<mer[k]<<" " ;
}
