//PIGLATIN PROGRAMMING

#include<iostream>
#include<string>
using namespace std;
 
void main()
{

	string o1;

	cout<<"\n Enter a string:";
	getline(cin,o1);
	
    int 	end;
	string temp,str2;
	string delimiters=" ";

	int start=o1.find_first_not_of(delimiters);
	while(start!= -1)
	{
		end=o1.find_first_of(delimiters,start+1);
		temp=o1.substr(start,end-start );
        str2=str2+temp.substr(1)+temp.at(0)+"ay ";
	    start=o1.find_first_not_of(delimiters,end+1);
	}

	
	cout<<str2;
}
