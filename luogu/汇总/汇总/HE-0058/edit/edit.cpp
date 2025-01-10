#include<bits/stdc++.h>
using namespace std;
int T,n;
string s1,s2,t1,t2;
char S1[55],S2[55];
char tmp1[55],tmp2[55];
void work2(){
	int tot=0;
	for(int i=1;i<=n;i++){
		if(s1[i]==s2[i]) tot++; 
	}
	printf("%d\n",tot);
}
bool ch[55];
int ans=-1;
void dfs(string pa,int depth){
	if(pa[depth]==' ') dfs(pa,depth+1);
	if(depth==2*n+1){
		for(int i=1;i<=n;i++){
			if(ch[i]==true){
				swap(S1[i],S1[i+1]);
			}
			if(ch[i+n+1]==true){
				swap(S2[i],S2[i+1]);
			}
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			if(S1[i]==S2[i]) tot++;
		}
		ans=max(ans,tot);
		for(int i=1;i<=n;i++){
			S1[i]=tmp1[i];
			S2[i]=tmp2[i];
		} 
		return ;
	}
	if(pa[depth]=='1' && pa[depth]==pa[depth+1]){
		ch[depth]=1;
		dfs(pa,depth+1);
		ch[depth]=0;
		dfs(pa,depth+1);
	}else{
		ch[depth]=0;
		dfs(pa,depth+1);
	}
}
void work1(){
	memset(ch,0,sizeof ch);
	for(int i=1;i<=n;i++){
		S1[i]=s1[i];
		S2[i]=s2[i];
		tmp1[i]=s1[i];
		tmp2[i]=s2[i];
	}
	ans=-1;
	dfs(" "+t1+" "+t2,1);
	printf("%d\n",ans);
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cin>>s1;cin>>s2;cin>>t1;cin>>t2;
		s1=' '+s1;
		s2=' '+s2;
		bool f=0;
		for(int i=1;i<n;i++){
			if(s1[i]!=s1[i+1]){
				f=1;
				break;
			}
		}
		if(!f){
			work2();
			continue;
		}
		if(n<=10){
			work1();
		}
	}
	
	
	
	
	return 0;
}
