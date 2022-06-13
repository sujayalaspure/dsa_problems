#include <iostream>
#include <vector>
using namespace std;


// Generate all N digit Numbers using only {1, 2}
void generateNNumbers(int arr[], int n, int idx) {
  if (n == idx) {
    for (int i = 0;i < n;i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
    return;
  }
  arr[idx] = 1;
  generateNNumbers(arr, n, idx + 1);
  arr[idx] = 2;
  generateNNumbers(arr, n, idx + 1);
}


// Check if there exist a subset with sum==k
/*
* array
* target Sum
* curr Sum
* index
*/

int checkSubset(int arr[], int n, int target, int current, int idx) {
  if (idx == n) {
    if (target == current) return 1;
    return 0;
  }

  current += arr[idx];
  int x = checkSubset(arr, n, target, current, idx + 1);

  current -= arr[idx];
  int y = checkSubset(arr, n, target, current, idx + 1);
  return x + y;

}

int main() {

  // int n = 5;
  // int arr[n];
  // generateNNumbers(arr, n, 0);

  int n = 6;
  int arr[] = { 10, 2, 7, 6, 1, 5 };
  int target = 8;
  int ans = checkSubset(arr, n, target, 0, 0);
  cout << ans << endl;


  return 0;
}