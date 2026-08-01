#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = (r - l) * min(height[l], height[r]);

        while (l < r) {
            int s = r - l;
            ans = max(ans, s * min(height[l], height[r]));

            if (height[r] <= height[l])
                r--;
            else
                l++;
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution s;
    int result = s.maxArea(height);
    cout << "最大盛水量为: " << result << endl;

    return 0;
}