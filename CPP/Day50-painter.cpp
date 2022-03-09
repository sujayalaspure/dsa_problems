#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int m, vector<int> &nums, int n, int k)
{
  long s = nums[0];
  int c = 1;
  for (int i = 1; i < n; i++)
  {
    s += nums[i];
    if (s > m)
    {
      s = nums[i];
      c++;
    }
  }
  // if (s != 0)
  //   c++;
  return c <= k;
}

int solve(int A, int B, vector<int> &C)
{
  int n = C.size();
  long ans = 0;
  long b = B;
  int low = INT_MIN;
  long high = 0;
  for (int i = 0; i < n; i++)
  {
    // cout << C[i] << " ";
    high += C[i];
    low = max(low, C[i]);
  }

  cout << endl;
  cout << low << " - " << high << endl;
  while (low <= high)
  {
    long mid = low + (high - low) / 2;
    if (check(mid, C, n, A))
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  cout << ans << " " << b << " = " << ((ans % 10000003) * (b % 10000003)) % 10000003 << endl;
  return (int)((ans * B) % 10000003);
}
int main()
{

  int A = 1;
  int B = 1000000;
  vector<int> C = {1000000, 1000000};
  int ans = solve(A, B, C);
  cout << ans << endl;
  return 0;
}