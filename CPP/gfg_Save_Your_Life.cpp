// https://practice.geeksforgeeks.org/problems/save-your-life4601/1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

string maxSum(string w, char x[], int b[], int n) {
  int size = w.size();
  int currentSum = 0;
  int left = 0, right = 0;
  int lastMax = INT_MIN;
  int lastLeft = 0, lastRight = 0;
  unordered_map<char, int> mp;
  for (int i = 0;i < n;i++) {
    mp[x[i]] = b[i];
  }


  for (int i = 0;i < size;i++) {
    if (mp.find(w[i]) == mp.end())
      currentSum += (int)w[i];
    else currentSum += mp[w[i]];

    if (currentSum < 0) {
      lastRight = i - 1;
      left = i + 1;
      currentSum = 0;
    }
    else {
      if (currentSum > lastMax) {
        lastMax = currentSum;
        lastLeft = left;
        right = i;
      }
    }

  }

  cout << left << " " << right << endl;
  cout << lastLeft << " " << lastRight << endl;
  return w.substr(lastLeft, right - lastLeft + 1);
}

int main() {
  string W = "dbfbsdbf";
  int N = 2;
  char X[] = { 'b', 's' };
  int B[] = { -100, 45 };

  // string W = "oK";
  // int N = 2;
  // char X[] = { 'K', 'o' };
  // int B[] = { -880, 53 };
  // string W = "abcde";
  // int N = 1;
  // char X[] = { 'c', };
  // int B[] = { -1000 };
  cout << maxSum(W, X, B, N) << endl;
  return 0;
}

/*

W = dbfbsdbf
N = 2
X[] = { 'b','s' }
B[] = { -100, 45  }

100-100+102-100+45+100-100+102

runningSum=
maxSum=
l=
r=

*/