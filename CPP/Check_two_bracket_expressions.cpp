#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main() {

  string A = "-(a+b+c)";

  int n = A.size();

  vector<bool> ans(26);
  bool global = A[0] == '-' ? false : true;

  for (int i = 0;i < n;i++) {
    bool local = true;


    if ('a' <= A[i] && A[i] <= z) {

      if (i > 0 && A[i - 1] == '-') {
        local = false;
      }
      ans[A[i] - 96] = local ^ global;
    }



  }

  return 0;
}