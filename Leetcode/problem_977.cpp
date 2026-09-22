#include<iostream>
#include<vector>
#include<math.h>
#include <algorithm>
using namespace std;

vector<int> squaresorted(vector<int> &nums){
        vector<int> ans(nums.size());

        

//         for(int i=0;i<nums.size();i++){
//             ans.push_back(nums[i] * nums[i]);
//         }
        
//         sort(ans.begin(), ans.end());
//         // for(int i=0;i<nums.size()-2;i++){
//         //    int  min =i;
//         //     for(int j=i;j<=nums.size()-1;j++){
//         //         if(nums[j]<nums[min]){
//         //             min=j;
//         //         }
//         //         swap(nums[min],nums[i]);
//         //     }
//         // }
//         return ans;
// }

// optimal approch 

int n= nums.size();
int left = 0;
int right= n-1;
int k = n-1;

while(left<=right){
    int leftsquare = nums[left] * nums[left];
    int rightsquare = nums[right] * nums[right];

    if(leftsquare > rightsquare){
        ans[k]= leftsquare;
        left++;
    }
    else{
        ans[k]=rightsquare;
        right--;
    }

    k--;

} 
return ans;
}

int main () {
    vector<int> nums = {-7,-3,2,3,11};

    vector<int> ans = squaresorted(nums);

    for (int x : ans)
        cout << x << " ";

    
}



