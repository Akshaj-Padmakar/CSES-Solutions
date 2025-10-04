#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int MOD = 1e9 + 7;
int binpow(int a, int b) {
    if(b == 0) {
        return 1;
    }

    int x = binpow(a, b/2);
    return (((x * x) % MOD) * (b % 2 ? a : 1)) % MOD;
}

int inv(int x) {
    return binpow(x, MOD - 2);
}
void solve() {
    int n;
    cin >> n;
    int sm = (n * (n + 1)) /2;

    if(sm % 2) {
        cout << 0 << '\n'; return;
    }

    vector<int> dp(sm + 1, 0);
    // dp[i] -> number of ways to create exact sum i;
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        vector<int> nxt = dp;
        for(int j = i; j <= sm; j++) {
            nxt[j] += dp[j - i];
            nxt[j] %= MOD;
        }
        swap(nxt , dp);
    }
    debug(inv(2));
    cout << (dp[sm/2] * inv(2)) % MOD << '\n';
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