#include<iostream>
#include<stdlib.h>
#define STACK_SIZE 3
using namespace std;
class STACK
{ 
	int s[20];
	int top;
   public : STACK()
   	   {
   	      top=-1;
   	   }
   	   friend ostream  &operator<<(ostream &,STACK);
   	   STACK operator + (int item);
   	   STACK operator - (int X);
};

ostream &operator<<(ostream &dout, STACK o)
{
	int i;
	if(o.top==-1)
	{
		cout<<"stack empty"<<endl;
		return dout;
	}
	dout<<"stack elements are"<<endl;
	for(i=o.top;i>=0;i--)
   		dout<<o.s[i]<<endl;
      return  dout;
   
}

STACK STACK ::operator + (int item)
{
	if(top==STACK_SIZE-1)
	{
		cout<<"stack overflow";
		return *this;
	}
	s[++top]=item;
	return *this;
}

STACK STACK::operator - (int X)
{
	if(top==-1)
	{
		cout<<"stack underflow";
		return *this;
	}
   	cout<<"popped item is"<<s[top--];
   	return *this;
}

int main()
{
	STACK s1;
	int ch,item;
   	for(;;)
   	{
      		cout<<"enter choice"<<endl;
                cout<<"1:push 2:pop 3:exit\n";
      		cin>>ch;
      		switch(ch)
      		{
         		case 1:cout<<"enter element to push\n";
                	cin>>item;
                	s1= s1+item;
                	cout<<s1;
                	break;
         		case 2:s1=s1-'0';
                	cout<<s1;
                	break;
         		case 3:exit(0);       
         
      		}
   	}
	return 0;
}
