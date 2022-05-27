#include <iostream>
#include <vector>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
  string A = "ADOBECODEBANC";
  string B = "ABC";
  unordered_map<char, int> m;
  int count = 0;
  for (char a : B) {
    count++;
    if (m.count(a) == 1) m[a]++;
    else m[a] = 1;

  }

  int min_len = -1, idx = -1, start = 0, end = 0;
  while (end < A.size()) {
    if (m.count(A[end]) == 1) {
      if (m[A[end]] > 0) count--;
      m[A[end]]--;
    }
    while (count == 0) {
      int len = end - start + 1;
      if (idx == -1 || min_len > len) {
        min_len = len;
        idx = start;
      }
      if (m.count(A[start]) == 1) {
        if (m[A[start]] >= 0)
          count++;
        m[A[start]]++;

      }
      start++;
    }
    end++;
  }

  if (idx == -1) {
    cout << "nothing" << endl;
    // break;
  }
  else {
    cout << A.substr(idx, idx + min_len) << endl;
  }



  return 0;
}