//QUESTIION 39 PG 116
#include<iostream>
#include<iomanip>
using namespace std;


void main()
{
	int tv,vcr,cd,tape,rem;
    const double t_pr=400.00,cd_pr=300.00,vcr_pr=220.00,rem_pr=35.20,tap_pr=150.00,tax=8.25;
    double total,sub_t;

	cout<<"\n How many TVs were sold?";
	cin>>tv;

	cout<<"\n How many VCRs were sold?";
	cin>>vcr;
	
	cout<<"\n How many Remote Controllers were sold?";
	cin>>rem;
	
	cout<<"\n How many CDs were sold?";
	cin>>cd;
	
	cout<<"\n How many Tpe Recorders were sold?";
	cin>>tape;

	cout<<"QTY"<<setw(3)<<"D"<<
    