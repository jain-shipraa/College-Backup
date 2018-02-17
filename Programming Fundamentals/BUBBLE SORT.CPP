//BUBBLE SORT
#include<iostream>
using namespace std;
#define maxSzie 50 

//Defining Functions 
void bubbleSort(int[maxSize], int);

int main()
{
	int intArr[maxSize],numberOfElements,it;

	cout << "\n Enter number of elements u want to enter : " ;
	cin >> numberOfElements ;

	for ( it=0 ; it<numberOfElements ; it++ ){
		cin >> intArr[it] ;
	}

	bubblesort(intArr,numberOfElements);
	
	cout << "\n Sorted Result : " ;

	for ( it=0 ; it<numberOfElements ; it++ ){
		cout << intArr[it] << " " ;
	}
	
	return 0;
}

void bubblesort(int arr[],int size)
{
	int i,j,temp;

	for ( i=0 ; i<size ; i++ ) {
		for ( j=0 ; j<size-1 ; j++ ) {
			if ( arr[j]>arr[j+1] ) {
				temp=arr[j] ;
				arr[j]=arr[j+1] ;
				arr[j+1]=temp ;
			 }
		}
	}
}
