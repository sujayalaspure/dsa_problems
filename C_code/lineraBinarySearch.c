#include <stdio.h>

int linearSearch(int arr[], int element, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == element)
    {
      return i;
    }
  }

  return -1;
}

int binarySearch(int arr[], int element, int size)
{
  int low, mid, high;

  low = 0;
  high = size - 1;

  while (low <= high)
  {
    mid = (low + high) / 2;
    printf("%d\n", mid);
    if (arr[mid] == element)
    {
      return mid;
    }
    else if (arr[mid] < element)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return -1;
}

int main(int argc, char *argv[])
{
  // Array for Linear Search
  // int arr[] = {1, 2, 3, 58, 4, 86, 9, 4, 846, 84, 684, 68, 46};
  // int element = 46;

  // Array for Binary Search
  int arr[] = {-1, 1, 3, 5, 9, 12};
  int element = 1;
  int size = sizeof(arr) / sizeof(int);
  int searchIndex = binarySearch(arr, element, size);
  printf("Element :>> %d Index:>> %d ", element, searchIndex);
  return 0;
}
