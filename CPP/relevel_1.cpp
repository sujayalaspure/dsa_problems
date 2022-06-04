#include <iostream>
#include <vector>
#include<queue>
#include<string>
using namespace std;


int solve2() {
  // vector<int> a = { 4, 3, 5, 1 };
  // int n = a.size();
  int n;
  cin >> n;
  int a[n];
  int total = 0;
  for (int i = 0;i < n;i++) {
    cin >> a[i];
    total += a[i];
  }

  int ans = 0;
  for (int i = 0;i < n;i++) {
    ans += (total - a[i]) * a[i];
  }

  return ans;

}






int main() {

  cout << solve2() << endl;


  // int A;
  // cin >> A;
  // // cout << A << endl;
  // string c[A];
  // queue<string> q;
  // for (int i = 0;i < A;i++) {
  //   cin >> c[i];
  //   q.push(c[i]);
  // }
  // // for (int i = 0; i < A; i++) {
  // //   cout << c[i] << endl;
  // // }
  // int cnt = A;
  // int N;
  // cin >> N;
  // cout << endl << q.front() << endl;
  // while (cnt < N) {
  //   string x = q.front();
  //   q.pop();
  //   for (int i = 0; i < A; i++) {

  //     string k = x + c[i];
  //     // cout << x << " " << c[i] << " " << k << " " << endl;
  //     q.push(k);
  //     cnt++;
  //     if (cnt == N) {
  //       cout << endl << "-> " << k << endl;
  //       break;
  //     }
  //   }

  // }

  return 0;
}