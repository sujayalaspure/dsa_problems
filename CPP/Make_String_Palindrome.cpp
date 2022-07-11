#include <iostream>
#include <vector>
#include<string>
using namespace std;


void makePalindrome() {
  string A = "babb";
  char first = A[0];
  int n = A.size();
  int i = n - 1;
  while (i >= 0 && A[i] != first) {
    i--;
  }
  int ans = n - i - 1;
  cout << ans << endl;


}

int main() {
  makePalindrome();
  return 0;
}