/* DELETE FROM LIST L1, NODES OCCUPYING POSITIONS INDICATED IN ORDERED LISTS L2 AND L3 . FRO INSTANCE , IF L1=(A B C D E), L2=(2 4 8) AND 
   L3=(2 5) , THEN AFTER DELETION , L1=(A C) */ 

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
	node<T> *head,*tail;

	public:
		SLList()
		{
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
		void deleteinode(int);
        void deleteele(SLList<int>, SLList<int>);

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
void SLList<T>::deleteinode(int i)
{

    int count=0;
	node<T> *temp;

	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}

	
	node<T> *prev ,*cur;
	prev=head;
	cur=head->next;

	if(i==1)
	{
		head=head->next;
		delete (prev);
	}
	else if(i>1 && i<=count)
	{
		for(int j=1;j<(i-1);j++)
		{
			prev=cur;
			cur=cur->next;
		}
		prev->next=cur->next;
		if(cur==tail)
			tail=prev;
		delete(cur);
	}
	else
		cout<<"\n Element not found";
}

template <class T>
void SLList<T>::deleteele(SLList<int> L2, SLList<int> L3)
{
   T x,y;
   x=L2.deletefromtail();
   y=L3.deletefromtail();

   	while(!L2.isempty() && !L3.isempty())
	{
	
	   if(x>y)
	   {
		deleteinode(x);
        	x=L2.deletefromtail();
      	   }
           else if(y>x)
	   {
		deleteinode(y);
		y=L3.deletefromtail();
	   }
	   else
	   {
		deleteinode(x);
                x=L2.deletefromtail();
    		y=L3.deletefromtail();
           }
	}

	if(!L2.isempty())
	{
		deleteinode(x);
                x=deletefromtail();
	}
        else if(!L3.isempty())
	{
		deleteinode(y);
                y=deletefromtail();
	}

}

void main()
{
	SLList<char> L, L2, LREV;
	SLList<int> L3,L4;
	int ch;
	char x;
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
		cout<<"\n 9. DELETE POSITIONS IN LIST 2 AND LIST 3";
		cout<<"\n ENTER YOUR CHOICE:";
		cin>>ch;

		switch(ch)
		{
		case 1: cout<<"\n IS LIST EMPTY OR NOT";
				ch=L.isempty();
				if(ch==1)
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
		case 9: cout<<"\n DELETE POSITIONS IN LIST 2 AND LIST 3";
    			cout<<"\n Enter elements for LIST 2";
                        if(L3.isempty())
			{	op='y';

				while(op=='y' || op=='Y')
				{
					cout<<"\n Enter element to be added=";
					cin>>ch;
					L3.addtotail(ch);
					cout<<"\n Want to  enter more?";
					cin>>op;
				}
			}

 			cout<<"\n Enter elements for LIST 3";
	                if(L4.isempty())
			{	op='y';

				while(op=='y' || op=='Y')
				{
					cout<<"\n Enter element to be added=";
					cin>>ch;
					L4.addtotail(ch);
					cout<<"\n Want to  enter more?";
					cin>>op;
				}
			}

			L.deleteele(L3,L4);
			cout<<"\n LIST AFTER DELETION :";
			L.display();
				break;
		default: cout<<"\n Wrong Choice";

		}

		cout<<"\n Do you want to continue?";
		cin>>op;

	}while(op=='Y' || op=='y');
}
