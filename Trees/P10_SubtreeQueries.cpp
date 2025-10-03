#include "bits/stdc++.h"
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


int log2_ceil(int x) {
    int cur = 0;
    while((1ll<<cur) < x) {
        cur++;
    }
    return cur;
}
template<class S, S (*op)(S, S), S (*e)()> struct segtree {
public :
    segtree(int n) {
        _n = n;
        log = log2_ceil(n);
        size = 1ll<<log;
        d = vector<S>(2*size, e());
    }

    segtree(vector<int> &v) {
        _n = v.size();
        log = log2_ceil(_n);
        size = 1ll<<log;
        d = vector<S>(2*size, e());

        for(int i = 0; i < _n; i++) {
            d[i + size] = v[i];
        }

        for(int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int id, S x) {
        assert(0 <= id && id < _n);

        id += size;
        d[id] = x;

        for(int i = 1; i <= log; i++) {
            update(id >> i);
        }
    }

    S get(int id) {
        assert(0<= id && id < _n);
        return d[size + id];
    }

    S prod(int l, int r) {
        debug(l, r, _n);
        assert(0<= l && l < _n && 0 <= r && r <= _n);
        S vl = e(), vr = e();
        l += size;
        r += size;

        while(l < r) {
            if(l & 1) vl = op(vl, d[l++]);
            if(r & 1) vr = op(vr, d[--r]);

            l >>= 1;
            r >>= 1;
        }
        return op(vl, vr);
    }

private :
    int _n, log, size;
    vector<S> d;
    void update(int k) {
        d[k] = op(d[2*k], d[2*k + 1]);
    }
};

int op(int a, int b) {
    return a + b;
}

int e() {
    return 0;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    
    vector<vector<int>> g(n);
    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> out(n, 0), in(n, 0);
    segtree<int, op, e> st(2*n);
    int timer = 0;
    function<void(int, int)> dfs=[&](int node, int p) {
        in[node] = timer++;
        st.set(in[node], v[node]);
        for(auto ch : g[node]) {
            if(ch ^ p) {
                dfs(ch, node);
            }
        }
        out[node] = timer++;
        st.set(out[node], v[node]);
    };


    dfs(0, -1);


    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int node, x;
            cin >> node >> x;
            node--;
            st.set(in[node], x);
            st.set(out[node], x);
        } else {
            int node;
            cin >> node;
            node--;
            cout << st.prod(in[node], out[node] + 1)/2 << '\n';
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