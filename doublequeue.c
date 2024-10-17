#include<stdio.h>
#define n 5
int deque[n];
int front = -1;
int rear = -1;

int isFull() {
    return (front == 0 && rear == n-1) || (front == rear+1);
}

int isEmpty() {
    return front == -1;
}

void insertFront(int x) {
    if (isFull()) {
        printf("D queue is full\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = n - 1;
        } else {
            front--;
        }
        deque[front] = x;
        printf("%d inserted at front\n", x);
    }
}

void insertRear(int x) {
    if (isFull()) {
        printf("d queue is full\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == n - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = x;
        printf("%d inserted at rear\n", x);
    }
}

void deleteFront() {
    if (isEmpty()) {
        printf("D queue is empty\n");
    } else {
        printf("Deleting %d from front\n", deque[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == n - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("D queue is empty\n");
    } else {
        printf("Deleting %d from rear\n", deque[rear]);
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = n - 1;
        } else {
            rear--;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("D queue is empty\n");
    } else {
        printf("D queue elements are: ");
        int i = front;
        while (i != rear) {
            printf("%d ", deque[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", deque[rear]);
    }
}

int main() {
    int choice, x;
    while (1) {
        printf("\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                printf("Enter element to insert at rear: ");
                scanf("%d", &x);
                insertRear(x);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
