#include <iostream>
#include <vector>
#include<string.h>
#include<stack>
using namespace std;

int main() {
  string s = "deeedbbcccbdaa";
  int k = 3;
  stack < pair<char, int>> st;
  int cnt = 1;
  for (int i = 0;i < s.size();i++) {
    if (st.empty() || st.top().first != s[i]) {
      st.push({ s[i], 1 });
    }
    else {
      st.push({ s[i], st.top().second + 1 });
      if (st.top().second >= k) {
        int l = st.top().second;
        while (l--) st.pop();
      }
    }

  }

  while (!st.empty()) {
    cout << st.top().first << " ";
    st.pop();
  }
  cout << endl;



  return 0;
}