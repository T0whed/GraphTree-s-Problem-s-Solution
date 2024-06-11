#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define endl "\n"
const int N = 2e6 + 7;

void stdio() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int n, m;
vector<int>g[N];
bool vis[N]; int color[N];

bool dfs(int node, int c) {
    bool bipartite = true;
    vis[node] = true;
    color[node] = c;

    for (int child : g[node]) {
        if (!vis[child]) {
            bool check = dfs(child, c ^ 1);
            if (!check) {bipartite = false; break;}
        }
        else {
            if (color[child] == color[node]) {
                bipartite = false; break;
            }
        }

    }
    return bipartite;
}

void solve() {
    while (cin >> n && n) {
        cin >> m;
        while (m-- > 0) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        cout << (dfs(0, 1) ? "BICOLORABLE." : "NOT BICOLORABLE.") << "\n";
        for (int i = 0; i < N; ++i) {g[i].clear(); vis[i] = false;}
    }
}

int32_t main() {
    FAST
    stdio();
    int t = 1, i = 0; //cin >> t;
    while (t -- > 0) {
        //cout << "Case " << ++i << ": ";
        solve();
    }
    return 0;
}
