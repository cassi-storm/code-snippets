class Solution {
public:
    int binarySearch(vector<int>& a, int x, bool lastIndex) {
        int mid, low = 0, high = a.size(); 
        if (!high || x > a[high - 1] || x < a[0]) return -1;
        if (lastIndex && a[high - 1] == x) return high - 1;
        lastIndex && ++x;
        while (low < high) {
            mid = (low + high) / 2;
            if (a[mid] < x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        lastIndex && --x;
        return lastIndex 
            ? (low ? (a[low - 1] == x ? low - 1 : -1) : -1) 
            : (a[low] == x ? low : -1);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, 0), binarySearch(nums, target, 1)};
    }
};
