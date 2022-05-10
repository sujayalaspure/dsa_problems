#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS(string A, int i, string B, int j, vector<vector<int> > &dp)
{
  if (i == -1 || j == -1)
    return 0;
  // cout << dp[i][j] << " ";
  if (dp[i][j] == -1)
  {
    if (A[i] == B[j])
    {
      dp[i][j] = 1 + LCS(A, i - 1, B, j - 1, dp);
    }
    else
    {
      dp[i][j] = max(LCS(A, i - 1, B, j, dp), LCS(A, i, B, j - 1, dp));
    }
  }
  return dp[i][j];
}

int iter(string A, string B)
{
  int n = A.size();
  int m = B.size();
  vector<vector<int> > dp(n, vector<int>(m, -1));
  dp[0][0] = 0;
  for (int i = 1; i < n; i++)
  {
    if (A[i] == B[0])
    {
      dp[i][0] = 1;
    }
    else
    {
      dp[i][0] = max(dp[i - 1][0], dp[i][0]);
    }
  }
  for (int i = 1; i < m; i++)
  {
    if (A[0] == B[i])
    {
      dp[0][i] = 1;
    }
    else
    {
      dp[0][i] = max(dp[0][i - 1], dp[i][0]);
    }
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      if (A[i] == B[j])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // print dp
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return dp[n - 1][m - 1];
}

int main()
{
  string A = "caababcebaeadeaaeeacbcbcabdaacdceadebcedcaacbbeacacaeacbcccebcdbcdababeedbbbccbecbeedeaa";
  string B = "bebdbebecdaeabdacbccbadabaeaecccbbcdadeacbeeeaedddaeebccbbecdeecaecacbcbeecabcdecbbdcdbd";
  cout << iter(A, B) << endl;
  int n = A.size();
  int m = B.size();
  vector<vector<int> > dp(n, vector<int>(m, -1));
  // cout << dp[n - 1][m - 1] << endl;
  int ans = LCS(A, n - 1, B, m - 1, dp);
  cout << "------" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << dp[n - 1][m - 1] << endl;
  return 0;
}