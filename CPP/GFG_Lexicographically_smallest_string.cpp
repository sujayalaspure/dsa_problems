// https://practice.geeksforgeeks.org/problems/mila-and-strings0435/1

#include<iostream>
#include<vector>
#include<math.h>
#include<stack>
#include<string>

using namespace std;

bool isPowerOfTwo(int n) {
  if (n == 0)
    return false;
  return (ceil(log2(n)) == floor(log2(n)));
}

string lexicographicallySmallest(string S, int k) {
  stack<char> st;
  int n = S.size();
  if (isPowerOfTwo(n)) k = k / 2;
  else k = k * 2;

  for (int i = 0;i < n;i++) {
    while (!st.empty() && k > 0 && st.top() > S[i]) {
      st.pop();
      k--;
    }
    st.push(S[i]);
  }

  while (k--) st.pop();
  string ans = "";
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  cout << reverse << endl;

}


int main() {
  string S = "fooland";
  int k = 2;
  lexicographicallySmallest(S, k);
}


// while (k>0 && stack not empty && stack top > S[i])  remove from stack and dec k by 1
// push to stack S[i]

// till k !=0 remove from stack

//  form strign from stack