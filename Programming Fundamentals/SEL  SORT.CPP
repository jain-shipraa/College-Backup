//SELECTION SORT

#include<iostream>
using namespace std;

void sel_sort(int a[], int s)
{

	int small,pos,i,j,temp;


	for(i=0;i<s;i++)
	{
		pos=i;
		small=a[i];

		 for(j=i+1;j<s;j++)
		 {
			 if(small>a[j])
			 {
				 pos=j;
				 small=a[j];
			 }
		 }

		 temp=a[pos];
		 a[pos]=a[i];
		 a[i]=temp;
	}
}

void main()
{

	int arr[10],size;

	cout<<"\n Enter size=";
	cin>>size;

	cout<<"\n ENTER ELEMENTS...";

	for(int i=0;i<size;i++)
		cin>>arr[i];

	sel_sort(arr,size);

	for(i=0;i<size;i++)
		cout<<arr[i]<<" " ;
}

