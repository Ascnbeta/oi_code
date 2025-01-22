#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node{
	int l,r;
};
bool a[205][205];
node lt[25];//统计每层最左（右）的楼梯。
int n,m,h=-1,ans=1e9+10;
void dfs(int flr,int stp,bool k){
	if(flr==h){//到达需要关灯的最高层。
		if(k==0) stp+=lt[flr].r;
		ans=min(ans,stp);
		return;
	}
	else if(lt[flr].l==-1&&lt[flr].r==-1){//本层没有灯需要关。
		dfs(flr-1,stp+1,k);
		return;
	} 
	else if(k==0){//人在左边楼梯。
		dfs(flr-1,stp+(2*lt[flr].r)+1,0);
		dfs(flr-1,stp+m+1,1);
	} 
	else if(k==1){//人在右边楼梯。
		dfs(flr-1,stp+(2*(m-lt[flr].l))+1,1);
		dfs(flr-1,stp+m+1,0);
	} 
}
int main(){
	n=read(),m=read();
	m++;
	for(int i=1;i<=20;i++) lt[i].l=lt[i].r=-1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			char c;
			cin>>c;
			a[i][j]=c-'0';
		}
		for(int j=0;j<=m;j++){//统计每层最左（右）的楼梯。
			int k=m-j;
			if(a[i][j]&&lt[i].l==-1) lt[i].l=j;
			if(a[i][k]&&lt[i].r==-1) lt[i].r=k;
			if(lt[i].l!=-1&&lt[i].r!=-1) break;
		}
		if(h==-1&&(lt[i].l!=-1||lt[i].r!=-1)) h=i;//统计最高层需要关的灯。
	}
	if(h==-1){
		cout<<0;
		return 0;
	} 
	dfs(n,0,0);//初始位置为 n ，步数为 0 ，在左边。
	cout<<ans;
    return 0;
}
