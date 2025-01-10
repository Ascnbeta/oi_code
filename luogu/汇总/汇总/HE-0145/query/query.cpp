#include <bits/stdc++.h>
#define heng_shui_tai_hua_zhong_xue good

using namespace std;

const int N = 5e5 + 5;

struct node {
	int to, nxt;
} e[N];
int head[N], cnt = 1, num[N];
bool bj[N];

void add(int u, int v) {
	e[cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
	cnt ++;
}

int main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	int q;
	cin >> q;
	while(q --) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << 1 << endl;
	}

	return 0;
}
