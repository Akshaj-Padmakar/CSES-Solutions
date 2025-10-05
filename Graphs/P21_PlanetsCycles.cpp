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
    vector<vector<int>> g(n), rg(n);
    vector<int> in(n, 0);

    for(int i = 0, x; i < n; i++) {
        cin >> x; x--;
        g[i].push_back(x);
        rg[x].push_back(i);
        in[x]++;
    }

    queue<int> q;
    vector<bool> done(n, false) ;
    vector<int> tp;
    for(int i = 0; i < n; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }

    while(q.size()) {
        int node = q.front(); q.pop();
        tp.push_back(node);
        done[node] = 1;

        for(auto ch : g[node]) {
            in[ch]--;
            if(in[ch] == 0) {
                q.push(ch);
            }
        }
    }
    vector<vector<int>> cycle;
    vector<int> vis(n, false);
    function<void(int, vector<int> &)> dfs=[&](int node, vector<int> &cur) {
        cur.push_back(node);
        vis[node] = 1;
        for(auto ch : g[node]) {
            if(!vis[ch]) {
                dfs(ch, cur);
            }
        }
    };

    vector<int> dp(n, 0);
    // dp[i] -> number of edges passed to reach a visited node.

    for(int i = 0; i < n; i++) {
        if(!done[i] && vis[i] == false) {
            vector<int> cur;
            dfs(i, cur);
            for(auto node : cur) {
                dp[node] = (int)cur.size();
            }
        }
    }

    reverse(tp.begin(), tp.end());

    for(auto node : tp) {
        for(auto ch : g[node]) {
            dp[node] = dp[ch] + 1;
        }
    }


    for(auto &x: dp) {
        cout << x << " ";
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