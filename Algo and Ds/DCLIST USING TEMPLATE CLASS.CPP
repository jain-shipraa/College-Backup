// IMPLEMENTING DOUBLE CIRCULAR LIST USING TEMPLATE CLASS

#include<iostream>
using namespace std;

template<class T>
class node
{

	public:
	T info;
	node *next,*prev;

	node(T x, node *n=0, node *p=0)
	{
		info=x;
		next=n;
		prev=p;
	}
};

template<class T>
class DCList 
{
	node<T> *tail;

	public:
		DCList()
		{
			tail=NULL;
		}

		int isempty();
		void addtohead(T);
		void addtotail(T);
		T deletefromhead();
		T deletefromtail();
		void deletenode(T);
		int isinlist(T);
		//~DCList();
		void display();
	    DCList<T> reverse();
		void concat(DCList<T> O1);

};

template<class T>
int DCList<T>::isempty()
{
	if(tail==NULL)
		return 1;
	else
		return 0;
}

template<class T>
void DCList<T>::addtohead(T x)
{
	node<T> *temp=new node<T>(x);

	if(isempty())
	{
		tail=temp;
		tail->next=tail;
		tail->prev=tail;
	}
	else
	{
		temp->next=tail->next;
		temp->prev=tail;
		tail->next->prev=temp;
		tail->next=temp;
	}
}

template<class T>
void DCList<T>::addtotail(T x)
{
	node<T> *temp=new node<T>(x);

	if(isempty())
	{
		tail=temp;
		tail->next=tail;
		tail->prev=tail;
	}
	else
	{
		temp->next=tail->next;
		temp->prev=tail;
		tail->next->prev=temp;
		tail->next=temp;
		tail=temp;
	}

}

template<class T>
T DCList<T>::deletefromhead()
{
	T x=tail->next->info;

	if(tail==tail->next)
	{
		delete tail;
		tail=NULL;
	}
	else
	{
		node<T> *temp;
		temp=tail->next;
		tail->next=temp->next;
		temp->next->prev=temp->prev;
		delete temp;
	}

	return x;
}

template<class T>
T DCList<T>::deletefromtail()
{
	T x=tail->info;

	if(tail==tail->next)
	{
		delete tail;
		tail=NULL;
	}
	else
	{
		node<T> * temp;
		tail->prev->next=tail->next;
		tail->next->prev=tail->prev;
		temp=tail;
		tail=tail->prev;
		delete temp;
	}
	return x;

}

template<class T>
void DCList<T>::deletenode(T x) 
{
	if(tail->next==tail && tail->info==x)
	{
		delete tail;
		tail=NULL;
	}
	else if(tail->next->info==x)
	{
		x=deletefromhead();
	}
	else
	{
		node<T> *cur;
		cur=tail->next->next;

		while(cur!=tail->next && cur->info!=x)
		{
			cur=cur->next;
		}

		if(cur!=tail->next)
		{
			cur->prev->next=cur->next;
			cur->next->prev=cur->prev;
			if(tail==cur)
			   tail=cur->prev;
			delete cur;
		}
		else
			cout<<"\n Element not found";
	}

}

template<class T>
int DCList<T>::isinlist(T x)
{
	node<T> *temp;
	temp=tail->next;

	do
	{
		if(temp->info==x)
			return 1;

		temp=temp->next;
	}
	while(temp!=tail->next);

	return 0;
}

template<class T>
void DCList<T>::display()
{
	node<T> *temp;
	temp=tail->next;

	do
	{
		cout<<temp->info<<" ";
		temp=temp->next;
	}
	while(temp!=tail->next);

}

template<class T>
DCList<T> DCList<T>::reverse()
{
	DCList<T> O1;
	node<T> *temp=tail->next;
	do
	{

		O1.addtohead(temp->info);
		temp=temp->next;
	}
	while(temp!=tail->next);

	return O1;
}

template<class T>
void DCList<T>::concat(DCList<T> O1)
{
	node<T> *temp;
	temp=O1.tail->next;
	do
	{
		addtotail(temp->info);
		temp=temp->next;
	}
	while(temp!=O1.tail->next);
}


void main()
{

	DCList<int> L, L2, LREV;
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
		cout<<"\n 10.CONCAT";
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
		case 9: cout<<"\n REVERSE ";
			    if(L.isempty()==0)
				{
					LREV=L.reverse();
					LREV.display();
				}
				else
					cout<<"\n List contains no element";
				break;
	    case 10: cout<<"\n CONCAT";
			     cout<<"\n CREATE ANOTHER LIST";
				 cout<<"\n ENTER ELEMNTS:";
				 op='y';
				 while (op=='y')
				 {
					 cout<<"\n Enter element=";
					 cin>>x;
					 L2.addtotail(x);
					 cout<<"\n Want to enter more?";
					 cin>>op;
				 }
			     if(L.isempty()==0)
				 {
					 cout<<"\n CONCATENATED LIST:"<<endl;
					 L.concat(L2);
					 L.display();
				 }
				 break;

		default: cout<<"\n Wrong Choice";

		}

		cout<<"\n Do you want to continue?";
		cin>>op;

	}while(op=='Y' || op=='y');
}

