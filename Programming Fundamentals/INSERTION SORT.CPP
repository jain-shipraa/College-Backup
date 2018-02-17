//INSERTION SORT

#include<iostream>
using namespace std;

void ins_sort(int a[], int n)
{
	int i,j,temp;

	for(i=1;i<n;i++)
	{
		temp=a[i];

		for(j=i-1;j>=0;j--)
		{
			if(temp<a[j])
			{
				a[j+1]=a[j];
			}
			else
				break;
		}
		a[j+1]=temp;
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

    ins_sort(arr,size);

	for(i=0;i<size;i++)
		cout<<arr[i]<<" " ;
}
