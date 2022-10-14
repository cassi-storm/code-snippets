class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxi = 1;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                dp[i][i + 1] = 2;
            }
        }
        for (int i = 1; i < n; ++i) { 
            for (int j = 0; i + j < n; ++j) {
                if (s[j] == s[i + j] && dp[j + 2][i + j]) {
                    dp[j + 1][i + j + 1] = dp[j + 2][i + j] + 2;
                } 
                if (maxi < dp[j + 1][i + j + 1]) {
                    maxi = dp[j + 1][i + j + 1];
                    start = j;
                }
            }
        }
        return s.substr(start, maxi);
    }
};
