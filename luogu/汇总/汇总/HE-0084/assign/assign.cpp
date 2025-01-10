#include<bits/stdc++.h>
#define int long long
#define th1 first
#define th2 second
#define vadd emplace_back
#define mp make_pair
#define qr(x) x=read()
#define Type int
using namespace std;

inline Type read(){
    char c=getchar(); Type x=0, f=1;
    while(!isdigit(c)) (c=='-'?f=-1:f=1), c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48), c=getchar();
    return x*f;
}

const int N = 1e5 + 5;

int T, n, ans
;
int c[N], d[N], pos[N];

inline void dfs(int cnt){
	if(cnt == n + 1){
		for(int i=1; i<n; i++){
			if(x[i] == a[i] and x[i+1] != b[i]) return;
		}
		ans++;
		return ;
	}
	if(pos[cnt]){
		x[cnt] = pos[cnt], dfs(cnt+1);
		return ;
	}
	x[cnt] = 1; dfs(cnt+1);
	x[cnt] = 2; dfs(cnt+1);
}

signed main(){ //a
   freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);

    qr(T);
    while(T--)
    {
        qr(n); qr(m); fill(pos, pos+1+n, 0); bool f = true;
		for(int i=1; i<=m; i++){
			qr(c[i]); qr(d[i]);
			if(pos[c[i]] and pos[c[i]] != d[i]) f = false;
		}
		if(!f){
			cout<<"0\n";
			continue;
		}
    }


    return 0;
}
