// concatination of an array .

#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<int> nums = {1,2,1};
    
    int n = nums.size();
    vector<int>ans(2*n) ; //size double 

    for (int i =0;i<n;i++){
        ans[i]=nums[i];
        ans[i+n]= nums[i];

    }
    for(int i=0;i<2*n;i++){

        cout<<ans[i]<<" ";
    }
 return 0;
   
}