//  #include<iostream>
//  #include<vector>
//  using namespace std;
//  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

//         int n1= nums1.size();
//         int n2 = nums2.size();

//         int i=0;
//         int j=0;

//         vector<int> ans;

//         while(i<n1 && j<n2){
//             if(nums1[i]<nums2[j]){
//                 ans.push_back(nums1[i]);
//                 i++;
//             }

//             else if(nums2[j]<nums1[i]){
//                 ans.push_back(nums2[j]);
//                 j++;
//             }

//             else if((nums1[i]==nums2[j] ) && ((nums1[i]==nums2[j] )!= ans) ){
//                 ans.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//         }
//         return ans;
//     }

// int main() {
//     vector<int> nums1 = {1,2,2,1};
//     vector<int> nums2 = {2,2};

//     vector<int> ans = intersection(nums1, nums2);

//     for (int x : ans) {
//         cout << x << " ";
//     }
// }








#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> ans;

    int i = 0, j = 0;
    int n = nums1.size();
    int m = nums2.size();

    while (i < n && j < m) {

        if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            j++;
        }
        else {
            ans.push_back(nums1[i]);

            int value = nums1[i];

            while (i < n && nums1[i] == value)
                i++;

            while (j < m && nums2[j] == value)
                j++;
        }
    }

    return ans;
}

int main() {

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    vector<int> ans = intersection(nums1, nums2);

    for (int x : ans)
        cout << x << " ";
}