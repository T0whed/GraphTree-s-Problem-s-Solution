#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define INF LLONG_MAX
#define endl "\n"
const int N = 2e2 + 7;

void stdio() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int n, m;
char g[N][N];
int dist[N][N];

vector<pair<int, int>> moves = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};

bool is_valid(int x, int y) {return (x >= 1 && x <= n && y >= 1 && y <= m && (g[x][y] == '.' or g[x][y] == 'J'));}

void f_bfs() {
    queue<pair<int, int>>q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] == 'F') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;

        q.pop();
        for (pair<int, int> move : moves) {
            int x = a + move.first;
            int y =  b + move.second;

            if (is_valid(x, y) and dist[x][y] > dist[a][b] + 1) {
                dist[x][y] = dist[a][b] + 1;
                q.push({x, y});
            }
        }
    }
}
bool is_escape(int x, int y) {return (x == 1 or x == n or y == 1 or y == m and (g[x][y] == '.' or g[x][y] == 'J'));}

int j_bfs(int x, int y) {
    if (is_escape(x, y))return 0;

    dist[x][y] = 0;
    queue<pair<int, int>>q;
    q.push({x, y});

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;

        q.pop();
        for (pair<int, int> move : moves) {
            int x = a + move.first;
            int y =  b + move.second;

            if (is_valid(x, y) and dist[x][y] > dist[a][b] + 1) {
                dist[x][y] = dist[a][b] + 1;
                if (is_escape(x, y))return dist[x][y];

                q.push({x, y});
            }
        }
    }
    return -1;

}

void solve() {
    cin >> n >> m;
    int x, y, a, b;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j]; dist[i][j] = INF; if (g[i][j] == 'J') {x = i; y = j;}
        }
    }

    f_bfs();
    int ans = j_bfs(x, y);

    if (ans == -1)cout << "IMPOSSIBLE\n";
    else cout << ++ans << "\n";
}

int32_t main() {
    FAST
    stdio();
    int t = 1, i = 0; cin >> t;
    while (t -- > 0) {
        cout << "Case " << ++i << ": ";
        solve();
    }
    return 0;
}
