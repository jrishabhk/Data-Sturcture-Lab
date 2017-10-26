/* LAB PROGRAM
11. Design, develop, and execute a program in C to implement a doubly linked list where each node consists of integers. The program should support the following operations; 
i) Create a doubly linked list by adding each node at the front. 
ii) Insert a new node to the left of the node whose key value is read as an input. 
iii) Delete the node of a given data if it is found, otherwise display appropriate message.			
iv) Display the contents of the list.*/


#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,n,type)\
p=(type*)malloc(n*sizeof(type));\
if(p==NULL)\
{\
printf("Insufficient memory!\n");\
exit(0);\
}

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
	
typedef  struct node *NODE;

NODE insert_front(int item,NODE head)
{
	NODE temp,cur;
	MALLOC(temp,1,struct node);
	temp->info=item;
	cur=head->rlink;
	head->rlink=temp;
	temp->llink=head;
	cur->llink=temp;
	temp->rlink=cur;
	return head;
}

NODE insert_left(int key,NODE head)
{
	NODE temp, cur,prev;
	int item;
	if(head->rlink==head)
	{
		printf("circular DLL is empty\n");
		return head;
        }
        cur=head->rlink;
        while(cur!=head)
        {
        	if(key==cur->info)
        	{
        		prev=cur->llink;
        		printf("Enter the node to insert to the left of the specified node\n");
        		MALLOC(temp,1,struct node);
        		scanf("%d",&item);
        		temp->info=item;
        		prev->rlink=temp;
        		temp->llink=prev;
        		temp->rlink=cur;
        		cur->llink=temp;
        		return head;
        	}
        	cur=cur->rlink;
        }
        printf("key specified not found\n");
        return head;
}


NODE delete_key(int key, NODE head)
{
	NODE cur, next, prev;
	if(head->rlink==head)
	{
		printf("circular DLL is empty\n");
		return head;
	}
	cur=head->rlink;
	while(cur!=head)
	{
		if(key==cur->info)
		{
			prev=cur->llink;
			next=cur->rlink;
			printf("\nthe deleted node with info is %d\n",cur->info);
			prev->rlink=next;
			next->llink=prev;
			free(cur);
			return head;
		}
		cur=cur->rlink;
	}
	printf("key node info specified not found\n");
	return head;
}

void display(NODE head)
{
	NODE temp;
	if(head->rlink==head)
	{
		printf("Circular DLL empty!\n");
		return;
	}
	printf("The contents of the circular DLL is\n");
	temp=head->rlink;
	while(temp!=head)
	{
		printf("%d\n",temp->info);
		temp=temp->rlink;
	}
}

void main()
{
	NODE head;
	int item, choice, key;
	MALLOC(head,1,struct node);
	head->llink=head;
	head->rlink=head;
	for(;;)
	{
		printf("1. Insert_front 2. Insert_left 3. Delete_key\n 4. Display 5. Exit\n\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the item\n");
				scanf("%d",&item);
				head=insert_front(item,head);
				break;
			case 2: printf("Enter the key to search\n");
				scanf("%d",&key);
				head=insert_left(key,head);
				break;
			case 3: printf("Enter the key to delete\n");
				scanf("%d",&key);
				head=delete_key(key,head);
				break;
			case 4: display(head);
				break;
		       default: exit(0);
		 }
	}
}
