//QUEUE USING CIRCULAR ARRAY

#include<iostream>
using namespace std;

template<class T, int size=10>
class queue
{
	T a[size];
	int front , rear;

	public:

		queue()
		{
			front=rear=-1;
		}

		void enqueue(T);
		T dequeue();
		void clear();
		void display();
		int isfull();
		int isempty();
};



template<class T, int size>
int queue<T,size>::isfull()
{
	if(rear==size-1 && front==0 || rear==front-1)
		return 1;
	else
		return 0;
}

template<class T, int size>
int queue<T,size>::isempty()
{
	if(front==-1 && rear==-1)
		return 1;
	else
		return 0;
}

template<class T, int size>
void queue<T,size>::enqueue(T x)
{
	if(rear==size-1)
	{
		rear=0;
	}
	else if(rear==-1)
	{
		front=rear=0;
	}
	else
	{
		++rear;
	}

	a[rear]=x;
}

template<class T , int size>
void queue<T, size>::clear()
{
	rear=front=-1;
}


template<class T , int size>
T queue<T,size>::dequeue()
{
  T x;
  x=a[front];

  if(front==rear)
  {
	  front=rear=-1;
  }
  else if(front==size-1)
  {
	  front=0;
  }
  else
  {
	  front++;
  }

  return x;
}

template<class T , int size>
void queue<T,size>::display()
{
	int i;

	if(rear<front)
	{
		for(i=front;i<size;i++)
			cout<<a[i]<<" ";

		
		for(i=0;i<=rear;i++)
			cout<<a[i]<<" ";
	}
	else
	{
		
		for(i=front;i<=rear;i++)
			cout<<a[i]<<" ";
	}
}


void main()
{
	queue<int,5> Q1;
	int x, ch;
	char op;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. ENQUEUE ELEMENT";
		cout<<"\n 2. DEQUEUE ELEMENT";
		cout<<"\n 3. DISPLAY";
		cout<<"\n 4. CLEAR";
		cout<<"\n ENTER A CHOICE";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"\n ENQUEUE";
			   cout<<"\n Enter an element";
			   cin>>x;
			   if(Q1.isfull()==0)
			   {
				   Q1.enqueue(x);
			   }
			   else
				   cout<<"\n OVERFLOW";

			   break;
		case 2:cout<<"\n DEQUEUE";
			   if(Q1.isempty()==0)
			   {
				   x=Q1.dequeue();
				   cout<<"\n Element popped:"<<x<<endl;
			   }
			   else
				   cout<<"\n UNDERFLOW";
			   break;
		case 3:if(Q1.isempty()==0)
			   {
				   Q1.display();
			   }
			   else
				   cout<<"\n No element to be  displayed";
			   break;
		case 4:Q1.clear();
			   break;
		}
		cout<<"\n Do you want to continue?";
		cin>>op;
	}
	while(op=='Y' || op=='y');
}
