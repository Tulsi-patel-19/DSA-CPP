// print 3 rd max ele
#include<iostream>
#include <climits>
#include<vector>

using namespace std;

int thirdmaxele(vector<int> &nums,int n){
    long long ln = LLONG_MIN;
    long long thirdlar =LLONG_MIN;
    long long sl= LLONG_MIN;

    for(int x: nums){
        if(x >ln){
            thirdlar=sl;
            sl=ln;
            ln=x;
        }

          else if (x > sl) {
            thirdlar = sl;
            sl = x;
        }

       else if (x > thirdlar) {
            thirdlar = x;
        }
        else{
          return  ln;
        }
    }

      if (thirdlar == LLONG_MIN) {
        return ln;
    }
    
    return thirdlar;
}
int main(){
    vector<int> nums= {2,1};
    int n= nums.size();
    int ans =thirdmaxele(nums,n);
    cout<< ans;
}