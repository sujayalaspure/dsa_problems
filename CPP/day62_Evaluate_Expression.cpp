#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{

  vector<string> A = {"5", "1", "2", "+", "4", "*", "+", "3", "-"};
  int n = A.size();
  stack<string> st;

  for (int i = 0; i < n; i++)
  {

    if (A[i] == "+")
    {
      int y = stoi(st.top());
      st.pop();
      int x = stoi(st.top());
      st.pop();
      int ans = x + y;
      cout << x << "+" << y << ":" << ans << "->";
      st.push(to_string(ans));
    }
    else if (A[i] == "-")
    {
      int y = stoi(st.top());
      st.pop();
      int x = stoi(st.top());
      st.pop();
      int ans = x - y;
      cout << x << "-" << y << ":" << ans << "->";

      st.push(to_string(ans));
    }
    else if (A[i] == "*")
    {
      int y = stoi(st.top());
      st.pop();
      int x = stoi(st.top());
      st.pop();
      int ans = x * y;
      cout << x << "*" << y << ":" << ans << "->";

      st.push(to_string(ans));
    }
    else if (A[i] == "/")
    {
      int y = stoi(st.top());
      st.pop();
      int x = stoi(st.top());
      st.pop();
      int ans = x / y;
      cout << x << "/" << y << ":" << ans << "->";

      st.push(to_string(ans));
    }
    else
    {
      st.push(A[i]);
      cout << "inL:";
    }
    cout << st.top() << endl;
  }

  return 0;
}