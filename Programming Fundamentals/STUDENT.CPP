//CREATE A STRUCTURE STUDENT
#include<iostream>
#include<fstream>
using namespace std;

struct student
{

int rno,cls;
char nam[25];
int yr;
double total;
};

void main()
{
	ofstream f;
	f.open("STUDENT.txt");
	ifstream f1;
	student s;
	int i=0;
	char ch;

	while(i<10)
	{
		cout<<"\n ENTER ROLL NO=";
		cin>>s.rno;
		f<<s.rno<<"\t";

		cout<<"\n ENTER NAME=";
		cin>>s.nam;
		f<<s.nam<<"\t";

		cout<<"\n ENTER CLASS:";
		cin>>s.cls;
		f<<s.cls<<"\t";

		cout<<"\n ENTER YEAR:";
		cin>>s.yr;
		f<<s.yr<<"\t";

		cout<<"\n ENTER TOTAL:";
		cin>>s.total;
		f<<s.total;
		f<<"\n";

		i++;
	}

	f.close();
	f1.open("STUDENT.txt");

	while(f1.get(ch))
	{
		cout<<ch;//question 29
	}

	f1.close();
}


