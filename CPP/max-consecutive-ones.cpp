#include <iostream>
#include <vector>
#include<string.h>
using namespace std;


int maxConsecutiveCharacters() {
  string s = "abbcccddddeeeeedcba";
  int arr[26];
  memset(arr, 0, sizeof(arr));
  char prev = 'A';
  int ans = 1;
  for (int i = 0;i < s.size();i++) {
    int idx = s[i] - 'a';
    if (prev == s[i]) {
      arr[idx]++;
      ans = max(ans, arr[idx]);
      // cout << s[i] << " " << idx << " " << ans << endl;
    }
    else {
      arr[idx] = 1;
    }
    prev = s[i];
  }


  return ans;
}

int maxConsecutiveOnes3() {
  vector<int> nums = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
  int k = 3;
  int n = nums.size();
  int p1 = 0, p2 = 0, ans = 0, cnt = 0;
  for (;p2 < n;p2++) {
    if (nums[p2] == 1) ans = max(ans, p2 - p1 + 1);
    else if (nums[p2] == 0 && cnt < k) {
      cnt++;
      ans = max(ans, p2 - p1 + 1);
    }
    else if (nums[p2] == 0 && cnt >= k) {
      cnt++;
      while (cnt > k) {
        if (nums[p1] == 0) cnt--;
        p1++;
      }
    }
  }

  return ans;
}

int main() {

  cout << maxConsecutiveCharacters() << endl;

  return 0;
}