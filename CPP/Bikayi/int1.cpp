
// A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

// The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

// For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
// Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.
// Input: cost = [6,5,7,9,2,2]
// Output: 23
// Explanation: The way in which we can get the minimum cost is described below:
// - Buy candies with costs 9 and 7
// - Take the candy with cost 6 for free
// - We buy candies with costs 5 and 2
// - Take the last remaining candy with cost 2 for free
// Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.

// 6,5,7,9,2,2]
// 2 2 5 6 7 9

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> A = {6, 5, 7, 9, 2, 2, 3};

  int n = A.size();
  sort(A.begin(), A.end());
  int ans = 0;

  for (int i = n - 1; i >= 0; i -= 3)
  {
    if (i == 0)
    {
      ans += A[i];
    }
    else
    {
      ans += A[i] + A[i - 1];
    }
  }

  cout << ans << endl;
  return 0;
}