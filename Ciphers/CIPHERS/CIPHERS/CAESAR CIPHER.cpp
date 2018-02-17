//
//  CAESAR CIPHER.cpp
//  CIPHERS
//
//  Created by DEEPTI SHARMA on 26/11/17.
//  Copyright © 2017 DEEPTI SHARMA. All rights reserved.
//
//  Encryption
//  The message is written out in rows of a fixed length, and then read out again column by column, and the columns are chosen in some scrambled order.
//  Width of the rows and the permutation of the columns are usually defined by a keyword.
//  For example, the word HACK is of length 4 (so the rows are of length 4), and the permutation is defined by the alphabetical order of the letters in the keyword. In this case, the order would be “3 1 2 4”.
//  Any spare spaces are filled with nulls or left blank or placed by a character (Example: _).
//  Finally, the message is read off in columns, in the order specified by the keyword.
//
//
//  Decryption
//
//

#include <iostream>
#include <string>
#include <cctype>
//#include <bits/stdc++>
using namespace std;

string encryption(string,string);
string decryption(string,string);

int  main(){
    
    string samplePlainText="WE ARE FAR FROM DISCOVERY";
    string sampleKey="HACK";
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

string encryption(string P, string K){
    
    string cipherText;
    

    
    return cipherText;
}

string decryption(string C , string K){
    
    string plainText;

    
    
    return plainText;
}



