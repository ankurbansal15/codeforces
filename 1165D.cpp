#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        long long x = a.front() * a.back();

        vector<long long> divisors;
        for (long long i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                divisors.push_back(i);
                if (i != x / i) {
                    divisors.push_back(x / i);
                }
            }
        }

        sort(divisors.begin(), divisors.end());

        if (divisors == a) {
            cout << x << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
