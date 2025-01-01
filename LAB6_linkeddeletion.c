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


void deleteatbeg(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = *head;
        *head = temp->next;
        free(temp);
    }
}


void deleteatend(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    struct node *prev = NULL;


    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }


    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}


void deleteatpos(struct node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = *head;
    struct node *prev = NULL;


    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    int count = 1;
    while (temp != NULL && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }


    if (temp == NULL) {
        printf("Position is out of range\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
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
    printf("Linked List Operations:\n");
    struct node *head = NULL;

    insertatbeg(&head, 10);
    insertatbeg(&head, 20);
    insertatbeg(&head, 30);
    insertatbeg(&head, 40);
    insertatbeg(&head, 50);

    printf("Initial List: ");
    display(head);

    deleteatbeg(&head);
    printf("After deleting at the beginning: ");
    display(head);

    deleteatend(&head);
    printf("After deleting at the end: ");
    display(head);

    deleteatpos(&head, 2);
    printf("After deleting at position 2: ");
    display(head);

    return 0;
}
