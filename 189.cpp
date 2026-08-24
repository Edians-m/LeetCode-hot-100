// 轮转数组
#include <iostream>
#include <vector>
using namespace std;

//开数组复制
class Solution01 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k%n == 0) {
            return;
        }
        k %= n;

        vector<int> res;
        for(int i = n-k; i < n; i++) {
            res.push_back(nums[i]);
        }

        for(int i = 0; i < n-k; i++) {
            res.push_back(nums[i]);
        }

        nums = res;
    }
};

//先整体旋转，再局部旋转
class Solution02 {
public:
    void reverse(vector<int>& nums, int l, int r) {
        while(l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution02 s;
    s.rotate(nums, k);

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
}
