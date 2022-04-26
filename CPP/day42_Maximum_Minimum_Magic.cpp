#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

  vector<int> A = {-98, 54, -52, 15, 23, -97, 12, -64, 52, 85};

  int n = A.size();
  cout << "Maximum element is: " << endl;

  // for Min
  sort(A.begin(), A.end());
  int min_value = 0, max_value = 0;
  for (int i = 0; i < n; i += 2)
  {
    min_value += abs(A[i] - A[i + 1]);
  }

  // for max
  // sort(A.begin(), A.end(), greater<int>());
  int p1 = 0, p2 = n - 1;
  while (p1 < p2)
  {
    max_value += abs(A[p2] - A[p1]);
    p1++;
    p2--;
  }

  cout << max_value << " " << min_value << endl;
  return 0;
}