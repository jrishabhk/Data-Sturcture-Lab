#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class OCTAL
{
   int oct;
   public : OCTAL(int m)
            {
               oct=dec2oct(m);
            }
            int dec2oct(int);
            int oct2dec(int);
            int operator+(int);
            friend ostream & operator<<(ostream &, OCTAL);
};


int OCTAL::operator+(int i)
{
   int k=oct2dec(oct)+i;
   return k;
}

int OCTAL::dec2oct(int num)
{
   int i=0, sum=0;
   if(num>=0 && num<=7)
      sum=num;
   else 
   {
     while(num>0)
     {
        sum=sum+num%8*pow(10, i);
        i++;
        num=num/8;
     }
   }
   return sum;
}


int OCTAL::oct2dec(int num)
{
   int i=0,sum=0;
   if(num>=0 && num<=9)
      sum=num;
   else
   {
      while(num>0)
      {
         sum=sum+num%10*pow(8,i);
         i++;
         num=num/10;
      }
   }
   return sum;   
}


ostream& operator<<(ostream& dout,OCTAL o)
{
   dout<<o.oct<<endl;
   return dout;
}


int main()
{
  int x,y,k;
  cout<<"enter decimal number\n";
  cin>>x;
  OCTAL h=x;
  cout<<"\nequivalent octal number is\n"<<h;
  cout<<"\nenter the integer to be added\n";
  cin>>k;
  y=h+k;
  cout<<"sum="<<y<<endl;
  return 0;
}
