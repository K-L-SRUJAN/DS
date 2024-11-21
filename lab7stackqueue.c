#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


struct node* createnode(int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}


void insertatbeg(struct node **head, int x) {
    struct node *newnode = createnode(x);
    newnode->next = *head;
    *head = newnode;
}
void insertatend(struct node **head, int x) {
    struct node *newnode = createnode(x);
    struct node *temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}


void deleteatbeg(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = *head;
        *head = temp->next;
        free(temp);
    }
}






void display(struct node *head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // printf("Linked List Operations:\n");
    struct node *head = NULL;

     while(1){
        printf("enter 1 -> stack : 2 -> queue\n");
        int i;
        scanf("%d",&i);
        while(1){
        if(i==1){
            printf("STACK !!!\n");
            printf("Enter 1-> push : 2->pop : 3-> display : otherwise exit\n");
            scanf("%d",&i);
            if(i==1){
                printf("Enter elemet :\n");
                int d;
                scanf("%d",&d);
                insertatbeg(&head,d);
            }
            else if(i==2){
                printf("deleting elemet :%d",head->data);
                deleteatbeg(&head);
            }
            else if(i==3){
                printf("printing element\n");
                display(head);
            }
            else {
                printf("exiting :)");
                break;
            }
        }
        
        else if(i==2){
            printf("queue !!!");
            printf("Enter 1-> push : 2->pop : 3-> display : otherwise exit\n");
            scanf("%d",&i);
            if(i==1){
                printf("Enter elemet :\n");
                int d;
                scanf("%d",&d);
                insertatend(&head,d);
            }
            else if(i==2){
                printf("deleting elemet :%d",head->data);
                deleteatbeg(&head);
            }
            else if(i==3){
                printf("printing element\n");
                display(head);
            }
            else {
                printf("exiting :)");
                break;
            }
        }
        }
    }

    
}
