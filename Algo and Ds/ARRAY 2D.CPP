//ARRAY 1D USING CLASSES 

#include<iostream>
using namespace std;

template<class T>
class Array1D 
{
	T* a;
	int size;
	
	public:

		Array1D(const Array1D<T>& O1);
		Array1D(int sz=0);
		~Array1D(){}
		Array1D<T> operator+( Array1D<T> O1);
		Array1D<T> operator-( Array1D<T> O1);
		Array1D<T> operator*( Array1D<T> O1);
		Array1D<T> operator+=( T x);
		Array1D<T> operator=( Array1D<T> O1);
		T& operator[](int i);
		int size1();
		void resize(int i);
};

template<class T>
Array1D<T>::Array1D(int sz)
{
	size=sz;
	a=new T[size];
}

template<class T>
Array1D<T>::Array1D(const Array1D<T>& O1)
{
	size=O1.size;
	a=new T[size];

	for(int i=0;i<size;i++)
		a[i]=O1.a[i];
}

template<class T>
T& Array1D<T>::operator [](int i)
{
	if(i<0||i>size)
	{
		cout<<"\n Invalid";
		exit(1);
	}

	return a[i];
}

template<class T>
Array1D<T> Array1D<T>::operator=(Array1D<T> O1)
{
	if(this!=&O1)
	{
        size=O1.size;
		delete[] a;
		a=new T[size];

		for(int i=0;i<size;i++)
			a[i]=O1.a[i];
	}
	return (*this);
}

template<class T>
Array1D<T> Array1D<T>::operator+(Array1D<T> O1)
{
	Array1D<T> O2(size);

	if(size!=O1.size)
	{
		cout<<"\n Unequal Sizes";
		exit(1);
	}
	else
	{
		for(int i=0;i<size;i++)
			O2.a[i]=a[i]+O1.a[i];
	}

	return O2;
}

template<class T>
Array1D<T> Array1D<T>::operator-( Array1D<T> O1)
{
	Array1D<T> O2(size);

	if(size!=O1.size)
	{
		cout<<"\n Unequal Sizes";
		exit(1);
	}
	else
	{
		for(int i=0;i<size;i++)
			O2.a[i]=a[i]-O1.a[i];
	}

	return O2;
}

template<class T>
Array1D<T> 	Array1D<T>::operator*( Array1D<T> O1)
{
	Array1D<T> O2(size);

	if(size!=O1.size)
	{
		cout<<"\n Unequal Sizes";
		exit(1);
	}
	else
	{
		for(int i=0;i<size;i++)
			O2.a[i]=a[i]*O1.a[i];
	}

	return O2;
}

template<class T>
Array1D<T> Array1D<T>::operator+=( T x)
{
	for(int i=0;i<size;i++)
			a[i]=a[i]+x;

	return (*this);
}

template<class T>
int Array1D<T>::size1()
{
	return size;
}

template<class T>
void Array1D<T>::resize(int i)
{
	size=i;
	delete[] a;
	a=new T[size];
}

//ARRAY 2D CLASS

template<class T>
class Array2D
{
	Array1D<T>* row1;
	int row,col;

	public:

		Array2D(int r=0,int c=0);
		Array2D(const Array2D<T>& M);
		Array1D<T>& operator[](int i);
		Array2D<T>& operator=(Array2D<T>& M);
		Array2D<T> operator+(Array2D<T>& M);
		Array2D<T> operator-(Array2D<T>& M);
		Array2D<T> operator*(Array2D<T>& M);
		int rows();
		int cols();
		void resize(int r,int c);
};

template<class T>
Array2D<T>::Array2D(int r,int c)
{
	row=r;
	col=c;

	row1=new Array1D<T>[row];

	for(int i=0;i<row;i++)
		row1[i].resize(c);
}

template<class T>
Array2D<T>::Array2D(const Array2D<T>& M)
{
	row=M.row;
	col=M.col;
    row1=new Array1D<T>[row];
	for(int i=0;i<row;i++)
		row1[i]=M.row1[i];
}

template<class T>
Array1D<T>& Array2D<T>::operator [](int i)
{
	if(i<0 ||i>row)
		exit(1);

	return row1[i];
}

template<class T>
Array2D<T> Array2D<T>::operator+(Array2D<T>& M)
{
	Array2D<T> O2(row,col);
	
	for(int i=0;i<row;i++)
	{
		
		O2.row1[i]=(row1[i]+M.row1[i]);
	}

	for(i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			cout<<O2.row1[i][j]<<" " ;
		cout<<endl;
	}

		return O2;
}


template<class T>
Array2D<T> Array2D<T>::operator-(Array2D<T>& M)
{
	Array2D<T> O2(row,col);

	for(int i=0;i<row;i++)
		O2.row1[i]=row1[i]-M.row1[i];

	return O2;
}


