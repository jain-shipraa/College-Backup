//QUESTION 29

#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	ifstream f1;
	ofstream f2;
	char ch;

	f1.open("D:\\2014315_DEEPTI\\P10\\P2\\STUDENT.txt");

	while(!f1.eof())
	{
			f1.get(ch);
			cout<<ch;
	 }


	f1.close();

}

