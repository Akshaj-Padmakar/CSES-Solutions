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
    vector<vector<int>> g(2*m), rg(2*m);
    for(int i = 0; i < n; i++) {
        char aa, bb;
        int a, b;
        cin >> aa >> a >> bb >> b;
        a--, b--;
        if(a == b && aa == bb) {
            if(aa == '-') {
                g[a].push_back(a + m);
                rg[a + m].push_back(a);
            } else {
                g[a + m].push_back(a);
                rg[a].push_back(a + m);
            }
            continue;
        }
        if(aa == '+' && bb == '+') {
            g[a + m].push_back(b);
            g[b + m].push_back(a);

            rg[b].push_back(a + m);
            rg[a].push_back(b + m);
        } else if(aa == '+' && bb == '-') {
            g[a + m].push_back(b + m);
            g[b].push_back(a);

            rg[b + m].push_back(a + m);
            rg[a].push_back(b);
        } else if(aa == '-' && bb == '+') {
            g[a].push_back(b);
            g[b + m].push_back(a + m);

            rg[b].push_back(a);
            rg[a + m].push_back(b + m);
        } else { // - -
            g[a].push_back(b + m);
            g[b].push_back(a + m);
            
            rg[b + m].push_back(a);
            rg[a + m].push_back(b);
        }
    }


    vector<bool> vis(2*m, false);
    vector<int> out;
    function<void(int)> dfs=[&](int node) {
        vis[node] = true;
        for(auto ch: g[node]) {
            if(!vis[ch]) {
                dfs(ch);
            }
        }
        out.push_back(node);
    };

    for(int i = 0; i < 2*m; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    function<void(int, vector<int> &)> dfs2=[&](int node, vector<int> &cur) {
        cur.push_back(node);
        vis[node] = true;
        for(auto ch: rg[node]) {
            if(!vis[ch]) {
                dfs2(ch, cur);
            }
        }
    };


    vis.assign(2*m, false);
    vector<vector<int>> ans;
    for(int i = out.size() - 1; i >= 0; i--) {
        int node = out[i];
        if(!vis[node]) {
            vector<int> cur;
            dfs2(node, cur);
            ans.push_back(cur);
        }
    }

    int id = 0;
    reverse(ans.begin(), ans.end());
    vector<int> comp(2*m, 0);
    for(auto v : ans) {
        for(auto x : v) {
            comp[x] = id;
        }
        id++;
    }

    debug(ans);

    for(int i = 0; i < m; i++) {
        if(comp[i] == comp[i + m]) {
            cout << "IMPOSSIBLE\n"; return;
        }
    }
    vector<int> add(m, -1);
    
    for(auto v : ans) {
        for(auto x : v) {
            if(add[x % m] == -1) {
                add[x % m] = (x >= m ? 0 : 1);
            }
        }
    }

    for(auto &x: add) {
        cout << (x == 0 ? '-' : '+') << " ";
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