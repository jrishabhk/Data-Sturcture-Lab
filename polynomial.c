#include<stdio.h>
#include<stdlib.h>

#define COMPARE(x,y) ((x==y)?0:(x>y)?1:-1)

#define MALLOC(p,n,type) \
p=(type*)malloc(n*sizeof(type));\
if(p==NULL) \
{ \
  printf("insufficient memory\n"); \
  exit(0); \
}
struct node 
	{
	 int coeff,expon;
	 struct node *link;
	};

typedef struct node *NODE;

void display( NODE head)
{
 NODE temp;
 if(head->link==head)
  { 
   printf("polynomial does not exist");
   return;
  }
		temp=head->link;
	while(temp!=head)
	{
	 if(temp->coeff<0) printf("%2dx^%2d",temp->coeff,temp->expon);
	 else printf("+%2dx^%2d",temp->coeff,temp->expon);
	temp=temp->link;
	}
}

NODE attach(int coeff, int expon,NODE head)
{
 NODE temp,cur;
 MALLOC(temp,1,struct node);
 temp->coeff=coeff;
 temp->expon=expon;
cur=head->link;
while(cur->link!=head)
{
 cur=cur->link;
}
cur->link=temp;
temp->link=head;
return head;
}
  
NODE read( NODE head)
{
 int coeff,expon,i=1;
while(1)
{
 printf("enter %d term\n",i++);
 printf("coeff= "); scanf("%d",&coeff); 
 if(coeff==-999) break;
 printf("expon= ");  scanf("%d",&expon);
 head=attach(coeff,expon,head);
}
return head;
}
NODE add(NODE head1,NODE head2,NODE head3)
{
 NODE a,b;
int coeff;
a=head1->link;
b=head2->link;
while(a!=head1 && b!=head2)
{
 switch (COMPARE(a->expon,b->expon))
{
  case 0: coeff=a->coeff+b->coeff;
          if(coeff!=0)
          head3=attach(coeff,a->expon,head3);
          a=a->link; 
          b=b->link;
          break;
  case 1: head3=attach(a->coeff,a->expon,head3);
          a=a->link; break;
  default: head3=attach(b->coeff,b->expon,head3);
           b=b->link;
    }
  }
	while(a!=head1)
	{ 
                head3=attach(a->coeff,a->expon,head3);
 		a=a->link;
	}	
	while(b!=head2)
	{ 
 	 head3=attach(b->coeff,b->expon,head3);
	 b=b->link;
	}
return head3;
}


void main()
{ 
	NODE head1,head2,head3;
	MALLOC(head1,1,struct node);  head1->link=head1;
	MALLOC(head2,1,struct node);  head2->link=head2;
	MALLOC(head3,1,struct node);  head3->link=head3;

	printf("enter 1st polynomial\n");
              head1=read(head1);
	printf("enter 2nd polynomial\n"); head2=read(head2);
	head3=add(head1,head2,head3);
	printf("polynomial 1\n\n");
	display(head1);
	printf("\npolynomial 2\n\n");
	display(head2);
	printf("\naddition of two pollynomails is\n\n"); 
	display(head3);
}
