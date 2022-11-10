	#include<stdio.h>
	#include<stdlib.h>
	struct node{
		int data;
		struct node *next;
	}*head=NULL,*cur,*newnode;
	int count();
	int search(int);
	void delete_at_beginning();
	void delete_at_end();
	void delete_at_pos();
	void createnode(int data);
	void create_linkedlist();
	void insert_at_beginning();
	void insert_at_end();
	void insert_at_pos();
	void display();
	void main(){
		int choice1,data,choice2,s;
		printf("\nMENU:-\n\t1.Create linked list\n\t2.Insertion\n\t3.Deletion\n\t4.Display\n\t5.Count\n\t6.Search\n\t7.Exit");
		while(1){
			printf("\nEnter Choice:");
			scanf("%d",&choice1);
			switch(choice1){
				case 1:create_linkedlist();
						break;
				case 2:printf("Enter the data:");
					scanf("%d",&data);
					createnode(data);
					printf("\n\tMENU.2:-\n\t\t1.Insert at begin\n\t\t2.Insert at end\n\t\t3.Insert after nth node\n\tEnter Choice:");
					scanf("%d",&choice2);
					switch(choice2){
						case 1:insert_at_beginning();
							break;
						case 2:insert_at_end();
							break;
						case 3:insert_at_pos();
							break;
						default:printf("Invalid operation");
					}
					break;
				case 3:printf("\n\tMENU.3:-\n\t\t1.Deletion at begin\n\t\t2.Deletion at end\n\t\t3.Deletion at position\n\tEnter Choice:");
					scanf("%d",&choice2);
					switch(choice2){
						case 1:delete_at_beginning();
							break;
						case 2:delete_at_end();
							break;
						case 3:delete_at_pos();
							break;
						default:printf("Invalid operation");
					}
					break;
				case 4:display();
					break;
				case 5:printf("\nNumber of elements:%d",count());
					break;
				case 6:printf("\nEnter the number to be search:");
					scanf("%d",&s);
					(search(s)>0)?printf("\n%d founded at position %d",s,search(s)):printf("%d not found!",s);
					break;
				case 7:exit(0);
					break;
				default:printf("Invalid operation");
			}
		}
	}
	void createnode(int data){
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=data;
		newnode->next=NULL;
	}
	void create_linkedlist(){
		int n,d,i;
		printf("Enter the number of elements:");
		scanf("%d",&n);
		printf("Enter the elements:");
		for(i=0;i<n;++i){
			scanf("%d",&d);
			createnode(d);
			if(head==NULL){
				newnode->next=NULL;
				head=cur=newnode;
			}
			else{
				cur->next=newnode;
				cur=newnode;
			}

		}

		}
	void insert_at_beginning(){
		if(head==NULL){
			newnode->next=NULL;
			head=newnode;

		}
		else{
			newnode->next=head;
			head=newnode;
		}
        }
	void insert_at_end(){
		struct node *curr;
		for(curr=head;curr->next!=NULL;curr=curr->next);
		curr->next=newnode;
	}
	void insert_at_pos(){
		int pos,c,i;
		struct node *pre,*curr;
		printf("\nEnter the position:");
		scanf("%d",&pos);
		c=count();
		if(pos>c){
			printf("Invalid position");
		}
		else{
			for(i=1,curr=head;i<pos;++i,pre=curr,curr=curr->next);
			newnode->next=pre->next;
			pre->next=newnode;
		}
	}
	void delete_at_beginning(){
		struct node *t;
		t=head;
		if(head==NULL){
			printf("Linked List is empty");
		}
		else{
			head=head->next;
			printf("%d deleted",t->data);
			free(t);
		}

	}
	void delete_at_end(){
		struct node *t,*pre,*curr;
		if(head==NULL){
			printf("Linked List is empty");
		}
		else{
			for(curr=head;curr->next!=NULL;pre=curr,curr=curr->next);
			t=curr;
			pre->next=NULL;
			printf("%d deleted",t->data);
			free(t);
		}
		
	}
	void delete_at_pos(){
		int pos,c,i;
		struct node *pre,*t,*curr;
		if(head==NULL){
			printf("Linked List is empty");
		}
		else{
		printf("\nEnter the position:");
		scanf("%d",&pos);
		c=count();
		if(pos>c){
			printf("Invalid position");
		}
		else{
			for(i=1,curr=head;i<pos;++i,pre=curr,curr=curr->next);
			t=pre->next;
			pre->next=curr->next;
			printf("%d deleted",t->data);
			free(t);
		}
		}



	}
	int search(int data){
		int i;
		struct node *curr;
		for(i=1,curr=head;curr!=NULL;++i,curr=curr->next)
			if(curr->data==data)
				return i;
		return 0;
	}
	void display(){
		struct node *curr;
		printf("\nElements:");
		for(curr=head;curr!=NULL;curr=curr->next)
			printf("\t%d",curr->data);	
	}
	int count(){
		int i;
		struct node *curr;
		for(i=0,curr=head;curr!=NULL;++i,curr=curr->next);
		return i;
	}
