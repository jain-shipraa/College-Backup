#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
class MulCiph
{
  public:
  char str[100];
  int key;
  void getkey();
  void gettext();
  void enc();
  int inverse(int);
  void dec();

};
void MulCiph :: gettext()
{
  cout<<"\nEnter the string: ";
  cin>>str;
}
void MulCiph :: getkey()
{
  cout<<"\nEnter the multiplicative cipher key: ";
  cin>>key;
}
void MulCiph :: enc()
{
  int h=strlen(str);
  for(int i=0;i<h;i++)
  {
    char c=(((toascii(str[i])-97)*key)%26)+97;
    cout<<str[i]<<"\t"<<((toascii(str[i])-97)*key)%26<<"\t"<<c<<endl;
  }
}

int MulCiph :: inverse(int key)
{
  int r1,r2,r,q,t1,t2,t;
  r1=26;r2=key;
  t1=0;t2=1;
  while(r2>0)
  {
    q=r1/r2;
    r=r1-q*r2;
    r1=r2;r2=r;
    t=t1-q*t2;
    t1=t2;t2=t;
  }
  if(r1==1)
  {
    if(t1<0)
      t1+=26;
    return t1;
  }
}

void MulCiph :: dec()
{
  int h=strlen(str);
  int inv=inverse(key);
  for(int i=0;i<h;i++)
  {
    int dkey=(((toascii(str[i])-97)*inv))%26;
    char ch=dkey+97;
    cout<<str[i]<<"\t"<<dkey<<"\t"<<ch<<endl;
  }
}
void main()
{
  clrscr();
  MulCiph a;
  a.gettext();
  a.getkey();
  a.enc();
  a.dec();
  getch();
}