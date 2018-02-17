//COUNT SORT IMPLEMENTATION

#include<iostream>
using namespace std;

class csort
{
	int a[50];
	int size,range;

public:

	csort()
	{
		size=range=0;
	}

	void input();
	void sort();
	void countingsort(int);
	void display();

};

void csort::input()
{
	int i;

	cout<<"\n Enter the number of elements ::";
	cin>>size;

	cout<<"\n Enter the elements:";
	for(i=0;i<size;i++)
		cin>>a[i];
}

void csort::sort()
{
	int max,i;

	max=a[0];

	for(i=1;i<size;i++)
	{
		if(max<a[i])
			max=a[i];
	}

	range=max;
	countingsort(range);

}

void csort::countingsort(int r)
{
	int i,j;
	int b[50],c[50];

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

	for(j=0;j<size;j++)
		a[j]=b[j+1];
}

void csort::display()
{
	int i;
	cout<<"\n Displaying....";
	for(i=0;i<size;i++)
		cout<<" "<<a[i];
}

void main()
{
	
	csort O1;

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
