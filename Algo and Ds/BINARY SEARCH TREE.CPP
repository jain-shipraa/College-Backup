//BINARY SEARCH TREE IMPLEMENTATION 

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

//STACK CLASS
 
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
		cout<<temp->info;
		temp=temp->next;
	}
}
	// QUEUE  CLASS
template<class T>
class queue
{
	

	public:
		node<T> *front,*rear;

		queue()
		{
			front=rear=NULL;
		}

		void enqueue(T);
		T dequeue();
		void display();
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
		cout<<temp->info;
		temp=temp->next;
	}
}

//BST NODE CLASS 

template<class T>
class BSTnode
{
	public:
		T info;
		BSTnode *left,*right;
		int level;

		BSTnode(T x, BSTnode *l=0,BSTnode *r=0)
		{
			level=0;
			info=x;
			left=l;
			right=r;
		}
};

//TREE CLASS 

template<class T>
class Tree
{
		BSTnode<T> *root;
	    int h;

		public:

			Tree()
			{
				root=NULL;
				h=0;
			}

			int isempty()
			{
				if(root==NULL)
					return 1;
				else 
					return 0;
			}

			void insertion(T x);
			int search(T x);
        
			void preorder();
			void postorder();
			void inorder();
			void preorder(BSTnode<T>*);
			void postorder(BSTnode<T>*);
			void inorder(BSTnode<T>*);
			void iterativepreorder();
			void iterativepostorder();
			void iterativeinorder();
			void Breadthfirst();
			
	        void findanddeletebymerge(T x);
		    void findanddeletebycopy(T x);
			void deletebymerge(BSTnode<T>*&);
		    void deletebycopy(BSTnode<T>*&);
			
			void count();
			void determineh();
			Tree<T> mirror();
			void insert_mir(T x);
};

template<class T>
void Tree<T>::insertion(T x)
{
	BSTnode<T> *temp=new BSTnode<T>(x);
	BSTnode<T> *p,*prev;
	prev=NULL;
	p=root;

	while(p!=NULL)
	{
		prev=p;
		if(p->info>x)
			p=p->left;
		else
			p=p->right;
	}

	if(prev==0)
		root=temp;
	else if(prev->info>x)
	{
		temp->level=prev->level+1;
		prev->left=temp;
	}
	else
	{
		temp->level=prev->level+1;
		prev->right=temp;
	}
}

template<class T>
int Tree<T>::search(T x)
{
	BSTnode<T> *p;
	p=root;

	while(p!=NULL)
	{
		if (p->info==x)
			return 1;
		else if(p->info>x)
			p=p->left;
		else
			p=p->right;
	}
	return 0;
}

template<class T>
void Tree<T>::Breadthfirst()
{
	queue<BSTnode<T>*> Q;
	BSTnode<T> *p=root;

	Q.enqueue(p);
	
	while(!Q.isempty())
	{
		p=Q.dequeue();
		cout<<p->info<<" ";
		if(p->left!=0)
			Q.enqueue(p->left);
		if(p->right!=0)
			Q.enqueue(p->right);
	}
}

template<class T>
void Tree<T>::preorder()
{
	preorder(root);
}

template<class T>
void Tree<T>::preorder(BSTnode<T>* p)
{
	if(p!=0)
	{
		cout<<p->info<<"  ";
		preorder(p->left);
		preorder(p->right);
	}
}


template<class T>
void Tree<T>::postorder()
{
	postorder(root);
}

template<class T>
void Tree<T>::postorder(BSTnode<T>* p)
{
	if(p!=0)
	{
		postorder(p->left);
		postorder(p->right);
	    cout<<p->info<<"  ";
	}
}


template<class T>
void Tree<T>::inorder()
{
	inorder(root);
}

template<class T>
void Tree<T>::inorder(BSTnode<T>* p)
{
	if(p!=0)
	{
		inorder(p->left);
		cout<<p->info<<"  ";
		inorder(p->right);
	}
}

template<class T>
void Tree<T>::iterativepreorder()
{
	stack<BSTnode<T>*> S1;
	BSTnode<T> *p,*V;
	p=root;

	if(p!=NULL)
	{
		S1.push(p);
		while(!S1.isempty())
		{
			V=S1.pop();
			cout<<V->info<<"  ";
			if(V->right!=0)
				S1.push(V->right);
			if(V->left!=0)
				S1.push(V->left);
		}
	}
}

