//THREADED TREE

#include<iostream>
using namespace std;


template<class T>
class Tnode
{
	public:

	T info;
	Tnode *left,*right;
	unsigned int suc:1;
	
	Tnode(T x,Tnode *l=0,Tnode *r=0)
	{
		info=x;
		left=l;
		right=r;
		suc=0;
	}

	Tnode()
	{
		left=right=0;
	}
};

template<class T>
class TTree
{
	Tnode<T> *root;

	public:
		
		TTree()
		{
			root=NULL;
		}

		void insert(T x);
		void inorder();
};

template<class T>
void TTree<T>::insert(T x)
{
	Tnode<T> *p,*prev=0,*newnode;
	newnode=new Tnode<T>(x);

	if(root==0)
	{
		root=newnode;
		return;
	}
	p=root;

	while(p!=0)
	{
		prev=p;
		if(p->info>x)
			p=p->left;
		else if(p->suc==0)
			p=p->right;
		else
			break;
	}

	if(prev->info>x)
	{
		prev->left=newnode;
		newnode->suc=1;
		newnode->right=prev;
	}
	else if(prev->suc==1)
	{
		newnode->suc=1;
		prev->suc=0;
		newnode->right=prev->right;
		prev->right=newnode;
	}
	else
		prev->right=newnode;
}

template<class T>
void TTree<T>::inorder()
{
	Tnode<T>*prev,*p=root;

	if(p!=0)
	{
		while(p->left!=0)
			p=p->left;
		while(p!=0)
		{
			cout<<p->info<<" ";
			prev=p;
			p=p->right;
			if(p!=0 && prev->suc==0)
				while(p->left!=0)
					p=p->left;
		}
	}
	else
		cout<<"\n The Tree is empty";
}

void main()
{
	TTree<int> T;
	int op,x;
	char ch;


	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INSERT";
		cout<<"\n 2. INORDER TRAVERSAL";
		cout<<"\n Enter your choice";
		cin>>op;

		switch(op)
		{
		case 1:cout<<"\n Enter a number to be inserted:";	
			   ch='y';

			   while(ch=='y' || ch=='Y')
			   {
				   cin>>x;
				   T.insert(x);
				   cout<<"\n Enter more?";
				   cin>>ch;
			   }

			   break;
		case 2:cout<<"\n Inorder Traversal";
			   T.inorder();
			   break;

		}

		cout<<"\n Do you want to continue?";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}









