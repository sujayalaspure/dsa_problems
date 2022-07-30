#include <iostream>
#include <vector>
using namespace std;


int getRoot(int node, vector<int>& c) {
  if (c[node] == node) return node;
  c[node] = getRoot(c[node], c);
  return c[node];
}


void sortByWeight(vector<vector<int> >& B) {
  auto cmp = [](vector<int> first, vector<int> second) {
    return first[2] < second[2];
  };
  sort(B.begin(), B.end(), cmp);
}


bool checkUnion(int node1, int node2, vector<int>& root, vector<int>& rank) {
  int root1 = getRoot(node1, root);
  int root2 = getRoot(node2, root);
  if (root1 == root2) return false;
  if (rank[root1] > rank[root2]) root[root2] = root1;
  else if (rank[root1] < rank[root2]) root[root1] = root2;
  else {
    root[root1] = root2;
    rank[root2]++;
  }
  return true;

}

int solve(int A, vector<vector<int> >& B) {

  sortByWeight(B);
  vector<int> root(A + 1, 1);
  vector<int> rank(A + 1, 1);
  for (int i = 1; i <= A; i++) {
    root[i] = i;
    rank[i] = 1;
  }
  int total = 0;
  for (int i = 0;i < B.size();i++) {
    int u = B[i][0], v = B[i][1], w = B[i][2];
    if (checkUnion(u, v, root, rank)) {
      total += w;
    }
  }

  return total;
}




int main() {

  int A = 5;
  vector<vector<int>> B =
  {
  {1, 2, 8},
  {1, 5, 7},
  {2, 5, 2},
  {2, 3, 4},
  {3, 5, 3},
  {4, 3, 6},
  {4, 5, 5} };

  cout << solve(A, B) << endl;

  // sortByWeight(B);
  // for (auto i : B) {
  //   cout << i[0] << " " << i[1] << " " << i[2] << endl;
  // }


  return 0;
}