template<class T>
void Tree<T>::iterativeinorder()
{

	stack<BSTnode<T>*> S1;
	BSTnode<T> *p;
	p=root;
	
	while(p!=NULL)
	{
		while(p!=0)
		{
			if(p->right)
		       S1.push(p->right);
			S1.push(p);
			p=p->left;
		}

		p=S1.pop();

		while(!S1.isempty() && p->right==0)
		{
			cout<<p->info<<"  ";
			p=S1.pop();

		}

		cout<<p->info;

		if(!S1.isempty())
			p=S1.pop();
		else 
			p=0;

	}

}


template<class T>
void Tree<T>::iterativepostorder()
{
	
	stack<BSTnode<T>*> S1;
	BSTnode<T> *p,*q;
	p=q=root;
	
	while(p!=NULL)
	{
		for(;p->left!=0;p=p->left)
			S1.push(p);
		while(p!=0 && (p->right==0 || p->right==q))
		{
			cout<<p->info<<"  ";
			q=p;
			if(S1.isempty())
				return;
			p=S1.pop();
		}
		S1.push(p);
		p=p->right;
	}
}

template<class T>
void Tree<T>::findanddeletebymerge(T x)
{
	BSTnode<T> *p,*prev;
	p=root;

	while(p!=NULL)
	{
		if(p->info==x)
			break;
		prev=p;
		if(p->info<x)
			p=p->right;
		else
			p=p->left;
	}


	if(p!=0 && p->info==x)
	{
		if(p==root)
			deletebymerge(root);
		else if(prev->left==p)
			deletebymerge(prev->left);
		else
			deletebymerge(prev->right);
	}
	else if(root!=0)
		cout<<"\n "<<x<<" is not element in the tree";
	else
		cout<<"\n The tree is empty";
}

template<class T> 
void Tree<T>::deletebymerge(BSTnode<T>*& p)
{
	BSTnode<T> *tmp=p;
	if(p!=0)
	{
		if(p->right==0)
			p=p->left;
		else if(p->left==0)
			p=p->right;
		else
		{
			tmp=p->left;
			while(tmp->right!=0)
				tmp=tmp->right;

			tmp->right=p->right;
			tmp=p;
			p=p->left;
		}
		delete tmp;
	}
}

template<class T>
void Tree<T>::findanddeletebycopy(T x)
{
	BSTnode<T> *p,*prev;
	p=root;

	while(p!=NULL)
	{
		if(p->info==x)
			break;
		prev=p;
		if(p->info<x)
			p=p->right;
		else
			p=p->left;
	}


	if(p!=0 && p->info==x)
	{
		if(p==root)
			deletebycopy(root);
		else if(prev->left==p)
			deletebycopy(prev->left);
		else
			deletebycopy(prev->right);
	}
	else if(root!=0)
		cout<<"\n "<<x<<" is not element in the tree";
	else
		cout<<"\n The tree is empty";
}

template<class T>
void Tree<T>::deletebycopy(BSTnode<T>*& p)
{
	BSTnode<T> *prev,*tmp;
	tmp=p;

	if(p->right==0)
		p=p->left;
	else if(p->left==0)
		p=p->right;
	else
	{
		tmp=p->left;
		prev=p;

		while(tmp->right!=0)
		{
			prev=tmp;
			tmp=tmp->right;
		}

		p->info=tmp->info;

		if(prev==p)
			prev->left=tmp->left;
		else
			prev->right=tmp->left;
	}
	delete tmp;
}


template<class T>
void Tree<T>::count()
{
	int l=0, nl=0;
	queue<BSTnode<T>* > Q1;
	BSTnode<T>*p=root;

	if(p!=0)
	{
		Q1.enqueue(root);
		while(!Q1.isempty())
		{
			p=Q1.dequeue();
			if(p->right!=0 || p->left!=0)
				nl++;
			else
				l++;

			if(p->left!=0)
				Q1.enqueue(p->left);
			if(p->right!=0)
				Q1.enqueue(p->right);
		}
	}

	cout<<"\n LEAF:"<<l;
	cout<<"\n NON LEAF:"<<nl;
}

template<class T>
void Tree<T>::determineh()
{
	queue<BSTnode<T>* > Q1;
	BSTnode<T>*p=root;

	if(p!=0)
	{
		Q1.enqueue(root);
		while(!Q1.isempty())
		{
			p=Q1.dequeue();
			if(p->level>h)
				h=p->level;

			if(p->left!=0)
				Q1.enqueue(p->left);
			if(p->right!=0)
				Q1.enqueue(p->right);
		}
	}

	h++;
	cout<<"\n HEIGHT OF THE TREE:"<<h;
}

template<class T>
Tree<T> Tree<T>::mirror()
{
	Tree<T> tmp;
	queue<BSTnode<T>* > Q1;
	BSTnode<T>*p=root;

	if(p!=0)
	{
		Q1.enqueue(root);
		while(!Q1.isempty())
		{
			p=Q1.dequeue();
			tmp.insert_mir(p->info);

			if(p->left!=0)
				Q1.enqueue(p->left);
			if(p->right!=0)
				Q1.enqueue(p->right);
		}
	}

	return(tmp);
}

