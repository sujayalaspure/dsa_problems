#include<iostream>
#include<vector>
#include<queue>

using namespace std;


vector <int> max_of_subarrays(int* arr, int n, int k) {
  queue<int> Q;
  vector<int> ans;
  int maxEle = INT_MIN;
  for (int i = 0;i < k;i++) {
    maxEle = max(maxEle, arr[i]);
  }
  Q.push(maxEle);
  ans.push_back(Q.back());

  int i = 1, j = k;
  while (j < n) {
    if (arr[i - 1] == Q.front()) Q.pop();
    if (arr[j] >= Q.back()) Q.push(arr[j]);
    ans.push_back(Q.back());
    i++;
    j++;
  }
  return ans;

}

int main() {

  int N = 9, K = 3;
  int  arr[] = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
  vector <int> ans = max_of_subarrays(arr, N, K);
  for (int a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}



// Approach 1
/*
 - Use sliding window of size k
 - on every interation, traverse the window and get the max
 - Time: O(n*k) Size: O(1)
*/

// Approach 2
/**
 * we will use Queue here to keep track of largest so far
 * for the first window manually find the max and add in Q.
 * for subsequent windows
 *  if(back < coming) add in Q
 *  if(front == leaving [0]) remove from Q
 *
 * at any point Q back is largest.
*/