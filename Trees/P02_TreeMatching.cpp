#include "bits/stdc++.h"
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/*
Matching of graph = set of edges such that each node is part of only 1 node.
*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);

    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<int>> dp(n, vector<int>(2, 0));
    // dp[node][0] -> number of matching in the subtree of node. s.t node IS NOT matched.
    // dp[node][0] -> number of matching in the subtree of node. s.t node IS matched.
    
    function<void(int, int)> dfs=[&](int node, int p) {
        for(auto ch : g[node]) {
            if(ch ^ p) {
                dfs(ch, node);
                dp[node][0] += max(dp[ch][0], dp[ch][1]);
            }
        }

        for(auto ch : g[node]) {
            if(ch ^ p) {
                dp[node][1] = max(dp[node][1], dp[node][0] - max(dp[ch][0], dp[ch][1]) + dp[ch][0] + 1); // match node <-> ch
            }
        }
    };

    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
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