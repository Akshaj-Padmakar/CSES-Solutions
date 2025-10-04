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
const int MAXN = 1e6 + 1;
vector<vector<int>> dp(MAXN, vector<int>(2));
/* 
dp[i][0] -> both tiles are not joined at the i-th index.
    * doesn't extend -> dp[i-1][1] + dp[i-1][0]
    * 1 extend -> dp[i-1][0] * 2(both side)
    * both extend -> dp[i-1][0];
dp[i][1] -> both tiles are joined at i-th index
    * doesn't extend -> dp[i-1][0] + dp[i-1][1]
    * extend -> dp[i-1][1];
*/
void solve() {
    int x;
    cin >> x;
    cout << (dp[x][0] + dp[x][1]) % MOD << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i < MAXN; i++) {
        dp[i][0] = (4* dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1]) % MOD;
    }

    while (t--) {
        solve();
    }

    // cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}