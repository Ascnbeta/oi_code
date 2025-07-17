#include <iostream>
#include <cstdio>
#include <queue>
#include <assert.h>
#define int long long
using namespace std;
struct role{
    int maxhp,hp;
    int maxmp,mp;
    int atk,deltaatk;
    int def,deltadef;
    int talent,tval[5];
    int skill,sval[5];
    int p[12];
    bool live;
    void init() {hp=maxhp,mp=0,deltaatk=0,deltadef=0,live=true;}
    void addmp(int val) {mp+=val,mp=min(mp,maxmp);}
    void addhp(int val) {hp+=val,hp=min(hp,maxhp);}
}r[2][12];//0->Alice 1->Bob
int n;int cnt[2];//活着几个角色
int tim;//第几回合
queue<pair<int,int>> s4[2];//first:技能4最后生效回合 second:其生效时可回复的能量值大小
queue<pair<int,int>> s6[2];//first:技能6最后生效回合 second:其生效时敌方减少的deltaatk
queue<pair<int,int>> s7[2];//first:技能7最后生效回合 second:其生效时我方增加的deltaatk
queue<pair<int,int>> s8[2];//first:技能8最后生效回合 second:其生效时敌方减少的deltadef
queue<pair<int,int>> s9[2];//first:技能9最后生效回合 second:其生效时我方增加的deltadef
int s10[2];//技能10何时结束
void init() {
    cnt[0]=cnt[1]=n;
    for (int i = 1; i <= n; i++) r[0][i].init();
    for (int i = 1; i <= n; i++) r[1][i].init();
}
void play(int c);
void skill(int num,int per,int bel);
void damage(int per,int bel,int val,int true_val);
int calcdamage(int per,int bel,int val,int true_val);
void judgewin();
int choose_target(int per,int bel);
void total();
void print();
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> r[0][i].maxhp >> r[0][i].maxmp >> r[0][i].atk >> r[0][i].def;
        for (int j = 1; j <= n; j++) cin >> r[0][i].p[j];
        cin >> r[0][i].talent >> r[0][i].tval[1] >> r[0][i].tval[2];
        cin >> r[0][i].skill >> r[0][i].sval[1] >> r[0][i].sval[2] >> r[0][i].sval[3];
    }
    for (int i = 1; i <= n; i++) {
        cin >> r[1][i].maxhp >> r[1][i].maxmp >> r[1][i].atk >> r[1][i].def;
        for (int j = 1; j <= n; j++) cin >> r[1][i].p[j];
        cin >> r[1][i].talent >> r[1][i].tval[1] >> r[1][i].tval[2];
        cin >> r[1][i].skill >> r[1][i].sval[1] >> r[1][i].sval[2] >> r[1][i].sval[3];
    }
    init();
    play(1);
    return 0;
}
#define A max(r[bel][per].atk+r[bel][per].deltaatk,1ll)
#define D max(r[bel][per].def+r[bel][per].deltadef,0ll)
void play(int c) {
    ++tim;
    if (c > 23333) {
        cerr << "fatal error: 02" << '\n';
        exit(0);
        return;
    }
    //Alice
    int tg = 0;
    for (int i = n; i >= 1; i--) {
        if (r[0][i].live&&r[0][i].mp==r[0][i].maxmp) {
            if (tg == 0) tg = i;
            else if (r[0][i].skill > r[0][tg].skill) tg = i;
        }
    }
    if (tg) {
        // printf("Alice %d used skill %d.\n",tg,r[0][tg].skill);
        if (r[0][tg].skill != 10) r[0][tg].mp = 0;
        skill(r[0][tg].skill,tg,0);
        if (r[0][tg].talent == 5) {
            r[0][tg].addmp(r[0][tg].tval[2]+1);
        }else{
            r[0][tg].addmp(1);
        }

    }else{
        int hp = 0,dam = 0;
        for (int i = n; i >= 1; i--) {
            if (r[0][i].live) {
                int tgt = choose_target(i,0);
                if (r[1][tgt].hp > hp) {
                    tg = i,hp = r[1][tgt].hp;
                    int tmp = 0;
                    if (r[0][i].talent == 2) {
                        tmp = calcdamage(tgt,1,max(r[0][i].atk+r[0][i].deltaatk,1ll),r[0][i].tval[1]);
                    }else if(r[0][i].talent == 4) {
                        tmp = calcdamage(tgt,1,0,max(r[0][i].atk+r[0][i].deltaatk,1ll));
                    }else{
                        tmp = calcdamage(tgt,1,max(r[0][i].atk+r[0][i].deltaatk,1ll),0);
                    }
                    dam = tmp;
                }else if(r[1][tgt].hp == hp) {
                    int tmp = 0;
                    if (r[0][i].talent == 2) {
                        tmp = calcdamage(tgt,1,max(r[0][i].atk+r[0][i].deltaatk,1ll),r[0][i].tval[1]);
                    }else if(r[0][i].talent == 4) {
                        tmp = calcdamage(tgt,1,0,max(r[0][i].atk+r[0][i].deltaatk,1ll));
                    }else{
                        tmp = calcdamage(tgt,1,max(r[0][i].atk+r[0][i].deltaatk,1ll),0);
                    }
                    if (tmp > dam) tg = i,dam = tmp;
                }
            }
        }
        int tgt = choose_target(tg,0);
        // printf("Alice %d attacked %d.\n",tg,tgt);
        if (r[0][tg].talent == 2) {
            damage(tgt,1,max(r[0][tg].atk+r[0][tg].deltaatk,1ll),r[0][tg].tval[1]);
        }else if(r[0][tg].talent == 4) {
            damage(tgt,1,0,max(r[0][tg].atk+r[0][tg].deltaatk,1ll));
        }else{
            damage(tgt,1,max(r[0][tg].atk+r[0][tg].deltaatk,1ll),0);
        }
        if (r[0][tg].talent == 5) {
            r[0][tg].addhp(r[0][tg].tval[1]);
        }
        r[0][tg].addmp(1);
    }
    int pls = 1,len = s4[0].size(),t = 0;
    while (!s4[0].empty()) {
        ++t;
        auto tmp = s4[0].front();
        s4[0].pop();
        pls += tmp.second;
        if (tmp.first != tim) s4[0].push(tmp);
        if (t == len) break;
    }
    if (s10[0]) pls++;
    for (int i = 1; i <= n; i++) {
        if (r[0][i].live) {
            r[0][i].addmp(pls);
            if (r[0][i].talent == 3) r[0][i].addhp(r[0][i].tval[1]),r[0][i].addmp(r[0][i].tval[2]);
        }
    }
    // puts("Alice's round over.");
    // print();
    //Bob
    tg = 0;
    for (int i = n; i >= 1; i--) {
        if (r[1][i].live&&r[1][i].mp==r[1][i].maxmp) {
            if (tg == 0) tg = i;
            else if (r[1][i].skill > r[1][tg].skill) tg = i;
        }
    }
    if (tg) {
        if (r[1][tg].skill != 10) r[1][tg].mp = 0;
        // printf("Bob %d used skill %d.\n",tg,r[1][tg].skill);
        skill(r[1][tg].skill,tg,1);
        if (r[1][tg].talent == 5) {
            r[1][tg].addmp(r[1][tg].tval[2]+1);
        }else{
            r[1][tg].addmp(1);
        }

    }else{
        int hp = 0,dam = 0;
        for (int i = n; i >= 1; i--) {
            if (r[1][i].live) {
                int tgt = choose_target(i,1);
                if (r[0][tgt].hp > hp) {
                    tg = i,hp = r[0][tgt].hp;
                    int tmp = 0;
                    if (r[1][i].talent == 2) {
                        tmp = calcdamage(tgt,0,max(r[1][i].atk+r[1][i].deltaatk,1ll),r[1][i].tval[1]);
                    }else if(r[1][i].talent == 4) {
                        tmp = calcdamage(tgt,0,0,max(r[1][i].atk+r[1][i].deltaatk,1ll));
                    }else{
                        tmp = calcdamage(tgt,0,max(r[1][i].atk+r[1][i].deltaatk,1ll),0);
                    }
                    dam = tmp;
                }else if(r[0][tgt].hp == hp) {
                    int tmp = 0;
                    if (r[1][i].talent == 2) {
                        tmp = calcdamage(tgt,0,max(r[1][i].atk+r[1][i].deltaatk,1ll),r[1][i].tval[1]);
                    }else if(r[1][i].talent == 4) {
                        tmp = calcdamage(tgt,0,0,max(r[1][i].atk+r[1][i].deltaatk,1ll));
                    }else{
                        tmp = calcdamage(tgt,0,max(r[1][i].atk+r[1][i].deltaatk,1ll),0);
                    }
                    if (tmp > dam) tg = i,dam = tmp;
                }
            }
        }
        
        int tgt = choose_target(tg,1);
        // printf("Bob %d attacked %d.\n",tg,tgt);
        if (r[1][tg].talent == 2) {
            damage(tgt,0,max(r[1][tg].atk+r[1][tg].deltaatk,1ll),r[1][tg].tval[1]);
        }else if(r[1][tg].talent == 4) {
            damage(tgt,0,0,max(r[1][tg].atk+r[1][tg].deltaatk,1ll));
        }else{
            damage(tgt,0,max(r[1][tg].atk+r[1][tg].deltaatk,1ll),0);
        }
        if (r[1][tg].talent == 5) {
            r[1][tg].addhp(r[1][tg].tval[1]);
        }
        r[1][tg].addmp(1);
    }
    pls = 1,len = s4[1].size(),t = 0;
    while (!s4[1].empty()) {
        ++t;
        auto tmp = s4[1].front();
        s4[1].pop();
        pls += tmp.second;
        if (tmp.first != tim) s4[1].push(tmp);
        if (t == len) break;
    }
    if (s10[1]) pls++;
    for (int i = 1; i <= n; i++) {
        if (r[1][i].live) {
            r[1][i].addmp(pls);
            if (r[1][i].talent == 3) r[1][i].addhp(r[1][i].tval[1]),r[1][i].addmp(r[1][i].tval[2]);
        }
    }
    // puts("Bob's round over.");
    // print();
    total();
    // printf("Round %d is over.\n",tim);
    // print();
    play(c+1);
}
void skill(int num,int per,int bel)  {
    int atk = bel^1;//被攻击的玩家编号
    int tgt = choose_target(per,bel);//选择目标
    if (num == 0) return;
    else if(num == 1) {
        for (int i = 1; i <= n; i++) {
            if (r[atk][i].live) {//活着
                damage(i,atk,r[bel][per].sval[1],0);
                if (r[atk][i].live) r[atk][i].mp -= r[atk][i].mp/10;
            }
        }
    }else if(num == 2) {
        for (int i = 1; i <= n; i++) {
            if (r[atk][i].live) {
                damage(i,atk,0,A);
            }
        }
    }else if(num == 3) {
        for (int i = 1; i <= n; i++) {
            if (r[atk][i].live) {
                damage(i,atk,min(r[atk][i].maxhp/10,r[bel][per].sval[1]*A),0);
            }
        }
    }else if(num == 4) {
        s4[bel].push({tim+r[bel][per].sval[1]-1,r[bel][per].sval[2]});
    }else if(num == 5) {
        r[atk][tgt].deltadef -= r[bel][per].sval[1];
        damage(tgt,atk,0,A);
    }else if(num == 6) {
        damage(tgt,atk,0,A);
        s6[bel].push({tim+r[bel][per].sval[1]-1,r[bel][per].sval[2]});
        for (int i = 1; i <= n; i++) {
            if (r[atk][i].live) {
                r[atk][i].deltaatk -= r[bel][per].sval[2];
            }
        }
    }else if(num == 7) {
        int tg = 0;
        for (int i = 1; i <= n; i++) {
            if (r[bel][i].live) {
                if (tg == 0) tg = i;
                else if(r[bel][i].hp < r[bel][tg].hp) tg = i;
            }
        }
        r[bel][tg].addhp(r[bel][per].sval[3]);
        for (int i = 1; i <= n; i++) {
            if (r[bel][i].live) {
                r[bel][i].deltaatk += r[bel][per].sval[2];
            }
        }
        s7[bel].push({tim+r[bel][per].sval[1]-1,r[bel][per].sval[2]});
    }else if(num == 8) {
        for (int i = 1; i <= n; i++) {
            if (r[atk][i].live) damage(i,atk,A,0);
        }
        for (int i = 1; i <= n; i++) {
            if (r[atk][i].live) {
                r[atk][i].deltadef -= r[bel][per].sval[2];
            }
        }
        s8[bel].push({tim+r[bel][per].sval[1]-1,r[bel][per].sval[2]});
    }else if(num == 9) {
        for (int i = 1; i <= n; i++) {
            if (r[bel][i].live) {
                r[bel][i].addhp(r[bel][per].sval[3]);
                r[bel][i].deltadef += r[bel][per].sval[2];
            }
        }
        s9[bel].push({tim+r[bel][per].sval[1]-1,r[bel][per].sval[2]});
    }else if(num == 10) {
        s10[bel] = tim+r[bel][per].sval[1]-1;
        for (int i = 1; i <= n; i++) {
            if (r[bel][i].live) {
                r[bel][i].atk *= 2;
                r[bel][i].def *= 2;
                r[bel][i].hp = max(r[bel][i].maxhp/2,r[bel][i].hp);
                r[bel][i].mp = max(r[bel][i].maxmp/2,r[bel][i].mp);
               
            }
            if (r[bel][i].skill == 10) r[bel][i].skill = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (r[atk][i].skill == 10) r[atk][i].skill = 0;
        }
    }else{
        cerr << "fatal error: 01" << '\n';
        assert(0);
    }
}
void damage(int per,int bel,int val,int true_val) {//val->伤害，true_val->真实伤害
    if (!r[bel][per].live) return;
    r[bel][per].addmp(1);
    int hp_backup = r[bel][per].hp;
    r[bel][per].hp -= max(val-D,0ll)+true_val-(r[bel][per].talent==1?1:0)*(true_val/2);
    // if (bel == 0) printf("Alice %d get %d damage\n",per,hp_backup-r[bel][per].hp);
    // else printf("Bob %d get %d damage\n",per,hp_backup-r[bel][per].hp);
    if (r[bel][per].hp <= 0) {
        r[bel][per].hp = 0;
        r[bel][per].live = false;
        --cnt[bel];
        // if (bel == 0) printf("Alice %d died.\n",per);
        // else printf("Bob %d died.\n",per);
        judgewin();
        return;
    }

}
int calcdamage(int per,int bel,int val,int true_val) {//val->伤害，true_val->真实伤害
    // hp1 = max(0,hp1);
    if (!r[bel][per].live) assert(0);
    return max(val-D,0ll)+true_val-(r[bel][per].talent==1)*(true_val/2);
}
void judgewin() {
    if (cnt[0] == 0) {
        cout << tim << '\n';
        cout << "Bob" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << r[1][i].hp << ' ';
        }
        exit(0);
    }else if(cnt[1] == 0) {
        cout << tim << '\n';
        cout << "Alice" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << r[0][i].hp << ' ';
        }
        exit(0);
    }
    return;
}
int choose_target(int per,int bel)  {
    for (int i = 1; i <= n; i++) {
        if (r[bel^1][r[bel][per].p[i]].hp > 0) return r[bel][per].p[i];
    }
    cerr << "fatel error:00" << '\n';
    assert(0);
}
void total() {
    if (s10[0] == tim) {
        cout << tim << '\n';
        cout << "Bob" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << r[1][i].hp << ' ';
        }
        exit(0);
    }else if(s10[1] == tim) {
        cout << tim << '\n';
        cout << "Alice" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << r[0][i].hp << ' ';
        }
        exit(0);
    }
    while (!s6[0].empty()&&s6[0].front().first==tim) {
        auto tmp = s6[0].front();
        s6[0].pop();
        for (int i = 1; i <= n; i++) {
            if (r[1][i].live) {
                r[1][i].deltaatk += tmp.second;
            }
        }
    }
    while (!s7[0].empty()&&s7[0].front().first==tim) {
        auto tmp = s7[0].front();
        s7[0].pop();
        for (int i = 1; i <= n; i++) {
            if (r[0][i].live) {
                r[0][i].deltaatk -= tmp.second;
            }
        }
    }
    while (!s8[0].empty()&&s8[0].front().first==tim) {
        auto tmp = s8[0].front();
        s8[0].pop();
        for (int i = 1; i <= n; i++) {
            if (r[1][i].live) {
                r[1][i].deltadef += tmp.second;
            }
        }
    }
    while (!s9[0].empty()&&s9[0].front().first==tim) {
        auto tmp = s9[0].front();
        s9[0].pop();
        for (int i = 1; i <= n; i++) {
            if (r[0][i].live) {
                r[0][i].deltadef -= tmp.second;
            }
        }
    }
    while (!s6[1].empty()&&s6[1].front().first==tim) {
        auto tmp = s6[1].front();
        s6[1].pop();
        for (int i = 1; i <= n; i++) {
            if (r[0][i].live) {
                r[0][i].deltaatk += tmp.second;
            }
        }
    }
    while (!s7[1].empty()&&s7[1].front().first==tim) {
        auto tmp = s7[1].front();
        s7[1].pop();
        for (int i = 1; i <= n; i++) {
            if (r[1][i].live) {
                r[1][i].deltaatk -= tmp.second;
            }
        }
    }
    while (!s8[1].empty()&&s8[1].front().first==tim) {
        auto tmp = s8[1].front();
        s8[1].pop();
        for (int i = 1; i <= n; i++) {
            if (r[0][i].live) {
                r[0][i].deltadef += tmp.second;
            }
        }
    }
    while (!s9[1].empty()&&s9[1].front().first==tim) {
        auto tmp = s9[1].front();
        s9[1].pop();
        for (int i = 1; i <= n; i++) {
            if (r[1][i].live) {
                r[1][i].deltadef -= tmp.second;
            }
        }
    }
}
void print() {
    for (int i = 1; i <= n; i++) printf("Alice: %d hp=%d mp=%d\n",i,r[0][i].hp,r[0][i].mp);
    for (int i = 1; i <= n; i++) printf("Bob: %d hp=%d mp=%d\n",i,r[1][i].hp,r[1][i].mp);
}