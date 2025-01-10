#include<bits/stdc++.h>
using namespace std;
const int N=4e6+86;
int lson(int x)
{
return x<<1;
}
int rson(int x)
{
 return x<<1|1;
}
int dp[1503][110003];//这真的开的出来吗?
int a[N],b[11],sum[N],tag[N],X[N],n,m,q; 
 int cnt2=0;//这个是用来 存数的种数 
void pushup(int x)
{
 sum[x]=sum[lson(x)]|sum[rson(x)];
}
void pushdown(int x)
{
 if(tag[x])
 {
  tag[lson(x)]=tag[x];
  sum[lson(x)]=tag[x];
  tag[rson(x)]=tag[x];
  sum[rson(x)]=tag[x];
  tag[x]=0;
 } 
}
                                             //怎么把叶子节点的权值赋成状态啊 
                                             //这里用一种不太优的方法来进行权到编号的对应（其实就是桶）

void build(int x,int l,int r)
{
 if(l==r)
 {
  sum[x]=1<<(X[a[l]]-1); 
 }
 else
 {
   int mid=(l+r)>>1;
   build(lson(x),l,mid);
   build(rson(x),mid+1,r);
   pushup(x);
 }
}
void update(int x,int l,int r,int L,int R,int d)
{
	
 if(l>=L&&r<=R)
 {
  tag[x]=1<<(X[d]-1);
  sum[x]=1<<(X[d]-1);
  //cout<<"-";
  return;
 }
 
  pushdown(x);//6
  int mid=(l+r)>>1;
  if(mid<=R) update(rson(x),mid+1,r,L,R,d);
  if(mid>L) update(lson(x),l,mid,L,R,d);
   pushup(x);

}
int query(int x,int l,int r,int L,int R)
{
 int tmp=0;
 if(l>=L&&r<=R)
 {
 	return sum[x];
 }
 else {
  int mid=(l+r)>>1;
  pushdown(x);
  if(mid<=R)tmp|=query(rson(x),mid+1,r,L,R);
  if(mid>L) tmp|=query(lson(x),l,mid,L,R);

  return tmp;
 }
}
void init()
{
	for(int i=0;i<=(1<<cnt2-1);i++)
	{
	 dp[i][0]=1;
  for(int j=1;j<=m;j++)
  {
   for(int k=1;k<=cnt2;k++)
  	if(i&(1<<(k-1))) dp[i][j]=(dp[i^(1<<(k-1))][j-b[k]])||(dp[i^(1<<(k-1))][j]);
  }
	}	   
}
int l[N],r[N],x[N],opt[N]; map<int ,int >mp;
                                                      //给自个埋个坑先 线段树上的点应该是编号 
int main()
{

cin>>n>>m>>q;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  if(!mp.count(a[i]))
  {
  	mp[a[i]]=1;
  	b[++cnt2]=a[i];
  	X[a[i]]=cnt2;
   } 
 }int cnt=0;

 while(q--)                         //先把输入搞完 看数据就知道肯定离线处理 
 {
  cin>>opt[++cnt]>>l[cnt]>>r[cnt]>>x[cnt];
  if(!mp.count(x[cnt]))
  { 
   mp[x[cnt]]=1;                     //x是顺序; 
   b[++cnt2]=x[cnt];                //b中是数值 X中是反向映射 
   X[x[cnt]]=cnt2;                 //吐槽一句 我这写的JB啊 
  }
 }
 init();
 build(1,1,n);
 int k=0; 
 
// cout<<"cnt:"<<cnt<<' ';
 
 
 for(int i=1;i<=cnt;i++)
 {cout<<++k<<" ";
if(opt[i]==1)
  {
  //cout<<++k<<" ";	
    update(1,1,n,l[i],r[i],x[i]);
  }
else {
                          //	cout<<1<<" ";   就进了一次这个else？？ 
   if(dp[query(1,1,n,l[i],r[i])][x[i]]==1)
   {
   	//cout<<++k;
   	 cout<<"Yes"<<endl;
   	 //cout<<"k";
   }
   else cout<<"No"<<endl; 
   } 
 }
 
 
 return 0;
}
/*
3 3 3
1 2 3
2 1 3 2
1 1 3 3
2 1 3 2
*/