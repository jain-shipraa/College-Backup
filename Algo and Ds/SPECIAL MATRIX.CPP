//SPECIAL MATRIX-DIAGONAL, TRIDIAGONAL, LOWER MATRIX

#include<iostream>
using namespace std;

template<class T>
class diag
{
	T *a;
	int size;

	public:

		diag(int k)
		{
			a=new T[k];
			size=k;
		}

		void store(int i, int j, T x);
		T retrieve(int i, int j);
};


template<class T> 
void diag<T>::store(int i, int j, T x)
{
	if(i<1 || i>size || j<1 || j>size)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}

	if(i==j)
		a[i-1]=x;
	else if(x!=0)
		cout<<"\n It must be zero ";
}

template<class T>
T diag<T>::retrieve(int i, int j)
{
	if(i<1 || j<1 || i>size || j>size)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}
	if(i==j)
		return a[i-1];
	else
		return 0;
}

//TRIDIAGONAL MATRIX

template<class T>
class tridiag
{
	T *a;
	int size;

	public:

		tridiag(int k)
		{
			a=new T[(3*k)-2];
			size=k;
		}

		void store(int i, int j, T x);
		T retrieve(int i, int j);
};

template<class T> 
void tridiag<T>::store(int i, int j, T x)
{
	if(i<1 || i>size || j<1 || j>size)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}

	switch(i-j)
	{
		//diagonalwise

	case 1: a[i-2]=x;
		    break;
	case 0:a[size+i-2]=x;
		    break;
	case -1:a[2*size+i-2]=x;
		    break;
	default: if(x!=0)
				 cout<<"\n It should be zero";
		     break;
	}
}
	
template<class T>
T tridiag<T>::retrieve(int i, int j)
{
	if(i<1 || j<1 || i>size || j>size)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}
	
	switch(i-j)
	{
		//diagonalwise
	case 1: return(a[i-2]);
	case 0: return(a[size+i-2]);
	case -1:return(a[2*size+i-2]);
	default: return(0);
	}
}

//LOWER TRIANGLE

template<class T>
class lower
{
	T *a;
	int size;

	public:

		lower(int k)
		{
			a=new T[(k*(k+1))/2];
			size=k;
		}

		void store(int i, int j, T x);
		T retrieve(int i, int j);
};


template<class T> 
void lower<T>::store(int i, int j, T x)
{
	if(i<1 || i>size || j<1 || j>size)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}

	if(i>=j)
		a[i*(i-1)/2+(j-1)]=x;
	else if(x!=0)
		cout<<"\n It must be zero ";
}

template<class T>
T lower<T>::retrieve(int i, int j)
{
	if(i<1 || j<1 || i>size || j>size)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}
	if(i>=j)
		return a[i*(i-1)/2+(j-1)];
	else
		return 0;
}

template<class T>
class upper
{
	T *a;
	int size;

	public:

		upper(int k)
		{
			a=new T[(k*(k+1))/2];
			size=k;
		}

		void store(int i, int j, T x);
		T retrieve(int i, int j);
};


template<class T> 
void upper<T>::store(int i, int j, T x)
{
	if(i<1 || i>size || j<1 || j>size)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}

	if(j>=i)
		a[j*(j-1)/2+(i-1)]=x;
	else if(x!=0)
		cout<<"\n It must be zero ";
}

template<class T>
T upper<T>::retrieve(int i, int j)
{
	if(i<1 || j<1 || i>size || j>size)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}
	if(j>=i)
		return a[j*(j-1)/2+(i-1)];
	else
		return 0;
}

//SYMMETRY CLASS
template<class T>
class symmetry
{
	T *a;
	int size;

	public:

		symmetry(int k)
		{
			a=new T[(k*(k+1))/2];
			size=k;
		}

		void store(int i, int j, T x);
		T retrieve(int i, int j);
};


template<class T> 
void symmetry<T>::store(int i, int j, T x)
{
	if(i<1 || i>size || j<1 || j>size)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}

	if(j>=i)
		a[j*(j-1)/2+(i-1)]=x;
}

template<class T>
T symmetry<T>::retrieve(int i, int j)
{
	if(i<1 || j<1 || i>size || j>size)
	{
		cout<<"\n Invalid Index";
		exit(1);
	}
	if(j>=i)
		return a[j*(j-1)/2+(i-1)];
	else
		return a[i*(i-1)/2+(j-1)];
}


