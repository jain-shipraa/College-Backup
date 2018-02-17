//QUESTION 15 EMPLOYEES RECORD

#include<iostream>
using namespace std;

struct emp
{
	int eid;
	char nam[25];
	double basic,hra,da,exa;
	double sal;
};

void main()
{
	emp e[5];
	int i=0,id;

	while(i<1)
	{
		cout<<"\n ENTER EMPLOYEE ID:";
    	cin>>e[i].eid;
	    cout<<"\n ENTER NAME";
	    cin>>e[i].nam;
		cout<<"\n ENTER BASIC:";
	    cin>>e[i].basic;

	//let hra=10% of basic and da=70% of basic 
    	e[i].hra=0.10*e[i].basic;
	    e[i].da=0.70*e[i].basic;
		e[i].exa=0.05*e[i].basic;
		e[i].sal=e[i].basic+e[i].hra+e[i].da+e[i].exa;

		i++;
	}

	cout<<"\n PAYSLIP.....";
	cout<<"\n Enter id of the Employee whose payslip u want to see=";
	cin>>id;

	for(i=0;i<5;i++)
	{
		if(id==e[i].eid)
		{
			cout<<"\n PAYSLIP....."<<endl;
	        cout<<"\n EID....."<<e[i].eid;
			cout<<"\t NAME...."<<e[i].nam<<endl;
			cout<<"\n SALARY:-";
			cout<<"\n BASIC:"<<e[i].basic;
			cout<<"\n HRA..:"<<e[i].hra;
			cout<<"\n DA...:"<<e[i].da;
			cout<<"\n EXA..:"<<e[i].exa;
			cout<<"\n------------------------------";
			cout<<"\n TOTAL SALARY="<<e[i].sal;
			cout<<"\n------------------------------";
		}
	}
}

