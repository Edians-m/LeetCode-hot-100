//搜索二维矩阵
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = m*n;
        int l = 0;

        while(l < r) {
            int mid = l + (r-l)/2;
            int x = matrix[mid/n][mid%n];

            if(target == x) return true;
            else if(target < x) r = mid;
            else l = mid + 1; 
        }

        return false;
    }
};

int main() {
    int m, n, target;
    cin >> m >> n >> target;

    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution s;
    bool ans = s.searchMatrix(matrix, target);

    cout << (ans ? "true" : "false") << endl;

    return 0;
}