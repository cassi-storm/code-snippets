class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), maxi = 0, sumi = 0;
        stack<int> st;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (!st.empty()) {
                dp[i] = i - st.top() + 1;
                st.pop();
            }
        }
        int i = n - 1;
        while (i > -1) {
            if (dp[i] == 0) {
                --i;
                sumi = 0;
                continue;
            }
            sumi += dp[i];
            i -= dp[i];
            maxi = max(maxi, sumi);
        }
        return maxi;
    }
};
