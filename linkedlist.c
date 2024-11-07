
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    
};

struct node * createnode(int data){
  struct node* newnode=  (struct node* )malloc(sizeof (struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void insertatbeg(struct node **head, int data){
    struct node* newnode=createnode(data);
    newnode->next=*head;
    *head=newnode;
}

void insertatend(struct node** head,int data){
    struct node * newnode=createnode(data);
    struct node* temp=* head;
    if(*head==NULL){
        *head=newnode;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void display(struct node * head){
    struct node* temp= head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
}

int main() {
    struct node *head=NULL;
    insertatbeg(&head,20);
    display(head);
}













