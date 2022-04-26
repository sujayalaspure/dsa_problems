#include <iostream>
#include <vector>
#include <string> // for string and to_string()
#include <algorithm>
#include <queue>

using namespace std;
bool cmp(string a, string b)
{
    return (a + b >= b + a);
}
int main()
{
    queue<pair<string, int> > q;
    q.push(make_pair("", 0));

    return 0;
}