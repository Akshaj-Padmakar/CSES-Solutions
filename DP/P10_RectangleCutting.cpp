#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const int INF = 1e6;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    // dp[i][j] -> min cut st no more cuts are possible for i*j

    dp[1][1] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }
            for(int x = 1; x < i; x++) {
                dp[i][j] = min(dp[i][j], dp[x][j] + dp[i - x][j] + 1);
            }

            for(int x = 1; x < j; x++) {
                dp[i][j] = min(dp[i][j], dp[i][x] + dp[i][j - x] + 1);
            }
        }
    }

    cout << dp[n][m] << '\n';
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