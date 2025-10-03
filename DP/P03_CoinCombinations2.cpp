#include "bits/stdc++.h"
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int MOD = 1e9 + 7;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto &y: v) {
        cin >> y;
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for(auto &y : v) {
        for(int i = 1; i <= x; i++) {
            if(i >= y) {
                dp[i] += dp[i - y];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
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