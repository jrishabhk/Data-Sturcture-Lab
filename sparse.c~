#include<stdio.h>
#include<stdlib.h>
#define MAX_TERM 101
typedef struct{
                int row, col, val;
              } TERM;

void read_sparse(TERM a[], int m, int n)
{
   int i,j,k=1,item;
   a[0].row=m, a[0].col=n;
   for(i=0; i<m; i++)
   {
     for(j=0; j<n; j++)
     {
        scanf("%d",&item);
        if(item==0) continue;
        
        a[k].row=i;
        a[k].col=j;
        a[k].val=item;
        k++;
     }
   }
   a[0].val=k-1;
   printf("sparse matrix in triple form is\n");
   printf("<Row  Column  Value>\n");
   for(i=0; i<=a[0].val;i++)
   {
      printf("\n%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);
   }
}

void search_item(int item, TERM a[])
{
  int i,j;
  for(i=1; i<=a[0].val;i++)
  {
    if(item==a[i].val)
    {
      printf("search succesful\n");
      exit(0);
    }
  }
  printf("search unsuccesful\n");
}

void main()
{
  int m,n,item;
  TERM a[MAX_TERM];
  printf("enter the number of rows\n");
  scanf("%d",&m);
  printf("enter the number of column");
  scanf("%d",&n);
  printf("enter the elements of the matrix\n");
  read_sparse(a,m,n);
  printf("enter the element to be searched\n");
  scanf("%d",&item);
  search_item(item,a);
}
