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
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }
    vector<vector<int>> g(n), rg(n);
    vector<array<int, 2>> e;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        rg[b].push_back(a);
        e.push_back({a, b});
    }
    vector<int> vis(n, false), out;
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
    function<void(int, vector<int>&)> dfs2=[&](int node, vector<int> &cur) {
        vis[node] = true;
        for(auto &ch: rg[node]) {
            if(!vis[ch]) {
                dfs2(ch, cur);
            }
        }
        cur.push_back(node);
    };

    vis.assign(n, false);
    vector<vector<int>> scc;
    for(int i = out.size() - 1; i >= 0; i--) {
        int node = out[i];
        if(!vis[node]) {
            vector<int> cur;
            dfs2(node, cur);
            scc.push_back(cur);
        }
    }

    set<array<int, 2>> e_condense;
    vector<int> id(n, 0), val;
    int idd = 0;
    for(auto &x: scc){
        int sm = 0;
        for(auto &y: x) {
            id[y] = idd;
            sm += a[y];
        }
        val.push_back(sm);
        idd++;
    }

    for(auto [a, b] : e) {
        if(id[a] != id[b]) {
            e_condense.insert({id[a], id[b]});
        }
    }

    vector<vector<int>> g_condense(idd), rg_condense(idd);
    vector<int> in(idd, 0);
    for(auto [a, b] : e_condense) {
        g_condense[a].push_back(b);
        rg_condense[b].push_back(a);
        in[b]++;
    }

    queue<int> q;
    for(int i = 0; i < idd; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }
    vector<int> tp;
    while(q.size()) {
        int node = q.front();
        q.pop();
        tp.push_back(node);
        for(auto &ch : g_condense[node]) {
            in[ch]--;
            if(in[ch] == 0) {
                q.push(ch);
            }
        }
    }
    vector<int> dp(idd, 0);
    for(auto node : tp) {
        dp[node] = val[node];
        for(auto prev : rg_condense[node]) {
            dp[node] = max(dp[node], dp[prev] + val[node]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
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