#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);
    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution s;
    vector<vector<string>> result = s.groupAnagrams(strs);
    
    
}