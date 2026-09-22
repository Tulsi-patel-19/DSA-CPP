#include <iostream>
#include <vector>

using namespace std;
int missingNum(vector<int> nums, int n)
{

  int ans = n;
    for(int i=0;i<n;i++){
        ans = ans^i;
        ans = ans^nums[i];
    }
        return ans;
    }
   


int main()
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int n = nums.size();

    vector<int> ans = missingNum(nums, n);

    for (int x : ans)
        cout << x << " ";
}