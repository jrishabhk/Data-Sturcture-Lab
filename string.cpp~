#include<iostream>
#include<string.h>
using namespace std;

class STRING
{
   char s[20];
   public:
          STRING(){}
          STRING (char x[])
          {
             strcpy(s,x);
          }
          STRING (STRING &b)
          {
             strcpy(s,b.s);
          }
          friend STRING operator+(STRING,STRING);
          friend  ostream  &operator<<(ostream &,STRING);
};

STRING operator+(STRING s1,STRING s2)
{
   STRING temp(s1);
   strcat(temp.s,s2.s);
   return temp;
}

ostream &operator<<(ostream &dout, STRING x)
{
   dout<<x.s<<endl;
   return dout;
}

int main()
{
   STRING s1("VTU");
   STRING s2("BELGAUM");
   STRING s3;
   cout<<endl;
   cout<<"first STRING "<<s1<<endl;
   cout<<"second STRING "<<s2<<endl;
   s3=s1+s2;
   cout<<s3;
   cout<<endl;
}
