 //QUESTION 45 PAGE 222
#include<iostream>
using namespace std;

void main()
{
	int num1;

	cout<<"\n Enter any number =";
    cin>>num1;

	switch(num1)
	{
	case 2:
	case 3:num1=num1*99;
		   break;
    case 9: cout<<"\n Enter the value again=";
		    cin>>num1;
			break;
	case 10:num1*=num1;
            break;
	default:cout<<"\n Invalid value reeceived=";
    }

	cout<<"\n Result="<<num1<<endl;

}
