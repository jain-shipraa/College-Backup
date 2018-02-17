//QUESTION 15 EMPLOYEES RECORD

#include<iostream>
#include<fstream>
using namespace std;

struct emp
{
	int eid;
	char nam[25];
	double basic,hra,da,exa;
};

void main()
{

	
	ofstream f;
	f.open("NEW.txt");
	ifstream f1;
	emp e;
	char ch;
	int i=0;

	while(i<5)
	{
		cout<<"\n ENTER EMPLOYEE ID:";
    	cin>>e.eid;
		f<<e.eid;

	    cout<<"\n ENTER NAME";
	    cin>>e.nam;
		f<<"\t"<<e.nam;
	
		cout<<"\n ENTER BASIC:";
	    cin>>e.basic;
		f<<"\t"<<e.basic;

	//let hra=10% of basic and da=70% of basic
 
    	e.hra=0.10*e.basic;
		f<<"\t"<<e.hra;

	    e.da=0.70*e.basic;
		f<<"\t"<<e.da;

		e.exa=0.05*e.basic;
		f<<"\t"<<e.exa;
		f<<"\n";
		i++;
	}

	f.close();
	f1.open("NEW.txt");

     while(f1.get(ch))
	 {
		 cout<<ch;
	 }

	 f1.close();
}
