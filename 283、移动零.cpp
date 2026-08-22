#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int t = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[t++], nums[i]);
            }
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution s;
    s.moveZeroes(nums);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << (i == n - 1 ? '\n' : ' ');
    }
}