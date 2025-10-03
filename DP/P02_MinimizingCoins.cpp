#include "bits/stdc++.h"
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 1e9;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &y : a) {
        cin >> y;
    }

    vector<int> dp(x + 1, INF);

    dp[0] = 0;
    for(int i = 1; i <= x; i++) {
        for(auto y : a) {
            dp[i] = min(dp[i], i >= y ? dp[i - y] + 1 : INF);
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
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