#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 100005;
ll power[N];
ll fact[N];
const int mod = 1e9 + 7;

ll powe(ll base, int n, int mod) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * base) % mod;
            n--;
        } else {
            base = (base * base) % mod;
            n /= 2;
        }
    }
    return ans;
}

void preCompute() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    for (int i = 0; i < N; i++) {
        power[i] = powe(fact[i], mod - 2, mod);
    }
}

ll NcR(int n, int r) {
    if (r > n) return 0;
    return (fact[n] * (power[r] * power[n-r] % mod)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preCompute();

    int t = 1; // Number of test cases
    // cin >> t;

    while (t--) {
        int n, r;
        cin >> n >> r;
        cout << NcR(n, r) << "\n";
    }

    return 0;
}
