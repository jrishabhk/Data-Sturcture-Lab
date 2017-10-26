#include<stdio.h>
#include<stdlib.h>
#define queue_size 5
void insert_rear(int item, int *r, int q[])
{
  if(*r==queue_size -1)
  {
    printf("queue full \n");
    return;
  }
  *r+=1;
  q[*r]=item;
}

void delete_front(int *f, int *r, int q[])
{
  if(*f>*r)
  {
    printf("queue empty");
    *f=0;
    *r=-1;
    return;
  }
  else
  {
    printf("deleted item is %d\n", q[*f]);
    *f+=1;
  }
}

void display(int q[], int f, int r)
{
   int i,j;
   if(f>r)
   {
      printf("stack is empty\n");
      return;
   }
   else
   {
      printf("the contnts of queue are\n");
      for(i=f; i<=r; i++)      printf("%d\n",q[i]);
   }   
}

void main()
{
   int q[queue_size], item, f,r, choice;
   f=0;
   r=-1;
   for(;;)
   {
     printf("1:insert  2:delete  3:display  4:exit \n");
     printf("enter your choice\t");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:printf("enter the item to insert\t");
               scanf("%d",&item);
               insert_rear(item,&r, q);
        break;
        case 2: delete_front(&f,&r,q);
        break;
        case 3: display(q,f,r);
        break;
        default : exit(0);
               
     }
   }
}
