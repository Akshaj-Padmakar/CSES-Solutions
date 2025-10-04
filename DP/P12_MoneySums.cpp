#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const int MAXN = 1e5 + 5;
void solve() {
    vector<bool> dp(MAXN, false); // dp[i] = making i is possible ?
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }   

    dp[0] = true;
    for(auto &x: a) {
        for(int i = MAXN - 1; i >= x; i--) {
            dp[i] = dp[i] | dp[i - x];
        }
    }
    vector<int> ans;
    for(int i = 1; i < MAXN; i++) {
        if(dp[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for(auto &x: ans) {
        cout << x << ' ';
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