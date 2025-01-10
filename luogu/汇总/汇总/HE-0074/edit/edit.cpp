#include<bits/stdc++.h>
using namespace std;
int n;
string s1,s2;
string can1,can2;
int cnt1[100001][2],cnt2[100001][2];
int fa1[100001],fa2[100001];
bool isc1[100001],isc2[100001];
int find1(int id){
    if(fa1[id]==id) return id;
    return fa1[id]=find1(fa1[id]);
}
inline void join1(int x,int y){
    int fx=find1(x),fy=find1(y);
    if(fx!=fy){
        cnt1[fx][0]+=cnt1[fy][0];
        cnt1[fx][1]+=cnt1[fy][1];
        cnt1[fy][0]=0;
        cnt1[fy][1]=0;
        fa1[fy]=fx;
    }
}
int find2(int id){
    if(fa2[id]==id) return id;
    return fa2[id]=find2(fa2[id]);
}
inline void join2(int x,int y){
    int fx=find2(x),fy=find2(y);
    if(fx!=fy){
        cnt2[fx][0]+=cnt2[fy][0];
        cnt2[fx][1]+=cnt2[fy][1];
        cnt2[fy][0]=0;
        cnt2[fy][1]=0;
        fa2[fy]=fx;
    }
}
int main(){
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    // freopen("edit.in","r",stdin);
    // freopen("down/day0/edit/edit2.in","r",stdin);
    // freopen("out.out","w",stdout);
    ios::sync_with_stdio(false);
    int cases;cin>>cases;
    while(cases--){
        cin>>n;
        cin>>s1>>s2>>can1>>can2;
        for(int i=0;i<n;++i){
            cnt1[i+1][0]=(s1[i]=='0');
            cnt1[i+1][1]=(s1[i]=='1');
            cnt2[i+1][0]=(s2[i]=='0');
            cnt2[i+1][1]=(s2[i]=='1');
        }
        for(int i=1;i<=n;++i){
            fa1[i]=i;
            fa2[i]=i;
            isc1[i]=false;
            isc2[i]=false;
        }
        for(int i=1;i<n;++i){
            if(can1[i]=='1' and can1[i-1]=='1'){
                join1(i,i+1);
                isc1[i]=true;
                isc1[i+1]=true;
            }
            if(can2[i]=='1' and can2[i-1]=='1'){
                join2(i,i+1);
                isc2[i]=true;
                isc2[i+1]=true;
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            if(!isc1[i] and !isc2[i]){
                ans+=(s1[i-1]==s2[i-1]);
            }
            else if(isc1[i] and isc2[i]==false){
                if(cnt1[find1(i)][s2[i-1]-'0']){
                    ans++;
                    cnt1[find1(i)][s2[i-1]-'0']--;
                }
            }
            else if(isc1[i]==false and isc2[i]){
                if(cnt2[find2(i)][s1[i-1]-'0']){
                    ans++;
                    cnt2[find2(i)][s1[i-1]-'0']--;
                }
            }
        }
        for(int i=1;i<=n;++i){
            if(isc1[i] and isc2[i]){
                if(cnt1[find1(i)][0] and cnt2[find2(i)][0]){
                    ans++;
                    cnt1[find1(i)][0]--;
                    cnt2[find2(i)][0]--;
                }
                else if(cnt1[find1(i)][1] and cnt2[find2(i)][1]){
                    ans++;
                    cnt1[find1(i)][1]--;
                    cnt2[find2(i)][1]--;
                }
            }
        }
        cout<<ans<<'\n';
    }
}