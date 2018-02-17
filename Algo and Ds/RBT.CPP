//IMPLEMENTING RBT : INSER DELETE ANS SEARCH A NODE

#include<iostream>
using namespace std;

class node
{

public:

	int info;
	node *left,*right,*p;
	char color;
    node(int key)
	{ 
		info=key;
		left=right=p=NULL;
	}
};

class RBT
{
	node *NIL,*root;

public: 
	RBT()
	{ 
		NIL=new node(0);
		NIL->left=NIL;
		NIL->right=NIL;
		NIL->p=NIL;
		root=NIL;
	}

	void left_rotate(node*);
	void right_rotate(node*);
	void insert();
	void insert(int);
	void insert_fixup(node *z);
	void inorder();
	void inorder(node *n);
	void transplant(node *u,node *v);
	node* search(int k);
	void search();
	node* minimum(node* n);
	void deletenode();
    void deletenode(int k);
	void delete_fixup(node* x);
};

void RBT::left_rotate(node *x)
{ 
	node *y=new node(0);
	y=x->right;
	x->right=y->left;

	if(y->left!=NIL)
		y->left->p=x;
	
	y->p=x->p;
	if(x->p==NIL)
		root=y;
	else if(x==x->p->left)
		 x->p->left=y;
	else
		x->p->right=y;
	
	y->left=x;
	x->p=y;
}

void RBT::right_rotate(node *x)
{ 
	node *y=new node(0);
	y=x->left;
	x->left=y->right;

	if(y->right!=NIL)
		y->right->p=x;
	
	y->p=x->p;
	if(x->p==NIL)
		root=y;
	else if(x==x->p->right)
		x->p->right=y;
	else
		x->p->left=y;
	
	y->right=x;
	x->p=y;
}

void RBT::insert()
{
	int i,n,k;

	cout<<"\nEnter no. of elements you want to add:";
	cin>>n;
	cout<<"\nEnter elements:";
	
	for(i=0;i<n;i++)
	{
		cin>>k;
		insert(k);
	}

}

void RBT::insert(int k)
{ 
	node *z=new node(k);
	node *y=0,*x=0;
	
	y=NIL;
	x=root;
		
	while(x!=NIL)
	{
		y=x;
		if(z->info<x->info)
			x=x->left;
		else
			x=x->right;
	}
	
	z->p=y;
	
	if(y==NIL)
		root=z;
	else if(z->info<y->info)
		y->left=z;
	else
		y->right=z;
	
	z->left=NIL;
	z->right=NIL;
	z->color='R';
	insert_fixup(z);
}

void RBT::insert_fixup(node *z)
{ 
	node *y=0;
	while(z->p->color=='R')
	{ 
		if(z->p==z->p->p->left)
		{ 
			y=z->p->p->right;
			if(y->color=='R')
			{ 
				z->p->color='B';
			    y->color='B';
				z->p->p->color='R';
				z=z->p->p;
			 }
			 else if(z==z->p->right)
			 {
				 z=z->p;
				 left_rotate(z);
				 z->p->color='B';
				 z->p->p->color='R';
				 right_rotate(z->p->p);
			 }
			 else
			 {
				 z->p->color='B';
			     z->p->p->color='R';
				 right_rotate(z->p->p);
			  }
		}
		else
		{ 
			y=z->p->p->left;
			if(y->color=='R')
			{
				z->p->color='B';
			    y->color='B';
				z->p->p->color='R';
				z=z->p->p;
			}
			else if(z==z->p->left)
			{
				z=z->p;
			    right_rotate(z);
				z->p->color='B';
				z->p->p->color='R';
				left_rotate(z->p->p);
			}
			else
			{
				z->p->color='B';
				z->p->p->color='R';
				left_rotate(z->p->p);
			 }
		}
	}
    root->color='B';
}

void RBT::inorder()
{ 
	inorder(root);
}

void RBT::inorder(node *n)
{
	if(n!=NIL)
	{ 
		inorder(n->left);
		cout<<n->info<<":"<<n->color<<" ";
		inorder(n->right);
	}
}
        
void RBT::transplant(node *u,node *v)
{ 
	if(u->p==NIL)
	    root=v;
	else if(u==u->p->left)
		u->p->left=v;
	else
		u->p->right=v;
	
	v->p=u->p;
}

