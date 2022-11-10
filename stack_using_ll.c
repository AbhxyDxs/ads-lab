#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL,*newnode;
void push();
void pop();
void display();
void main(){
    int c;
    while(1){
        printf("\n**MENU**\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.QUIT\nEnter choice:");
        scanf("%d",&c);
        switch(c){
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
        default:printf("Invalid Input!");
        }
    }

}
void push(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}
void pop(){
    struct node *t;
    if(top==NULL){
        printf("\nUnderflow!");
    }
    else{
        t=top;
        top=top->next;
        free(t);
    }
}
void display(){
    struct node *cur;
    if(top==NULL)
        printf("\nNo elements");
    else{
        printf("\nElements:");
        for(cur=top;cur!=NULL;cur=cur->next)
            printf("%d\t",cur->data);
    }
    
}