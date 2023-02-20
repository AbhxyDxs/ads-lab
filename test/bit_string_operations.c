#include<stdio.h>

int a[20],b[20],choice,i,n;
void bitunion();
void intersection();
void a_diff_b();
void b_diff_a();

int main()
{
    printf("Enter Number of Elements [MAX 20] : ");
    scanf("%d",&n);
    printf("Enter Bit String 1 : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter Bit String 2 : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }

    do{
        printf("\nBitString Operations\n");
        printf("1.Union\n2.Intersection\n3.A-B\n4.B-A\n5.Exit\n");
        printf("Enter Selection : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                bitunion();
                break;
            case 2:
                intersection();
                break;
            case 3:
                a_diff_b();
                break;
            case 4:
                b_diff_a();
                break;
            case 5:
                printf("\nExiting..!\n");
                break;
            default:
                printf("\nInvalid Selection\n");
                break;
        }
    }while(choice!=5);

    return 0;
}

void bitunion()
{
    int u[20];
    for(i=0;i<n;i++)
    {
        u[i]=a[i] | b[i];
    }
    printf("\nA Union B is\n");
    for(i=0;i<n;i++)
    {
        printf("%d",u[i]);
    }
}

void intersection()
{
    int inter[20];
    for(i=0;i<n;i++)
    {
        inter[i]=a[i] & b[i];
    }
    printf("\nA Intersection B is\n");
    for(i=0;i<n;i++)
    {
        printf("%d",inter[i]);
    }
}

void a_diff_b()
{
    int a_b[20];
    for(i=0;i<n;i++)
    {
        a_b[i]=a[i] & ~b[i];
    }
    printf("\nA-B is\n");
    for(i=0;i<n;i++)
    {
        printf("%d",a_b[i]);
    }
}

void b_diff_a()
{
    int b_a[20];
    for(i=0;i<n;i++)
    {
        b_a[i]=b[i] & ~a[i];
    }
    printf("\nB-A is\n");
    for(i=0;i<n;i++)
    {
        printf("%d",b_a[i]);
    }
}