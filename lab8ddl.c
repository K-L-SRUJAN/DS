#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};


struct node *createnode(int f) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = f;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}


void insertatpos(struct node **head, int f, int pos) {
    struct node *nnode = createnode(f);

    if (*head == NULL) { 
        *head = nnode;
    } else if (pos == 1) { 
        nnode->next = *head;
        (*head)->prev = nnode;
        *head = nnode;
    } else { 
        struct node *temp = *head;
        int c = 1;

        while (c < pos - 1 && temp->next != NULL) { 
            c++;
            temp = temp->next;
        }

        if (temp->next == NULL && c < pos - 1) {
            printf("Invalid position!\n");
            free(nnode);
            return;
        }
        temp->prev->next=nnode;
        nnode->prev=temp->prev;
        nnode->next=temp;
        temp->prev=nnode;
        
    }
}


void deleteatpos(struct node **head, int val) {
    struct node *temp = *head;

    if (*head == NULL) { 
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL && temp->data != val) { 
        temp = temp->next;
    }

    if (temp == NULL) { 
        printf("Element not found!\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else { 
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}


void display(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    printf("Doubly Linked List Program\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1 -> Insert at position\n");
        printf("2 -> Delete by value\n");
        printf("3 -> Display list\n");
        printf("4 -> Exit\n");
        printf("Enter your choice: ");

        int choice, x, pos;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &x);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertatpos(&head, x, pos);
                break;

            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &x);
                deleteatpos(&head, x);
                break;

            case 3:
                printf("Current list: ");
                display(head);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
