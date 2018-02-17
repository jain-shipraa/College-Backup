//FIBONACCI SERIES


#include <iostream>
using namespace std;

int main()
{
	int n1=0,n2=1,n3=0,n;

	cout << " \n Enter the last no of series : " ;
	cin >> n ;

	cout << " \n Series " << endl;


	cout << n1 << " \t " <<n2;
	while ( n3 < n ){

		n3=n1+n2;
		n1=n2;
		n2=n3;

		if(n3<n)
			cout<<"\t"<<n3;
	}

	cout<<endl;

}
