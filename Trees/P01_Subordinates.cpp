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
* Given a tree count the number of nodes in it's subtree
*/
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0, x; i < n - 1; i++) {
        cin >> x;
        x--;
        g[x].push_back(i + 1);
        g[i + 1].push_back(x);
    }

    vector<int> sz(n, 0);
    function<void(int, int)> dfs=[&](int node, int p) {
        sz[node] = 1;
        for(auto ch : g[node]) {
            if(ch ^ p) {
                dfs(ch, node);
                sz[node] += sz[ch];
            }
        }
    };

    dfs(0, -1);

    for(auto &x: sz) {
        cout << x - 1 << ' '; // exclude itself.
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