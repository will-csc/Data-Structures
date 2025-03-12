#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 0

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binary_search(int arr[], int target, int high, int low){
    if(low > high){ return -1; }
    
    int mid = (low + high) / 2;
    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] > target){
        return binary_search(arr,target,mid-1,low);
    }else{
        return binary_search(arr,target,high,mid+1);
    }
}

void generate_arr(int arr[],int size){
    int i = 0;
    
    while(i < size){
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        i++;
    }
}

void printArray(int arr[]){
    int i = 0;
    
    printf("\nArray generated: [");
    while(arr[i] != '\0'){
        if(arr[i+1] == '\0'){
            printf("%d",arr[i]);
            break;
        }
        printf("%d,",arr[i]);
        i++;
    }
    printf("]");
}

int main(){
    int target,size;

    printf("Enter a target (0-100): ");
    scanf("%d",&target);
    printf("Enter a size: ");
    scanf("%d",&size);
    
    int arr[size];
    arr[size] = '\0';
    
    generate_arr(arr,size);
    qsort(arr, size, sizeof(int), compare);
    printArray(arr);
    
    int idx = binary_search(arr,target,size-1,0);
    if(idx > 0){
        printf("\nYour target was found at %d",idx);
    }else{
        printf("\nYour target was not found");
    }
}