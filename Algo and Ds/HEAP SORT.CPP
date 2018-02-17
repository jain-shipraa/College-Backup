//HEAP SORT

#include<iostream>
using namespace std;

class heap
{
	int arr[50];
	int heapsize;

public:

	heap()
	{
		heapsize=0;
	}

	void input();
	int parent(int);
	int left(int);
	int right(int);
	void maxheapify(int);
	void buildmaxheap();
	void heapsort();
	void display();
};

void heap::input()
{
	cout<<"\n Enter the size of the heap=";
	cin>>heapsize;

	for(int i=0;i<heapsize;i++)
		cin>>arr[i];
}

int heap::parent(int i)
{
	return ((i-1)/2);
}

int heap::left(int i)
{
	return ((2*i )+1);
}

int heap::right(int i)
{
	return ((2*i)+2);
}

void heap::maxheapify(int i)
{

	int l, r, largest, temp;

	largest=i;
	l=left(i);
	r=right(i);

	if(l<heapsize && arr[l]>arr[i])
		largest=l;
	else
		largest=i;

	if(r<heapsize && arr[r]>arr[largest])
		largest=r;

	if(largest!=i)
	{
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		maxheapify(largest);
	}

}

void heap::buildmaxheap()
{
	for(int i=(heapsize-1)/2; i>=0;i--)
	{
		maxheapify(i);
	}
}

void heap::heapsort()
{
	int i,temp,len;
	buildmaxheap();
	len=heapsize;

	for(i=len-1;i>=1;i--)
	{
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;

		heapsize--;
		maxheapify(0);
	}

	heapsize=len;
}

void heap::display()
{
	int i;

	for(i=0;i<heapsize;i++)
		cout<<arr[i]<<" ";
}

void main()
{
	heap H;

	int op, i;
	char ch;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INPUT";
		cout<<"\n 2. MAX HEAPIFY";
		cout<<"\n 3. BUILD MAX HEAP";
		cout<<"\n 4. HEAP SORT";
		cout<<"\n 5. DISPLAY:";
		cout<<"\n Enter your choice=";
		cin>>op;

		switch(op)
		{
		case 1: cout<<"\n INPUT";
			    H.input();
				break;
		case 2: cout<<"\n MAX HEAPIFY...";
			    cout <<"\n Enter position on which you want to run maxheapify:";
				cin>>i;
	            H.maxheapify(i);
				H.display();
				break;
		case 3: cout<<"\n BUILD MAX HEAPIFY ";
			    H.buildmaxheap();
				H.display();
				break;
		case 4: cout<<"\n HEAPSORT ";
			    H.heapsort();
				H.display();
				break;
		case 5: cout<<"\n DISPLAY....";
			    H.display();
				break;
		}


		cout<<"\n Do you want to continue?";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}


