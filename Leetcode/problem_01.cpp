#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {12,2,8,4,3};
    int target = 10;

    
     int n = nums.size();

          for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i] + nums[j] == target){
                    cout<<i<<" "<<j;
                }
            }
          }
     
          return{};
}