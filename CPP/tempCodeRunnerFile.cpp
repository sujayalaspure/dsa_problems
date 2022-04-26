sort(A.begin(), A.end(), greater<int>());
  int p1 = 0, p2 = n - 1;
  while (p1 < p2)
  {
    max_value += abs(A[p1] - A[p2]);
  }