#include <iostream>
#include <vector>
using namespace std;

void printSub(vector<int>& A, int n, int i, vector<int>& sub, int prev) {
  if (i == -1) {
    cout << "" << endl;
    for (int i = sub.size() - 1; i >= 0; i--) {
      cout << sub[i] << " ";
    }

    return;
  }

  sub.push_back(A[i]);
  printSub(A, n, i - 1, sub, A[i]);

  sub.pop_back();
  printSub(A, n, i - 1, sub, A[i]);
}


int main() {

  vector<int> A = { 1, 2, 3 };
  int n = A.size();
  vector<int> sub;
  printSub(A, n, n - 1, sub, -1);

  return 0;
}