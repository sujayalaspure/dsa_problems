#include <iostream>
#include<vector>
#include <string> // for string and to_string()

using namespace std;
bool cmp(string a, string b){
    return (a+b>=b+a);
}
int main()
{
      vector<int> nums={3,30,34,5,9};
      vector<string> res;
      for(int a:nums){
          res.push_back(to_string(a));
      }
      sort(res.begin(),res.end(),cmp);
      string ans;
      for(int i=0;i<res.size();i++){
          ans+=res[i];

      }
      cout<<ans<<endl;
      return 0;
}