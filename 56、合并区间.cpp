#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(n == 0) {
            return {};
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];

            if(!res.size() || res.back()[1] < l) {
                res.push_back({l, r});
            }else {
                res.back()[1] = max(res.back()[1], r);
            }
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution s;
    vector<vector<int>> result = s.merge(intervals);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
}