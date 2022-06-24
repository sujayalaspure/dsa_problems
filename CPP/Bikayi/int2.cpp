
// =====================
// A peak element is an element that is strictly greater than its neighbors.

// Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞.

// Constraints:

// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// nums[i] != nums[i + 1] for all valid i.

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

// [1,2,1,3,5,6,4]

#include <iostream>
#include <vector>

using namespace std;

int solve() {
  vector<int> A = { 1 };
  int n = A.size();

  int left = 0, right = n - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (mid == 0 && A[mid] > A[mid + 1]) {
      return 0;
    }
    if (mid == n - 1 && A[mid - 1] > A[mid])
      return n - 1;

    if ((A[mid - 1] < A[mid]) && (A[mid] > A[mid + 1])) {
      return mid;
    }
    else {
      if (A[mid - 1] > A[mid + 1]) {
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }
  }
  return 0;
}

int main() {

  int ans = solve();
  cout << ans << endl;
  return 0;
}