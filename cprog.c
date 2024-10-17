#include<stdio.h>
#define n 5
int a[n];
int f=-1;
int r=-1;

int x;

void enque(int x){
    if (r == n-1){
        printf("The queue is full\n");
    }
    else if(f == -1 && r == -1){
        f = 0;
        r = 0;
        a[r] = x;
    }
    else{
        r++;
        a[r] = x;
    }
}

void dque(){
    if(f == -1 && r == -1){
        printf("Queue is empty\n");
    }
    else if(f == r){
        printf("Deleting last element: %d\n", a[f]);
        f = -1;
        r = -1;
    }
    else{
        printf("Deleting: %d\n", a[f]);
        f++;
    }
}

void display(){
    if(f == -1 && r == -1){
        printf("Queue is empty\n");
    }
    else {
        printf("-------------Printing current elements-------------\n");
        for (int i = f; i <= r; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

int main(){
    printf("Queue operation\n");

    int g = 0;
    while (g == 0) {
        printf("Enter 1->Add | 2->Delete | 3->Display | Any other key->Exit: ");
        int s;
        scanf("%d", &s);

        if(s == 1){
            printf("Enter the element: ");
            scanf("%d", &x);
            enque(x);
        }
        else if(s == 2){
            dque();
        }
        else if(s == 3){
            display();
        }
        else{
            printf("Exiting :)\n");
            break;
        }
    }

    return 0;
}
