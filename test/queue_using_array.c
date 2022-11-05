#include<stdio.h>
int queue[20],slctn,i,n,x;
int front=-1,rear=-1;
void insert(void);
void delete(void);
void display(void);
int main()
{
 printf("Enter Queue Size (Max-20) : ");
 scanf("%d",&n);
 printf("\nQueue Operations");
 printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Quit");
 do
 {
  printf("\nEnter the Selection : ");
  scanf("%d",&slctn);
  switch(slctn)
  {
   case 1:
   {
    insert();
    break;
   }
   case 2:
   {
    delete();
    break;
   }
   case 3:
   {
    display();
    break;
   }
   case 4:
   {
    printf("\nQuit....! \n");
    break;
   }
   default:
   {
    printf ("\nInvalid Input\n\nSelect one from (1/2/3/4)");
   }
  }
 }
 while(slctn!=4);
 return 0;
}


void insert()
{
 if(rear==n-1)
 {
  printf("\nQueue is Full!");
 }
 else
 {
  if(front==-1)
  {
   front=0;
  }
  printf("Enter an item to be inserted:");
  scanf("%d",&x);
  rear=rear+1;
  queue[rear]=x;
 }
}


void delete()
{
 if(front==-1 || front>rear)
 {
  printf("\nQueue Underflow!");
 }
 else
 {
  printf("\n%d Deleted!",queue[front]);
  front=front+1;
 }
}


void display()
{
 if(front==-1)
 {
  printf("\nThe Queue is empty!");
 }
 else
 {
  printf("\nThe elements in Queue \n");
  for(i=front; i<=rear; i++)
  {
   printf("%d ",queue[i]);
  }
  printf("\nPress Next Choice");
 } 
}

