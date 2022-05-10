#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkAll(vector<int> arr, int n, int B, int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  if (sum > B)
    return false;
  for (int i = 1; i < n - size + 1)
  {
    sum -= arr[i - 1] + arr[i + k]
  }
}

int main()
{
  vector<int> A = {1, 2, 3, 4, 5};
  int B = 10;
  int n = A.size();

  int low = 0, high = n - 1;
  while (low < high)
  {
    int mid = low + (high - low) / 2;
  }
  return 0;
}