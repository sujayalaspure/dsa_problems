#include <stdio.h>
#include <stdlib.h>

void printArray(int *A, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void bubbleSort(int *A, int n)
{
  int temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (A[j] > A[j + 1])
      {
        temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
      }
    }
  }
}

void bubbleSortAdaptive(int *A, int n)
{
  int temp;
  int isSorted = 0;
  for (int i = 0; i < n - 1; i++)
  {
    printf("for Pass :>> %d\n", i + 1);
    isSorted = 1;
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (A[j] > A[j + 1])
      {
        temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
        isSorted = 0;
      }
    }
    if (isSorted)
    {
      return;
    }
  }
}
int main(int argc, char *argv[])
{
  int A[] = {7, 11, 9, 2, 17, 4};
  // int A[] = {1, 2, 3, 4, 5, 6};
  int S = 6;

  printArray(A, S);
  bubbleSortAdaptive(A, S);
  printArray(A, S);

  return 0;
}
