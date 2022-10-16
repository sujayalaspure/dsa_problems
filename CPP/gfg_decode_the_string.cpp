#include<iostream>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;

int main() {
  string input = "1[b]";
  stack<char> charStack;

  for (int i = 0; i < input.size(); i++) {
    char a = input[i];

    if (a == ']') {
      string temp = "";
      string tmpCount = "";
      while (!charStack.empty() && charStack.top() != '[') {
        temp += charStack.top();
        charStack.pop();
      }
      charStack.pop();
      while (!charStack.empty() && isdigit(charStack.top())) {
        tmpCount += charStack.top();
        charStack.pop();
      }

      reverse(temp.begin(), temp.end());
      reverse(tmpCount.begin(), tmpCount.end());
      int count = stoi(tmpCount);
      while (count) {
        for (int i = 0; i < temp.size(); i++) {
          charStack.push(temp[i]);
        }
        count--;

      }
    }
    else charStack.push(a);
  }
  cout << endl;
  string ans = "";
  while (!charStack.empty()) {
    ans += charStack.top();
    charStack.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}


// 3[b2[ca]]

/**
 * 3 <-
 * */
 // ac
 // cacab
 /*

 */