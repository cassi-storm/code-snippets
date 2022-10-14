class Solution {
    public:
    bool findPartition(int a[], int n) {
        int sum_ = 4;
        vector<vector<long long>> dp(n + 1, vector<long long> (sum_ + 1, INT_MAX));
        sort(a, a + n);
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 0;
            for (int j = a[i - 1]; j <= sum_; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + 1);
            }
        }
        for (auto i : dp) {
            for (auto j : i) {
                printf("%12d", j);
            }
            cout << endl;
        }
        cout << dp[n][sum_] << endl;
        return 0;
    }
};
