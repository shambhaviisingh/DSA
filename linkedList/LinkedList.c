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
struct node* iab(struct node* head){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nInsert at beginning ");
	printf("enter data: ");
	scanf("%d",&newnode->data);
	if(head==NULL){
		newnode->next=NULL;
		head=newnode;
		return head;
	}
	else{
	newnode->next=head;
	head=newnode;
	return head;
}
}
struct node* iase(struct node* head){
	if(head==NULL)
	return head;
	else{
	
	int value;
	printf("enter specified element: ");
	scanf("%d",&value);
	struct node* temp=head;
	while(temp!=NULL && temp->data!=value){
		temp=temp->next;
		
	}
	if(temp==NULL){
		printf("Specific element does not exist; the new data element cannot be inserted.\n");
	}
	else{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nInsert after specified element");
	printf("\nenter data: ");
	scanf("%d",&newnode->data);	
	newnode->next=temp->next;
	temp->next=newnode;
	}
	return head;
}
}
struct node* ibse(struct node* head){
	struct node* prev, *curr;
	if(head==NULL)
	return head;
	prev=head;
	curr=head->next;

	int value;
	printf("enter specified element: ");
	scanf("%d",&value);
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data: ");
	scanf("%d",&newnode->data);	
	if(head->data==value){
		newnode->next=head;
		head=newnode;
		return head;
	}
	else{
		while(curr!=NULL && curr->data!=value){
			prev=curr;
			curr=curr->next;
		}
		if(curr==NULL)
		printf("Specific element does not exist; the new node with the data element cannot be inserted.\n" );
		else{
		
		prev->next=newnode;
		newnode->next=curr;
	}
	}
		return head;
}
struct node* del(struct node* head){
	if(head==NULL)
	return head;
	struct node*prev=head;
	struct node*temp=prev->next;
	int value;
	printf("enter node to be deleted: ");
	scanf("%d",&value);
	
	if(head->data==value){
	head=temp;
	free(prev);
	return head;
	}
	else{
		while(temp!=NULL && temp->data!=value){
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		printf("element not found");
		else
		prev->next=temp->next;
		free(temp);
	}
	return head;
}

int main(){
	struct node* head=NULL;
	char ch;
	printf("enter choice(y/n): ");
	scanf(" %c",&ch);
    if(ch=='y'|| ch=='Y'){
    head=create(head);
    display(head);
}
else
printf("linked list is empty");
/*head=iab(head);
display(head);*/
/*head=iase(head);
display(head);*/
/*head=ibse(head);
display(head);*/
head=del(head);
display(head);
return 0;
}
    