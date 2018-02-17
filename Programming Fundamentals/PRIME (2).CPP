//PRIME NO. fom 1 to 100

#include<iostream.h>

void main()
{
	int j=2,num,flag=0;

	cout<<"\n prime no:";

    while(j<=100)
	{
		num=j;
        
		int i=2;

		while(i<=(num/2))
		{

			if((num%i)==0)
			{
				flag=1;
			}
			i++;
			
		}
                if(flag==1)
	
				{
					flag=0;
				}
	          	else 
				{
		    	 cout<<"\t"<<j;
		       
				}
				
		
	j++;
		 
	}
	cout<<endl;


}