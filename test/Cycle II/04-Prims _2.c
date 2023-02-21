#include<stdio.h>
#define INFINITY 999

int main()
{
    int n;
    printf("Enter No of Vertices : ");
    scanf("%d",&n);
    int G[n][n],selected[n],i,j,vertex;
    printf("Enter Cost Adjacency Matrix \n");
    for(i=0;i<n;i++) 
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
    for(i=0;i<n;i++) //Creating All 0 Array for Vertices
    {
        selected[i]=0;
    }

    printf("Enter Source Vertex : ");
    scanf("%d",&vertex);

    int x,y,sum=0,edge_count=0,min;
    selected[vertex]=1; //Making Selected Vertex Value as 1
    while(edge_count<n-1)
    {
        x=0,y=0,min=INFINITY;
        for(i=0;i<n;i++)
        {
            if(selected[i]==1)
            {
                for(j=0;j<n;j++)
                {
                    if(!selected[j] && G[i][j]!=0)
                    {
                        if(min>G[i][j])
                        {
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        sum=sum+G[x][y];
        printf("%d - %d Edge -- Cost %d\n",x,y,G[x][y]);
        selected[y]=1;
        edge_count++;
    }
    printf("Min Cost = %d",sum);
    return 0;
}