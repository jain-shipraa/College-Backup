// DELETE AN I TH NODE FROM A SLL . BE SURE THAT SUCH A NODE EXIST

#include<iostream>
using namespace std;

template <class T>
class node
{
public:
	T info;
	node *next;

	node(T x, node *n=0)
	{
		info=x;
		next=n;
	}
};


template<class T>
class SLList 
{
	int c;
	node<T>* temp1[50];
	node<T> *head,*tail;

	public:
		SLList()
		{
			c=-1;
			head=tail=NULL;
		}

		int isempty();
		void addtohead(T);
		void addtotail(T);
		T deletefromhead();
		T deletefromtail();
		void deletenode(T);
		int isinlist(T);
		void display();
        void reverse();


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
void SLList<T>::addtohead(T x)
{
	node<T> *temp=new node<T>(x);


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
void SLList<T>::addtotail(T x)
{
	node<T> *temp=new node<T>(x);

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
T SLList<T>::deletefromhead()
{
	node<T> *temp;
	T x=head->info;

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

	return x;
}


template <class T>
T SLList<T>::deletefromtail()
{
	node<T> *temp;
	T x=tail->info;

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

	return x;
}


template <class T>
void SLList<T>::deletenode(T x)
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


template<class T>
void SLList<T>::display()
{
	node<T> *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		cout<<temp->info<<" ";
	}
};

template<class T>
int SLList<T>::isinlist(T x)
{
	node<T> *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->info==x)
		{
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}



template<class T>
void SLList<T>::reverse()
{
	node<T>* temp=head;
	int i;

	while(temp!=0)
	{
		temp1[++c]=temp;
		temp=temp->next;
	}

	for(i=c;i>0;i--)
	{
		temp1[i]->next=temp1[i-1];
	}

	temp1[i]->next=NULL;
	head=temp1[c];
}


void main()
{
	SLList<int> L, L2;
	int ch,x;
	char op;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. LIST IS EMPTY OR NOT ";
		cout<<"\n 2. ADD TO HEAD";
		cout<<"\n 3. ADD TO TAIL";
		cout<<"\n 4. DELETE FROM HEAD";
		cout<<"\n 5. DELETE FROM TAIL";
		cout<<"\n 6. DELETE NODE";
		cout<<"\n 7. ELEMENT IS IN LIST OR NOT";
		cout<<"\n 8. DISPLAY";
		cout<<"\n 9. REVERSE";
		cout<<"\n ENTER YOUR CHOICE:";
		cin>>ch;

		switch(ch)
		{
		case 1: cout<<"\n IS LIST EMPTY OR NOT";
				x=L.isempty();
				if(x==1)
					cout<<"\n List is empty ";
				else
					cout<<"\n List is not empty";
				break;

		case 2: cout<<"\n ADD TO HEAD";
			    cout<<"\n Enter a value to be added to the list=";
				cin>>x;
				L.addtohead(x);
				break;

		case 3: cout<<"\n ADD TO TAIL:";
			    cout<<"\n Enter a value to be added to the list=";
				cin>>x;
				L.addtotail(x);
				break;

		case 4: cout<<"\n DELETE FROM HEAD";
		        if(L.isempty()==0)
				{
					x=L.deletefromhead();
					cout<<"\n Delete element is : "<<x;
				}
				else
				 cout<<"\n UNDERFLOW!!!!!";
				break;
		case 5:cout<<"\n DELETE FROM TAIL";
		        if(L.isempty()==0)
				{
					x=L.deletefromtail();
					cout<<"\n Delete element is : "<<x;
				}
				else
				 cout<<"\n UNDERFLOW!!!!!";
				break;
		case 6:cout<<"\n  DELETE A PARTICULAR NODE";
	           if(L.isempty()==0)
				{
				    cout<<"\n Enter a value you want to delete from list:";
					cin>>x;
					L.deletenode(x);
				}
				else
				 cout<<"\n UNDERFLOW!!!!!";
				break;
		case 7: cout<<"\n ELEMENT IS IN LIST OR NOT?";
	    	    if(L.isempty()==0)
				{cout<<"\n Enter a value you want to search in list:";
				cin>>x;
				int status;
				status=L.isinlist(x);
				if(status==1)
					cout<<"\n Element found";
				else
					cout<<"\n Element not found";
				}
				else
				{
					cout<<"\n List is empty!!!";
				}
				break;
		case 8: cout<<"\n DISPLAYING LIST ";
			    if(L.isempty()==0)
			       L.display();
				else
					cout<<"\n No element to display";
				break;
		case 9: cout<<"REVERSE";
			    L.reverse();
				L.display();
				break;

		default: cout<<"\n Wrong Choice";

		}

		cout<<"\n Do you want to continue?";
		cin>>op;

	}while(op=='Y' || op=='y');
}
