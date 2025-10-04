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
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v;
    // r, l, p

    for(int i = 0, l , r, p; i < n; i++) {
        cin >> l >> r >> p;
        v.push_back({r, {l, p}});
    }
    sort(v.begin(), v.end());
    vector<int> l(n), r(n), p(n);
    for(int i = 0; i < n; i++) {
        l[i] = v[i].second.first;
        r[i] = v[i].first;
        p[i] = v[i].second.second;
    }

    vector<vector<int>> dp(n, vector<int>(2, 0));
    // dp[i][0] -> dont take the ith project, max money made;
    // dp[i][1] -> take the ith project, max money made;

    dp[0][0] = 0;
    dp[0][1] = p[0];
    for(int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

        auto it = lower_bound(r.begin(), r.end(), l[i]);
        if(it != r.begin()) {
            it--;
            int id = it - r.begin();
            dp[i][1] = max(dp[id][0], dp[id][1]) + p[i];
        } else {
            dp[i][1] = p[i];
        }
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]);
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