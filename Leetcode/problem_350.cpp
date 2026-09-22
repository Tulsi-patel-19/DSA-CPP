#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(vector<int> &nums1, int n, vector<int> nums2, int m)
{
    vector<int> ans;

    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    int n = nums1.size();
    int m = nums2.size();
    vector<int> ans = intersection(nums1,n, nums2,m);

    for (int x : ans)
        cout << x << " ";
}