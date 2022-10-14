class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        vector<int> maxv(n - k + 1);
        deque<pair<int, int>> dq;
        for (int i = 0; i + 1 < k; ++i) { 
            while (dq.size() && dq.back().first <= a[i]) {
                dq.pop_back();
            }
            dq.push_back({a[i], i});
        }
        for (int i = 0, j = k - 1; j < n; ++i, ++j) {
            if (dq.size() && dq.front().second < i) {
                dq.pop_front();
            }
            while (dq.size() && dq.back().first <= a[j]) {
                dq.pop_back();
            }
            dq.push_back({a[j], j});
            maxv[i] = dq.front().first;
        }
        return maxv;
    }
};
