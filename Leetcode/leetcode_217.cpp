#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {

    unordered_set<int> seen;

    for(int i = 0; i < nums.size(); i++) {

        if(seen.find(nums[i]) != seen.end()) {
            return false;
        }

        seen.insert(nums[i]);
    }

    return true;
}

int main() {

    vector<int> nums = {1, 2, 3, 4,1};

    bool ans = containsDuplicate(nums);

    cout << ans;

    return 0;
}