#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1005;

bool isPrime[MAX];

void sieve(int n) {
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i*i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    sieve(n);

    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    int count = 0;
    for (int i = 0; i + 1 < primes.size(); ++i) {
        int sum = primes[i] + primes[i + 1] + 1;
        if (sum <= n && isPrime[sum]) {
            count++;
        }
    }

    cout << (count >= k ? "YES" : "NO");
    return 0;
}
