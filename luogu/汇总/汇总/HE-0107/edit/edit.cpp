#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
string s,ss,t,tt;
void solve1(){
    for(int i=0;i<n;i++){
            if(s[i]==ss[i]) ans++;
        }
    cout<<ans<<endl;
}
void solve2(){
    string fixs=s,fixss=ss;
    int pos1=0,pos2=0;
    for(int i=0;i<n;i++){
        if(t[i]=='1'){
                fixs[pos1++]=s[i];
                fixss[pos2++]=ss[i];
        }
    }
    //cout<<fixs<<endl<<fixss<<endl;
    int zero1=0,zero2=0,one1=0,one2=0;
    for(int i=0;i<n;i++){
        if(fixs[i]=='0') zero1++;
        if(fixs[i]=='1') one1++;
        if(fixss[i]=='0') zero2++;
        if(fixss[i]=='1') one2++;
    }
    cout<<min(one1,one2)+min(zero1,zero2)<<endl;
}
int main(){
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        cin>>s>>ss>>t>>tt;
        int tmp=s[0];
        bool yes=true;
        for(int i=0;i<n;i++)
            if(s[i]!=tmp) {yes=false;break;}
        if(yes) solve1();
        else solve2();
    }
    return 0;
}
