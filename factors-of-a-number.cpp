#include <iostream>

int get_factors(int n) {
    int sumi = 0;
    vector<int> a;
    if (n % 2 == 0) {
        a.push_back(2);
        while (n % 2 == 0) {
            sumi += 2;
            n /= 2;
        }
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            a.push_back(i);
            while (n % i == 0) {
                sumi += i;
                n /= i;
            }
        }
    }
    if (n > 2) {
        a.push_back(n);
        sumi += n;
    }
    for (auto i : a) {
        cout << i << " " << (n / i) << " ";
    }
    return sumi;
}
