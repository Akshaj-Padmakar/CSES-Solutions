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
    vector<vector<int>> g(n), rg(n);
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    vector<int> out;
    vector<bool> vis(n, false);
    function<void(int)> dfs=[&](int node) {
        vis[node] = true;
        for(auto ch : g[node]) {
            if(!vis[ch]) {
                dfs(ch);
            }
        }
        out.push_back(node);
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    vis.assign(n, false);

    function<void(int, vector<int> &)> dfs2=[&](int node, vector<int> &cur) {
        vis[node] = 1;
        cur.push_back(node);
        for(auto &ch: rg[node]) {
            if(!vis[ch]) {
                dfs2(ch, cur);
            }
        }
    };

    vector<vector<int>> ans;
    for(int i = out.size()-1; i >= 0; i--) {
        if(!vis[out[i]]) {
            vector<int> cur;
            dfs2(out[i], cur);
            ans.push_back(cur);
        }
    }

    if(ans.size() >= 2) {
        cout << "NO\n";
        cout << ans[1][0] + 1 << " " << ans[0][0] + 1 << '\n';
    } else {
        cout << "YES\n";
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