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
Given a tree find it's diameter.
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

    int mx = -1, mxN = 0;
    function<void(int, int, int)> dfs=[&](int node, int p, int d) {
        if(mx < d) {
            mx = d;
            mxN = node;
        }
        for(auto ch: g[node]) {
            if(ch ^ p) {
                dfs(ch, node, d + 1);
            }
        }
    };

    dfs(0, -1, 0);
    mx = -1;
    dfs(mxN, -1, 0);

    cout << mx << '\n';
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