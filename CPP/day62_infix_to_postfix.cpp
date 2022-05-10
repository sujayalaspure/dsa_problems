#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

string solve(string A)
{
  string ans;
  stack<int> st;
  unordered_map<char, int> pre;
  pre['('] = -1;
  pre[')'] = -1;
  pre['+'] = 0;
  pre['-'] = 0;
  pre['/'] = 1;
  pre['*'] = 1;
  pre['^'] = 2;

  int n = A.size();

  for (int i = 0; i < n; i++)
  {
    // cout << A[i] << " " << pre.count(A[i]) << endl;
    if (pre.count(A[i]) == 0) // operand
    {
      ans += A[i];
    }
    else
    {
      if (A[i] == '(')
      {
        st.push(A[i]);
      }
      else if (A[i] == ')')
      {
        while (st.top() != '(')
        {
          ans += st.top();
          st.pop();
        }
        st.pop();
      }
      else // operator
      {
        if (!st.empty())
        {
          while (pre[A[i]] <= pre[st.top()])
          {
            ans += st.top();
            st.pop();
            if (st.empty())
              break;
          }
          st.push(A[i]);
        }
        else
        {
          st.push(A[i]);
        }
      }
    }
  }
  while (st.size() > 0)
  {
    ans += st.top();
    st.pop();
  }
  return ans;
}

int main()
{

  // string A = "x^y/(a*z)+b";
  string A = "-(a+b+c)";
  string B = "-a-b-c";
  // string A = "a*(r+o*h)";

  cout << solve(A) << endl;
  cout << solve(B) << endl;
  return 0;
}