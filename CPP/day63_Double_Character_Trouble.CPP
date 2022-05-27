#include <iostream>
#include <vector>
#include<string>
#include<stack>
using namespace std;

int main() {
  string A = "abccbc";
  stack<char> st;

  int n = A.size();

  for (int i = n - 1;i >= 0;i--) {
    if (!st.empty() && st.top() == A[i]) {
      st.pop();
    }
    else {
      st.push(A[i]);
    }
  }
  string ans = "";
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  cout << ans << endl;
  return 0;
}