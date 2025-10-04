#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

/*
new 
greedy + dp
diagonal iteration mat galat kariyo bhai
*/
void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for(auto &x: a) {
        for(auto &y : x) {
            cin >> y;
        }
    }

    string ans;

    vector<vector<int>> good(n, vector<int>(n, false));
    good[0][0] = true;
    int cur = 0;
    
    while(cur <= 2*n - 2) {
        for(int i = max(0ll, cur - (n - 1)); i <= min(n - 1, cur); ++i){
            int j = cur - i;
            if(good[i][j]) {
                ans.push_back(a[i][j]);
                break;
            }
        }
        cur++;
        char pos = 'z';
        auto ok=[&](int i, int j) {
            return (i > 0 ? good[i-1][j] : false) || (j > 0 ? good[i][j-1] : false);
        };

        for(int i = max(0ll, cur - (n - 1)); i <= min(n - 1, cur); ++i){
            int j = cur - i;
            if(ok(i, j)) {
                pos = min(pos, a[i][j]);
            }
        }
        for(int i = max(0ll, cur - (n - 1)); i <= min(n - 1, cur); ++i){
            int j = cur - i;
            if(ok(i, j) && a[i][j] == pos) {    
                good[i][j] = true;
            }
        }
    }
    cout << ans << '\n';

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