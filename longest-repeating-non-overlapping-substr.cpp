#include<bits/stdc++.h>
using namespace std;

string longestSubstring(string s, int n) {
	int start = -1, max_ = 0;
	vector<vector<int>> v(n + 1, vector<int> (n + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (s[i - 1] == s[j - 1]) {
				v[i][j] = v[i - 1][j - 1] + 1;
				if (min(j - i, v[i][j]) > max_) {
					max_ = min(j - i, v[i][j]);
					start = j - max_;
				}
			}
		}
	}
	return start == -1
		? "-1"
		: s.substr(start, max_);
}

int main() {
	cout << longestSubstring("sandyblazesandy", 15) << endl;
	return 0;
}
