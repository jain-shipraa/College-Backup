//
//  MULTIPLICATIVE CIPHER.cpp
//  CIPHERS
//
//  Created by DEEPTI SHARMA on 27/11/17.
//  Copyright © 2017 DEEPTI SHARMA. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class MulCiph
{
    
    string plainText;
    string cipherText;
    int key;
    int inverse(int);
    
    public:
    
    void sampleRun();
    void getKey();
    void getText();
    void encryption();
    void decryption();
    
};


void MulCiph :: getText(){
    cout << "\n Enter the plainText (CAPITAL LETTERS): " ;
    cin >> plainText ;
}

void MulCiph :: getKey(){
    cout << "\n Enter the (AN INTEGER NUMBER EG : 9 ) Key : ";
    cin >> key ;
}


void MulCiph :: encryption(){
    int i;
    int c;
    
    for ( i=0 ; i < plainText.length() ; i++){
        
//        cout << plainText[i] << " " << plainText[i]-'A' << " ";
        c=plainText[i]-'A';
//        cout << c << " " ;
        c*=key;
//        cout << c << " " ;
        c%=26;
//        cout << c << " " ;
        c+='A';
//        cout << c << " "  << endl;
        cipherText.push_back(c);
        
    }
    cout << "\n CIPHERTEXT : " << cipherText ;
}

int MulCiph :: inverse(int key){
    
    int i=1;
    while ((key*i)%26!=1){
        i++;
    }
    return i;
}

void MulCiph :: decryption(){
    int inv=inverse(key);
//    cout << inv ;
    int i;
    int c;
    string P;
    
    for ( i=0 ; i<cipherText.length() ; i++ ){
        
        
        c=cipherText[i]-'A';
//        cout << c << " " ;
        c*=inv;
//        cout << c << " " ;
        c%=26;
//        cout << c << " " ;
        c+='A';
//        cout << c << " " << endl;
        P.push_back(c);
    }
    
    cout << "\n PLAINTEXT :" << P ;
}

void MulCiph :: sampleRun(){

    plainText.clear();
    cipherText.clear();
    plainText = "PLAINTEXT";
    key = 45;

    cout << "\n MULTIPLICATIVE CIPHER " ;
    cout << "\n\n Sample Test ";
    cout << "\n\n PLAINTEXT : " << plainText ;
    cout << "\n KEY : " << key ;
    cout << "\n\n ENCRYPTING... " << endl ;
    this->encryption();
    cout << "\n\n DECRYPTING... " << endl ;
    this->decryption() ;
    plainText.clear();
    cipherText.clear();
    
}

int main()
{

    MulCiph M;
    M.sampleRun();
    M.getText();
    M.getKey();
    M.encryption();
    M.decryption();
    return 0;
}
