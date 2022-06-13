#include <iostream>
#include <vector>
#include<queue>
#include <cmath>
using namespace std;


// 
void maxSum() {
  vector<int> v = { 57, 3, -14, -87, 42, 38, 31, -7, -28, -61 };
  int A = 10;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int a : v) {
    q.push(a);
  }

  while (A) {
    int x = q.top();
    q.pop();
    q.push(-1 * x);
    A--;
  }
  int ans = 0;

  while (!q.empty()) {
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;

}


// Q3.Product of 3

void productOfThree() {

  vector<int> A = { 10, 2, 13, 4 };
  int n = A.size();
  priority_queue<int, vector<int>, greater<int>> q;
  vector<int> res(n);

  int curr = 1;
  for (int i = 0;i < 3;i++) {
    q.push(A[i]);
    curr *= A[i];
    res[i] = -1;
  }
  res[2] = curr;

  for (int i = 3;i < n;i++) {
    if (q.top() < A[i]) {
      curr /= q.top();
      q.pop();
      q.push(A[i]);
      curr *= A[i];
      res[i] = curr;
    }
  }

  for (int a : res) {
    cout << a << " ";
  }
  cout << endl;

}



int chocolate() {
  int A = 10;
  // vector<int> B = { 2, 4, 6, 8, 10 };
  vector<int> B = { 2147483647, 2000000014, 2147483647 };
  priority_queue<int, vector<int>> q;
  int n = B.size();
  int mod = 1e9 + 7;
  for (int i = 0;i < n;i++) {
    q.push(B[i]);
  }
  int ans = 0;
  while (A) {
    int x = q.top();
    ans = (ans % mod + x % mod) % mod;
    q.pop();
    int y = floor(x / 2);
    cout << y << endl;
    q.push(y);
    A--;
  }

  return ans % mod;
}


int meeshaAndCandies() {
  vector<int> A = { 406, 682, 42, 265, 387, 280, 98, 844, 209, 767, 357, 799, 356, 911, 922, 208, 749, 515, 0, 778, 679, 665, 402, 52, 435, 551, 648, 145, 125, 504, 237, 836, 137, 806, 45, 103, 919, 871, 248, 54, 386, 982, 986, 262, 638, 919, 844, 128, 784, 640, 672, 692, 202, 682, 756, 48, 111, 318, 817, 24, 537, 268, 684, 801, 787, 480, 694, 420, 227, 287, 944, 275, 821, 806, 939, 872 };
  // vector<int> A = { 3, 2, 3 };
  int B = 122;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int n = A.size();
  int ans = 0;
  for (int a : A) {
    minHeap.push(a);
  }
  cout << minHeap.top() << endl;
  while (!minHeap.empty()) {
    int x = minHeap.top();
    minHeap.pop();
    if (x <= B) {
      int y = x / 2;
      ans += y;
      int remaining = x - y;
      if (minHeap.empty()) break;
      int other = minHeap.top();
      minHeap.pop();
      minHeap.push(other + remaining);
    }

    // else{
    //     q.push(x-y);
    // }

  }

  return ans;
}



void convert2Dto1D() {
  vector<vector<int>>  A =
  { {5, 9, 11},
  {9, 11, 13},
  {10, 12, 15},
  {13, 14, 16},
  {16, 20, 21} };

  int row = A.size();
  int col = A[0].size();

  vector<int> res(row * col);
  for (int i = 0;i < row * col;i++) {
    res[i] = A[i / col][i % col];
    cout << res[i] << " ";
  }



}

typedef pair<int, int> pd;

struct myComp {
  constexpr bool operator()(
    pair<int, int> const& a,
    pair<int, int> const& b)
    const noexcept {
    return ((float)a.first / (float)a.second) > ((float)b.first / (float)b.second);
  }
};

void heapCustomSorting() {
  vector<int> A = { 1, 2, 3, 5 };
  auto comp = [](pair<int, int> a, pair<int, int> b) {
    return ((float)a.first / (float)a.second) > ((float)b.first / (float)b.second);
  };
  priority_queue<pd, vector<pd>, decltype(comp)> minHeap(comp);
  int n = A.size();
  for (int i = 0;i < n;i++) {
    for (int j = i + 1;j < n;j++) {

      minHeap.push(make_pair(A[i], A[j]));
    }
  }

  while (!minHeap.empty()) {
    auto x = minHeap.top();
    minHeap.pop();
    float aa = (float)x.first / (float)x.second;
    cout << x.first << " " << x.second << " " << aa << endl;
  }
}



int main() {
  // productOfThree();
  // cout << meeshaAndCandies() << endl;
  heapCustomSorting();
  return 0;
}