//REVERSE A STRING

#include<iostream>
using namespace std;

class rev
{
public:

void reverse()
{
	char ch;
	cin.get(ch);
	if(ch!='\n')
	{
		reverse();
		cout<<ch;
	}
}
};

void main()
{
	rev R;
	cout<<"\n Enter string";
	R.reverse();
	cout<<endl;
}
