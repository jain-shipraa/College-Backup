//WAP TO ADD TWO POLYNOMIAL USING LINKED LIST

#include<iostream>
using namespace std;

template<class T>
class node
{
	public:
		T info;
		T power;
		node *next;
		node(T x,T p,node *n=NULL)
		{
			info=x;
			power=p;
			next=n;
		}
};

template<class T>
class SLList 
{
	node<T> *head,*tail;

	public:
		SLList()
		{
			head=tail=NULL;
		}

		int isempty();
		void addtohead(T,T);
		void addtotail(T,T);
		void deletefromhead();
		void deletefromtail();
		//void deletenode(T,T);
		void display();
	    SLList<T> add(SLList<T>);
};

template<class T>
int SLList<T>::isempty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}

template<class T>
void SLList<T>::addtohead(T x,T p)
{
	node<T> *temp=new node<T>(x,p);


	if(isempty())
	{
		head=tail=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}

template<class T>
void SLList<T>::addtotail(T x,T p)
{
	node<T> *temp=new node<T>(x,p);

	if(isempty())
	{
		head=tail=temp;
	}
	else
	{
		tail->next=temp;
		tail=temp;
	}
}

template<class T>
void SLList<T>::deletefromhead()
{
	node<T> *temp;
	T x=head->info;
	T p=head->power;

	if(head==tail)
	{
		delete head;
		head=tail=NULL;
	}
	else
	{
		temp=head;
		head=head->next;
		delete temp;
	}

	cout<<"\n Deleted Term:"<<x<<"x^"<<p;
}


template <class T>
void SLList<T>::deletefromtail()
{
	node<T> *temp;
	T x=tail->info;
	T p=head->power;

	if(head==tail)
	{
		delete head;
		head=tail=NULL;
	}
	else
	{

		temp=head;
		while(temp->next!=tail)
		{
			temp=temp->next;
		}

		delete tail;
		tail=temp;
		temp->next=NULL;
	}

	
	cout<<"\n Deleted Term:"<<x<<"x^"<<p;
}


/*template <class T>
void SLList<T>::deletenode(T x, T p )
{
	if(head==tail && head->info==x)
	{
		delete head;
		head=tail=NULL;
	}
	else if(head->info==x)
	{
	    x=deletefromhead();
		cout<<"\n "<<x <<" is  deleted";
	}
	else
	{
		node<T> *prev,*cur;
		prev=head;
		cur=head->next;
		while(cur!=0 && cur->info!=x)
		{
			prev=cur;
			cur=cur->next;
		}

		if(cur!=0)
		{
			prev->next=cur->next;
		    if(tail==cur)
			{
			tail=prev;
			}
		delete cur;
		}
		else
		{
			cout<<"\n Element not found";
		}
	}
}
*/

template<class T>
void SLList<T>::display()
{
	node<T> *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		cout<<"+"<<temp->info<<"x^"<<temp->power<<" ";
	}
}

template<class T>
SLList<T>  SLList<T>::add(SLList<T> S2)
{
	node<T> *temp,*temp2;
	SLList<T> L3;

	temp=head;
	temp2=S2.head;

	while(temp!=NULL && temp2!=NULL)
	{
		if(temp->power==temp2->power)
		{
			L3.addtotail(temp->info+temp2->info,temp->power);
			temp=temp->next;
			temp2=temp2->next;
		}
		else if(temp->power>temp2->power)
		{
			L3.addtotail(temp->info,temp->power);
			temp=temp->next;
		}
		else
		{
			L3.addtotail(temp2->info,temp2->power);
			temp2=temp2->next;
		}
	}

	if(temp!=NULL)
	{
		while(temp!=NULL)
		{
			L3.addtotail(temp->info,temp->power);
			temp=temp->next;
		}
	}
	else
	{

		while(temp2!=NULL)
		{
			L3.addtotail(temp2->info,temp2->power);
			temp2=temp2->next;
		}
	}

	return  L3;
}

void main()
{
	SLList<int> S1,S2,S3;
	char ch='y';
	int coff, pow;

	cout<<"\n Enter first polynomial=";
	while(ch=='y' || ch=='Y')
	{
		cout<<"\n Enter term:";
		cout<<"\n Enter coefficient of x=";
		cin>>coff;
		cout<<"\n Enter power of x=";
		cin>>pow;

		S1.addtotail(coff,pow);
		cout<<"\n Want to  enter more terms?";
		cin>>ch;
	}


	ch='y';

	cout<<"\n Enter second polynomial=";
	while(ch=='y' || ch=='Y')
	{
		cout<<"\n Enter term:";
		cout<<"\n Enter coefficient of x=";
		cin>>coff;
		cout<<"\n Enter power of x=";
		cin>>pow;

		S2.addtotail(coff,pow);
		cout<<"\n Want to  enter more terms?";
		cin>>ch;
	}


	S3=S1.add(S2);
	cout<<"\n Result:";
	S3.display();
}
