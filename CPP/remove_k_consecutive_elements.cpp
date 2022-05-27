#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  string s = "acbbbcdddceb";
  stack<pair<char, int> > st;
  int k = 3;
  int cnt = 0;

  char a = '1';
  char b = '1';
  // int x = (int)a - 48;
  cout << a << " " << b << endl;
  int x = (int)a + (int)b;
  cout << x - 2 * 48 << endl;


  for (int i = 0; i < s.size(); i++) {
    if (st.empty()) {
      st.push(make_pair(s[i], 1));
      // cout << s[i] << " " << cnt << endl;
    }
    else {
      if (st.top().first == s[i]) {
        int x = st.top().second;
        st.pop();
        st.push(make_pair(s[i], x + 1));
        if (st.top().second == k) {
          st.pop();
        }
      }
      else {
        st.push(make_pair(s[i], 1));
      }
    }
  }

  cout << endl;
  string ans = "";
  while (!st.empty()) {
    // cout << st.top().first << " ";
    ans += st.top().first;
    st.pop();
  }
  cout << endl;
  reverse(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}