void RBT::search()
{
	int k;
	node *temp;

	cout<<"\n Enter the value to be searched:";
	cin>>k;

	temp=search(k);

	if(temp!=NIL)
	{
		cout<<"Node exists";
		cout<<temp->info<<":"<<temp->color;
	}
	else if(root==NIL)
		cout<<"\nTree is empty";
	else
		cout<<"\nNode does not exist"; 
}

node* RBT::search(int k)
{ 
	node *x=root;
	while(x!=NIL)		 
	{ 
		if(x->info==k)		      
			break;		   
		else if(x->info>k)	
			x=x->left;			
		else			
			x=x->right;		
	}
	
	if(x!=NIL)
		return(x); 
	else
		return(NIL);
}

node* RBT::minimum(node* n)
{
	while(n->left!=NIL)
		n=n->left;

    return n;
}

void RBT::deletenode()
{
	int k;
    cout<<"\n Enter the value you want to delete :";
	cin>>k;
	deletenode(k);
}

void RBT::delete_fixup(node* x)
{
	node* w=NIL;
	
	while(x->color=='B' && x!=root)
	{
		if(x==x->p->left)
		{
			w=x->p->right;
			
			if(w->color=='R')
			{
				w->color='B';
				x->p->color='R';
				left_rotate(x->p);
				w=x->p->right;
			}
			if(w->left->color=='B' && w->right->color=='B')
			{
				w->color='R';
				x=x->p;
			}
			else if(w->right->color=='B')
			{
				w->color='R';
				w->left->color='B';
				right_rotate(w);
				w=x->p->right;
				w->color=x->p->color;
				x->p->color='B';
				w->right->color='B';
				left_rotate(x->p);
				x=root;
			}
			else
			{
			    w->color=x->p->color;
				x->p->color='B';
				w->right->color='B';
				left_rotate(x->p);
				x=root;
			}
		}
		else
		{
			w=x->p->left;
			
			
			if(w->color=='R')
			{
				w->color='B';
				x->p->color='R';
				right_rotate(x->p);
				w=x->p->left;
			}
			if(w->left->color=='B' && w->right->color=='B')
			{
				w->color='R';
				x=x->p;
			}
			else if(w->left->color=='B')
			{
				w->color='R';
				w->right->color='B';
				left_rotate(w);
				w=x->p->left;
				w->color=x->p->color;
				x->p->color='B';
				w->left->color='B';
				right_rotate(x->p);
				x=root;
			}
			else
			{
				w->color=x->p->color;
				x->p->color='B';
				w->left->color='B';
				right_rotate(x->p);
				x=root;
			}
		}

	}
	x->color='B';
}

void RBT::deletenode(int k)
{ 
	node *z=search(k);
	node *y,*x;
	y=z;
	char yoc;
	yoc=y->color;
	
	if(z->left==NIL)
	{
		x=z->right;
		transplant(z,z->right);
	}
	else if(z->right==NIL)
	{
		x=z->left;
		transplant(z,z->left);
	}
	else
	{
		y=minimum(z->right);
		x=y->right;
		yoc=y->color;
		
		if(y->p==z)
			x->p=y;
		else
		{
			transplant(y,y->right);
		    y->right=z->right;
			y->right->p=y;
		}
		
		transplant(z,y);
		y->left=z->left;
		y->left->p=y;
		y->color=z->color;
	}
	if(yoc=='B')
		delete_fixup(x);
}

void main()
{
	RBT R;
	int op;
	char ch;

	do
	{
		cout<<"\n MENU:";
		cout<<"\n 1. INSERT";
		cout<<"\n 2. DELETE";
		cout<<"\n 3. DISPLAY:";
		cout<<"\n 4. SEARCH";
		cout<<"\n Enter your choice=";
		cin>>op;

		switch(op)
		{
		case 1: cout<<"\n INSERTION.....";
			    R.insert();
				break;
		case 2: cout<<"\n DELETION......";
			    R.deletenode();
	            R.inorder();
				break;
		case 3: cout<<"\n DISPLAY....";
			    R.inorder();
				break;
		case 4: cout<<"\n SEARCHING.....";
			    R.search();
				break;
		default:cout<<"\n Wrong Choice .....";

		}

		cout<<"\n Do you want to continue?";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');

}