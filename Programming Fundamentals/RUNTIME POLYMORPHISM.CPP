//RUN TIME POLYMORPHISM

#include<iostream>
#include<new>
using namespace std;

class person
{
protected:
	char nam[25];
	int age;
	char add[125];
	long cont;

public:

	virtual void getinput()
	{
		cout<<"\n Enter Name=";
		cin>>nam;
		cout<<"\n Enter age=";
		cin>>age;
		cout<<"\n Enter Address=";
		cin>>add;
		cout<<"\n Enter Contact=";
		cin>>cont;
	}

	virtual void display()
	{
		cout<<"\n Details:";
		cout<<"\n Name="<<nam;
		cout<<"\n Age="<<age;
		cout<<"\n Address="<<add;
		cout<<"\n Contact="<<cont;
	}

	person()
	{
		age=cont=0;
	}

	~person()
	{
	}


};

class teacher:public person
{
	int id;
	char qual[25];
	double salary;
	char courses[125];

public:
	void getinput()
	{
		person::getinput();
		cout<<"\n Enter Id=";
		cin>>id;
		cout<<"\n Enter Qualification=";
		cin>>qual;
		cout<<"\n Enter salary=";
		cin>>salary;
		cout<<"\n Courses=";
		cin>>courses;
	}

	void display()
	{
		person::display();
		cout<<"\n Id="<<id;
		cout<<"\n Qualification="<<qual;
		cout<<"\n Salary="<<salary;
		cout<<"\n Courses="<<courses;
	}

	teacher()
	{
		id=salary=0;
	}

	~teacher()
	{
	}

};

class student:public person
{
	int rno;
	int cls;
	float marks;

public:

	void getinput()
	{
		person::getinput();
		cout<<"\n Enter roll number=";
		cin>>rno;
		cout<<"\n Enter class=";
		cin>>cls;
		cout<<"\n Enter Marks=";
		cin>>marks;
	}

	void display()
	{
		person::display();
		cout<<"\n Roll No="<<rno;
		cout<<"\n Class="<<cls;
		cout<<"\n Marks="<<marks;
	}

	student()
	{
		rno=cls=marks=0;
	}

	~student()
	{
	}
};

void main()
{
	person *bp,*bp1;
	teacher *t1;
	t1=new teacher();
	student *s1;
	s1=new student();
	int ch;
	char op;

	do
	{
		cout<<"\n Menu";
		cout<<"\n 1. Create object";
		cout<<"\n 2. Display Objects";
		cout<<"\n 3. Delete Objects";
		cout<<"\n Enter your choice=";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"\n Whose object do you want to create";
			   cout<<"\n 1. Class Teacher";
			   cout<<"\n 2. Class Student";
			   cin>>ch;

			   if(ch==1)
			   {
				   
				   bp=t1;
				   bp->getinput();
			   }
			   else if(ch==2)
			   {
				   
				   bp1=s1;
				   bp1->getinput();
			   }
			   else
				   cout<<"\n Wrong Choice";
			   break;
		case 2:cout<<"\n Which object do you want to display=";
			   cout<<"\n 1. Class Teacher";
			   cout<<"\n 2. Class Student";
			   cin>>ch;

			   if(ch==1)
			   {
				   bp->display();
			   }
			   else if(ch==2)
			   {
				   bp1->display();
			   }
			   else 
				   cout<<"\n Wrong Choice";
			   break;
		case 3:cout<<"\n Delete which object?";
			   cout<<"\n 1. Class Teacher";
			   cout<<"\n 2. Class Student";
			   cin>>ch;

			   if(ch==1)
			   {
				   delete t1;
				   t1=NULL;
			   }
			   else if(ch==2)
			   {
				   delete s1;
				   s1=NULL;
			   }
			   else 
				   cout<<"\n Wrong choice";
			   break;
		default:cout<<"\n Wrong Choice";
		}

		cout<<"\n Do you want to continue?";
		cin>>op;
	}
	while(op=='y'|| op=='Y');
}




