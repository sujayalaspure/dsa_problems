#include <iostream>
#include <vector>
using namespace std;

void generate(vector<int>& hm, vector<int>& current, vector<int>& result, int n) {
  if (current.size == n) {
    result.push_back(current);
    return;
  }

  for (int i = 0;i < 10;i++) {
    if (hm[i] > 0) {
      hm[i]--;
      current.push_back(i);
      generate(hm, current, result, n);
      current.pop_back();
      hm[i]++;
    }

  }
}


int main() {

  vector<int> hm(10, 0);
  vector<int> current, result;

  for (int i = 0;i < 10;i++) {
    hm[i]++;
  }

  generate(hm, current, result, 3);


  return 0;
}