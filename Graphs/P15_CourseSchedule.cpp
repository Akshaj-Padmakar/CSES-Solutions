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
    vector<vector<int>> g(n);
    vector<int> in(n, 0);
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        in[b]++;
    }


    queue<int> q;
    vector<int> tp;
    for(int i = 0; i < n; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }

    while(q.size()) {
        int node = q.front();
        q.pop();
        tp.push_back(node);
        for(auto &x: g[node]) {
            in[x]--;
            if(in[x] == 0) {
                q.push(x);
            }
        }
    }

    if((int)tp.size() < n) { // there is a cycle.
        cout << "IMPOSSIBLE\n"; return;
    }

    for(auto &x: tp) {
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