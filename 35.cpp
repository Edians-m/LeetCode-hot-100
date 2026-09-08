#include <iostream>
#include <vector>
using namespace std;

//左闭右开
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        while(l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }

        return l;
    }
};

//左闭右闭 
class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return l;
    }
};

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution1 s1;
    int ans1 = s1.searchInsert(nums, target);

    cout << ans1 << endl;
}