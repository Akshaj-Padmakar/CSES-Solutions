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

    multiset<int> l, r;
    int smL = 0, smR = 0;

    auto rebalance=[&]() {
        int sz = (k + 1)/ 2;
        while((int)l.size() > sz) {
            smR += *(--l.end());
            smL -= *(--l.end());
            
            r.insert(*(--l.end()));
            l.erase(--l.end());

        }
        while((int)l.size() < sz && (int)r.size() > 0) {
            smL += *r.begin();
            smR -= *r.begin();
            
            l.insert(*r.begin());
            r.erase(r.begin());
        }
    };
    auto add=[&](int x) {
        if((int)l.size() == 0 || *(--l.end()) > x) {
            l.insert(x);
            smL += x;
        } else {
            r.insert(x);
            smR += x;
        }
        rebalance();
    };

    auto remove=[&](int x) {
        if(l.find(x) != l.end()) {
            l.erase(l.find(x));
            smL -= x;
        } else {
            r.erase(r.find(x));
            smR -= x;
        }
        rebalance();
    };

    for(int i = 0; i < k; i++) {
        add(a[i]);
    }
    int median = *(--l.end());
    cout << l.size()*median - smL + smR - r.size()*median << " ";

    for(int i = k ; i < n; i++) {
        add(a[i]);
        remove(a[i-k]);
        median = *(--l.end());
        cout << l.size()*median - smL + smR - r.size()*median << " ";
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