// TO IMPLEMENT QUICK SORT(THE PROGRAM MUST REPORT THE NUMBER OF COMPARISONS)

#include<iostream>
using namespace std;

class qsrt
{
	int arr[50];
	int sz;
	static int counter;

public:

	qsrt()
	{
		sz=0;
	}

	void input();
	int partition(int , int);
	void quick_sort(int , int);
	void sort();
	void display();
};
int qsrt::counter=0;

void qsrt::input()
{
	int i;

	cout<<"\n Enter the number of elements =";
	cin>>sz;

	for(i=0;i<sz;i++)
	{
		cin>>arr[i];
	}
}

int qsrt::partition(int p, int r)
{
	int i,j,x,temp;

	x=arr[r];
	i=p-1 ;

	for(j=p;j<r;j++)
	{
		if(arr[j]<=x)
		{
			counter++;
			i++;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		
		}

	}

	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;

	return (i+1);
}

void qsrt::quick_sort(int p, int r)
{
	int q;
	if(p<r)
	{
		q=partition(p,r);
		quick_sort(p,q-1);
		quick_sort(q+1,r);
	}
}

void qsrt::sort()
{
	quick_sort(0,sz-1);
}

void qsrt::display()
{
	int i;

	for(i=0;i<sz;i++)
	{
		cout<<"  "<<arr[i];
	}

	cout<<"\n THE NUMBER OF COMPARISONS:"<<counter;
}

void main()
{

	qsrt O1;

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
			    O1.sort();
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


