//#include <bits/stdc++.h>
//#define LL long long
//#define Un unsigned
//#define __ __int128
//#define DB double
//#define LD long double
//#define pii pair<int,int>
//#define pLi pair<LL,int>
//#define pLL pair<LL,LL>
//#define Ve vector<int>
//#define VE vector<LL>
//#define pb push_back
//
//using namespace std;
//
//inline LL read()
//{
//	LL x = 0,f = 1;char ch = getchar();
//	while (!isdigit(ch)) (ch == '-') && (f = -1),ch = getchar();
//	while (isdigit(ch)) x = x*10+ch-48,ch = getchar();
//	return x*f;
//}
//
//const int N = 5e5+5;
//struct edge{int to,pre;}e[N<<1];
//int las[N],cnt,K[N],siz[N],hs[N];
//Ve ad[N],del[N];
////ad1[N],del1[N];
//bool fl[N];
//
//void add(int u,int v){e[++cnt] = {v,las[u]},las[u] = cnt;}
//
//void D(int x,int fa)
//{
//	siz[x] = 1;
//	for (int i = las[x],y;i;i = e[i].pre)
//	{
//		if ((y = e[i].to) != fa)
//		{
//			D(y,x),siz[x] += siz[y];
//			if (siz[y] > siz[hs[x]]) hs[x] = y;
//		}
//	}
//}
//
//struct tree{int l,r,mx,mn;}tr[N<<2];
//
//void build(int l,int r,int i)
//{
//	tr[i].l = l,tr[i].r = r;
//	if (l == r) return (void)(tr[i].mx = tr[i].mn = l);
//	int mid = (l+r)>>1;
//	build(l,mid,i<<1),build(mid+1,r,i<<1|1);
//	tr[i].mx = max(tr[i<<1].mx,tr[i<<1|1].mx);
//	tr[i].mn = min(tr[i<<1].mn,tr[i<<1|1].mn);
//}
//
//void M(int p,int k,int i)
//{
//	if (tr[i].l == tr[i].r)
//	{
//		if (k) tr[i].mx = tr[i].mn = tr[i].l;
//		else tr[i].mx = 0,tr[i].mn = 1e9;
//		return ;
//	}
//	if (p <= tr[i<<1].r) M(p,k,i<<1);
//	else M(p,k,i<<1|1);
//	tr[i].mx = max(tr[i<<1].mx,tr[i<<1|1].mx);
//	tr[i].mn = min(tr[i<<1].mn,tr[i<<1|1].mn);
//}
//
//int Qmx(int l,int r,int i)
//{
//	if (tr[i].l >= l && tr[i].r <= r) return tr[i].mx;
//	int res = 0;
//	if (tr[i<<1].r >= l) res = max(res,Qmx(l,r,i<<1));
//	if (tr[i<<1|1].l <= r) res = max(res,Qmx(l,r,i<<1|1));
//	return res;
//}
//
//int Qmn(int l,int r,int i)
//{
//	if (tr[i].l >= l && tr[i].r <= r) return tr[i].mn;
//	int res = 1e9;
//	if (tr[i<<1].r >= l) res = min(res,Qmn(l,r,i<<1));
//	if (tr[i<<1|1].l <= r) res = min(res,Qmn(l,r,i<<1|1));
//	return res;
//}
//
//void D1(int x,int fa)
//{
//	for (int i = las[x],y;i;i = e[i].pre)
//	{
//		if ((y = e[i].to) != fa)
//		{
//			D1(y,x);
//		}
//	}
//}
//
//int main()
//{
////	freopen("query.in","r",stdin);
////	freopen("query.out","w",stdout);
//	int n = read();
//	for (int i = 1,u,v;i < n;i++) u = read(),v = read(),add(u,v),add(v,u);
//	D(1,0);build(1,n,1),D1(1,0);
//	int m = read();
//	for (int i = 1,l,r;i <= m;i++)
//		l = read(),r = read(),ad[l].pb(i),del[r+1].pb(i),K[i] = read();
////	set < int > s;
////	priority_queue < pii,vector<pii>,greater<pii> > q;
////	for (int i = 1;i <= n;i++)
////	{
////		for (int j : ad[i]) q.push({K[j],j});
////		for (int j : del[i]) fl[j] = 1;
////	}
//	return 0;
//}
#include <bits/stdc++.h>
#define LL long long
#define Un unsigned
#define __ __int128
#define DB double
#define LD long double
#define pii pair<int,int>
#define pLi pair<LL,int>
#define pLL pair<LL,LL>
#define Ve vector<int>
#define VE vector<LL>
#define pb push_back

using namespace std;

inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	while (!isdigit(ch)) (ch == '-') && (f = -1),ch = getchar();
	while (isdigit(ch)) x = x*10+ch-48,ch = getchar();
	return x*f;
}

