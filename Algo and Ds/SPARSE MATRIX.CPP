//SPARSE MATRIX

#include<iostream>
using namespace std;

template<class T>
class Term
{
	public:
		int row,col;
		T value;
};

template<class T>
class sparse 
{
	

	public:
		
		int rows, cols;
		int terms;
		Term<T> *a;
		int Maxterms;
		
		sparse(int maxterms=10);
		~sparse();

		friend ostream& operator<<(ostream&, const sparse<T>&);
		friend istream& operator>>(istream&, const sparse<T>&);
};

template<class T>
sparse<T>::sparse(int maxterms)
{
	if(maxterms<1)
	{
		cout<<"\n Bad initializers";
		exit(1);
	}
	Maxterms=maxterms;

	a=new Term<T>[Maxterms];
	terms=rows=cols=0;
}

template<class T>
sparse<T>::~sparse()
{
	delete[] a;
}

template<class T> 
ostream& operator<<(ostream& out, const sparse<T>& x)
{
	out<<"rows="<<x.rows<<" columns="<<x.cols<<endl;
	out<<"nonzero terms="<<x.terms<<endl;

	for(int i=0;i<x.terms;i++)
		out<<"a("<<x.a[i].row<<","<<x.a[i].col<<")="<<x.a[i].value<<endl;

	return out;
}

template<class T>
istream& operator>>(istream& in , sparse<T>& x)
{
	cout<<"\n Enter number of rows , columns and terms="<<endl;
	in>>x.rows>>x.cols>>x.terms;
	for(int i=0;i<x.terms;i++)
	{
		cout<<"\n Enter row , column, and value of the term="<<(i+1)<<endl;
		in>>x.a[i].row>>x.a[i].col>>x.a[i].value;
	}

	return in;
}

void main()
{
	sparse<int> O1(10);
	cin>>O1;
	cout<<O1;
}     

