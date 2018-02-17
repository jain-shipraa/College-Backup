//QUEUE USING LINKED LIST

#include<iostream>
using namespace std;


template<class T>
class node
{
	public:
		T info;
		node *next;
		node(T x, node *n=NULL)
		{
			info=x;
			next=n;
		}
};
 
template<class T>
class queue
{
	node<T> *front,*rear;

	public:

		queue()
		{
			front=rear=NULL;
		}

		void enqueue(T);
		T dequeue();
		void display();
		void clear();
		int isempty();
};


template<class T>
void queue<T>::enqueue(T x)
{
	node<T> *temp=new node<T>(x);

	if(isempty())
	{
		front=rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}


template<class T>
int queue<T>::isempty()
{
	if(front==NULL)
		return 1;
	else 
		return 0;
}


template<class T>
T queue<T>::dequeue()
{
	node<T> *temp;
	T x;
	x=front->info;

	if(front==rear)
	{
		delete front;
		front=rear=NULL;
	}
	else
	{
		temp=front;
		front=front->next;
		delete temp;
	}

	return x;

} 

template<class T>
void queue<T>::display()
{
	node<T> *temp;
	temp=front;
	while(temp!=NULL)
	{
		cout<<" " <<temp->info;
		temp=temp->next;
	}
}

template<class T>
void queue<T>::clear()
{
	T x;
	while(front!=NULL)
	{
		x=dequeue();
	}

	front=NULL;
	rear=NULL;
}

void main()
{
	queue<int> Q1;
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
			   Q1.enqueue(x);
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
