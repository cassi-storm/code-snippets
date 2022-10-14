class Solution {
public:
    void get_all_strings(vector<string> &a, string cr, int n) {
        if (n == 0) {
            a.push_back(cr);
            return;
        }
        string s3 = cr + "()", s2 = "()" + cr, s1 = "(" + cr + ")";
        get_all_strings(a, s1, n - 1);
        if (s1 != s2) {
            get_all_strings(a, s2, n - 1);    
        }
        if (s1 != s3 && s2 != s3) {
            get_all_strings(a, s3, n - 1);    
        }
    } 
    vector<string> generateParenthesis(int n) {
        vector<string> a;
        get_all_strings(a, "", n);
        return a;
    }
};
