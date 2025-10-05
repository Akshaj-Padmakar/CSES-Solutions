#include <bits/stdc++.h>
using namespace std;

// #define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// How is this failing???
const int LOGN = 30;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for(auto &x: p) {
        cin >> x; x--;
    }
    vector<array<int, LOGN>> dp(n);
    for(int i = 0; i < n; i++) {
        dp[i][0] = p[i];
    }

    for(int j = 1; j < LOGN; j++) {
        for(int i = 0; i < n; i++) {
            int prev = dp[i][j-1];
            dp[i][j] = dp[prev][j-1];
        }
    }

    auto ancestor=[&](int x, int k) {
        int cur = x;
        for(int i = LOGN - 1; i >= 0; i--) {
            if(k & (1ll << i)) {
                cur = dp[cur][i];
            }
        }
        return cur;
    };

    while(q--) {
        int x, k; cin >> x >> k; x--;
        cout << ancestor(x, k) + 1 << '\n';
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    // cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}