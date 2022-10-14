class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> dp(m, 0);
        int maxi = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[j] = a[i][j] == '1' ? dp[j] + 1 : 0;
            }
            maxi = max(maxi, getMaxArea(dp));
        }
        return maxi;
    }
    int getMaxArea(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; ++i) {
            while(!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }
            l[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i > -1; --i) {
            while(!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }
            r[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int maxi = 0;
        for (int i = 0; i < n; ++i) {
            maxi = max(maxi, a[i] * (r[i] - l[i] - 1));
        }
        return maxi;
    }
};
