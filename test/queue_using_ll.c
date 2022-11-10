#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*front=NULL,*rear=NULL;
void enqueue();
void dequeue();
void display();
void main(){
    int c;
    printf("\n**MENU**\n\t1.ENQUEUE\n\t2.DEQUEUE\n\t3.DISPLAY\n\t4.QUIT");
    while(1){
        printf("\nEnter choice:");
        scanf("%d",&c);
        switch(c){
            case 1:enqueue();
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
        default:printf("Invalid Input");
        }
    }

}
void enqueue(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(front==NULL)
    {
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue(){
    struct node *t;
    if(front==NULL){
        printf("\nUnderflow!");
    }
    else{
        t=front;
        printf("%d deleted",t->data);
        front=front->next;
        free(t);
    }
}
void display(){
    struct node *cur;
    if(front==NULL)
        printf("\nNo elements");
    else{
        printf("\nElements:");
        for(cur=front;cur!=NULL;cur=cur->next)
            printf("%d\t",cur->data);
    }
    
}