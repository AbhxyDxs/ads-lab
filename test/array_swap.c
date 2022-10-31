#include<stdio.h>
int main()
{
 int a[20],b[20],temp[20],i,n;
 printf("Enter No. of Elements of 1st Array : ");
 scanf("%d",&n);
 printf("Enter %d Elements of 1st Array : ",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("Enter %d Elements of 2nd Array : ",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&b[i]);
 }
 for(i=0;i<n;i++)
 {
  temp[i]=a[i];
  a[i]=b[i];
  b[i]=temp[i];
 }
 printf("\n1st Array After Swapping \n");
 for(i=0;i<n;i++)
 {
  printf("%d ",a[i]);
 }
 printf("\n2nd Array After Swapping \n");
 for(i=0;i<n;i++)
 {
  printf("%d ",b[i]);
 }
 return 0;
}