template<class T>
Array2D<T> Array2D<T>::operator*(Array2D<T>& M)
{
	if(col==M.row)
	{
		Array2D<T> W(row,M.col);

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<M.col;j++)
		{
			W.row1[i][j]=0;
			for(int k=0;k<col;k++)
			{
		     W.row1[i][j]=W.row1[i][j]+row1[i][k]*M.row1[k][j];
			}
		}
	}
	return W;
	}
	else
		exit(1);
}

template<class T>
Array2D<T>& Array2D<T>::operator=(Array2D<T>& M)
{

	if(this!=&M)
	{
		row=M.row;
		col=M.col;
		delete[] row1;

		row1=new Array1D<T>[row];

		for(int i=0;i<row;i++)
			row1[i].resize(col);

		for(i=0;i<row;i++)
			row1[i]=M.row1[i];
	}

	return (*this);
}

template<class T>
int Array2D<T>::rows()
{
	return row;
}

template<class T>
int Array2D<T>::cols()
{
	return col;
}

template<class T>
void Array2D<T>::resize(int r,int c)
{
	row=r;
	col=c;
	delete[] row1;
	row1=new Array1D<T>[row];

	for(int i=0;i<row;i++)
		row1[i].resize(col);
}

//VOID MAIN

void main()
{
	Array2D<int> A1,A2,A3;
	int ch,r,c,x,i,j;
	char op;

	do
	{
		cout<<"\n MENU";
		cout<<"\n 1. ENTER VALUES";
		cout<<"\n 2. ADDITION ";
		cout<<"\n 3. SUBTRACTION";
		cout<<"\n 4. MULTIPLICATION";
		cout<<"\n 5. DISPLAY";
		cout<<"\n ENTER YOUR CHOICE";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"\n ENTER VALUES";	
			   cout<<"\n Enter the rows for your array=";
			   cin>>r;
			   cout<<"\n Enter the cols for your array=";
			   cin>>c;

			   A1.resize(r,c);
			   cout<<"\n Enter values for your array="<<endl;

			   for(i=0;i<A1.rows();i++)
			   {
				   for(j=0;j<A1.cols();j++)
				   {
					   cout<<"["<<i+1<<"]=";
			     	   cin>>A1[i][j];
				   }
			   }

			   break;
		case 2:cout<<"\n ADDITION";
			   cout<<"\n Enter the rows for your array=";
			   cin>>r;
			   cout<<"\n Enter the cols for your array=";
			   cin>>c;

			   A2.resize(r,c);
			   cout<<"\n Enter values for your array="<<endl;

			   for(i=0;i<A2.rows();i++)
			   {
				   for(j=0;j<A2.cols();j++)
				   {
					   cout<<"["<<i+1<<"]=";
			     	   cin>>A2[i][j];
				   }
			   }
			   A3=A1+A2;
			   
			   cout<<"\n ADDITION RESULT"<<endl;

			   for(i=0;i<A3.rows();i++)
			   {
				   for(j=0;j<A3.cols();j++)
				      cout<<"["<<i+1<<"]="<<A3[i][j];
			   }

			   cout<<endl;
			   break;
		case 3:cout<<"\n SUBTRACTION";
			   
			   cout<<"\n Enter values for your array="<<endl;

			   for(i=0;i<A2.rows();i++)
			   {
				   for(j=0;j<A2.cols();j++)
				   {
					   cout<<"["<<i+1<<"]=";
			     	   cin>>A2[i][j];
				   }
			   }

			   
			   A3=A1-A2;
			   cout<<"\n SUBTRACTION RESULT"<<endl;

			   for(i=0;i<A3.rows();i++)
			   {
				   for(j=0;j<A3.cols();j++)
				      cout<<"["<<i+1<<"]="<<A3[i][j];
			   }

			   cout<<endl;
			   break;
		case 4:cout<<"\n MULTIPLICATION";
			   
			   
			   cout<<"\n Enter values for your array="<<endl;

			   for(i=0;i<A2.rows();i++)
			   {
				   for(j=0;j<A2.cols();j++)
				   {
					   cout<<"["<<i+1<<"]=";
			     	   cin>>A2[i][j];
				   }
			   }

			   
			   A3=A1*A2;
			   cout<<"\n MULTIPLICATION RESULT"<<endl;

			   for(i=0;i<A3.rows();i++)
			   {
				   for(j=0;j<A3.cols();j++)
				      cout<<"["<<i+1<<"]="<<A3[i][j];
			   }

			   cout<<endl;
			   break;
		case 5:cout<<"\n DISPLAY";
			   
			    for(i=0;i<A1.rows();i++)
			   {
				   for(j=0;j<A1.cols();j++)
				      cout<<"["<<i+1<<"]="<<A1[i][j];
			   }

			   cout<<endl;
			   break;
		default:cout<<"\n Wrong Choice";
	}

	cout<<"\n Want to continue";
	cin>>op;

	}while(op=='y'||op=='Y');
}