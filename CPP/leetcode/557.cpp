// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.


#include <iostream>
#include <vector>
#include <sstream>

#include <string>
using namespace std;

vector<string> split(const string& s, char delim) {
  vector<string> result;
  stringstream ss(s);
  string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}



int main() {
  string s = "Let's take LeetCode contest";
  vector<string> v = split(s, ' ');
  for (int i = 0;i < v.size();i++) {
    string a = v[i];
    vector<char> A(a.begin(), a.end());
    int p1 = 0, p2 = a.size() - 1;
    while (p1 < p2) {
      swap(A[p1], A[p2]);
      p1++;
      p2--;
    }
    string s(A.begin(), A.end());
    v[i] = s;
  }
  string ans;
  for (string a : v) {
    cout << a << " ";
    ans += a + " ";
  }
  ans.
    cout << ans << endl;
  return 0;
}


