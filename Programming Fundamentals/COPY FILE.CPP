//COPYING TEXT FILE


#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	ifstream f1;
	ofstream f2;
	char ch;

	f1.open("D:\\2014315_DEEPTI\\P10\\P2\\STUDENT.txt");
	f2.open("COPY.txt");

	while(f1.get(ch))
	{
		if(!(ch=='\t'||ch=='\n'||ch==' ' ))
			f2<<ch;
	}

	f1.close();
	f2.close();
}





	
