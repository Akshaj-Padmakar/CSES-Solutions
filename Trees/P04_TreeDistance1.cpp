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
Claim : diameter nodes -> farthest 
*/
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
 
    for(int i = 0, a, b; i + 1 < n; i++) {
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    function<void(int, int, int, vector<int> &)> dfs=[&](int node, int p, int d,vector<int>& dis) {
        dis[node] = d;
        for(auto ch: g[node]) {
            if(ch ^ p) {
                dfs(ch, node, d + 1, dis);
            }
        }
    };
 
    vector<vector<int>> dis(2, vector<int>(n, 0));
    
    dfs(0, -1, 0, dis[0]);
 
    int mxN = max_element(dis[0].begin(), dis[0].end()) - dis[0].begin();
    dfs(mxN, -1, 0, dis[0]);
 
    int mxN2 = max_element(dis[0].begin(), dis[0].end())- dis[0].begin();
 
    dfs(mxN2, -1, 0, dis[1]);
    for(int i = 0; i < n; i++) {
        cout << max(dis[0][i], dis[1][i]) << ' ';
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
