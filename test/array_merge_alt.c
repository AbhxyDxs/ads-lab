#include<stdio.h>
int main()
{
 int a[20],b[20],c[40],i,j,n;
 printf("Enter No. of Elements in 1st Array : ");
 scanf("%d",&n);
 printf("Enter Elements of 1st Array : ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("Enter %d Elements of 2nd Array : ",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&b[i]);
 }
 
 for(i=0,j=0;i<n;i++,j=j+2)
 {
  c[j]=a[i]; 
 }
 for(i=0,j=1;i<n;i++,j=j+2)
 {
  c[j]=b[i];
 }
 printf("Arrays After Merging (Alternate Positions -> A1,B1,A2,B2....) \n");
 for(i=0;i<n+n;i++)
 {
  printf("%d ",c[i]);
 }
 return 0;
} 

