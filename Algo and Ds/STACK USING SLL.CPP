//STACK USING LINKED LIST

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
class stack
{
	node<T> *top;

	public:

		stack()
		{
			top=NULL;
		}

		void push(T);
		T pop();
		void display();
		T topel();
		void clear();
		int isempty();
};

template<class T>
void stack<T>::push(T x)
{
	node<T> *temp=new node<T>(x);

	if(isempty())
	{
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}

template<class T>
int stack<T>::isempty()
{
	if(top==NULL)
		return 1;
	else 
		return 0;
}

template<class T>
T stack<T>::pop()
{
	node<T> *temp;
	T x;
	x=top->info;

	if(top->next==NULL)
	{
		delete top;
		top=NULL;
	}
	else
	{
		temp=top;
		top=top->next;
		delete temp;
	}

	return x;

}

template<class T>
void stack<T>::display()
{
	node<T> *temp;
	temp=top;
	while(temp!=NULL)
	{
		cout<<" " <<temp->info;
		temp=temp->next;
	}
}

template<class T>
T stack<T>::topel()
{
	T x;
	x=top->info;
	return(x);
}

template<class T>
void stack<T>::clear()
{
	T x;
	while(top!=NULL)
	{
		x=pop();
	}

	top=NULL;
}

void main()
{
	stack<int> S1;
	int x, ch;
	char op;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. PUSH ELEMENT";
		cout<<"\n 2. POP ELEMENT";
		cout<<"\n 3. TOP MOST ELEMENT";
		cout<<"\n 4. DISPLAY";
		cout<<"\n 5. CLEAR";
		cout<<"\n ENTER A CHOICE";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"\n PUSH";
			   cout<<"\n Enter an element";
			   cin>>x;
			   S1.push(x);
			   break;
		case 2:cout<<"\n POP";
			   if(S1.isempty()==0)
			   {
				   x=S1.pop();
				   cout<<"\n Element popped:"<<x<<endl;
			   }
			   else
				   cout<<"\n UNDERFLOW";
			   break;
		case 3:if(!S1.isempty())
			   {
				   x=S1.topel();
			       cout<<"\n TOP MOST ELEMNT:"<<x;
			   }
			   else 
				   cout<<"\n No element yet to display";
			   break;
		case 4:if(S1.isempty()==0)
			   {
				   S1.display();
			   }
			   else
				   cout<<"\n No element to be  displayed";
			   break;
		case 5:S1.clear();
			   break;
		}
		cout<<"\n Do you want to continue?";
		cin>>op;
	}
	while(op=='Y' || op=='y');


}
