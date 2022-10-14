class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> a(n, 0), b(n, 0);
        a[0] = h[0];
        for (int i = 1; i < n; ++i) {
            a[i] = max(h[i], a[i - 1]);
        }
        b[n - 1] = h[n - 1];
        for (int i = n - 2; i > -1; --i) {
            b[i] = max(h[i], b[i + 1]);
        }
        int sumi = 0;
        for (int i = 0; i < n; ++i) {
            sumi += max(min(a[i], b[i]) - h[i], 0);
        }
        return sumi;
    }
};
