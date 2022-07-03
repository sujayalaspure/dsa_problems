#include <iostream>
#include <vector>
#include<string.h>
#include<unordered_map>
using namespace std;

int main() {
  vector<string> messages = { "m1 we", "m2", "m3" };
  vector<string> senders = { "s1", "s2", "s1" };
  int maxCount = INT_MIN;
  string user = "";
  int n = senders.size();
  unordered_map<string, int> mp;
  for (int i = 0;i < n;i++) {
    int count = 1;
    string temp = messages[i];
    for (int k = 0;k < temp.size();k++) {
      if (temp[k] == ' ') count++;
    }
    mp[senders[i]] += count;
    if (maxCount < mp[senders[i]]) {
      maxCount = mp[senders[i]];
      user = senders[i];
    }
  }

  cout << user << endl;
  return 0;
}
// maxCout-> 3
// user -> "s1"

// "s1" -> 3
// "s2" -> 1
