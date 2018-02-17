// RADIX SORT IMPLEMENTATION USING COUNTING SORT

#include<iostream>
#include<cmath>
using namespace std;

class rsort
{
	int arr[50],a[50],b[50],temp[50];
	int size;

public:

	rsort()
	{
		size =0;
	}

	void input();
	void radix_sort();
	void countingsort(int[],int);
	void display();
	int nod();

};

void rsort::input()
{	
	int i;

	cout<<"\n Enter the number of elements =";
	cin>>size;

	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
}

void rsort::display()
{

	int i;

	for(i=0;i<size;i++)
	{
		cout<<"  "<<arr[i];
	}
}

int rsort::nod()
{
	int i,x;
	x=arr[0];

	for(i=1;i<size;i++)
	{
		if(x<arr[i])
			x=arr[i];
	}

	i=0;

	while(x!=0)
	{
		x/=10;
		i++;
	}

	return i;
}

void rsort::radix_sort()
{
	int i,j,k,y,j2,x;

	for(j=nod();j>0;j--)
	{
		for(i=0;i<size;i++)
		{

			y=pow(10,nod()-j);
			x=arr[i]/y;
			a[i]=x%10;
		}

		countingsort(a,9);
		
		k=0;
		for(i=1;i<=size;i++)
		{
			for(j2=0;j2<size;j2++)
			{
				if(b[i]==a[j2])
				{
					temp[k]=arr[j2];
					k++;
					a[j2]=10;
					
				}
			}
		}

		for(i=0;i<size;i++)
			arr[i]=temp[i];


	}
}


void rsort::countingsort(int a[], int r)
{
	int i,j;
	int c[50];

	for(i=0;i<=r;i++)
		c[i]=0;

	for(j=0;j<size;j++)
		c[a[j]]=c[a[j]]+1;

	for(i=1;i<=r;i++)
		c[i]=c[i]+c[i-1];

	for(j=size-1;j>=0;j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]=c[a[j]]-1;
	}

}

void main()
{
	rsort O1;

	int op;
	char ch;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INPUT";
		cout<<"\n 2. SORT";
		cout<<"\n 3. DISPLAY:";
		cout<<"\n Enter your choice=";
		cin>>op;

		switch(op)
		{
		case 1: cout<<"\n INPUT";
			    O1.input();
				break;
		case 2: cout<<"\n SORTED ARRAY....";
			    O1.radix_sort();
	            O1.display();
				break;
		case 3: cout<<"\n DISPLAY....";
			    O1.display();
		}


		cout<<"\n Do you want to continue?";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}



