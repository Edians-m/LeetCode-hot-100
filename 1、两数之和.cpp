#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for(int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];

            auto it = hash.find(t);
            if(it != hash.end()) {
                return {it->second, i};
            }

            hash[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    Solution s;
    vector<int> result = s.twoSum(nums, target);

    if(result.size() == 2) {
        cout << result[0] << " " << result[1] << '\n';
    }else {
        cout << "Not found" << '\n';
    }
}