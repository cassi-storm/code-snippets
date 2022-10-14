#include <bits/stdc++.h>
#define endl "\n"
#define long long long int
#define sort(x) sort(x.begin(), x.end())
#define vmax(x) *max_element(x.begin(), x.end())
#define vmin(x) *min_element(x.begin(), x.end())
#define sum(x) accumulate(x.begin(), x.end(), 0l)
using namespace std;

int main()
{
    // cook your dish here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n), f(n);
        for (auto &i : a)
        {
            scanf("%d", &i);
        }
        map<int, int> x;
        int ans = n, ind = 0, cnt = 0;
        for (int i = 0; i < n; ++i) 
        {
            auto s = x.find(a[i]);
            if (s == x.end() || s->second < ind) 
            {
                cnt = i;
                int tp = min(ind, n - cnt - 1) + ind + n - cnt - 1;
                ans = min(ans, tp);
            }
            else
            {
                ind = s->second + 1;
            }
            x[a[i]] = i;
        }
        cout << ans << endl;
    }
    return 0;
}
