//
//  main.cpp
//  DES
//
//  Created by DEEPTI SHARMA on 21/11/17.
//  Copyright © 2017 DEEPTI SHARMA. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#define maxSize 64

class DES{
    
    string plainText,plainText2;
    int block[maxSize], CipherBlock[maxSize];
    int left[maxSize/2], right[maxSize/2] ;
    int expansion[48];
    int key[maxSize];
    int keyRound[16][48];
    
    int ck[28];
    int dk[28];
    int pc1[56];
    int pc2[48];
    int xorExpKey[48];
    int sub[32];
    int p[32];
    int xorLeftP[32];
    int inv[8][8];
    
    public :
    string cipherText;
    void getText();
    void makeBlock();
    void makeCipherBlock(string,int);
    void toBinary(int,int);
    void toCipherBinary(int,int);
    
    void defineKey();
    void keyGen();
    void permChoice1();
    void permChoice2();
    
    void encryption();
    void initialPermutation();
    void expansion32To48();
    void xor1(int);
    void substitution();
    void permutation();
    void xor2();
    void inversePermutation();
    void toCipher();
    
    void printCipherText();
    void printPlainText();
    
    void decryption();
    void toPlain();
    void xor1D(int);
};

void DES :: printCipherText(){
    cout << "\n CIPHER TEXT : " << cipherText ;
}

void DES :: printPlainText(){
    cout << "\n PLAIN TEXT : " << plainText ;
}

void DES :: getText(){
    
    cout << "\n PlainText : ";
    cin >> plainText;
    makeBlock();
}

/*
 BLOCK
 GENERATOR
*/

        void DES :: makeBlock(){
            
            int Plength,i,nBlocks=0;
            
            Plength = plainText.length();
            nBlocks = (Plength) / 8;
            if ( Plength%8 )
            {
                nBlocks++;
                for(i=Plength ; i < 8*nBlocks ;i++){
                    plainText.push_back('_');
                }
            }
        //    cout << nBlocks ;
        //    cout << plainText << endl ;
            defineKey();
            keyGen();
            
            for ( i=0 ; i < nBlocks ; i++ ){
                
                toBinary(i*8,(i+1)*8);
                
        //        for(i=0;i<64;){
        //            cout << block[i++] << " ";
        //            if(i%8==0){
        //                cout << endl ;
        //            }
        //        }
                encryption();
        //        cout << " \n AFTER ENCRYPTION \n";
        //        for(i=0;i<64;){
        //            cout << block[i++] << " ";
        //            if(i%8==0){
        //                cout << endl ;
        //            }
        //        }

                toCipher();
        //        cout << " i : " << i;
            }
            
        //    for(i=0;i<64;){
        //        cout << block[i++] << " ";
        //        if(i%8==0){
        //            cout << endl ;
        //        }
        //    }
        //
        }


        void DES :: toBinary(int s, int l ){

            int i,c,j,it;
            it=1;
            for ( i=s ; i<l ;i++){
                c = plainText[i];
        //        cout << c << endl;
                j=(it*8)-1;
        //        cout << j ;
                while(j>=((it-1)*8)){
                    block[j]=c%2;
        //            cout << block[j] << " " << j << " " <<endl;
                    c/=2;
                    j--;
                }
                it++;
            }
            
        //    cout << endl;
        }

