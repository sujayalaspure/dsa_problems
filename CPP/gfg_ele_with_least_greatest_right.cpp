#include<iostream>
#include<vector>
#include<stack>
#include<set>

using namespace std;

vector<int> findLeastGreater(vector<int>& arr, int n) {
  vector<int> ans(n, -1);

  for (int i = 0;i < n;i++) {
    stack<int> st;

    for (int j = i + 1;j < n;j++) {
      if (arr[i] < arr[j] && (st.empty() || st.top() > arr[j])) {
        st.push(arr[j]);
      }
    }
    if (!st.empty()) ans[i] = st.top();
  }

  return ans;
}



vector<int> findLeastGreater2(vector<int>& arr, int n) {
  vector<int> ans;
  set<int> se;
  for (int i = n - 1;i >= 0;i--) {
    auto it = se.upper_bound(arr[i]);
    cout << *it << " - ";
    se.insert(arr[i]);
    if (it == se.end()) ans.push_back(-1);
    else ans.push_back(*it);
  }
  reverse(ans.begin(), ans.end());
  cout << endl;
  return ans;
}


vector<int> nextGreater(vector<int>& A) {
  int n = A.size();
  stack<int> st;
  vector<int> ans(n, -1);
  for (int i = n - 1;i >= 0;i--) {
    while (!st.empty() && st.top() <= A[i]) st.pop();
    if (!st.empty()) ans[i] = st.top();
    st.push(A[i]);
  }
  return ans;

}

int main() {

  vector<int> arr = { 8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28 };
  int n = arr.size();

  vector<int> result = findLeastGreater2(arr, n);

  for (int a : result) cout << a << " ";
  cout << endl;

  return 0;
}