// SWITCH EXAMPLE

#include<iostream>
using namespace std;

void main()
{
	int score;
	char gr;

	cout<<"\n Enter your score(0-10)=";
	cin>>score;
    
	switch(score)
	{
	case 10:
	case 9: gr='A';
		    break;
	case 8: gr='A';
		    break;
    case 7: gr='B';
		    break;
	case 6: 
    case 5:
    case 4: gr='C';
		    break;
    case 3: 
    case 2: gr='D';
		    break;
    default:cout<<"\n Fail";
	}

	cout<<"\n RESULT="<<"\n SCORE="<<score<<"\n GRADE="<<gr<<endl;

}
