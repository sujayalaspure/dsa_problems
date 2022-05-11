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
  vector<bool> ans;
  bool prevG = true, g = true;

  for (int i = 0; i < n; i++) {
    if (i > 0 && s[i] == '(' && s[i - 1] == '-') {
      prevG = g;
      g = !g;
      st.push(g);
    }
    if (s[i] == ')') {
      bool t = prevG;
      prevG = st.top();
      st.push(t);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
  }
}

int main() {
  string A = "-(-(-(-a+b)-d+c)-q)";
  string B = "a-b-d+c+q";

  vector<bool> Aval;
  vector<bool> Bval;

  Aval = getVal(A);
  cout << "--" << endl;
  Bval = getVal(B);
  for (int i = 0; i <= 26; i++)
    if (Aval[i] != Bval[i]) {
      cout << "not same" << endl;
      break;
    }

  // int a = 'a' - 96;

  // cout << a << endl;

  return 0;
}