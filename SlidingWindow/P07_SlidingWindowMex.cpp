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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    map<int, int> mp;
    set<int> s;
    for(int i = 0; i <= k; i++) {
        s.insert(i);
    }

    for(int i = 0; i < n; i++) {
        int cur = a[i];
        mp[cur]++;
        if(s.find(cur) != s.end()) {
            s.erase(cur);
        }

        if(i >= k) {
            int front = a[i - k];
            mp[front]--;
            if(mp[front] == 0) {
                mp.erase(front);
                s.insert(front);
            }
        }

        if(i >= k - 1) { // we have a window of k
            cout << *s.begin() << ' ';
        }
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