#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define endl "\n"
const int N = 1e4 + 7;


void stdio() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

std::vector<int> g[N];
bool vis[N];
int cnt;

void dfs(int node) {
    vis[node] = true;
    cnt++;
    for (int child : g[node]) {
        if (!vis[child])dfs(child);
    }
}

void solve() {
    int n, m, l; cin >> n >> m >> l;

    while (m-- > 0) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        //g[v].push_back(u);
    }

    while (l-- > 0) {
        int node; cin >> node;
        if (!vis[node])dfs(node);
    }
    cout << cnt << "\n";
    cnt = 0;
    for (int i = 0; i < N; ++i) {vis[i] = false; g[i].clear();}
}

int32_t main() {
    FAST
    stdio();
    int t = 1, i = 0; cin >> t;
    while (t -- > 0) {
        //cout << "Case " << ++i << ": ";
        solve();
    }
    return 0;
}
