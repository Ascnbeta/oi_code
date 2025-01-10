#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy,ex,ey;
char c[2005][2005];
bool f[2005][2005];
struct wz{
    int x,y,ans;
};
int gx[4]={0,0,1,-1};
int gy[4]={1,-1,0,0};
map<char,bool> mapp;
int bfs(){
    queue<wz> q;
    wz a;
    a.x=sx;
    a.y=sy;
    a.ans=0;
    q.push(a);
    while(!q.empty()){
        a=q.front();
        q.pop();
        if(a.x==ex&&a.y==ey) return a.ans;
        for(int i=0;i<4;i++){
            wz xin;
            xin.x=gx[i]+a.x;
            xin.y=gy[i]+a.y;
            xin.ans=a.ans+1;
            if(f[xin.x][xin.y]) q.push(xin),f[xin.x][xin.y]=false;
        }
        if(c[a.x][a.y]!='.'){
            char cs=c[a.x][a.y];
            if(mapp[cs]) continue;
            mapp[cs]=true;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(c[i][j]==cs){
                        wz xin;
                        xin.x=i;
                        xin.y=j;
                        xin.ans=a.ans+1;
                        q.push(xin);
                        f[i][j]=false;
                    }
                }
            }
        }
    }
    return -1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
            if(c[i][j]!='#') f[i][j]=true;
            if(c[i][j]=='S') sx=i,sy=j;
            if(c[i][j]=='G') ex=i,ey=j;
        }
    }
    cout<<bfs();
	return 0;
}