
// Given a array of integers A of size N and an integer B.

//     Return number of non - empty subsequences of A of size B having sum <=
// 1000. A = [ 1, 2, 8 ] B = 2 ans = 3
// A = [ 5, 17, 1000, 11 ] B = 4 ans = 0

// 1, 2, 8

#include <iostream>
using namespace std;

int solve(int ar[], int n, int k, int pos, int sum)
{
  if (pos == k)
  {
    if (sum <= k)
      return 1;
    else
      return 0;
  }
  sum += ar[pos];
  int x = solve(ar, n, k, pos + 1, sum);
  sum -= ar[pos];
  int y = solve(ar, n, k, pos + 1, sum);
  return x + y;
}

int main()
{
  int ar[3] = {1, 2, 8};
  int n = 3;
  int k = 2;
  cout << solve(ar, n, k, 0, 0) << endl;
  return 0;
}