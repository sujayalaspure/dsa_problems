#include <iostream>
#include <set>
#include <vector>
using namespace std;

int solve(vector<int> &A, vector<int> &B)
{
  set<pair<int, int> > ts;
  int n = A.size();
  for (int i = 0; i < n; i++)
  {
    ts.insert(make_pair(A[i], B[i]));
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int x1 = A[i];
      int y1 = B[i];
      int x2 = A[j];
      int y2 = B[j];
      if (x1 == x2 || y1 == y2)
        continue;
      if (ts.count(make_pair(x2, y1)) == 1 && ts.count(make_pair(x1, y2)) == 1)
      {
        ans++;
      }
    }
  }
  return ans / 2;
}
int main()
{
  vector<int> A = {1, 1, 2, 2}, B = {1, 2, 1, 2};
  cout << solve(A, B) << endl;
  return 0;
}