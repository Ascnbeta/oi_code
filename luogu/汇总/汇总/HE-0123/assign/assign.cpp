#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n,m,v;
struct node{
  ll c,d;
};

int x[10000010];
node xz[100010];

void work(){
  scanf("%lld%lld%lld",&n,&m,&v);
  for(ll i=1;i<=m;i++){
    scanf("%lld%lld",&xz[i].c,&xz[i].d);
    x[xz[i].c]=xz[i].d;
  }
  ll ans=1;
  for(ll i=1;i<=n-1;i++){
    ans=ans*v;
  }
  ans=ans*ans;
  //cout<<"firans:"<<ans<<"v:"<<v<<v*(v-1);
  int a1=1;
  for(ll i=1;i<=n-1;i++){
    a1=a1*(v+1-i);
  }
  /*
   for(int i=1;i<=n-1;i++){
    ans=ans-(v+1-i)*(v-i);
  }
  ans+=n-1;
  */
  ans=ans-a1+1;
  cout<<ans%1000000007<<endl;
return;
}

int main(){
  freopen("assign.in","r",stdin);
  freopen("assign.out","w",stdout);
  scanf("%d",&T);
  for(int i=1;i<=T;i++){
    work();
  }

return 0;
}
