// array partition

#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int partion(vector<int> &nums,int n){

    sort(nums.begin(),nums.end());
    int ans=0;
    // int mini=-1;

    for(int i=0;i<n;i+=2){
        ans+=nums[i];
    }

//    for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             cout << "(" << nums[i] << ", " << nums[j] << ")" << endl;

//             ans = min(nums[i],nums[j]);

//         }
//     }
return ans;
    
}
int main(){
    vector<int> nums={6,2,6,5,1,2};
    int n= nums.size();

    int res= partion(nums,n);
    cout<<res;

}