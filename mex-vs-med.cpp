#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod_ 1000000007
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            a[x] = i;
        }
        int ans = 0, l = n, r = -1;
        // cout << "Debug : \n";
        for (int i = 1; i <= n; ++i)
        { // length i
            if (i & 1)
            {
                l = min(l, a[i / 2]);
                r = max(r, a[i / 2]);
            }
            ans += max(0ll, min(n - i, l) - max(0ll, r + 1 - i) + 1);
            // cout << "(" << l << ", " << r << ", " << ans << ")\n";
        }
        cout << ans << endl;
        // cout << endl;
    }
    return 0;
}
