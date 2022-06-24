#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArray(vector<int> nums1, vector<int> nums2) {
  int i = 0, p1 = 0, p2 = 0;
  int n = nums1.size();
  int m = nums2.size();
  vector<int> newArr(n + m);

  while (p1 < n && p2 < m && i < n + m) {
    // cout << nums1[p1] << " " << nums2[p2] << endl;
    if (nums1[p1] < nums2[p2]) {
      newArr[i] = nums1[p1];
      p1++;
      i++;
    }
    else {
      newArr[i] = nums2[p2];
      i++;
      p2++;
    }
  }
  while (p1 < n) {
    newArr[i] = nums1[p1];
    p1++;
    i++;
  }
  while (p2 < m) {
    newArr[i] = nums2[p2];
    i++;
    p2++;
  }

  return newArr;

}


int main() {

  vector<int> nums1 = { 1, 2 }, nums2 = { 3, 4 };

  vector<int> arr = mergeSortedArray(nums1, nums2);

  for (int a : arr) cout << a << " ";
  cout << endl;

  int n = arr.size();
  if (n % 2 == 1) {
    int val = arr[n / 2];
    cout << val << endl;
  }
  else {
    int half = n / 2;
    double aa = ((double)arr[half - 1] + (double)arr[half]) / 2;
    cout << arr[half] << " " << aa << endl;
  }


  return 0;
}