#include "bits/stdc++.h"
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int LOGN = 22;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for(int i = 0, x; i + 1 < n; i++) {
        cin >> x; x--;
        g[x].push_back(i + 1);
        g[i + 1].push_back(x);
    }

    vector<vector<int>> dp(n, vector<int>(LOGN, -1));
    vector<int> depth(n, 0);

    function<void(int, int)> dfs_lca=[&](int node, int p) {
        dp[node][0] = p;
        depth[node] = (p == -1 ? 0 : (depth[p] + 1));
        for(int i = 1; i < LOGN; i++) {
            int prev = dp[node][i - 1];
            if(prev != -1) {
                dp[node][i] = dp[prev][i - 1];
            }
        }

        for(auto ch : g[node]) {
            if(ch ^ p) {
                dfs_lca(ch, node);
            }
        }
    };

    dfs_lca(0, -1);

    auto ancestor=[&](int node, int k) {
        int cur = node;
        for(int i = 0; i < LOGN; i++) {
            if(k & 1ll<<i) {
                cur = dp[cur][i];
            }
            if(cur == -1) {
                return (int)-1;
            }
        }

        return cur;
    };

    auto lca=[&](int a, int b) {
        if(depth[a] < depth[b]) {
            swap(a, b);
        }

        a = ancestor(a, depth[a] - depth[b]);

        if(a == b) {
            return a;
        }

        for(int i = LOGN - 1; i >= 0; i--) {
            if(dp[a][i] != dp[b][i]) {
                a = dp[a][i];
                b = dp[b][i];
            }
        }

        return dp[a][0];
    };


    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        cout << lca(a, b) + 1 << '\n';
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