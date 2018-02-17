//
//  SIMPLE DES.cpp
//  DES
//
//  Created by DEEPTI SHARMA on 27/11/17.
//  Copyright © 2017 DEEPTI SHARMA. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

#define maxSize 1000
#define blockSize 64


class DES
{

    int KeyRound[16][48],block[blockSize];
    int left[32],right[32];
    char result[maxSize];
    
    int KEY[blockSize]={
        0,0,0,1,0,0,1,1,
        0,0,1,1,0,1,0,0,
        0,1,0,1,0,1,1,1,
        0,1,1,1,1,0,0,1,
        1,0,0,1,1,0,1,1,
        1,0,1,1,1,1,0,0,
        1,1,0,1,1,1,1,1,
        1,1,1,1,0,0,0,1};
    
    /*
     EXTRA
     VARIABLES
     */
    
    
    int ck[28],dk[28],expansion[48],pc2[48];
    int xor1[48],substitute[32],p[32],xor2[32];
    int temp[blockSize],pc1[56],initPermute[blockSize],inverse[8][8];
    
    
    public:
    
    void initialPermutation();
    
    void keyGen();
    void PermChoice1();
    void PermChoice2();
    void printKey();
    
    char* encryption(char *);
    char* decryption(char *);
    void Expansion();
    void xorTwo();
    void xorOneEnc(int);
    void xorOneDec(int);
    void substitution();
    void permutation();
    
    void finalPermutation();
};

void DES :: printKey(){
   
    for(int i=0;i<blockSize;)
    {
        cout << " " << KEY[i++] ;
        if(i%8==0)
            cout << endl ;
    }
    
}



void DES :: initialPermutation()
{
    int k=58,i;
    for(i=0;i<32;i++)
    {
        initPermute[i]=block[k-1];
        if(k-8>0)  k=k-8;
        else       k=k+58;
    }
    
    k=57;
    
    for( i=32;i<blockSize;i++)
    {
        initPermute[i]=block[k-1];
        if(k-8>0)   k=k-8;
        else        k=k+58;
    }
}





void DES :: PermChoice1() //Permutation Choice-1
{
    int k=57,i;
    for(i=0;i<28;i++)
    {
        pc1[i]=KEY[k-1];
        if(k-8>0)
            k=k-8;
        
        else
            k=k+57;
    }
    
    k=63;
    
    for( i=28;i<52;i++)
    {
        pc1[i]=KEY[k-1];
        if(k-8>0)
            k=k-8;
        
        else
            k=k+55;
    }
    
    k=28;
    
    for(i=52;i<56;i++)
    {
        pc1[i]=KEY[k-1];
        k=k-8;
    }
    
}




void DES :: Expansion() //Expansion Function applied on `right' half
{
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
    
    k=0;
    for(i=0;i<8;i++)
        for(j=0;j<6;j++)
            
            expansion[k++]=exp[i][j];
}



void DES :: PermChoice2()
{
    int permute[56],i,k;
    for(i=0;i<28;i++) permute[i]=ck[i];
    for(k=0,i=28;i<56;i++) permute[i]=dk[k++];
    
    pc2[0]=permute[13] ;
    pc2[1]=permute[16] ;
    pc2[2]=permute[10] ;
    pc2[3]=permute[23] ;
    pc2[4]=permute[0] ;
    pc2[5]=permute[4] ;
    pc2[6]=permute[2] ;
    pc2[7]=permute[27];
    pc2[8]=permute[14] ;
    pc2[9]=permute[5] ;
    pc2[10]=permute[20] ;
    pc2[11]=permute[9] ;
    pc2[12]=permute[22] ;
    pc2[13]=permute[18] ;
    pc2[14]=permute[11] ;
    pc2[15]=permute[3] ;
    pc2[16]=permute[25] ;
    pc2[17]=permute[7] ;
    pc2[18]=permute[15] ;
    pc2[19]=permute[6] ;
    pc2[20]=permute[26] ;
    pc2[21]=permute[19] ;
    pc2[22]=permute[12] ;
    pc2[23]=permute[1] ;
    pc2[24]=permute[40] ;
    pc2[25]=permute[51] ;
    pc2[26]=permute[30] ;
    pc2[27]=permute[36] ;
    pc2[28]=permute[46] ;
    pc2[29]=permute[54] ;
    pc2[30]=permute[29] ;
    pc2[31]=permute[39] ;
    pc2[32]=permute[50] ;
    pc2[33]=permute[46] ;
    pc2[34]=permute[32] ;
    pc2[35]=permute[47] ;
    pc2[36]=permute[43] ;
    pc2[37]=permute[48] ;
    pc2[38]=permute[38] ;
    pc2[39]=permute[55] ;
    pc2[40]=permute[33] ;
    pc2[41]=permute[52] ;
    pc2[42]=permute[45] ;
    pc2[43]=permute[41] ;
    pc2[44]=permute[49] ;
    pc2[45]=permute[35] ; 
    pc2[46]=permute[28] ;
    pc2[47]=permute[31] ;
}



