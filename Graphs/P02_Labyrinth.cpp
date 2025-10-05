#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 1e9 + 5;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    pair<int, int> start, end;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char y;
            cin >> y;
            if(y == 'A') {
                start = {i, j};
                y = '.';
            }

            if(y == 'B') {
                end = {i, j};
                y = '.';
            }
            a[i][j] = y;
        }
    }

    queue<pair<int, int>> q;
    q.push(start);

    vector<vector<int>> dis(n, vector<int>(m, INF));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));

    vector<pair<int, int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    auto is_valid=[&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.';
    };

    dis[start.first][start.second] = 0;
    while(q.size()) {
        pair<int, int> node = q.front();
        q.pop();

        for(auto [dx, dy] : dr) {
            int xx = dx + node.first;
            int yy = dy + node.second;

            if(is_valid(xx, yy) && dis[xx][yy] > dis[node.first][node.second] + 1) {
                dis[xx][yy] = dis[node.first][node.second] + 1;
                par[xx][yy] = node;
                q.push({xx, yy});
            }
        }
    }
    int d = dis[end.first][end.second];
    if(d == INF) {
        cout << "NO\n"; return;
    }
    cout <<  "YES\n" << d << '\n';
    pair<int, int> cur = end;

    auto dir=[&](pair<int, int> p1, pair<int, int> p2) {
        if(p1.first + 1 == p2.first) {
            return 'D';
        } else if (p1.first - 1 == p2.first) {
            return 'U';
        } else if(p1.second + 1 == p2.second) {
            return 'R';
        } else {
            return 'L';
        }
    };

    string ans;
    while(true) {
        if(cur == start) {
            break;
        }
        ans.push_back(dir(par[cur.first][cur.second], cur));
        cur = par[cur.first][cur.second];
    }
    reverse(ans.begin(), ans.end());
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