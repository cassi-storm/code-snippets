class Solution {
public:
    double getMedian(vector<int> &a, vector<int> &b) {
        const int big = 1000000000;
        int n = a.size(), m = b.size();
        int i = 0, j = n, rmid = (n + m + 1) / 2;
        int la, lb, ra, rb;
        while (i <= j) {
            int mida = (i + j) / 2;
            int midb = rmid - mida;
            la = (mida > 0 ? a[mida - 1] : -big), lb = (midb > 0 ? b[midb - 1] : -big);
            ra = (mida < n ? a[mida] : big), rb = (midb < m ? b[midb] : big);
            if (la <= rb && lb <= ra) {
                if ((m + n) % 2 == 1) {
                    return max(la, lb);
                }
                return (1.0 * max(la, lb) + min(ra, rb)) / 2;
            } 
            if (la > lb) j = mida - 1;
            else i = mida + 1;
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n == 1 && m == 1) {
            return 1.0 * (nums1[0] + nums2[0]) / 2;
        }
        if (n > m) {
            return getMedian(nums2, nums1);
        }
        return getMedian(nums1, nums2);
    }
};
