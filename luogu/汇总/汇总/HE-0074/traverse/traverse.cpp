// #include<bits/stdc++.h>
// using namespace std;
// int n,q;
// struct edge{
//     int from,to;
// };
// edge e[100001];
// bool vis[100001];
// int cnt=0;
// vector<int>p;
// vector<int>e2[100001];
/*
#include<bits/stdc++.h>
using namespace std;
vector<int>p;
int n,q;
struct edge{
    int from,to;
};
edge e[100001];
bool vis[100001];
int cnt=0;
map<unsigned long long,bool>mp;
inline unsigned long long __hash(){
    unsigned long long ans=0;
    for(int i:p) ans=ans*233ull+i;
    return ans;
}
void dfs(int now){
    vis[now]=true;
    p.push_back(now);
    cnt++;
    if(cnt==n-1){
        mp[__hash()]=true;
        return;
    }
    vector<int>can;
    for(int i=1;i<=n-1;++i){
        if(!vis[i] and (e[i].from==e[now].from or e[i].from==e[now].to or e[i].to==e[now].from or e[i].to==e[now].to)){
            can.push_back(i);
        }
    }
    sort(can.begin(),can.end());
    do{
        for(int i:can){
            if(!vis[i] and (e[i].from==e[now].from or e[i].from==e[now].to or e[i].to==e[now].from or e[i].to==e[now].to)){
                dfs(i);
            }
        }
    }while(next_permutation(can.begin(),can.end()));
    vis[now]=false;
    cnt--;
    p.pop_back();
}
int main(){
    freopen("down/day0/traverse/traverse2.in","r",stdin);
    ios::sync_with_stdio(false);
    int id,cases;
    cin>>id>>cases;while(cases--){
        cin>>n>>q;
        for(int i=1;i<=n-1;++i){
            cin>>e[i].from>>e[i].to;
        }
        mp.clear();
        while(q--){
            int x;cin>>x;
            dfs(x);
        }
        cout<<mp.size()<<'\n';
    }
}
*/
// vector<int>can;
// inline bool check(){
//     bool flag=false;
//     for(int i:can){
//         if(p[1]==i){
//             flag=true;
//             break;
//         }
//     }
//     if(!flag) return false;
//     int minn=n-1;
//     for(int i=n-1;i>=2;--i){
//         bool flag2=false;
//         for(int j=minn;j>=1;--j){
//             if(e[i].from==e[j].from or e[i].to==e[j].from or e[i].from==e[j].to or e[i].to==e[j].to){
//                 flag2=true;
//                 minn=min(minn,j);
//                 break;
//             }
//         }
//         if(!flag2) return false;
//     }
//     for(int i=1;i<=n-1;++i) cout<<p[i]<<' ';
//     cout<<endl;
//     // for(int i=2;i<=n-1;++i){
//     //     bool flag2=false;
//     //     for(int j=1;j<i;++j){
//     //         if(e[i].from==e[j].from or e[i].to==e[j].from or e[i].from==e[j].to or e[i].to==e[j].to){
//     //             flag2=true;
//     //             break;
//     //         }
//     //     }
//     //     if(!flag2) return false;
//     // }
//     return true;
// }
// int dfs(){
//     int ans=0;
//     for(int i=1;i<=n-1;++i){
//         p[i]=i;
//     }
//     do{
//         ans+=check();
//     }while(next_permutation(p+1,p+n));
//     return ans;
// }
//za zuo sheng cheng shu ji shu
// int main(){
//     // freopen("down/day0/traverse/traverse2.in","r",stdin);
//     freopen("traverse.in","r",stdin);
//     freopen("traverse.out","w",stdout);
//     ios::sync_with_stdio(false);
//     int id,cases;
//     cin>>id>>cases;while(cases--){
//         cin>>n>>q;
//         for(int i=1;i<=n-1;++i){
//             cin>>e[i].from>>e[i].to;
//         }
//         for(int i=1;i<=n-1;++i){
//             for(int j=1;j<i;++j){
//                 if(e[i].from==e[j].from or e[i].to==e[j].from or e[i].from==e[j].to or e[i].to==e[j].to){
//                     e2[i].push_back(j);
//                     e2[j].push_back(i);
//                 }
//             }
//         }
//         while(q--){
//             int x;cin>>x;
//         }
//     }
// }
#include<bits/stdc++.h>
using namespace std;
vector<int>p;
int n,q;
struct edge{
    int from,to;
};
edge e[100001];
bool vis[100001];
int cnt=0;
map<unsigned long long,bool>mp;
inline unsigned long long __hash(){
    unsigned long long ans=0;
    for(int i:p) ans=ans*233ull+i;
    return ans;
}
void dfs(int now){
    vis[now]=true;
    p.push_back(now);
    cnt++;
    if(cnt==n-1){
        mp[__hash()]=true;
        return;
    }
    vector<int>can;
    for(int i=1;i<=n-1;++i){
        if(!vis[i] and (e[i].from==e[now].from or e[i].from==e[now].to or e[i].to==e[now].from or e[i].to==e[now].to)){
            can.push_back(i);
        }
    }
    sort(can.begin(),can.end());
    do{
        for(int i:can){
            if(!vis[i] and (e[i].from==e[now].from or e[i].from==e[now].to or e[i].to==e[now].from or e[i].to==e[now].to)){
                dfs(i);
            }
        }
    }while(next_permutation(can.begin(),can.end()));
    vis[now]=false;
    cnt--;
    p.pop_back();
}
int main(){
    freopen("traverse.in","r",stdin);
    freopen("traverse.out","w",stdout);
    ios::sync_with_stdio(false);
    int id,cases;
    cin>>id>>cases;while(cases--){
        cin>>n>>q;
        for(int i=1;i<=n-1;++i){
            cin>>e[i].from>>e[i].to;
        }
        mp.clear();
        while(q--){
            int x;cin>>x;
            dfs(x);
        }
        cout<<mp.size()<<'\n';
    }
}