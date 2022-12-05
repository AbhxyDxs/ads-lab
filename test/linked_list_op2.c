#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
}*head=NULL,*cur,*newnode;
int count();
int search(int);
void delete_at_beginning();
void delete_at_end();
void delete_at_pos();
void createnode(int data);
void create_linkedlist();
void insert_at_beginning();
void insert_at_end();
void insert_at_pos();
void display();

void main()
{
 int choice1,data,choice2,s;
 printf("\nLINKED LIST\n\n1.Create LL\n2.Insertion\n3.Deletion\n4.Display\n5.Count\n6.Search\n7.Exit");
 while(1)
 {
  printf("\nEnter An Option : ");
  scanf("%d",&choice1);
  switch(choice1)
  {
   case 1:create_linkedlist();
   break;
   case 2:printf("Enter Element : ");
   scanf("%d",&data);
   createnode(data);
   printf("\nWhere to Insert ?\n\n1.Beginning\n2.End\n3.As nth Node\n\nEnter A Selection : ");
   scanf("%d",&choice2);
   switch(choice2)
   {
    case 1:insert_at_beginning();
    break;
    case 2:insert_at_end();
    break;
    case 3:insert_at_pos();
    break;
    default:printf("Invalid Selection!!");
   } 
   break;
   case 3:printf("\nWhere to Delete ?\n\n1.Beginning\n2.End\n3.nth Position\n\nEnter A Selection : ");
   scanf("%d",&choice2);
   switch(choice2)
   {
    case 1:delete_at_beginning();
    break;
    case 2:delete_at_end();
    break;
    case 3:delete_at_pos();
    break;
    default:printf("Invalid Selection!!");
   }
   break;
   case 4:display();
   break;
   case 5:printf("\nNumber of Elements : %d",count());
   break;
   case 6:printf("\nEnter Element to Search : ");
   scanf("%d",&s);
   (search(s)>0)?printf("\n%d Found at Position %d",s,search(s)):printf("%d Not found!",s);
   break;
   case 7:exit(0);
   break;
   default:printf("Invalid Selection!!");
  }
 }
}
	

void createnode(int data)
{
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=data;
 newnode->next=NULL;
}

void create_linkedlist()
{
 int n,d,i;
 printf("Enter No of Elements to be Added : ");
 scanf("%d",&n);
 printf("Enter Elements : ");
 for(i=0;i<n;++i)
 {
  scanf("%d",&d);
  createnode(d);
  if(head==NULL)
  {
   newnode->next=NULL;
   head=cur=newnode;
  }
  else
  {
   cur->next=newnode;
   cur=newnode;
  }
 }
}

void insert_at_beginning()
{
 if(head==NULL)
 {
  newnode->next=NULL;
  head=newnode;
 }
 else
 {
  newnode->next=head;
  head=newnode;
 }
}

void insert_at_end()
{
 struct node *curr;
 for(curr=head;curr->next!=NULL;curr=curr->next);
 curr->next=newnode;
}

void insert_at_pos()
{
 int pos,c,i;
 struct node *pre,*curr;
 printf("\nEnter Position (n) : ");
 scanf("%d",&pos);
 c=count();
 if(pos>c)
 {
  printf("Invalid Position!!");
 }
 else
 {
  for(i=1,curr=head;i<pos;++i,pre=curr,curr=curr->next);
  newnode->next=pre->next;
  pre->next=newnode;
 }
}

void delete_at_beginning()
{
 struct node *t;
 t=head;
 if(head==NULL)
 {
  printf("Linked List is Empty");
 }
 else
 {
  head=head->next;
  printf("%d Deleted",t->data);
  free(t);
 }
}

void delete_at_end()
{
 struct node *t,*pre,*curr;
 if(head==NULL)
 {
  printf("Linked List is Empty");
 }
 else
 {
  for(curr=head;curr->next!=NULL;pre=curr,curr=curr->next);
  t=curr;
  pre->next=NULL;
  printf("%d Deleted",t->data);
  free(t);
 }
}

void delete_at_pos()
{
 int pos,c,i;
 struct node *pre,*t,*curr;
 if(head==NULL)
 {
  printf("Linked List is Empty");
 }
 else
 {
  printf("\nEnter Position (n) : ");
  scanf("%d",&pos);
  c=count();
  if(pos>c)
  {
   printf("Invalid Position");
  }
  else
  {
   for(i=1,curr=head;i<pos;++i,pre=curr,curr=curr->next);
   t=pre->next;
   pre->next=curr->next;
   printf("%d Deleted",t->data);
   free(t);
  }
 }
}

int search(int data)
{
 int i;
 struct node *curr;
 for(i=1,curr=head;curr!=NULL;++i,curr=curr->next)
 if(curr->data==data)
 {
  return i;
 }
 return 0;
}

void display()
{
 struct node *curr;
 printf("\nElements : ");
 for(curr=head;curr!=NULL;curr=curr->next)
 printf("   %d",curr->data);	
}

int count()
{
 int i;
 struct node *curr;
 for(i=0,curr=head;curr!=NULL;++i,curr=curr->next);
 return i;
}