/*
 KEY
 GENERATOR
*/

            void DES :: defineKey(){
                
                int newKey[64]={
                    0,0,0,1,0,0,1,1,
                    0,0,1,1,0,1,0,0,
                    0,1,0,1,0,1,1,1,
                    0,1,1,1,1,0,0,1,
                    1,0,0,1,1,0,1,1,
                    1,0,1,1,1,1,0,0,
                    1,1,0,1,1,1,1,1,
                    1,1,1,1,0,0,0,1};
                
                int i;
                
                for ( i=0 ; i < 64 ; i++ ){
                    key[i] = newKey[i];
                }

            }

            void DES :: permChoice1()
            {
                int k=57,i;
                for(i=0;i<28;i++)
                {
                    pc1[i]=key[k-1];
                    if(k-8>0)
                        k=k-8;
                    
                    else
                        k=k+57;
                }
                
                k=63;
                
                for( i=28;i<52;i++)
                {
                    pc1[i]=key[k-1];
                    if(k-8>0)
                        k=k-8;
                    
                    else
                        k=k+55;
                }
                
                k=28;
                
                for(i=52;i<56;i++)
                {
                    pc1[i]=key[k-1];
                    k=k-8;
                }
                
            }

            void DES :: permChoice2()
            {
                int per[56],i,k;
                for(i=0;i<28;i++) per[i]=ck[i];
                for(k=0,i=28;i<56;i++) per[i]=dk[k++];
                
                pc2[0]=per[13];
                pc2[1]=per[16];
                pc2[2]=per[10];
                pc2[3]=per[23];
                pc2[4]=per[0];
                pc2[5]=per[4];
                pc2[6]=per[2];
                pc2[7]=per[27];
                pc2[8]=per[14];
                pc2[9]=per[5];
                pc2[10]=per[20];
                pc2[11]=per[9];
                pc2[12]=per[22];
                pc2[13]=per[18];
                pc2[14]=per[11];
                pc2[15]=per[3];
                pc2[16]=per[25];
                pc2[17]=per[7];
                pc2[18]=per[15];
                pc2[19]=per[6];
                pc2[20]=per[26];
                pc2[21]=per[19];
                pc2[22]=per[12];
                pc2[23]=per[1];
                pc2[24]=per[40];
                pc2[25]=per[51];
                pc2[26]=per[30];
                pc2[27]=per[36];
                pc2[28]=per[46];
                pc2[29]=per[54];
                pc2[30]=per[29];
                pc2[31]=per[39];
                pc2[32]=per[50];
                pc2[33]=per[46];
                pc2[34]=per[32];
                pc2[35]=per[47];
                pc2[36]=per[43];
                pc2[37]=per[48];
                pc2[38]=per[38];
                pc2[39]=per[55];
                pc2[40]=per[33];
                pc2[41]=per[52];
                pc2[42]=per[45];
                pc2[43]=per[41];
                pc2[44]=per[49];
                pc2[45]=per[35];
                pc2[46]=per[28];
                pc2[47]=per[31];
            }

            void DES :: keyGen(){
                
                permChoice1();
                
                int i,j,k=0;
                for(i=0;i<28;i++)
                {
                    ck[i]=pc1[i];
                }
                for(i=28;i<56;i++)
                {
                    dk[k]=pc1[i];
                    k++;
                }
                
                int noshift=0,round;
                
                for(round=1;round<=16;round++)
                {
                    if(round==1||round==2||round==9||round==16)
                        noshift=1;
                    
                    else
                        noshift=2;
                    
                    while(noshift>0)
                    {
                        int t;
                        t=ck[0];
                        for(i=0;i<28;i++)
                            ck[i]=ck[i+1];
                        ck[27]=t;
                        t=dk[0];
                        for(i=0;i<28;i++)
                            dk[i]=dk[i+1];
                        dk[27]=t;
                        noshift--;
                    }
                    
                    permChoice2();
                    for(i=0;i<48;i++)
                    {
                        keyRound[round-1][i]=pc2[i];
            //            cout << keyRound[round-1][i] << " ";
                    }
                    
                }
            }
/*
 ENCRYPTION
 AND ALL RELATED
 FUNCTIONS
 */

void DES::initialPermutation()
{
    int k=58,i;
    int ip[64];
    
    for(i=0;i<32;i++)
    {
        ip[i]=block[k-1];
        if(k-8>0)
            k=k-8;
        else
            k=k+58;
    }
    
    k=57;
    for(i=32;i<64;i++)
    {
        ip[i]=block[k-1];
        if(k-8>0)
            k=k-8;
        else
            k=k+58;
    }
    
    for(i=0;i<64;i++){
        block[i]=ip[i]; //permuted block
    }
}

void DES :: expansion32To48(){
    
    int exp[8][6],i,j,k;
    
    for( i=0;i<8;i++)
    {
        for( j=0;j<6;j++)
        {
            if((j!=0)||(j!=5))
            {
                k=4*i+j;
                exp[i][j]=right[k-1];
            }
            if(j==0)
            {
                k=4*i;
                exp[i][j]=right[k-1];
            }
            if(j==5)
            {
                k=4*i+j;
                exp[i][j]=right[k-1];
            }
        }
    }
    exp[0][0]=right[31];
    exp[7][5]=right[0];
//    cout << exp[0][2] << " ";
    
    k=0;
    for(i=0;i<8;i++)
        for(j=0;j<6;j++)
        {
            
            expansion[k]=exp[i][j];
//            cout << expansion[k] << "!";
            k++;
            
        }
}

