#include<bits/stdc++.h>
using namespace std;

const int M=1e5+5;
int n,ans;
string s1,s2,t1,t2;
bool bk1[M],bk2[M],flag1,flag2,flag3;
map<string,bool> vis1,vis2;

void ed(){
	int num=0;
	for(int i=0;i<n;i++){
		if(s1[i]==s2[i]) num++;
	}
	ans=max(ans,num);
}

void dfs2(int now){
	if(now+1>=n){
		ed();
		return;
	}
	if(bk2[now]&&bk2[now+1]){
		dfs2(now+1);
		swap(s2[now],s2[now+1]);
		if(!vis2[s2]){
			vis2[s2]=1;
			dfs2(now+1);
			vis2[s2]=0;
		}
		swap(s2[now],s2[now+1]);
	}
	else{
		dfs2(now+1);
	}
}

void dfs(int now){
	if(now+1>=n){
		dfs2(0);
		return;
	}
	if(bk1[now]&&bk1[now+1]){
		dfs(now+1);
		swap(s1[now],s1[now+1]);
		if(!vis1[s1]){
			vis1[s1]=1;
			dfs(now+1);
			vis1[s1]=0;
		}
		swap(s1[now],s1[now+1]);
	}
	else{
		dfs(now+1);
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	int _;
	cin>>_;
	while(_--){
		cin>>n>>s1>>s2>>t1>>t2;
		int __=0,___=0;
		flag1=flag2=flag3=0;
		ans=0;
		for(int i=0;i<n;i++){
			bk1[i]=t1[i]-'0',bk2[i]=t2[i]-'0';
			if(i) if(s1[i]!=s1[i-1]) flag1=1;
			if(t1[i]!=t2[i]) flag2=1;
			if(t1[i]=='0') __++;
			if(t2[i]=='0') ___++;
		}
		if(__>1||___>1) flag3=1;
		if(n<=10){
			dfs(0);
			cout<<ans<<'\n';
		}
		else if(flag1==0){
			for(int i=0;i<n;i++) if(s1[i]==s2[i]) ans++;
			cout<<ans<<'\n';
		}
		else if(flag2==0){
			vector<int> p;
			int a1[M],a2[M];
			for(int i=0;i<n;i++) a1[i]=s1[i]-'0',a2[i]=s2[i]-'0';
			p.push_back(-1);
			for(int i=0;i<n;i++) if(!bk1[i]) p.push_back(i);
			p.push_back(n);
			for(int i=0;i+1<p.size();i++){
				int l=p[i],r=p[i+1];
				sort(a1+l+1,a1+r);
				sort(a2+l+1,a2+r);
			}
			for(int i=0;i<n;i++) if(a1[i]==a2[i]) ans++;
			cout<<ans<<'\n';
		}
		else if(flag3==0){
			int p1,p2;
			for(int i=0;i<n;i++){
				if(!bk1[i]) p1=i;
				if(!bk2[i]) p2=i;
			}
			int a1[M],a2[M];
			for(int i=0;i<n;i++) a1[i]=s1[i]-'0',a2[i]=s2[i]-'0';
			sort(a1,a1+p1);sort(a1+p1+1,a1+n);
			sort(a2,a2+p2);sort(a2+p2+1,a2+n);
			if(a1[p1]!=a2[p1]){
				for(int i=0;i<n;i++){
					if(a2[i]==a1[p1]&&a1[i]!=a2[i]&&i!=p2){
						swap(a2[i],a2[p1]);
					}
				}
			}
			if(a1[p2]!=a2[p2]){
				for(int i=0;i<n;i++){
					if(a1[i]==a2[p2]&&a1[i]!=a2[i]&&i!=p1){
						swap(a1[i],a1[p2]);
					}
				}
			}
			for(int i=0;i<n;i++) if(a1[i]==a2[i]) ans++;
			cout<<ans<<'\n';
		}
	}
	return 0;
}
