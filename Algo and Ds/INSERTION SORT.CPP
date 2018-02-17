//INSERTION SORT

#include<iostream>
using namespace std;

class isort
{
	int A[50];
	int size;
	static int counter;

public:

	isort()
	{
		size =0;
	}

	void input();
	void sort();
	void insert_sort(int size);
	void display();
};

int isort::counter=0;

void isort::sort()
{
	insert_sort(size);
}

void isort::display()
{
	int i;

	for(i=0;i<size;i++)
	{
		cout<<"  "<<A[i];
	}

	cout<<"\n COMAPRISONS="<<counter;
}

void isort::input()
{
	int i;

	cout<<"\n Enter the number of elements =";
	cin>>size;

	for(i=0;i<size;i++)
	{
		cin>>A[i];
	}

}

void isort::insert_sort( int size)
{
	int i, j , key;

	for(i=1;i<size;i++)
	{
		
		key=A[i];


		for(j=i-1; j>=0 && A[j]>key; j=j-1)
		{
			
			counter++;
			A[j+1]=A[j];
		
		}

		A[j+1]=key;
	}

	cout<<endl;
}

void main()
{
	isort O1;

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
 

