#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* create(struct node* head){
	char ch;
	struct node* newnode,*temp;
	do{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data: ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL){
			head=newnode;	
		}
		else
		{
		 temp=head;
		 while(temp->next!=NULL){
		 	temp=temp->next;
		 }	
		 temp->next=newnode;
		}
		printf("enter choice:(y/n) ");
	    scanf(" %c",&ch); 
	}while(ch=='y'||ch=='Y');    
	return head;
}
void display(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main(){
	struct node* head=NULL;
	struct node* HEAD;
	char ch;
	printf("enter choice:(y/n) ");
	scanf(" %c",&ch);
    if(ch=='y'|| ch=='Y'){
    HEAD=create(head);
    display(HEAD);
}
else
printf("linked list is empty");
return 0;
}
    