//
//  COLUMNAR TRANSPOSITION.cpp
//  CIPHERS
//
//  Created by DEEPTI SHARMA on 26/11/17.
//  Copyright © 2017 DEEPTI SHARMA. All rights reserved.
//
//
//  Encryption
//  The plaintext(P) and key(K) are added modulo 26.
//  Ei = (Pi + Xi ) mod 26
//
//  Decryption
//  Di = (Ei - Xi) mod 26
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int* generateMap(string);
void mergeSort(string&, int, int);
void merge(string&, int, int, int);
int search(string, char);
string encryption(string,string);
string decryption(string,string);

int  main(){
    
    string samplePlainText = "PLAINTEXT";
    string sampleKey = "HACK";
    string sampleCipherText;

    
    cout << "\n COLUMNAR CIPHER " ;
    cout << "\n\n Sample Test ";
    cout << "\n\n PLAINTEXT : " << samplePlainText ;
    cout << "\n KEY : " << sampleKey ;
    cout << "\n\n ENCRYPTING... " << endl ;
    cout << "\n CIPHER TEXT : " << encryption(samplePlainText,sampleKey);
    cout << "\n\n DECRYPTING... " << endl ;
    cout << "\n PLAINTEXT/ORIGINAL TEXT : " << decryption(encryption(samplePlainText,sampleKey),sampleKey) ;
    
    
    string plainText, cipherText;
    string key ;
    
    cout << "\n\n ENTER THE PLAINTEXT : ";
    cin >> plainText ;
    
    cout << "\n ENTER THE KEY : " ;
    cin >> key ;
    
    cipherText = encryption(plainText,key) ;
    cout << " CIPHERTEXT GENERATED FORM THE PLAINTEXT : " << cipherText << endl ;
    plainText = decryption(cipherText,key) ;
    cout << " PLAINTEXT GENERATED FROM THE CIPHERTEXT : " << plainText << endl ;
    
    
    return 0;
}


int* generateMap(string K){
    
    int* keyMap = new int[K.size()];
    int i, map;
    string K2 = K;
    mergeSort( K2 , 0 , K2.size()-1 );
//    cout << K2 ;
    
    for ( i = 0 ; i < K2.size() ; i++ ) {
        map = search( K , K2[i] ) ;
        keyMap[i] = map;
        //        cout << keyMap[i] << " " ; -> print the columns in cipher in the order 1203 for HACK should have column 1 then col 2 col 0 then col 3 printed : ACHK
    }
    
    return keyMap;
}


int search( string s, char c){
    
    for ( int i=0 ; i < s.size() ; i++ ) {
        if ( s[i]==c ) {
            return i;
        }
    }
    return -1;
}

void merge(string& s, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    char L[n1], R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = s[l + i];
    for (j = 0; j < n2; j++)
        R[j] = s[m + 1+ j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            s[k] = L[i];
            i++;
        }
        else
        {
            s[k] = R[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        s[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        s[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(string &s, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(s, l, m);
        mergeSort(s, m+1, r);
        merge(s, l, m, r);
    }
}


string encryption(string P, string Key){
    
    string cipherText="";
    int* K;
    int KSize;
    int col,row ;
    int i,j,k;
    
    K = generateMap(Key);
    KSize = Key.size();
    col = Key.size();
    row = P.size()/col;
    
    if(P.size()%col){
        row++;
    }

    char matrix[row][col];
    
    k=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(P[k]=='\0'){
                matrix[i][j]='_';
            }
            else{
                matrix[i][j]=P[k];
                k++;
            }
        }
    }
    
    k=0;
    for(i=K[k];k<KSize;){
        for(j=0;j<row;j++){
            cipherText+=matrix[j][i];
        }
        k++;
        i=K[k];
    }
    
    
    return cipherText;
}

string decryption(string C , string Key){
    
    string plainText="";
    int* K;
    int KSize;
    int col,row ;
    int i,j,k,n;
    
    K = generateMap(Key);
    KSize = Key.size();
    col = Key.size();
    row = C.size()/col;
    
    if(C.size()%col){
        row++;
    }
    
    char matrix[row][col];
    
    k=0;
    n=0;
    for(i=K[k];k<KSize;){
        for(j=0;j<row;j++){
            matrix[j][i]=C[n++];
        }
        k++;
        i=K[k];
    }
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            plainText+=matrix[i][j];
        }
    }
    
    return plainText;
}



