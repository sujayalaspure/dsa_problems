// Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".


#include <iostream>
#include <vector>
using namespace std;

string firstPalindrome(vector<string>& words) {

  for (string a : words) {
    int p1 = 0, p2 = a.size() - 1;
    while (p1 <= p2) {
      // cout << a[p1] << " " << a[p2] << "-";
      if (a[p1] != a[p2]) break;
      p1++;
      p2--;
    }

    if (p1 > p2)return a;
    // cout << endl;
  }
  return "";
}

int main() {
  vector<string> words = { "abc", "car", "ada", "racecar", "cool" };
  cout << firstPalindrome(words) << endl;
  return 0;
}