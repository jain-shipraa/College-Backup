//BINARY SEARCH

#include<iostream>
using namespace std;
#define maxSize 100

int binsearch(int arr[], int, int);

int main()
{
	int arr[maxSize], size, element, position, i=0;

	cout << " \n Enter number of elements entered : " ;
	cin >> size ;

	cout << "\n Enter " << size << " elements : \n " ;
	for ( i = 0 ; i < size ; i++ ){
		cin >> arr[i] ;
	}

	cout << " \n Enter the element to be searched : " ;
	cin >> element ;

	position = binsearch(arr,size,element);
	if ( position == -1 ){
		cout << "\n Not found " ;
	}
	else{
		cout << "\n POSITION : "<< position+1 ;
	}
	
	return 1 ;

}


int binsearch(int arr[],int size,int element){
	
	int first, last, mid ;
	first = 0 ;
	last = size - 1 ;

	while ( first <= last ){
		
		mid = ( first + last ) / 2 ;

		if ( element == arr[ mid ] ){
			return mid ;
		}
		else if ( element < arr[ mid ] ){
			last = mid - 1 ;
		}
		else{
			first = mid + 1 ;
		}
	}
	return -1;
}
