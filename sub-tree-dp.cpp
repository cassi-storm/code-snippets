#include <bits/stdc++.h>
#define endl "\n"
#define long long long int
#define sort(x) sort(x.begin(), x.end())
#define vmax(x) *max_element(x.begin(), x.end())
#define vmin(x) *min_element(x.begin(), x.end())
#define sum(x) accumulate(x.begin(), x.end(), 0l)
using namespace std;

int dfs(int root, int p, vector<int> &a, vector<int> &b, vector<vector<int>> &dp, vector<vector<int>> &tr, int flag)
{
    if (dp[flag][root] != -1)
        return dp[flag][root];
    int col = a[root], ans = 0;
    if (flag && p != -1)
        col = b[p];
    if (col != b[root])
    {
        ans = 1;
        for (auto i : tr[root])
        {
            if (i != p)
            {
                ans += dfs(i, root, a, b, dp, tr, 1);
            }
        }
    }
    else
    {
        int v1 = 0, v2 = 1;
        for (auto i : tr[root])
        {
            if (i != p)
            {
                v1 += dfs(i, root, a, b, dp, tr, flag);
                v2 += dfs(i, root, a, b, dp, tr, 1);
            }
        }
        ans = min(v1, v2);
    }
    return dp[flag][root] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cook your dish here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<vector<int>> dp(2, vector<int>(n, -1));
        for (auto &i : a)
        {
            cin >> i;
        }
        for (auto &i : b)
        {
            cin >> i;
        }
        int u, v, ue, ve;
        vector<vector<int>> tr(n);
        for (int i = 1; i < n; ++i)
        {
            cin >> u >> v;
            u--;
            v--;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        int count;
        count = dfs(0, -1, a, b, dp, tr, 0);
        cout << count << endl;
    }
    return 0;
}
