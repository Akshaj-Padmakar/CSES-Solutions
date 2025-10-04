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

    multiset<int>l, r;

    auto rebalance=[&]() {
        int sz = (k + 1)/2;
        while(l.size() > sz) {
            r.insert(*(--l.end()));
            l.erase(--l.end());
        }
        while(l.size() < sz && r.size() > 0) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
    };
    auto add=[&](int x) {
        if(l.empty() || *(--l.end()) > x) {
            l.insert(x);
        } else {
            r.insert(x);
        }
        rebalance();
    };
    auto remove=[&](int x) {
        if(l.find(x) != l.end()) {
            l.erase(l.find(x));
        } else {
            r.erase(r.find(x));
        }
        rebalance();
    };
    
    for(int i = 0; i < k; i++) {
        add(a[i]);
    }


     cout << *(--l.end()) << " ";
    for(int i = k; i < n; i++) {
        add(a[i]);
        remove(a[i-k]);
        cout << *(--l.end()) << " ";
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