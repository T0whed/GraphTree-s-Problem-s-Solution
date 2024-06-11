#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e3 + 7;

vector<int> g[N];
bool vis[N];

void prime() {
	for (int i = 2; i < N; ++i) {
		int n = i;
		for (int j = 2; j < i; ++j) {
			if (n % j == 0) {
				while (n % j == 0)n /= j;
				if (i + j < N)g[i].push_back(i + j);
			}
		}
	}
}

int bfs(int s, int t) {
	queue<int> q;
	int level[N];
	q.push(s);
	vis[s] = true;
	level[s] = 0;

	while (!q.empty()) {
		int frnt = q.front();
		q.pop();
		for (auto it : g[frnt]) {
			if (vis[it])continue;
			vis[it] = true;
			level[it] = level[frnt] + 1;
			q.push(it);
		}
	}
	if (vis[t])return level[t];
	else return -1;
}

void solve() {
	int n, m; cin >> n >> m;
	cout << bfs(n, m) << endl;
	for (int i = 0; i < N; ++i) {
		//g[i].clear();
		vis[i] = false;
	}
}

int32_t main() {
	FAST
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	prime();
	int t = 1, i = 0; cin >> t;
	//cin.ignore();
	while (t--) {
		cout << "Case " << ++i << ": ";
		solve();
		//cout << ans << endl;
	}

}
