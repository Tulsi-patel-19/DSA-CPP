#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    
    int removeDuplicate(vector<int>& nums){
   
    if(nums.size()==0){
        return 0;
    }

    int write =0;

    for(int readptr = 1; readptr < nums.size(); readptr++){
        if(nums[readptr]!= nums[write]){
            write++;
            nums[write]= nums[readptr];
        }
        
    }
    return write+1;
}
  
};
int main(){
    Solution obj;

    vector<int> nums = {1,1,2,2,3,4};

    int k = obj.removeDuplicate(nums);

    cout<<"number of unique elements : "<<k<<endl;

    return 0;
}

