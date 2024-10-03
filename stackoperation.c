#include <stdio.h>
#define size 5

int arra[size];
int top=-1;
int x;
int main(){
    int v=0;
    while(v==0){
        printf("\nenter 1 for push, 2 for pop, 3 for display : ");
    int d;
    scanf("%d",&d);
    if(d==1){
        if(top>=size){
            printf("stack full\n");
            printf("");
        }1
        top=top+1;
        printf("ENTER THE NUMBER :");
        printf("");
        scanf("%d",&x);
        arra[top]=x;
        printf("new element added :%d\n",arra[top]);
        printf("");
    }
    else if(d==2){
        if(top==-1){
            printf("empty stack");
            printf("");
        }
        printf("the deleted element is :%d\n",arra[top]);
        printf("");
        top=top-1;
        
    }
    else if(d==3){
        for(int i=0;i<size;i++){
            if(top==-1){
                break;
            }
            printf("%d",arra[i]);
            printf("");
        }
    }
    else{
        break;
    }
    }
}
