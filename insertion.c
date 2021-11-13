#include <stdio.h>

void display (int arr[], int n) {

for (int i = 0; i < n; i++)
{
  printf("%d ", arr[i]);
}
printf("\n");
}

int IndInsert (int arr[], int capacity, int size, int element, int index) {
   if(size>=capacity){
     return -1;
   }

   for (int i = size-1; i >=index; i--)
   {
     arr[i + 1] = arr[i];
   }
   arr[index] = element;

   return 1;
}


int main (int argc, char *argv[]) {

  int arr[100] = {1, 3, 9, 58};
  int size = 110, capacity = 100, element= 45, index = 2;
  display(arr, 4);

  if (IndInsert(arr, capacity, size, element, index)==1)
  {
  size++;
  display(arr, 5);
    /* code */
  }
  else
  {
printf("No Update");
  }
  

  return 0;
}
