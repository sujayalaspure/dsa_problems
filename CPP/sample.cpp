#include <iostream>
#include <vector>
#include<string.h>
#include<unordered_map>
using namespace std;


void alienWords() {
  string order = "hlabcdefgijkmnopqrstuvwxyz";
  unordered_map<char, char> mp;
  for (int i = 0;i < 26;i++) {
    char a = i + 'a';
    mp[a] = order[i];
  }

  vector<string>words = { "hello", "leetcode" };

  for (string& a : words) {
    for (char& b : a) b = mp[b];
  }

  for (string a : words) cout << a << endl;
}


int findDuplicate(vector<int> nums) {
  int slow = nums[0], fast = nums[0];
  // while (fast != slow) {
  //   slow = nums[slow];
  //   fast = nums[nums[fast]];
  // }
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
    cout << slow << " " << fast << endl;
  } while (fast != slow);

  slow = nums[0];
  cout << "---" << endl;

  while (fast != slow) {
    fast = nums[fast];
    slow = nums[slow];
    cout << slow << " " << fast << endl;

  }

  return slow;
}


void findMissingandRepeating() {
  vector<int> A = { 3, 1, 2, 5, 3 };
  int repeating = A[0];
  for (int i = 1;i < A.size();i++) {
    repeating ^= A[i];
  }
  for (int i = 1;i <= A.size();i++) {
    repeating ^= i;
  }
  for (int i = 1;i <= A.size();i++) {
    repeating ^= i;
  }
  cout << repeating << endl;
  // int missing = repeating;
  // for (int i = 1;i <= A.size();i++) {
  //   missing^ i;

  // }
  // missing ^= repeating;
  // return { missing, repeating };
}


int main() {


  // cout << findDuplicate({ 1,3,4,2,2 }) << endl;

  findMissingandRepeating();



  // alienWords();
  // vector<vector<int>> matrix = { {1, -1}, {-1, 1} };
  // int k = 0;
  // int n = matrix.size(), m = matrix[0].size();
  // vector<vector<int>> pf(n, vector<int>(m, 0));
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     pf[i][j] = matrix[i][j];
  //     if (j > 0) pf[i][j] += pf[i][j - 1];
  //   }
  // }
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     pf[i][j] = pf[i][j];
  //     if (i > 0) pf[i][j] += pf[i - 1][j];
  //   }
  // }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << pf[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // int cnt = 0;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     int res = pf[i][j];
  //     if (i > 0) res -= pf[i - 1][j];
  //     if (j > 0) res -= pf[i][j - 1];
  //     if (i > 0 && j > 0) res += pf[i - 1][j - 1];
  //     cout << res << " ";
  //     if (res == k) cnt++;
  //   }

  // }

  // cout << cnt << endl;



}