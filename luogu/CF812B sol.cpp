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
node lt[25];//ͳ��ÿ�������ң���¥�ݡ�
int n,m,h=-1,ans=1e9+10;
void dfs(int flr,int stp,bool k){
	if(flr==h){//������Ҫ�صƵ���߲㡣
		if(k==0) stp+=lt[flr].r;
		ans=min(ans,stp);
		return;
	}
	else if(lt[flr].l==-1&&lt[flr].r==-1){//����û�е���Ҫ�ء�
		dfs(flr-1,stp+1,k);
		return;
	} 
	else if(k==0){//�������¥�ݡ�
		dfs(flr-1,stp+(2*lt[flr].r)+1,0);
		dfs(flr-1,stp+m+1,1);
	} 
	else if(k==1){//�����ұ�¥�ݡ�
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
		for(int j=0;j<=m;j++){//ͳ��ÿ�������ң���¥�ݡ�
			int k=m-j;
			if(a[i][j]&&lt[i].l==-1) lt[i].l=j;
			if(a[i][k]&&lt[i].r==-1) lt[i].r=k;
			if(lt[i].l!=-1&&lt[i].r!=-1) break;
		}
		if(h==-1&&(lt[i].l!=-1||lt[i].r!=-1)) h=i;//ͳ����߲���Ҫ�صĵơ�
	}
	if(h==-1){
		cout<<0;
		return 0;
	} 
	dfs(n,0,0);//��ʼλ��Ϊ n ������Ϊ 0 ������ߡ�
	cout<<ans;
    return 0;
}