void DES :: xorOneEnc(int round) //for encryptionion
{
    int i;
    for(i=0;i<48;i++)
        xor1[i]=expansion[i]^KeyRound[round-1][i];
}



void DES :: xorOneDec(int round) //for decryption
{
    int i;
    for(i=0;i<48;i++)
        xor1[i]=expansion[i]^KeyRound[16-round][i];
}



void DES :: substitution()
{
    int sBox1[4][16]={
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    };
    
    int sBox2[4][16]={
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    };
    
    int sBox3[4][16]={
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    };
    
    int sBox4[4][16]={
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    };
    
    int sBox5[4][16]={
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    };
    
    int sBox6[4][16]={
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    };
    
    int sBox7[4][16]={
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    };
    
    int sBox8[4][16]={
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
            a[i][j]=xor1[k++];
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
        
        count=i+1;
        switch(count)
        {
            case 1:    v=sBox1[k][q];    break;
            case 2:    v=sBox2[k][q];    break;
            case 3:    v=sBox3[k][q];    break;
            case 4:    v=sBox4[k][q];    break;
            case 5:    v=sBox5[k][q];    break;
            case 6:    v=sBox6[k][q];    break;
            case 7:    v=sBox7[k][q];    break;
            case 8:    v=sBox8[k][q];    break;
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
            substitute[g++]=a[i];
    }
}




void DES :: permutation()
{
    p[0]=substitute[15] ;
    p[1]=substitute[6] ;
    p[2]=substitute[19] ;
    p[3]=substitute[20] ;
    p[4]=substitute[28] ;
    p[5]=substitute[11] ;
    p[6]=substitute[27] ;
    p[7]=substitute[16] ;
    p[8]=substitute[0] ;
    p[9]=substitute[14] ;
    p[10]=substitute[22] ;
    p[11]=substitute[25] ;
    p[12]=substitute[4] ;
    p[13]=substitute[17] ;
    p[14]=substitute[30] ;
    p[15]=substitute[9] ;
    p[16]=substitute[1] ;
    p[17]=substitute[7] ;
    p[18]=substitute[23] ;
    p[19]=substitute[13] ;
    p[20]=substitute[31] ;
    p[21]=substitute[26] ;
    p[22]=substitute[2] ;
    p[23]=substitute[8] ;
    p[24]=substitute[18] ;
    p[25]=substitute[12] ;
    p[26]=substitute[29] ;
    p[27]=substitute[5] ;
    p[28]=substitute[21] ;
    p[29]=substitute[10] ;
    p[30]=substitute[3] ;
    p[31]=substitute[24] ;
}



void DES :: xorTwo()
{
    int i;
    
    for ( i=0 ; i<32 ; i++ ){
        xor2[i] = left[i]^p[i];
    }
    
}



void DES :: finalPermutation()
{
    int p=40,q=8,k1,k2,i,j;
    for(i=0;i<8;i++)
    {
        k1=p;k2=q;
        for(j=0;j<8;j++)
        {
            if(j%2==0)
            {
                inverse[i][j]=temp[k1-1];
                k1=k1+8;
            }
            else if(j%2!=0)
            {
                inverse[i][j]=temp[k2-1];
                k2=k2+8;
            }
        }
        p=p-1;q=q-1;
    }
}



char * DES :: encryption(char *P1)
{
    int i,remBits,j,nB,m,iterBlock,k,K,B[8],n,t,d,round;
    int Plen;
    int mc=0;
    
    char *P=new char[maxSize];
    strcpy(P,P1);
    Plen = strlen(P);

    if ( Plen%8 )
    {
        remBits = Plen%8;
        i = Plen;
        for ( j=0; j<8-remBits ;j++,i++ ) {
                P[i]=' ';
        }
        
    }
    P[i]='\0';
    
    
    //GENERATING KEY FOR THE 16 ROUNDS
    keyGen();
    
    //GENERATING BINARY FROM CHARACTERS
    for(iterBlock=0,nB=0,m=0;m<((Plen/8)+1);m++)
    {
        for(iterBlock=0,i=0;i<8;i++,nB++)
        {
            n=P[nB];
            
            for(K=7;n>=1;K--)
            {
                B[K]=n%2;
                n/=2;
            }
            
            for(;K>=0;K--) B[K]=0;
            
            for(K=0;K<8;K++,iterBlock++)
                block[iterBlock]=B[K];
        }
        
        //INIIAL PERMUTATION
        initialPermutation();
        
        //COPYING BACK TO THE BLOCK
        for(i=0;i<blockSize;i++)
            block[i]=initPermute[i];
        
        //DEFINING LEFT AND RIGTH BLOCK
        for(i=0;i<32;i++)
            left[i]=block[i];
        for(;i<blockSize;i++)
            right[i-32]=block[i];
        
        for(round=1;round<=16;round++)
        {
            //Performing expansion on `right[32]' to get  `expansion[48]'
            Expansion();
            
            //Performing XOR operation on expansion[48],pc2[48] to get xor1[48]
            xorOneEnc(round);
            
            //Perform substitution on xor1[48] to get substitute[32]
            substitution();
            
            //Performing Permutation on substitute[32] to get p[32]
            permutation();
            
            //Performing XOR operation on left[32],p[32] to get xor2[32]
            xorTwo();
            
            for(i=0;i<32;i++)
                left[i]=right[i] ;
            for(i=0;i<32;i++)
                right[i]=xor2[i] ;
        }
        
        for(i=0;i<32;i++)
            temp[i]=right[i];
        for(;i<blockSize;i++)
            temp[i]=left[i-32];
        
        //FINAL PERMUTATION
        finalPermutation();
    
        //COPYING THE RESULT INTO CHARACTER ARRAY
        k=128;
        d=0;
        
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                d=d+inverse[i][j]*k;
                k=k/2;
            }
            result[mc++]=(char)d;
            k=128;
            d=0;
        }
    }

    result[mc]='\0';
    return(result);
}



