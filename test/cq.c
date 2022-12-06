#include<stdio.h>
#include<stdlib.h>

int max=5;
int q[10], front= -1, rear = -1;

void enqueue(){
    int n;
    if((rear%max)+1 == front){
        printf("\nQueue full ");
    }
    else{
        printf("Enter the element : ");
        scanf("%d", &n);
        if (rear == -1 && front == -1)
           rear = front = 1; 
        else
            rear++;
        q[rear] = n;
    }

}

void dequeue(){

}

void traversal(){
    if(front < rear){
        for(int i = front; i<=rear; i++){
            printf("%d",q[i]);
        }
    }
    else{
        for(int i=front; i<=max; i++ ){
            printf("%d\n", q[i]);
        }
        for(int i=0; i<=rear; i++){
            printf("%d\n",q[i]);
        }

    }

}

void main(){
    int c;
    while(1){
        printf("\n---------------------------\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&c);

        switch(c){
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: traversal();
                    break;
            case 4: exit(0);

            default: printf("\n Invalid Choice");
                    break;
        }
    }
}
