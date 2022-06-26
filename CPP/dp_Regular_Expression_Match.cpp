#include <iostream>
#include <vector>
#include<string.h>
using namespace std;


bool solve(string& A, int startA, string& B, int startB) {
  if (startA == A.size() && startB == B.size()) {
    return true;
  }
  if (startA == A.size() || startB == B.size()) {
    return false;
  }
  if (A[startA] == B[startB]) {
    return solve(A, startA + 1, B, startB + 1);
  }
  if (B[startB] == '*') {
    return solve(A, startA, B, startB + 1) || solve(A, startA + 1, B, startB);
  }
  return false;

}

int main() {
  string A = "abaa";
  string B = "a*?a";

  cout << solve(A, 0, B, 0) << endl;


  return 0;
}