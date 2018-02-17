//MERGE SORT ALGORITHM AND COUNTING THE NUMBER OF COMPARISONS

#include<iostream>
using namespace std;

class msort
{
	int A[50];
	int size;
	static int mergecounter;

public:

	msort()
	{
		size =0;
	}

	void input();
	void sort();
	void mergesort(int start, int end);
	void merge(int start, int mid, int end);
	void display();
};

int msort::mergecounter=0;

void msort::input()
{
	int i;

	cout<<"\n Enter the number of elements =";
	cin>>size;

	for(i=0;i<size;i++)
	{
		cin>>A[i];
	}

}
void msort::sort()
{
	mergesort(0,size-1);
}

void msort::mergesort(int start, int end)
{
	int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		mergesort(start, mid);
		
		mergesort(mid+1, end);
		merge(start, mid, end);
	}
}

void msort::merge(int start, int mid, int end)
{
	int i,j,k;
		k=start;

	int n1=(mid-start)+1;
	int n2=end-mid;

	int* arr1=new int[n1];
	int* arr2=new int[n2];
	
	for(i=0;i<n1;i++)
	{
		arr1[i]=A[start+i];
	}

	for(j=0;j<n2;j++)
	{
		arr2[j]=A[mid+1+j];

	}

	i=j=0;

	while(i<n1 && j<n2)
	{
		mergecounter++;
		if(arr1[i]<=arr2[j])
		{
			A[k]=arr1[i];
			i++;
		}
		else
		{
			A[k]=arr2[j];
			j++;
		}

		k++;
	}


	while(i<n1)
	{
		A[k]=arr1[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		A[k]=arr2[j];
		j++;
		k++;
	}

}


void msort::display()
{
	int i;

	for(i=0;i<size;i++)
	{
		cout<<"  "<<A[i];
	}

	cout<<"\n COMAPRISONS="<<mergecounter;
}

void main()
{
	msort O1;

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


