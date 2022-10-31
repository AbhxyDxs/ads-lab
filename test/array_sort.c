#include<stdio.h>
int main()
{
 int a[20],i,j,temp,n;
 printf("Enter No. of Elements : ");
 scanf("%d",&n); 
 printf("Enter Array Elements : ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(a[i]>a[j])
   {
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
   }
  }
 }
 printf("Sorted Array \n");
 for(i=0;i<n;i++)
 {
  printf("%d ",a[i]);
 }
 return 0;
}
