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