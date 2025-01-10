#include<bits/stdc++.h>
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

const int N = 5e5 + 5;
const int M = 1e5 + 5;

int Q, n;
vector<int>to[N];
int f[19][N], dep[N], g[19][N];

struct Que{
	int l, r, k;
}q[N];

inline void dfs(int x, int p){
    f[0][x] = p; dep[x] = dep[p] + 1;
    for(int i=1; i<=18; i++)
        f[i][x] = f[i-1][f[i-1][x]];
    for(int y : to[x]){
        if(y == p) continue;
        dfs(y, x);
    }
}

inline int LCA(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    int d = dep[x] - dep[y];
    for(int i=0; i<=18; i++){
        if(d & (1 << i)) x = f[i][x];
    }
    if(x == y) return x;
    for(int i=18; i>=0; i--){
        if(f[i][x] != f[i][y])
            x = f[i][x], y = f[i][y];
    }
    return f[0][x];
}

namespace Bl
{
    inline int STlca(int l, int r){
        int lgo = __lg(r - l);
        // cout<<lg<<"\n";
        // if(l == 3 and r == 4) cout<<r-(1<<lg)<<" SSS\n";
        return LCA(g[lgo][l], g[lgo][r-(1<<lgo)]);
	}

    int main(){

        // init();

        // cout<<g[0][3]<<" 34\n";
	
		for(int i=1; i<=Q; i++){
			int l = q[i].l, r = q[i].r, k = q[i].k;
            int ans = 0, lg = __lg(k);
            for(int i=l; i<=r; i++){
                if(i + k - 1 > r) break;
                // cout<<i<<" "<<i+k-1<<" "<<STlca(i, i+k-1)<<"\n";
                if(k == 1) ans = max(ans, dep[i]);
                else ans = max(ans, dep[STlca(i, i+k-1)]);

            }
            cout<<ans<<"\n";
			// r = r - k + 1;
            // cout<<l<<" "<<r<<" "<<k<<"\n";
			// cout<<ST(l, r, k)<<"\n";
		}
	

        return 0;
    }
}

namespace A{

    inline int STm(int l, int r){
        int lgo = __lg(r - l + 1);
        return max(g[lgo][l], g[lgo][r-(1<<lgo)+1]);
    }

    int main(){

        for(int i=1; i<=n; i++)
            g[0][i] = dep[i];

        for(int i=1; i<=18; i++)
            for(int j=1; j+(1<<i)-1<=n; j++){
                g[i][j] = max(g[i-1][j], g[i-1][j+(1<<i-1)]);
            }

        qr(Q);
        for(int i=1; i<=Q; i++){
            int qr(l), qr(r), qr(k);
            cout<<STm(l, r)<<"\n";
        }
        


        return 0;
    }
}

int dag[N];
signed main(){ //query
   freopen("query.in", "r", stdin); freopen("query.out", "w", stdout);

    qr(n); bool fA = 1;
    for(int i=1; i<n; i++){
        int qr(x), qr(y);
        to[x].vadd(y); dag[x]++;
        to[y].vadd(x); dag[y]++;
    }

    dfs(1, 0);

    for(int i=1; i<=n; i++) if(dag[i] > 2) fA = 0;
    if(fA) return A::main();

    for(int i=1; i<n; i++)
        g[0][i] = LCA(i, i+1);
    for(int i=1; i<=18; i++)
        for(int j=1; j+(1<<i)<=n; j++)
            g[i][j] = LCA(g[i-1][j], g[i-1][j+(1<<i-1)]);
	
	qr(Q);
	for(int i=1; i<=Q; i++){
		qr(q[i].l); qr(q[i].r); qr(q[i].k);
	}

    return Bl::main();
    

    return 0;
}
