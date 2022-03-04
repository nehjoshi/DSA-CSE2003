#include <stdio.h>

int linear_search(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}
int main(){
    printf("Enter size of array\n");
    int size;
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d integers\n", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search\n");
    int key;
    scanf("%d", &key);
    int index = linear_search(arr, size, key);
    if(index == -1){
        printf("Key not found");
    }
    else{
        printf("Key found at index %d", index);
    }
}