const int N = 5e5+5;
struct edge{int to,pre;}e[N<<1];
int las[N],cnt,siz[N],hs[N],top[N],dep[N],fa[N],st[20][N],d[N];

void add(int u,int v){e[++cnt] = {v,las[u]},las[u] = cnt;}

void D(int x)
{
	siz[x] = 1,dep[x] = dep[fa[x]]+1;
	for (int i = las[x],y;i;i = e[i].pre)
	{
		if ((y = e[i].to) != fa[x])
		{
			fa[y] = x,D(y),siz[x] += siz[y];
			if (siz[y] > siz[hs[x]]) hs[x] = y;
		}
	}
}

void D1(int x,int t)
{
	top[x] = t;
	if (hs[x]) D1(hs[x],t);
	for (int i = las[x],y;i;i = e[i].pre)
		if ((y = e[i].to) != fa[x] && y != hs[x]) D1(y,y);
}

inline int LCA(int x,int y)
{
	while(top[x] != top[y]) dep[top[x]] < dep[top[y]] ? y = fa[top[y]] : x = fa[top[x]];
	return dep[x] < dep[y] ? x : y;
}

inline int Q(int l,int r)
{
	int k = __lg(r-l+1);
	return LCA(st[k][l],st[k][r-(1<<k)+1]);
}

struct tree{int l,r,ans,sum,mxl,mxr;}tr[N<<2];

void build(int l,int r,int i)
{
	tr[i].l = l,tr[i].r = r;
	if (l == r) return ;
	int mid = (l+r)>>1;
	build(l,mid,i<<1),build(mid+1,r,i<<1|1);
}

inline tree merge(tree a,tree b)
{
	tree c = {a.l,b.r,max({a.ans,b.ans,a.mxr+b.mxl}),a.sum+b.sum,a.mxl,b.mxr};
	if (a.sum == a.r-a.l+1) c.mxl = a.sum+b.mxl;
	if (b.sum == b.r-b.l+1) c.mxr = b.sum+a.mxr;
	return c;
}

void M(int p,int k,int i)
{
	if (tr[i].l == tr[i].r) return (void)(tr[i].ans = tr[i].sum = tr[i].mxl = tr[i].mxr = k);
	if (p <= tr[i<<1].r) M(p,k,i<<1);
	else M(p,k,i<<1|1);
	tr[i] = merge(tr[i<<1],tr[i<<1|1]);
}

tree Q(int l,int r,int i)
{
	if (tr[i].l >= l && tr[i].r <= r) return tr[i];
	if (tr[i<<1].r < l) return Q(l,r,i<<1|1);
	if (tr[i<<1|1].l > r)  return Q(l,r,i<<1);
	return merge(Q(l,r,i<<1),Q(l,r,i<<1|1));
}

struct Que{int l,r,k,id;}q[N],tmp[N];
int ans[N];
Ve ve[N];

void W(int l,int r,int L,int R)
{
	if (L == R)
	{
		for (int i = l;i <= r;i++) ans[q[i].id] = L;
		return ;
	}
	int mid = (L+R)>>1;
	for (int i = R;i > mid;i--)
		for (int j : ve[i])
			M(j,1,1);
	int l1 = l,r1 = r;
	for (int i = l;i <= r;i++)
	{
		if (Q(q[i].l,q[i].r,1).ans < q[i].k) tmp[l1++] = q[i];
		else tmp[r1--] = q[i];
	}
	for (int i = l;i <= r;i++) q[i] = tmp[i];
	W(l,l1-1,L,mid);
	for (int i = R;i > mid;i--)
		for (int j : ve[i]) M(j,0,1);
	W(r1+1,r,mid+1,R);
}

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n = read(),mxd = 0;
	for (int i = 1,u,v;i < n;i++)
		u = read(),v = read(),add(u,v),add(v,u),d[u]++,d[v]++;
	D(1);
	for (int i = 1;i <= n;i++) mxd = max(mxd,d[i]);
	if (mxd == 2)
	{
		int m = read();
		for (int i = 1;i <= m;i++)  q[i] = {read(),read(),read(),i};
		for (int i = 1;i <= n;i++) ve[dep[i]].pb(i);
		build(1,n,1),
		W(1,m,1,n);
		for (int i = 1;i <= m;i++) printf("%d\n",ans[i]);
	}
	else
	{
		D1(1,1);
		for (int i = 1;i <= n;i++) st[0][i] = i;
		for (int i = 1;i <= __lg(n);i++)
			for (int j = 1;j+(1<<i)-1 <= n;j++)
				st[i][j] = LCA(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		int m = read();
		while (m--)
		{
			int l = read(),r = read(),k = read(),mx = 0;
			for (int i = l;i+k-1 <= r;i++) mx = max(mx,dep[Q(i,i+k-1)]); 
			printf("%d\n",mx);
		}
	}
	return 0;
}
