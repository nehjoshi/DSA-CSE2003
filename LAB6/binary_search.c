#include <stdio.h>
int iterativeBinarySearch(int array[], int start_index, int end_index, int element){
   while (start_index <= end_index){
      int middle = start_index + (end_index- start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] < element)
         start_index = middle + 1;
      else
         end_index = middle - 1;
   }
   return -1;
}
int main(void){
   printf("Enter size of array\n");
    int n;
    scanf("%d", &n);
    int array[n];
    printf("Enter %d integers\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
   printf("Enter key to search\n");
    int element;
    scanf("%d", &element);
   int found_index = iterativeBinarySearch(array, 0, n-1, element);
   if(found_index == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at index : %d",found_index);
   }
   return 0;
}