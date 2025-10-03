#include "bits/stdc++.h"
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
    vector<vector<int>> g(n);

    for(int i = 0, a, b; i + 1 < n; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dp(n, 0), sz(n, 0);
    // dp[node] -> sum of distance of nodes in subtree of node.
    
    function<void(int, int)> dfs=[&](int node, int p) {
        sz[node] = 1;
        for(auto ch : g[node]) {
            if(ch ^ p) {
                dfs(ch, node);
                sz[node] += sz[ch];
                dp[node] += (dp[ch] + sz[ch]);
            }
        }
    };

    dfs(0, -1);

    vector<int> ans(n, 0);
    function<void(int, int)> dfs_reroot=[&](int node, int p) {
        ans[node] = dp[node];

        for(auto ch : g[node]) {
            if(ch ^ p) {
                dp[node] -= dp[ch] + sz[ch];
                sz[node] -= sz[ch];

                sz[ch] += sz[node];
                dp[ch] += dp[node] + sz[node];

                dfs_reroot(ch, node);

                dp[ch] -= dp[node] + sz[node];
                sz[ch] -= sz[node];

                sz[node] += sz[ch];
                dp[node] += dp[ch] + sz[ch];
            }
        }
    };


    dfs_reroot(0, -1);

    for(auto &x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
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