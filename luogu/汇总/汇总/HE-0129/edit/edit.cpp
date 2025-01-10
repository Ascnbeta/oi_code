#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+3;
int s1[maxn],s2[maxn],t1[maxn],t2[maxn],vis[maxn];
struct node{
	int id;
	bool operator<(const node a)const{
		return id>a.id;
	}
};
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int t;cin>>t;
	while(t--){
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		memset(vis,0,sizeof(vis));
		bool flagb=1;
		int n,ans=0;cin>>n;
		priority_queue<node>q11,q10,q21,q20;
		for(int i=1;i<=n;i++){
			char x;cin>>x;
			s1[i]=x-'0';
		}
		for(int i=1;i<=n;i++){
			char x;cin>>x;
			s2[i]=x-'0';
		}
		for(int i=1;i<=n;i++){
			char x;cin>>x;
			t1[i]=x-'0';
			if(t1[i]==1){
				if(s1[i]==1)q11.push(node{i});
				else q10.push(node{i});
			}
		}
		for(int i=1;i<=n;i++){
			char x;cin>>x;
			t2[i]=x-'0';
			if(t2[i]==1){
				if(s2[i]==1)q21.push(node{i});
				else q20.push(node{i});
			}
		}
		for(int i=1;i<=n;i++){
			while(!q11.empty())if(vis[q11.top().id]==0)break;else q11.pop();
			while(!q10.empty())if(vis[q10.top().id]==0)break;else q10.pop();
			while(!q21.empty())if(vis[q21.top().id]==0)break;else q21.pop();
			while(!q20.empty())if(vis[q20.top().id]==0)break;else q20.pop();
			if(s1[i]==s2[i]){
				ans++;vis[i]=1;
				continue;
			}
			if(t2[i]==1){
				if(s1[i]==1&&(!q21.empty())){
					q20.push(node{q21.top().id});
					swap(s2[i],s2[q21.top().id]);
					q21.pop();
					ans++;vis[i]=1;continue;
				}
				else if(s1[i]==0&&(!q20.empty())){
					q21.push(node{q20.top().id});
					swap(s2[i],s2[q20.top().id]);
					q20.pop();
					ans++;vis[i]=1;continue;
				}
			}
			else if(t1[i]==1){
				if(s2[i]==1&&(!q11.empty())){
					q10.push(node{q11.top().id});
					swap(s1[i],s1[q11.top().id]);
					q11.pop();
					ans++;vis[i]=1;continue;
				}
				else if(s2[i]==0&&(!q10.empty())){
					q11.push(node{q10.top().id});
					swap(s1[i],s1[q10.top().id]);
					q10.pop();
					ans++;vis[i]=1;continue;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
