#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;

            int l = i + 1;
            int r = n - 1;
            int t = -nums[i];

            while(l < r) {
                if(nums[l] + nums[r] < t)
                    l++;
                else if(nums[l] + nums[r] > t)
                    r--;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }

        return res;
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
    vector<vector<int>> result = s.threeSum(nums);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}