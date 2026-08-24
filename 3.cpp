// 无重复字符的最长子串
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//哈希表
class S_hash {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hs;
        int n = s.size();
        int l = 0;
        int r = 0;
        int ans = 0;

        for(r; r < n; r++) {
            auto it = hs.find(s[r]);
            if(it != hs.end() && hs[s[r]] >= l) {
                l = hs[s[r]] + 1;
            }

            hs[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

//ASCLL
class S_vector {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> a(128, -1);
        int n = s.size();
        int l = 0;
        int r = 0;
        int ans = 0;

        for(r; r < n; r++) {
            if(a[s[r]] >= l) {
                l = a[s[r]] + 1;
            }

            a[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main() {
    string s;
    cin >> s;

    S_hash S1;
    cout << S1.lengthOfLongestSubstring(s) << endl;
}