template<class T>
void Tree<T>::insert_mir(T x)
{
	BSTnode<T> *temp=new BSTnode<T>(x);
	BSTnode<T> *p,*prev;
	prev=NULL;
	p=root;

	while(p!=NULL)
	{
		prev=p;
		if(p->info<x)
			p=p->left;
		else
			p=p->right;
	}

	if(prev==0)
		root=temp;
	else if(prev->info<x)
	{
		temp->level=prev->level+1;
		prev->left=temp;
	}
	else
	{
		temp->level=prev->level+1;
		prev->right=temp;
	}
}

void main()
{
	Tree<int> T1,T2;
	int x,op,res;
	char ch='y';

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INSERTION ";
		cout<<"\n 2. SEARCH";
		cout<<"\n 3. DELETION:";
		cout<<"\n 4. TRAVERSAL";
		cout<<"\n 5. LEAF-NON LEAF COUNT";
		cout<<"\n 6. DISPLAY HEIGHT";
		cout<<"\n 7. MIRROR";
		cout<<"\n Enter your choice:";
		cin>>op;

		switch(op)
		{
		case 1:cout<<"\n INSERTION";
			   cout<<"\n Enter values to be inserted into the tree=";

          	    while(ch=='y')
				{
	    			cin>>x;
	    		    T1.insertion(x);
	    	        cout<<"\n Enter more?";
	    	        cin>>ch;
				}
 
    			  break;
		case 2: cout<<"\n SEARCH AN ELEMENT ";
			    cout<<"\n Enter values to be searched into the tree=";
				cin>>x;
				if(!T1.isempty())
				{
					res= T1.search(x);
					
					if(res==1)
						cout<<"\n Elemnt found ";
					else
						cout<<"\n Elemnt not found";
				}
				else
					cout<<"\n The Tree is empty";
				break;
		case 3:cout<<"\n DELETION";
			   cout<<"\n 1. DELETION BY COPYING ";
			   cout<<"\n 2. DELETION BY MERGING ";
			   cout<<"\n Enter option";
			   cin>>op;

			   if(!T1.isempty())
			   {
				   cout<<"\n Enter an element to be deleted ";
				   cin>>x;

				   if(op==1)
				   {
					   T1.findanddeletebycopy(x);
					   cout<<"\n After deletion";
					   T1.Breadthfirst();
				   }
				   else
				   {
					   T1.findanddeletebymerge(x);
					   cout<<"\n After deletion";
					   T1.Breadthfirst();
				   }
			   }
			   else
				   cout<<"\n The Tree is empty";
			   break;
		case 4:cout<<"\n TRAVERSAL";
			   cout<<"\n 1. BREADTHFIRST";
			   cout<<"\n 2. PREORDER ";
			   cout<<"\n 3. POSTORDER";
			   cout<<"\n 4. INORDER";
			   cout<<"\n Enter option";
			   cin>>op;

			   if(!T1.isempty())
			   {
				   if(op==1)
				   {
					   T1.Breadthfirst();
				   }
				   else if(op==2)
				   {
					   cout<<"\n Through recursion";
					   T1.preorder();
					   cout<<"\n Through Iteration";
					   T1.iterativepreorder();
				   }
				   else if(op==3)
				   {
                       cout<<"\n Through recursion";
					   T1.postorder();
					   cout<<"\n Through Iteration";
					   T1.iterativepostorder();
				   }
				   else if(op==4)
				   {   
                       cout<<"\n Through recursion";
					   T1.inorder();
					   cout<<"\n Through Iteration";
					   T1.iterativeinorder();
				   }
				   else
					   cout<<"\n Wrong Options";
			   }
			   else
				   cout<<"\n The Tree is empty";
			   break;
		case 5: cout<<"\n LEAF-NON LEAF";
			    if (!T1.isempty())
				{
					T1.count();
				}
				else
					cout<<"\n The Tree is empty";
				break;
		case 6:cout<<"\n DISPLAY HEIGHT";
			   if(!T1.isempty())
			   {
				   T1.determineh();
			   }
			   else
				   cout<<"\n The Tree is empty";
			   break;
		case 7:cout<<"\n MIRROR IMAGE";
			   if(!T1.isempty())
			   {
				   T2=T1.mirror();
				   T2.Breadthfirst();
			   }
			    else
					cout<<"\n Worng Choice";
				break;

		}

		cout<<"\n Do you want to continue";
		cin>>ch;
		}
		while(ch=='y' || ch=='Y');
}


