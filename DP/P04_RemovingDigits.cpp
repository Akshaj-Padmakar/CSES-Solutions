#include "bits/stdc++.h"
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 1e7;
void solve() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    function<int(int)> dfs=[&](int x) {
        if(dp[x] != -1) {
            return dp[x];
        }

        string sx = to_string(x);

        int ans = INF;
        for(auto ch : sx) {
            if(ch == '0') {
                continue;
            }
            ans = min(ans, dfs(x - (ch - '0')) + 1);
        }
        return dp[x] = ans;
    };

    cout << dfs(n) << '\n';
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