#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

const int N = 1e5+10;
const int M = 1e9+7;

int n,m,v;
int a[N];

long long pw(int a,int b){
    long long t = a;
    long long ret = 1;
    while(b){
        if(b & 1){
            ret = ret * t % M;
        }
        b = b >> 1;
        t = t * t % M;
    }
    return ret;
}
int main(){

    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);

    int t;
    cin>>t;
    while(t){
        memset(a,0,sizeof(a));
        cin>>n>>m>>v;
        int c,d;
        long long ans = 0;
        bool ct = 0;
        int cnt = 0;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&c,&d);
            if(a[c] == 0){
                a[c] = d;
                cnt++;
            }else if(a[c]!=0){
                if(a[c] != d){
                    ct = 1;
                    break;
                }
            }
        }
        if(ct == 1){
            ans = 0;
        }else if(n == m){
            //personality A;
            ans = pw(v,n) - pw(v,n-1) + 1;
        }else if(n != m){
            //personality B;
            ans = pw(v,n-cnt);
        }
        cout<<ans<<endl;
        t--;
    }

    return 0;
}
