#include "bits/stdc++.h"
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
    vector<int> col(n);
    for(auto &x: col) {
        cin >> x;
    }

    vector<vector<int>> g(n);
    for(int i = 0, a, b; i + 1 < n; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> ans(n);
    set<int> prev;
    function<void(int, int)> dfs=[&](int node, int p) {
        set<int> cur;
        cur.insert(col[node]);

        for(auto ch : g[node]) {
            if(ch ^ p) {
                dfs(ch, node);

                if(prev.size() > cur.size()) {
                    for(auto x : cur) {
                        prev.insert(x);
                    }
                    swap(prev, cur);
                } else {
                    for(auto x : prev) {
                        cur.insert(x);
                    }
                }
            }
        }
        ans[node] = cur.size();
        swap(cur, prev);
    };
    dfs(0, -1);
    for(auto &x: ans) {
        cout << x << " ";
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