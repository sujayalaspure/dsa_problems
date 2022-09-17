#include <iostream>
#include <vector>
using namespace std;


// 3 1 3 2 2 

void findElement(vector<int> arr) {
  int size = arr.size();
  int finalXor = arr[0];
  for (int i = 1;i < size;i++) {
    finalXor = finalXor ^ arr[i];
  }

  cout << finalXor << endl;
}

// O(n) 


// n = 5

// [1, 0, 3, 5, 4, 0, 1, 2, 3, 4, 5]

void findMissing(int n, vector<int> arr) {
  int size = arr.size();
  int missingEle = arr[0];
  for (int i = 1;i < size;i++) {
    missingEle = missingEle ^ arr[i];
  }

  for (int i = 0;i <= n;i++) {
    missingEle = missingEle ^ i;
  }

  cout << missingEle << endl;
}


int main() {

  vector<int> arr = { 0,1,2,3,4 };
  int n = 5;
  findMissing(n, arr);

  return 0;
}