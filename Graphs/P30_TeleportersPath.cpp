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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<int> in(n, 0), out(n, 0);
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back({b, i});
        in[b]++;
        out[a]++;
    }
    if(out[0] != in[0] + 1 || in[n-1] != out[n-1] + 1) {
        cout << "IMPOSSIBLE\n"; return;
    }

    for(int i = 1; i < n - 1; i++) {
        if(in[i] != out[i]) {
            cout << "IMPOSSIBLE\n"; return;
        }
    }
    vector<int> vis(m, 0), ans;
    function<void(int)> dfs=[&](int node) {
        while(g[node].size()) {
            auto [ch, id] = g[node].back();
            g[node].pop_back();
            if(vis[id]) {
                continue;
            }
            vis[id] = true;
            dfs(ch);
        }
        ans.push_back(node);
    };
    dfs(0);
    if((int)ans.size() <= m) {
        cout << "IMPOSSIBLE\n"; return;
    }

    reverse(ans.begin(), ans.end());
    for(auto &x: ans) {
        cout << x + 1 << " ";
    }
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