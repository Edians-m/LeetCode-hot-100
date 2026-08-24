// 最大子数组和
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int res = nums[0];

        for(int i = 1; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            res = max(res, sum);
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution s;
    int result = s.maxSubArray(nums);
    cout << result << '\n';

    return 0;
}