#define Int long long

class SegmentTree {
    Int n;
    vector<Int> tree, v;
    void build(Int node, Int l, Int r) {
        if (l == r) {
            tree[node] = v[l];
            return;
        }
        Int m = l + (r - l) / 2;
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    void put(Int node, Int i, Int s, Int e, Int x) {
        if (i < s || e < i) 
            return;
        if (s == e) { 
            tree[node] += x;
            return; 
        }
        Int m = s + (e - s) / 2;
        put(2 * node, i, s, m, x);
        put(2 * node + 1, i, m + 1, e, x);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    Int get(Int node, Int l, Int r, Int s, Int e) {
        if (s > r || l > e) return 0;
        if (l <= s && e <= r) {
            return tree[node]; 
        }
        Int m = s + (e - s) / 2;
        return get(2 * node, l, r, s, m) + get(2 * node + 1, l, r, m + 1, e);
    }
public:
    SegmentTree(Int size) {
        n = size;
        v = vector<Int> (n, 0);
        tree = vector<Int> (4 * n, 0);
        build(1, 0, n - 1);
    }
    
    void puti(Int index) {
        ++v[index];
        Int x = 1;
        put(1, index, 0, n - 1, x);
    }
    
    Int getr(Int left, Int right) {
        return get(1, left, right, 0, n - 1);
    }
};

class Solution {
public:
    Int reversePairs(vector<Int>& nums) {
        vector<Int> a = nums;
        Int n = nums.size(), count = 0;
        SegmentTree tree(n);
        sort(a.begin(), a.end());
        for (Int i = 0; i < n; ++i) {
            count += tree.getr(upper_bound(a.begin(), a.end(), 2 * nums[i]) - a.begin(), n - 1);
            tree.puti(lower_bound(a.begin(), a.end(), nums[i]) - a.begin());
        }
        return count;
    }
};
