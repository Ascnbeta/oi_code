#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
using namespace std;
const int N=1e5+10,P=1e9+7;
int T,_,n,m,sum,k[N]; ll f[N]; vector<int>e[N],g[N]; bitset<N>vis[N];
inline int mod(int x,int y) {return (x+=y)>=P?x-P:x;}
signed main()
{
	freopen("traverse.in","r",stdin),freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>_>>T;T;T--)
	{
		cin>>n>>m; bool flag1=0,flag2=0;
		for(int i=1,x,y;i<n;i++)
		{
			cin>>x>>y,flag1|=(x!=i||y!=i+1);
			flag2|=(x!=1||y!=i+1);
		}
		for(int i=1;i<=m;i++) cin>>k[i];
		if(!flag1) {cout<<1<<endl; continue;}
	}
}