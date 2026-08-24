// 除自身以外数组的乘积
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1);

        for(int i = n-2; i >= 0; i--) {
            ans[i] = ans[i+1]*nums[i+1];
        }

        int l = nums[0];
        for(int i = 1; i < n; i++) {
            ans[i] = l*ans[i];
            l *= nums[i];
        }

        return ans;
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
    vector<int> ans = s.productExceptSelf(nums);

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}