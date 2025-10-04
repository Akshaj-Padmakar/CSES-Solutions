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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    vector<int> dp(m + 1, 0);
    // dp[i][j] -> number of ways to place j on i-th place.
    if(a[0]) {
        dp[a[0]] = 1;
    } else {
        for(int i = 1; i <= m; i++) {
            dp[i] = 1;
        }
    }

    for(int i = 1; i < n; i++) {
        vector<int> nxt(m + 1, 0);
        if(a[i] == 0) {
            for(int j = 1; j <= m; j++) {
                nxt[j] = (j >= 2 ? dp[j - 1] : 0) + dp[j] + (j + 1 <= m ? dp[j+1] : 0);
                nxt[j] %= MOD;
            }
        } else {
            int j = a[i];
            nxt[j] = (j >= 2 ? dp[j - 1] : 0) + dp[j] + (j + 1 <= m ? dp[j+1] : 0);
            nxt[j] %= MOD;
        }
        swap(nxt, dp);
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans << '\n';
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