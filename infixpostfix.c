#include<stdio.h>
#include<string.h>
int F(char symb)
{
  	switch(symb)
  	{
     	case '+' :
     	case '-' : return 2;
     	case '*' :
     	case '/' :return 4;
     	case '^' :
     	case '$' :return 5;
     	case '(' :return 0;
     	case '#' :return -1;
     	default  :return 8;
  	}
}

int G(char symb)
{
	switch(symb)
  	{
     		case '+' :
     		case '-' : return 1;
     		case '*' :
     		case '/' :return 3;
     		case '^' :
     		case '$' :return 6;
     		case '(' :return 9;
     		case ')' :return 0;
     		default  :return 7;
  	}
}

void infix_postfix(char infix[], char postfix[] )
{
   	int top;
   	int i,j;
   	char s[30],symb;
   	top=-1;
   	s[++top]='#';
   	j=0;
   	for(i=0;i<strlen(infix);i++)
   	{
      		symb=infix[i];
      		while (F(s[top])>G(symb))
      		{
        	 	postfix[j]=s[top--];
        		j++;
      		} 
		 if(F(s[top])!=G(symb))
        	 	s[++top]=symb;
      		else
        		 top--;   
	}
	while(s[top]!='#')
	{
		postfix[j++]=s[top--];
	}
   	postfix[j]='\0';
}

void main()
{
	char infix[20];
	char postfix[20];
  	printf("Enter the  infix expression\n");
  	scanf("%s",infix);
  	infix_postfix(infix, postfix);
	printf("");
  	printf("postfix expession is\n");
  	puts(postfix);
}            
