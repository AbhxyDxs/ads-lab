#include <stdio.h>

int main()
{
 int n,i;
 printf("BIT STRING of Even Numbers \n\n");
 printf("Conditional Set = {x:x is an even number} , x belongs to Z \n\n");
 printf("Number of Elements in Set : ");
 scanf("%d",&n);
 int a[n],bs[n];
 printf("Enter Set Elements : ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
  if (a[i]%2==0)
  {
   bs[i]=1;
  }
  else
  {
   bs[i]=0;
  }
 }
 printf("\nBit String = ");
 for(i=0;i<n;i++)
 {
  printf(" %d ",bs[i]);
 }
 printf("\nEven Elements = ");
 for(i=0;i<n;i++)
 {
  if(bs[i]==1)
  {
   printf(" %d ",a[i]);
  }
 }
 return 0;
}
