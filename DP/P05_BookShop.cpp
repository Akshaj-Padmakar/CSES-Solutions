#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for(auto &x : h) {
        cin >> x;
    }
    for(auto &x : s) {
        cin >> x;
    }

    // dp[i][j] -> scanned first i books, with exact j cost, stores the max pages possible.

    vector<int> dp(x + 1, 0);
    dp[0] = 0;
    if(h[0] <= x) {
        dp[h[0]] = s[0];
    }

    for(int i = 1; i < n; i++) {
        vector<int> nxt(x + 1, 0);
        for(int j = 0; j <= x; j++) {
            nxt[j] = max(dp[j], j >= h[i] ? dp[j - h[i]] + s[i] : 0);
        }
        swap(nxt, dp);
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
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