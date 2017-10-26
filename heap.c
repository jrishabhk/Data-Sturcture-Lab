#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int insert_heap(int item, int heap[], int n)
{
   int child, parent;
   if(n==MAX_SIZE)
   {
      printf("heap is full");
      return n;
   }
   child=n;
   parent=(child-1)/2;
   while(child!=0 && item> heap[parent])
   {
      heap[child]=heap[parent];
      child=parent;
      parent=(child-1)/2;
   }
   heap[child]=item;
   return n+1;
}


void display(int heap[], int n)
{
  int i;  if(n==0)
  {
     printf("heap is empty \n");
     return;
  }
  printf("the max heap content are\n");
  for(i=0;i<n;i++)
     printf("%d\n",heap[i]);
}


void main()
{
  int heap[MAX_SIZE], n=0, choice, item;
  for(;;) {
     printf("1.insert  2.display  3.exit\n");
     printf("enter your choice\n");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:printf("enter the item to be inserted\n");
               scanf("%d",&item);
               n=insert_heap(item, heap, n);
               break;
        case 2:display(heap, n);
               break;
       default:exit(0);       
     }
  }
}
