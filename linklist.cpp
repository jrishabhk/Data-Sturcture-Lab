#include<iostream>
#include<stdlib.h>
using namespace std;

class list
{
  int info;
  list *link;
  public:list()
	{
	   link=NULL;
	}
list *insert(int);
list *del();
void display();
}*first=NULL;

list *list::insert(int item)
{
  list *temp=new list;
  temp->info=item;
  temp->link=first;
  first=temp;
  return first;
}

list *list::del()
{
  if(first==NULL)
  {
    cout<<"the list is empty";
    return first;
  }
  list *temp=first;
  first=first->link;
  cout<<"the deleted item is\t"<<temp->info<<endl;
  delete(temp);
  return first;
}

void list::display()
{
  if(first==NULL)
  {
    cout<<"list is empty"; return;
  }
  list *temp=first;
  cout<<"\n the contents are\n";
  while(temp!=NULL)
  {
     cout<<temp->info<<endl;
     temp=temp->link;
  }
}

int main()
{
  int ch, item;
  for(;;)
  {
    cout<<"enter the choice\n";
   cout<<"1.insert 2.delete 3.display 4.exit\n";
    cin>>ch;
  switch(ch)
  {
    case 1:cout<<"enter the item\n";
          cin>>item;
          first=first->insert(item);
          break;
    case 2:first=first->del();
          break;
    case 3:first->display();
          break;
    default:exit(0);
  }
  }
return(0);
}
