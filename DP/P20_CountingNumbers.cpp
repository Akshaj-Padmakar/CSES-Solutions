#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int dp[20][10][2][2];
void solve() {
    int a, b;
    cin >> a >> b;

    a--;
    string aa = to_string(a);
    string bb = to_string(b);

    function<int(int, int, bool, bool, string&)> dfs=[&](int id, int cur, bool leading, bool tight, string &x) {
        if(id == 0) {
            return 1ll;
        }

        if(dp[id][cur][leading][tight] != -1) {
            return dp[id][cur][leading][tight];
        }

        int ans = 0;
        if(leading) {
            ans += dfs(id - 1, 0, 1, 0, x);
        }

        int ub = tight ? (x[x.size() - id] - '0') : 9;
        for(int i = (leading ? 1 : 0); i <= ub; i++) {
            if(i == cur && !leading) {
                continue;
            }
            ans += dfs(id - 1, i, 0, tight && (i == ub), x);
        }
        return dp[id][cur][leading][tight] = ans;
    };

    memset(dp, -1ll, sizeof(dp));
    int ansR = dfs(bb.size(), 0, 1, 1, bb);
    int ansL = 0;

    if(a >= 0) {
        memset(dp, -1ll, sizeof(dp));
        ansL = dfs(aa.size(), 0, 1, 1, aa);
    }

    cout << ansR - ansL << '\n';
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