//VOID MAIN

void main()
{
	int s;
	cout<<"\n Enter size of your matrix =";
	cin>>s;
	diag<int> D(s);
	tridiag<int> T(s);
	lower<int> L(s);
	upper<int> U(s);
	symmetry<int> S(s);

	int i,j,op,x;
	char ch;

	do
	{
		cout<<"\n WHAT TYPE OF MATRIX";
		cout<<"\n 1. DIAGONAL MATRIX";
		cout<<"\n 2. TRIDIAGONAL MATRIX";
		cout<<"\n 3. LOWER DIAGONAL MATRIX";
		cout<<"\n 4. UPPER DIAGONAL MATRIX";
		cout<<"\n 5. SYMMETRY MATRIX";
		cout<<"\n Enter your choice=";
		cin>>op;

		switch(op)
		{
		case 1: cout<<"\n DIAGONAL MATRIX";
			    cout<<"\n 1. STORE ";
				cout<<"\n 2. DISPLAY";
				cout<<"\n Enter your option";
				cin>>op;

				if(op==1)
				{
					cout<<"\n Enter the elements";

					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							cin>>x;
							D.store(i,j,x);
						}
					}
				}
				else if(op==2)
				{
					cout<<"\n MATRIX"<<endl;

					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							x=D.retrieve(i,j);
							cout<<" "<<x;
						}
						cout<<endl;
					}
				}
				else
					cout<<"\n WRONG CHOICE";

				break;
		case 2: cout<<"\n TRIDIAGONAL MATRIX";
			    cout<<"\n 1. STORE ";
				cout<<"\n 2. DISPLAY";
				cout<<"\n Enter your option";
				cin>>op;

				if(op==1)
				{
					cout<<"\n Enter the elements";

					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							cin>>x;
							T.store(i,j,x);
						}
					}
				}
				else if(op==2)
				{
					cout<<"\n MATRIX"<<endl;

					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							x=T.retrieve(i,j);
							cout<<" "<<x;
						}
						cout<<endl;
					}
				}
				else
					cout<<"\n WRONG CHOICE";

				break;
		case 3: cout<<"\n LOWER MATRIX";
			    cout<<"\n 1. STORE ";
				cout<<"\n 2. DISPLAY";
				cout<<"\n Enter your option";
				cin>>op;

				if(op==1)
				{
					cout<<"\n Enter the elements";

					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							cin>>x;
							L.store(i,j,x);
						}
					}
				}
				else if(op==2)
				{
					cout<<"\n MATRIX"<<endl;

					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							x=L.retrieve(i,j);
							cout<<" "<<x;
						}
						cout<<endl;
					}
				}
				else
					cout<<"\n WRONG CHOICE";

				break;
		case 4: cout<<"\n UPPER MATRIX";
			    cout<<"\n 1. STORE ";
				cout<<"\n 2. DISPLAY";
				cout<<"\n Enter your option";
				cin>>op;

				if(op==1)
				{
					cout<<"\n Enter the elements";

					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							cin>>x;
							U.store(i,j,x);
						}
					}
				}
				else if(op==2)
				{
					cout<<"\n MATRIX"<<endl;

					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							x=U.retrieve(i,j);
							cout<<" "<<x;
						}
						cout<<endl;
					}
				}
				else
					cout<<"\n WRONG CHOICE";

				break;
		case 5: cout<<"\n SYMMETRY MATRIX";
			    cout<<"\n 1. STORE ";
				cout<<"\n 2. DISPLAY";
				cout<<"\n Enter your option";
				cin>>op;

				if(op==1)
				{
					cout<<"\n Enter the elements";

					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							cin>>x;
							S.store(i,j,x);
						}
					}
				}
				else if(op==2)
				{
					cout<<"\n MATRIX"<<endl;

					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							x=S.retrieve(i,j);
							cout<<" "<<x;
						}
						cout<<endl;
					}
				}
				else
					cout<<"\n WRONG CHOICE";

				break;
		default: cout<<"\n WRONG CHOICE";
			}

			cout<<"\n Do you want to continue?";
			cin>>ch;
		}
		while(ch=='y' || ch=='Y');
}

			    




















