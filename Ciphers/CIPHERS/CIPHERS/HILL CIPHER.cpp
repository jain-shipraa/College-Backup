//
//  HILL CIPHER.cpp
//  CIPHERS
//
//  Created by DEEPTI SHARMA on 26/11/17.
//  Copyright © 2017 DEEPTI SHARMA. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void inverse(int[3][3],int[3][3]);
string matrixmult(int key[3][3],int block[3]);
string encryption(string,int[3][3]);
string decryption(string,int[3][3]);

int main()
{
    string plainText,cipherText;
    string samplePlainText="WEAREFARFROMDISCOVERY";
    string sampleKey="{{2,4,5},{9,2,1},{3,17,7}}";
    string sampleCipherText;
    int key[3][3] = {{2,4,5},{9,2,1},{3,17,7}};
    
    cout << "\n HILL CIPHER " ;
    cout << "\n\n Sample Test ";
    cout << "\n\n PLAINTEXT : " << samplePlainText ;
    cout << "\n KEY : " << sampleKey ;
    cout << "\n\n ENCRYPTING... " << endl ;
    cout << "\n CIPHER TEXT : " << encryption(samplePlainText,key);
    cout << "\n\n DECRYPTING... " << endl ;
    cout << "\n PLAINTEXT/ORIGINAL TEXT : " << decryption(encryption(samplePlainText,key),key) ;
    
    
    cout << " \n Enter string (CAPITAL LETTERS ONLY) : " ;
    cin >> plainText ;
    
    cout << " \n Encyrpted text : ";
    cipherText = encryption(plainText, key);
    cout << cipherText << endl ;
    
    
    cout<< "\n Decyrpted text : ";
    plainText = decryption(cipherText, key);
    cout << plainText << endl ;

    return 0;
}

string encryption(string P, int K[3][3]){
    
    string cipherText;
    int i,j,k;
    int block[3];
    int noBlocks;
    
    noBlocks = P.length()/3;
    if ( P.length()%3 ) {
        noBlocks++;
    }
    cout << "\n Number of Blocks : " << noBlocks << endl ;
    
    j=k=0;
    
    for ( i=0; i < noBlocks*3 ; i++)
    {
            if(k<P.length())
            {
                block[j] = ( P[k] - 'A' ) ;
              //  cout << block[j] << " " << j << " " << k << endl ;
                j++;
                k++;
            }
            else
            {
                block[j] = 1 ;
           //     cout << block[j] << endl ;
                j++;
            }
            
            if(j==3)
            {
                cipherText+=matrixmult(K,block);    // multiplying key with string of 3
                j=0;
            }
        
        
    }
    
    return cipherText ;
    
}

string decryption(string C,int K[3][3]){
  
    string plainText;
    int i;
    int block[3];
    int KInv[3][3];
    inverse(K,KInv);
    
    for ( i=0 ; i< C.length() ; i++ )
    {
        block[i%3] = (C[i] - 'A');
        if((i+1)%3==0 && i!=0)
        {
            plainText+=matrixmult(KInv,block);  // multiplying inverse of key with string of 3
        }
        
    }

    return plainText;
}

// simplfied multiplication because we know that entered string will be always 3x1
string matrixmult(int key[3][3],int block[3])
{
    string Text;
    int ans[3];
    int i , j;
    
    for ( i=0 ; i<3 ; i++ ){
        
        ans[i] = 0 ;
    }
    
    for ( i=0 ; i<3 ; i++ ){
        
        for ( j=0 ; j<3 ; j++ ){
            
            ans[i]+= key[i][j] * block[j];
        }
    }
    
    for ( i=0 ; i<3 ; i++ ){
        
        ans[i]%= 26;
        if ( ans[i]<0 )
            ans[i] = ans[i]+26;
        ans[i]+='A';
        
        Text.push_back(ans[i]);
    }
    return Text;
}


void inverse(int key[3][3],int finv[3][3])
{
    int i=0,j;
    int det;
    int inv[3][3];
    
    det=((key[0][0]*((key[2][2]*key[1][1])-(key[1][2]*key[2][1])))-(key[0][1]*((key[2][2]*key[1][0])-(key[1][2]*key[2][0])))+(key[0][2]*((key[2][1]*key[1][0])-(key[1][1]*key[2][0]))));
    //cout<<"Determinant of matrix is  "<<det<<"\n";
    
    
    // to find adjoint of this matrix
    if(det>0)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i+j %2 ==0)
                {
                    inv[i][j]= (key[(i+1)%3][(j+1)%3]*key[(i+2)%3][(j+2)%3] - key[(i+1)%3][(j+2)%3]*key[(i+2)%3][(j+1)%3]);
                }
                else
                {
                    inv[i][j]= (key[(i+1)%3][(j+1)%3]*key[(i+2)%3][(j+2)%3] - key[(i+1)%3][(j+2)%3]*key[(i+2)%3][(j+1)%3]);
                }
            }
        }
    }
    else if(det<0)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i+j %2 ==0)
                {
                    inv[i][j]= -(key[(i+1)%3][(j+1)%3]*key[(i+2)%3][(j+2)%3] - key[(i+1)%3][(j+2)%3]*key[(i+2)%3][(j+1)%3]);
                }
                else
                {
                    inv[i][j]= -(key[(i+1)%3][(j+1)%3]*key[(i+2)%3][(j+2)%3] - key[(i+1)%3][(j+2)%3]*key[(i+2)%3][(j+1)%3]);
                }
            }
        }
    }
    
    
    //instead of dividing by det. we will multiply the matrix with its multiplicative inverse
    //multiplicative inverse
    int detinv;
    det%=26;
    for(i=1;i<26;i++)
    {
        if((det*i)%26==1)
        {
            detinv=i;
           // cout<<"\nMultiplicative inverse of determinant is  "<<detinv<<"\n";
        }
    }
    
    //and to handle negative no.s we will apply (+26)
    //we will apply mod so that no.s are from 0-26
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            inv[i][j]=inv[i][j]%26;
            if(inv[i][j]<0)
            {
                inv[i][j]=inv[i][j]+26;
            }
            inv[i][j]=(inv[i][j]*detinv); // multiplying adjoint and inverse of det
            inv[i][j]=inv[i][j]%26;
        }
    }
    // tranpose of the final matrix will give us inverse
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finv[j][i]=inv[i][j];
        }
    }
    
//    for(i=0;i<3;i++)
//    {
//        for(j=0;j<3;j++)
//        {
//           cout<<finv[i][j]<<" ";
//        }
//      cout<<"\n";
//    }
//
    
}
