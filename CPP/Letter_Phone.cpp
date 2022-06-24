#include <iostream>
#include <vector>
#include<string.h>
#include<unordered_map>
using namespace std;

vector<string> res;
unordered_map<char, string> hm;


void solve(string A, int n, int idx, vector<char>& temp) {
  if (idx == n) {
    string s(temp.begin(), temp.end());
    res.push_back(s);
  }
  for (int i = 0; i < hm[A[idx]].size(); i++) {
    temp.push_back(hm[A[idx]][i]);
    solve(A, n, idx + 1, temp);
    temp.pop_back();
  }

}

int main() {
  res.clear();
  hm['0'] = "0";
  hm['1'] = "1";
  hm['2'] = "abc";
  hm['3'] = "def";
  hm['4'] = "ghi";
  hm['5'] = "jkl";
  hm['6'] = "mno";
  hm['7'] = "pqrs";
  hm['8'] = "tuv";
  hm['9'] = "wxyz";

  string A = "234";
  int n = A.size();
  vector<char> temp;
  solve(A, n, 0, temp);
  for (string a : res) {
    cout << a << " ";
  }
  cout << endl;

  return 0;
}