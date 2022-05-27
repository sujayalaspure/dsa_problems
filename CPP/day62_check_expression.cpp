#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<bool> getVal(string s) {
  int n = s.size();
  vector<bool> ans(26);
  for (int i = 0; i < n; i++) {

    if (s[i] >= 'a' && s[i] <= 'z') {
      bool g = true;
      bool l = true;
      for (int j = 0; j < i; j++) {
        if (j > 0 && (s[j] == '(') && s[j - 1] == '-')
          g = !g;
        if (j > 0 && s[j] == ')')
          g = !g;
      }
      if (i > 0 && s[i - 1] == '-')
        l = false;

      int idx = s[i] - 96;
      ans[idx] = l ^ g;
      cout << s[i] << " " << ans[idx] << endl;
    }
  }
  return ans;
}

vector<bool> solveUsingStack(string s) {
  int n = s.size();
  stack<bool> st;
  st.push(true);
  vector<bool> ans(26);
  bool prevG = true, g = true;
  // cout << st.top() << endl;


  for (int i = 0; i < n; i++) {
    if (s[i] == '+' || s[i] == '-') continue;
    if (i > 0 && s[i] == '(') {
      if (s[i - 1] == '-') {
        prevG = st.top();
        st.push(!st.top());
      }
      else {
        prevG = st.top();
        st.push(st.top());
      }
      // prevG = g;
      // g = !g;
      // cout << st.top() << endl;
      continue;
    }
    if (s[i] >= 'a' && s[i] <= 'z') {
      bool l = true;
      int idx = s[i] - 96;
      if (i > 0 && s[i - 1] == '-') l = false;
      ans[idx] = l ^ st.top();
      // if (i > 0 && s[i - 1] == '-') {

      // }
      // else {
      //   ans[idx] = st.top() ? 1 : -1;

      // }
      continue;

    }
    if (!st.empty() && s[i] == ')') st.pop();
  }

  return ans;
}

int main() {
  string A = "a+b-c+d-e-f";
  string B = "(a+b-c-d-e+f)";

  vector<bool> Aval;
  vector<bool> Bval;

  Aval = solveUsingStack(A);
  cout << "--" << endl;
  Bval = solveUsingStack(B);
  for (int i = 0; i <= 26; i++)
    if (Aval[i] != Bval[i]) {
      cout << "not same" << endl;
      break;
    }

  // int a = 'a' - 96;

  // cout << a << endl;

  return 0;
}