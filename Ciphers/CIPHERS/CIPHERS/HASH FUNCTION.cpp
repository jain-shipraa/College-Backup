//
//  HASH FUNCTION.cpp
//  CIPHERS
//
//  Created by DEEPTI SHARMA on 27/11/17.
//  Copyright © 2017 DEEPTI SHARMA. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std ;

int main()
{
    
    string plainText,cipherText ;
    int key, i,j=0 ;
    char reply = 'y' ;
    int code=0 ;
    int finalcode = 0  ;
    bool change = false ;
 
    cout << "\n Enter the Value of the KEY :" ;
    cin >> key ;
    
    ifstream in;
    in.open("/Users/deeps/CIPHERS/CIPHERS/PlainText.txt",ios::in) ;
   
    if(!in)
    {
        cout << "\n File coud not be opened " ;
    }
    
    ofstream out("/Users/deeps/CIPHERS/CIPHERS/HashCode.txt") ;
   
    if(!out)
    {
        cout << "\n File coud not be opened " ;
    }
    
    while ( getline(in,plainText) ){
        code=0;
//        cout << plainText<< "\n" ;
        for ( i=0 ; i<plainText.length() ;i++){
            
            code^= (toupper(plainText[i])-'A') ;
            
        }
//        cout << code ;
        finalcode = abs(code^key)%256;
        
        cout << "\n FINAL CODE : "<<j+1 <<" :"<< (char)finalcode << endl ;
        out << (char)finalcode ;
        j++;
    }
    in.close() ;
    out.close();
    
    cout << "\n HASH CODE HAS BEEN GENERATED " ;
    cout << "\n Do you want to continue ? (y/n) :";
    cin >> reply ;
    char finalcodechar;
    j=0;
    
    while ( reply=='y'){
        
        ifstream file("/Users/deeps/CIPHERS/CIPHERS/PlainText.txt") ;
        ifstream hash("/Users/deeps/CIPHERS/CIPHERS/HashCode.txt");
        
        int codesaved = 0 ;
        while ( getline(file,cipherText) ) {
            codesaved = 0 ;
//            cout << cipherText<< endl ;
            
            for(int i=0 ;i<cipherText.length() ;i++)
            {
                codesaved^=(toupper(cipherText[i])-'A') ;
            }
            
            codesaved=abs(codesaved^key)%256 ;
            hash.get(finalcodechar);
//            cout << "finalcodechar : "<< finalcodechar << endl ;
            change = (codesaved^finalcodechar)?true:false ;
            
            if(!change)
            {
//                cout << "Code Saved : " << (char)codesaved;
                cout << "\n FILE IS UNCHANGED : " << j+1 << endl ;
            }
            else
            {
//                 cout << "Code Saved : " << (char)codesaved;
                cout << "\n FILE HAS BEEN CHANGED "<< j+1 << endl;
            }
            j++;
        }
        
        cout << "\n Do you want to continue ? (y/n) :";
        cin >> reply ;
        file.close() ;
        out.close() ;
    }
    return 0 ;
}
