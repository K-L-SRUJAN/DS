
#include <stdio.h>
void movez(int* nums, int siz){
    int i=0;
    for(int j=0;j<siz;j++){
        if(nums[j]!=0){
            nums[i++]=nums[j];
        }
    }
    for(;i<siz;i++){
        nums[i]=0;
    }
}
int main() {
    int nums[]={0,1,0,4,0,5};
    int i=0;
    int size=sizeof(nums)/sizeof(nums[0]);
    movez(nums,size);
    for(int l=0;l<size;l++){
        printf("%d",nums[l]);
    }
    
    return 0;
}
