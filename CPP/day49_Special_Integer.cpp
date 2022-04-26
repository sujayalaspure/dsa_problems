#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> A = {1, 2, 3, 4, 5};
  int B = 10;
  int n = A.size();
  sort(A.begin(), A.end());
  int curr = 0;
  int cnt = 0;
  while (curr < B)
  {
    curr += A[n - 1 - cnt];
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}