#include <iostream>
// add math lib
#include <math.h>
#include <set>
#include <map>
using namespace std;

int main()
{
  set<pair<int, int> > s;
  s.insert(make_pair(1, 2));
  s.insert(make_pair(2, 3));
  s.insert(make_pair(3, 4));
  // print all elements
  for (set<pair<int, int> >::iterator it = s.begin(); it != s.end(); it++)
  {
    cout << it->first << " " << it->second << endl;
  }

  cout << s.count(make_pair(1, 2)) << endl;

  // create a hashmap
  // map<pair<int, int>, int> m;
  // m[make_pair(1, 2)] = 1;
  // m[make_pair(2, 3)] = 2;
  // m[make_pair(3, 4)] = 3;
  // // print all elements
  // for (map<pair<int, int>, int>::iterator it = m.begin(); it != m.end(); it++)
  // {
  //   cout << it->first.first << " " << it->first.second << " " << it->second << endl;
  // }

  return 0;
}