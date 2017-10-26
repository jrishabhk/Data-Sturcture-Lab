#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

double compute(char symb, double op1, double op2)
{
   switch(symb)
   {
      case '+' : return op1+op2;
      case '-' : return op1+op2;
      case '*' : return op1*op2;
      case '/' : return op1/op2;
      /*case '^' :
      case '$' :return pow(op1,op2);*/
   }
}

void main()
{
   double s[20];
   double op1, op2, res;
   int i,top;
   char postfix[20];
   char symb;
   printf("Enter the postfix expression\n");
   scanf("%s",postfix);
   top=-1;
   for(i=0;i<strlen(postfix);i++)
   {
      symb=postfix[i];
      if(isdigit(symb))
      {
         s[++top]=(symb-'0');
         
      }
      else
      {
         op2=s[top--];
         op1=s[top--];
         res=compute(symb,op1,op2);
         s[++top]=res;
      }
   }
   res=s[top--];
   printf("The result is %f",res);
}