char * DES :: decryption(char *C1)
{
    int i,remBits,j,nB,m,iterBlock,k,K,B[8],n,t,d,round;
    char *C=new char[maxSize];
    unsigned char ch;
    
    strcpy(C,C1);
    i=strlen(C);
    
    //KEY GENERATION FOR THE 16 ROUNDS
    keyGen();
    
    int mc=0;
    
    //GENERATING THE BINARY FORM OF THE CIPHER TEXT
    for(iterBlock=0,nB=0,m=0;m<(strlen(C)/8);m++)
    {
        for(iterBlock=0,i=0;i<8;i++,nB++)
        {
            ch=C[nB];
            n=(int)ch;
            for(K=7;n>=1;K--)
            {
                B[K]=n%2;
                n/=2;
            }
            
            for(;K>=0;K--) B[K]=0;
            for(K=0;K<8;K++,iterBlock++)
                block[iterBlock]=B[K];
        }
    
    
    //INITIAL PERMUTATION
    initialPermutation();
    
    //COPYING BACK TO THE BLOCK
    for(i=0;i<blockSize;i++)
        block[i]=initPermute[i];

    //LEFT RIGHT COPYING
    for(i=0;i<32;i++)
        left[i]=block[i];
    for(;i<blockSize;i++)
        right[i-32]=block[i];
        
    for( round=1 ; round<=16 ; round++ )
    {
        //Performing expansion on `right[32]' to get  `expansion[48]'
        Expansion();
        
        xorOneDec(round);
        
        //Perform substitution on xor1[48] to get substitute[32]
        substitution();
        
        //Performing Permutation on substitute[32] to get p[32]
        permutation();
        
        //Performing XOR operation on left[32],p[32] to get xor2[32]
        xorTwo();
        
        for(i=0;i<32;i++)
            left[i]=right[i];
        for(i=0;i<32;i++)
            right[i]=xor2[i];
    }


    for(i=0;i<32;i++)
        temp[i]=right[i];
    for(;i<blockSize;i++)
        temp[i]=left[i-32];

    //FINAL PERMUTATION
    finalPermutation();
        
    //Obtaining the Cypher-Text into result[maxSize]
    k=128;
    d=0;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            d=d+inverse[i][j]*k;
            k=k/2;
        }
        
        result[mc++]=(char)d;
        k=128;   d=0;
    }
}


        result[mc]='\0';
        char *result1=new char[maxSize];
        for(i=0,j=strlen(C);i<strlen(C);i++,j++)
            result1[i]=result[j]; result1[i]='\0';
        return(result);
    }



void DES :: keyGen()
{
    PermChoice1();
    
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
        
        PermChoice2();
        for(i=0;i<48;i++)
            KeyRound[round-1][i]=pc2[i];
    }
}




int main()
{
    DES D1,D2;
    
    char* plainText=new char[maxSize];
    char* cipherText=new char[maxSize];
    char* samplePlain ="PLAINTEXT";
    char* sampleCipher=new char[maxSize];

    cout << "\n DATA ENCRYPTION STANDARD " ;
    cout << "\n\n Sample Test ";
    cout << "\n\n PLAINTEXT : " << samplePlain ;
    cout << "\n KEY : " << endl ;
    D1.printKey();
    
    cout << "\n\n ENCRYPTING... " << endl ;
    cout << "\n CIPHER TEXT : " << D1.encryption(samplePlain);
    cout << "\n\n DECRYPTING... " << endl ;
    cout << "\n PLAINTEXT/ORIGINAL TEXT : " << D2.decryption(D1.encryption(samplePlain)) ;
    
    cout << "\n\n\n ENTER PLAINTEXT : ";
    cin >> plainText ;
    cipherText=D1.encryption(plainText);
    cout << "\n YOU ENTERD : " << plainText << endl ;
    cout << "\n CIPHER TEXT IS : " << cipherText << endl;
    cout << "\n UPON DECRYPTION :" << D2.decryption(cipherText) << endl;
    
    getchar();
}


