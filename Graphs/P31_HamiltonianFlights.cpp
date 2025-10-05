#include <bits/stdc++.h>
using namespace std;

// #define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const int MOD = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), rg(n);
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }


    vector<vector<int>> dp(n, vector<int>(1ll<<n, 0));
    // dp[i][msk] -> number of ways reach node i visiting msk set of nodes.

    dp[0][1] = 1;

    for(int msk = 1; msk < 1ll<<n; msk++) {
        int on = __builtin_popcount(msk);
        if(on == 1 || !(msk & 1)) {
            // base case
            continue;
        }

        for(int i = 0; i < n; i++) {
            if(!(msk & 1ll<<i)) {
                continue;
            }
 
            for(auto node : rg[i]) {
                if(!(msk & 1ll<<node)) {
                    continue;
                }
                dp[i][msk] += dp[node][msk ^ (1ll<<i)];
                dp[i][msk] %= MOD;
            }
        }
    }
    cout << dp[n-1][(1ll<<n) - 1] << '\n';
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