void DES :: xor1(int roundNumber){

    int i;
    for(i=0;i<48;i++){
        xorExpKey[i]=expansion[i]^keyRound[roundNumber-1][i];
//        cout << keyRound[roundNumber-1][i] << " ! ";
    }

}

void DES :: substitution()
{
    int s1[4][16]={
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    };
    
    int s2[4][16]={
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    };
    
    int s3[4][16]={
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    };
    
    int s4[4][16]={
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    };
    
    int s5[4][16]={
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    };
    
    int s6[4][16]={
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    };
    
    int s7[4][16]={
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    };
    
    int s8[4][16]={
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    };
    
    
    int a[8][6],k=0,i,j,p,q,count=0,g=0,v;
    
    for(i=0;i<8;i++)
    {
        for(j=0;j<6;j++)
        {
            a[i][j]=xorExpKey[k++];
            
        }
    }
    
    
    for( i=0;i<8;i++)
    {
        p=1;q=0;
        k=(a[i][0]*2)+(a[i][5]*1);
        j=4;
        
        while(j>0)
        {
            q=q+(a[i][j]*p);
            p=p*2;
            j--;
        }
//        cout << k<<" " << q ;
        count=i+1;
        switch(count)
        {
            case 1:    v=s1[k][q];    break;
            case 2:    v=s2[k][q];    break;
            case 3:    v=s3[k][q];    break;
            case 4:    v=s4[k][q];    break;
            case 5:    v=s5[k][q];    break;
            case 6:    v=s6[k][q];    break;
            case 7:    v=s7[k][q];    break;
            case 8:    v=s8[k][q];    break;
        }
        
        int d,i=3,a[4];
        while(v>0)
        {
            d=v%2;
            a[i--]=d;
            v=v/2;
        }
        while(i>=0)
        {
            a[i--]=0;
        }
        
        for(i=0;i<4;i++)
            sub[g++]=a[i];
    }
}

void DES :: permutation()
{
    p[0]=sub[15];p[1]=sub[6];p[2]=sub[19];p[3]=sub[20];p[4]=sub[28];p[5]=sub[11];p[6]=sub[27];p[7]=sub[16];
    p[8]=sub[0];p[9]=sub[14];p[10]=sub[22];p[11]=sub[25];p[12]=sub[4];p[13]=sub[17];p[14]=sub[30];p[15]=sub[9];
    p[16]=sub[1];p[17]=sub[7];p[18]=sub[23];p[19]=sub[13];p[20]=sub[31];p[21]=sub[26];p[22]=sub[2];p[23]=sub[8];
    p[24]=sub[18];p[25]=sub[12];p[26]=sub[29];p[27]=sub[5];p[28]=sub[21];p[29]=sub[10];p[30]=sub[3];p[31]=sub[24];
}

void DES :: xor2()
{
    int i;
    for(i=0;i<32;i++)
        xorLeftP[i]=left[i]^p[i];
    
}

void DES :: inversePermutation()
{
    int p=40,q=8,k1,k2,i,j;
    for(i=0;i<8;i++)
    {
        k1=p;k2=q;
        for(j=0;j<8;j++)
        {
            if(j%2==0)
            {
                inv[i][j]=block[k1-1];
                k1=k1+8;
            }
            else if(j%2!=0)
            {
                inv[i][j]=block[k2-1];
                k2=k2+8;
            }
        }
        p=p-1;q=q-1;
    }
}
void DES :: encryption(){
    
    int i;
    int round;
    
    //INITIAL PERMUTATAION
    initialPermutation();
    
    // DEFINING LEFT AND RIGHT HALF
    for(i=0;i<32;i++){
        left[i]=block[i];
    }
    for(;i<64;i++){
        right[i-32]=block[i];
    }
    
    // 16 ROUNDS
    for(round=1;round<=16;round++)
    {
        expansion32To48(); //Performing expansion on `right[32]' to get  `expansion[48]'
        xor1(round); //Performing XOR operation on expansion[48],pc2[48] to get xor1[48]
        substitution();//Perform substitution on xor1[48] to get sub[32]
        permutation(); //Performing Permutation on sub[32] to get p[32]
        xor2(); //Performing XOR operation on left[32],p[32] to get xor2[32]
        for(i=0;i<32;i++)
            left[i]=right[i]; //Dumping right[32] into left[32]
        for(i=0;i<32;i++)
            right[i]=xorLeftP[i]; //Dumping xor2[32] into right[32]
    }

    //FINAL COPYING
    for(i=0;i<32;i++)
        block[i]=right[i]; // Dumping   -->[ swap32bit ]

    for(;i<64;i++)
        block[i]=left[i-32];  //    left[32],right[32] into temp[64]


    inversePermutation();
}

