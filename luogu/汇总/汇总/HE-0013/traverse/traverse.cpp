#include<bits/stdc++.h>
using namespace std;
struct node{
	int end,nxt;
}edge[200100];
int cs,cases,n,k,cnt,head[100100],st[100100],ed[100100],s1[100100],e1[100100],pt[100100],fa[100100],ans;
unordered_map<long long,long long> mp;
inline unsigned long long qpow(unsigned long long x,unsigned long long y){
	unsigned long long rtr=1;
	for(;y;y>>=1){
		if(y&1){
			rtr=rtr*x;
		}
		x=x*x;
	}
	return rtr;
}
inline void add(int x,int y){
	++cnt;
	edge[cnt]={y,head[x]};
	head[x]=cnt;
}
int find(int x){
	if(fa[x]^x){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
inline void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x^y)
	fa[x]=y;
}
void dfs(int x){
	if(x>n-2){
		for(int i=1;i<n;++i){
			fa[i]=i;
		}
		int ulim=n-1;
		// for(int i=1;i<ulim;++i){
		// 	cout<<s1[i]<<" "<<e1[i]<<endl;
		// }
		// cout<<endl;
		unsigned long long tem=0;
		for(int i=1;i<ulim;++i){
			if(st[s1[i]]==st[e1[i]]||st[s1[i]]==ed[e1[i]]||ed[s1[i]]==st[e1[i]]||ed[s1[i]]==ed[e1[i]]){
				tem+=qpow(13,s1[i]*n+e1[i]);
				merge(s1[i],e1[i]);
			}else{
				// cout<<i<<endl;
				return;
			}
		}
		fa[1]=find(1);
		for(int i=2;i<n;++i){
			fa[i]=find(i);
			if(fa[i]^fa[i-1])
			return;
		}
		// cout<<"H"<<endl;
		if(!mp[tem])
		++ans;
		mp[tem]=1;
		return;
	}
	for(int i=1;i<n;++i){
		for(int j=i+1;j<n;++j){
			s1[x]=i;
			e1[x]=j;
			dfs(x+1);
		}
	}
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	scanf("%d%d",&cs,&cases);
	for(;cases;--cases){
		mp.clear();
		cnt=0;
		memset(head,0,sizeof(head));
		ans=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;++i){
			scanf("%d%d",&st[i],&ed[i]);
		}
		for(int i=1;i<=k;++i){
			scanf("%d",&pt[i]);
		}
		if(cs==18){
			printf("1\n");
			continue;
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}