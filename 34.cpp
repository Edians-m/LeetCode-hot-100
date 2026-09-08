//在排序数组中查找元素的第一个和最后一个位置
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n;
        int pos_l = 0;
        int pos_r = 0;

        //找到第一个 >= target的数
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        if(l < n && nums[l] == target) pos_l = l;
        else return {-1, -1};

        r = n;
        //找到第一个 > target的数
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        pos_r = l;

        return {pos_l, --pos_r};
    }
};

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution s;
    vector<int> ans = s.searchRange(nums, target);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}