#include<stdio.h>
int stack[20],slctn,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()
{
 top=-1;
 printf("\n Enter the size of Stack (Max-20) : ");
 scanf("%d",&n);
 printf("\nStack Operations");
 printf("\n1.Push\n2.Pop\n3.Display\n4.Quit");
 do
 {
  printf("\n Enter the Selection : ");
  scanf("%d",&slctn);
  switch(slctn)
  {
   case 1:
   {
    push();
    break;
   }
   case 2:
   {
    pop();
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


void push()
{
 if(top>=n-1)
 {
  printf("\nSTACK Overflow!");
 }
 else
 {
  printf(" Enter an item to be Pushed:");
  scanf("%d",&x);
  top++;
  stack[top]=x;
 }
}


void pop()
{
 if(top<=-1)
 {
  printf("\nStack Underflow!");
 }
 else
 {
  printf("\n%d Popped!",stack[top]);
  top--;
 }
}


void display()
{
 if(top>=0)
 {
  printf("\n The elements in STACK \n");
  for(i=top; i>=0; i--)
  printf("\n%d",stack[i]);
  printf("\n Press Next Choice");
 }
 else
 {
  printf("\n The STACK is empty!");
 }
}

