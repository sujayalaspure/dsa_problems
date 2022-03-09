#include <iostream>
#include<map>
using namespace std;

int main()
{

map<int,string> mymap;
mymap[1]="one";
mymap[2]="two";
mymap[3]="four";

cout<<mymap[1]<<endl;

auto it = mymap.find(1);
cout<<it->second <<" "<<mymap[1]<<endl;
      return 0;
}