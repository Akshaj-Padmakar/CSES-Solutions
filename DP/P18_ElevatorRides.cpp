#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 100;
pair<int, int> mn(pair<int, int> cur, pair<int, int> pos) {
    if(cur.first < pos.first) {
        return cur;
    } else if(cur.first > pos.first) {
        return pos;
    } else {
        return (cur.second < pos.second ? cur : pos);
    }
}
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &y: a) {
        cin >> y;
    }

    vector<pair<int, int>> dp(1ll<<n, {INF, 0});
    dp[0] = {0, 0};
    for(int msk = 1; msk < 1ll<<n; msk++) {
        for(int j = 0; j < n; j++) {
            if(!(msk & 1ll<<j)) {
                continue;
            }

            pair<int, int> prev = dp[msk ^ 1ll<<j];

            if(prev.second + a[j] <= x) {
                dp[msk] = mn(dp[msk], {prev.first, prev.second + a[j]});
            } else {
                dp[msk] = mn(dp[msk], {prev.first + 1, a[j]});
            }
        }
    }

    cout << dp[(1ll<<n) - 1].first + (dp[(1ll<<n) - 1].second > 0) << '\n';
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