void DES :: toCipher(){
    
    int k,c,i,j;
    k=128;
    c=0;
    
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            c=c+inv[i][j]*k; //( converting binary to decimal )
            k=k/2;
        }
        cipherText.push_back(c);
        k=128;
        c=0;
    }
}


void DES :: makeCipherBlock(string C,int len){

    int length,i,nBlocks;
    cipherText=C;
    cout << len ;
    length = len ;
    nBlocks = (length) / 8;
    cout << nBlocks;
    cout << " here" ;
    if ( length%8 )
    {
        
//        cout <<"her";
        nBlocks++;
        for(i=length ; i < 8*nBlocks ;i++){
            C.push_back('_');
        }
    }

//    cout << nBlocks;
    defineKey();
    keyGen();
    
    for ( i=0 ; i < nBlocks ; i++ ){
        toCipherBinary(i*8,(i+1)*8);
        
//        for(i=0;i<64;){
//                        cout << block[i++] << " ";
//                        if(i%8==0){
//                            cout << endl ;
//                        }
//                    }
        decryption();
        toPlain();
    }

}

void DES :: toCipherBinary(int s, int l ){
    
    int i,c,j,it;
    it=1;
    for ( i=s ; i<l ;i++){
        c = cipherText[i];
        //        cout << c << endl;
        j=(it*8)-1;
        //        cout << j ;
        while(j>=((it-1)*8)){
            block[j]=c%2;
            //            cout << block[j] << " " << j << " " <<endl;
            c/=2;
            j--;
        }
        it++;
    }
    
    //    cout << endl;
}
void DES :: xor1D(int round) //for Decrypt
{
    int i;
    for(i=0;i<48;i++)
    {
        xorExpKey[i]=expansion[i]^keyRound[16-round][i];
    }
}


void DES :: decryption() {
    
    int i;
    int round;
    
    initialPermutation(); //Performing initial permutation on `total[64]'
    
    // DEFINING LEFT AND RIGHT HALF
    for(i=0;i<32;i++){
        left[i]=block[i];
    }
    for(;i<64;i++){
        right[i-32]=block[i];
    }

    for(round=1;round<=16;round++)
    {
        expansion32To48(); //Performing expansion on `right[32]' to get  `expansion[48]'
        xor1D(round);
        substitution();//Perform substitution on xor1[48] to get sub[32]
        permutation(); //Performing Permutation on sub[32] to get p[32]
        xor2(); //Performing XOR operation on left[32],p[32] to get xor2[32]
        for(i=0;i<32;i++)
            left[i]=right[i]; //Dumping right[32] into left[32]
        for(i=0;i<32;i++)
            right[i]=xorLeftP[i]; //Dumping xor2[32] into right[32]
    }
    
    
    //FINAL COPYING
    for(i=0;i<32;i++)
        block[i]=right[i]; // Dumping   -->[ swap32bit ]
    
    for(;i<64;i++)
        block[i]=left[i-32];  //    left[32],right[32] into temp[64]
    
    
    inversePermutation();

    }



void DES :: toPlain(){
    
    int k,c,i,j;
    k=128;
    c=0;
    
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            c=c+inv[i][j]*k; //( converting binary to decimal )
            k=k/2;
        }
        plainText2.push_back(c);
        k=128;
        c=0;
    }
    cout <<endl;
    cout << plainText2 ;
    
    for ( i=0 ; i<plainText2.length(); i++){
        plainText[i]=plainText2[plainText2.length()-i];
        cout << plainText[i] ;
    }
    
}

int main(){
    DES D,D2;
    string c;
    int len;
    D.getText();
    D.printCipherText();
    
    c=D.cipherText ;
    len=D.cipherText.length();
//    cout << c << len;
    D2.makeCipherBlock(c,len);
    D2.printPlainText();
    return 0;
}

