#include <iostream>
#include <cmath>

using namespace std;

int sqrt(int A) {
    if(A==0) return 0;
    int ans=0;
    int start=1, end=A;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(mid<=A/mid){
            ans=mid;
            start=mid+1;
            
        }else{

    end=mid-1;
        }
    }
    return floor(ans);
}


int main()
{
      int ans = sqrt(1);
      cout << ans << endl;
      // cout << "Hello World!" << endl;
      return 0;
}