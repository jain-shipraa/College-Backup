/* Question : Performed Basic Operations on Array 
 * Modules 
 & Time 
 Complexity : 	void insertElement();  : O(n)
		void printEven(); : O(n)
		void prinOdd(); : O(n) 
		void printSumAvg(); : O(n)
		void findMinMax(); : O(n)
		void removeDuplicate(); : O(n^3)
 		void reverseArray(); O(ceil(n/2))
		void displayArray(); : O(n)
		int menuOptions(); : THETA(1)
		void performOperation(arrayClass,int); : THETA(1) 
*/

#include<iostream>
using namespace std;
#defie maxSize 10

class arrayClass {
	
	private:
	
	int arr[maxSize] ;
	int size ;
	
	public :
	
	arrayClass(int elementValue = 0){
		
		int i = 0 ;
		s = maxSize ;
		while ( i < s){
			arr[ i++ ] = elementValue;
		}
	}
	
	~arrayClass(){}
	
	int getSize();
	void insertElement();
	void printEven();
	void prinOdd();
	void printSumAvg();
	void findMinMax();
	void removeDuplicate();
	void reverseArray();
	void displayArray();

};

int arrayClass :: getSize(){
	return size ;
}

void arrayClass :: insertElement(){
		
	int i = 0;
	
	cout << " \n Enter Array Size : " ;
	cin >> size ;
	
	cout << "\n Enter " << size << " elements : ";
	while ( i < size ){	
		cin >> arr[ i++ ] ;
	}
	
	displayArray();
	
}

void arrayClass :: printEven(){
	
	int i = 0;
	displayArray();
	cout << "\n Filtering Out Even Elements we get : " ;

	while ( i < size ){
		
		if ( arr[ i ] % 2 == 0 ){
			cout << arr[ i ] << " ";
		}
		i++;
	}
}

void arrayClass :: prinOdd(){
	
	int i = 0;
	
	displayArray();
	cout << "\n Filtering Out Odd Elements we get : " ;
	
	while ( i < size ){
		
		if ( arr[ i ] % 2 != 0 ){
			cout << arr[ i ] << " " ;
		}
		i++;
	}
}

void arrayClass :: printSumAvg(){
	
	int i, sum, avg;
	sum = avg = i = 0;
	
	while ( i < size ){
		sum += arr[ i++ ];
	}
	
	cout << "\n Sum  of " << size << " elements = " << sum ;
	avg = sum / size ;
	cout << "\n Average of " << size << " elements = " << avg ;	
}

void arrayClass :: findMinMax(){
	
	int i, min, max;
	i=0 ;
	min = arr[0] ;
	max = arr[0] ;
	
	while ( i < size ){
		
		if ( max < arr[ i ] )
			max = arr[ i ] ;
		if ( min > arr[ i ] )
			min = arr[ i ];
		i++;
	}

	displayArray();
	cout << "\n Maximum of all elements is : " << max ;
	cout << "\n Minimum of all elements is : " << min ;
}

void arrayClass :: removeDuplicate(){

	int i, j, k;
	
	displayArray();
	for ( i = 0 ; i < size ; i++){
		for ( j = i+1 ; j < size ; j++ ){
			if ( arr [i] == arr[j] ){
				for ( k = j ; k < size-1 ; k++){
					arr[ k ] = arr [ k+1 ] ;
					size--;
				}
			}
		}
	}
	
	cout << "\n After Removing redundancy : ";
	displayArray();
	
}

void arrayClass :: reverseArray(){
	
	int i, j, temp;
	i = 0 ;
	j = size-1;

	displayArray();
	
	while ( i < size/2 ){
		
		temp = arr[ i ] ;
		arr[ i ] = arr[ j ] ;
		arr[ j ] = temp ;
	i++;
	j--;
 	}
	
	cout << "\n After reversing Array : " ;
	displayArray();
}

void arrayClass :: displayArray(){
		
	int i=0;
	cout << "\n Array Elements: \n " ; 
	
	while ( i < size ){
		cout << " " << arr[ i++ ] ;
	}
}

int menuOptions();
void performOperation(arrayClass,int);


int main()
{
	arrayClass arrayObj();
	char ans;

	do{
		performOperation(arrayObj,menuOptions());
		cout << "\n Do you want to continue ? (Y/N) " ;
		cin >> ans;
		
	}while ( ans == 'y' || ans == 'Y' ) ;
	return 0;
}

int menuOptions(){

	int choice;
	cout << " \n Possible Operation-List : " ;
	cout << " \n 1. Enter elements of array " ;
	cout << " \n 2. Print even valued elements " ;
	cout << " \n 3. Print odd valued elements " ;
	cout << " \n 4. Print sum and average of the elements " ;
	cout << " \n 5. Print maximumm and minimum element " ;
	cout << " \n 6. Remove redundant elements " ;
	cout << " \n 7. Reverse an array " ;
	cout << " \n 8. Quit !! " ;
	
	cout << " \n Enter your choice : (1:9) : " ;
	cin >> choice ;
	
	return choice;
}

void performOperation(arrayClass A,int option){
	
	switch ( option ) { 
			case 1  : A.insertElement();
			   	  break;
			case 2  : A.printEven();
				  break;
			case 3  : A.printOdd();
			          break;
			case 4  : A.printSumAvg();	
				  break;
			case 5  : A.findMinMax();
				  break;
			case 6  : A.removeDuplicate();
				  break;
			case 7  : A.reverseArray();
			  	  break;
			case 8  : cout << "\n Ending the program " ;
				  exit(1);
			default : cout << " \n You entered a wrong option !!! " ;
				  cout << " \n Enter a value again !!! ";
				  performOperation(A, menuOptions);
				  break;
			}
}
