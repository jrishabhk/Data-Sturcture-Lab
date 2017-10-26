#include<iostream>
#include<cstdlib>
using namespace std;
 class node
 {
    int info;
    node *ll, *rl;
    public: node()
            {
               rl=ll=NULL;
            }
    node *create(int, node*);
    void preorder(node*);
    void inorder(node*);
    void postorder(node*);
 };
 
 node *node::create(int item, node *root)
 {
   node *temp;
   temp=new node;
   temp->info=item;
   if(root==NULL)
   return temp;
   node *p, *c;
   p=root;
   c=root;
   while(c!=NULL)
   {
      p=c;
      if(item<c->info)
      c=c->ll;
      else
      c=c->rl;
   }
   if(item<p->info)
   p->ll=temp;
   else
   p->rl=temp;
   return root;
 }
 
 void node::preorder(node *root)
 {
    if(root==NULL)
    return;
    cout<<root->info<<"\t";
    preorder(root->ll);
    preorder(root->rl);
 }
 
 void node::inorder(node *root)
 {
    if(root==NULL) return;
    inorder(root->ll);
    cout<<root->info<<"\t";
    inorder(root->rl);
 }
 
 void node::postorder(node *root)
 {
    if(root==NULL) return;
    postorder(root->ll);
    postorder(root->rl);
    cout<<root->info<<"\t";
 }
 
 int main()
 {
   node *root=NULL;
   int ch, item;
   for(;;)
   {
      cout<<"\n 1.insert  2.display  3.exit\n";
      cout<<"enter your choice\n";
      cin>>ch;
      switch(ch)
      {
         case 1:cout<<"enter the item\n";
                cin>>item;
                root=root->create(item, root);
                break;
         case 2:cout<<"displaying preorder\n";
                root->preorder(root);
                cout<<"\n displaying inorder\n";
                root->inorder(root);
                cout<<"\n displaying postorder\n";
                root->postorder(root);
                break;
        default : exit(0);    
      }
   }
 }
