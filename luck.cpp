#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
string c[50];
void cin_cars() {
    int n;
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++) {
        getline(cin,c[i]);
        // cout << c[i] << '\n';
    }
    cin.clear();
}
mt19937 r(time(0));
int tot[50],res[50];
void cin_res() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> res[i];
        // cout << c[i] << '\n';
    }
}
int main () {
    SetConsoleOutputCP(CP_UTF8);
    freopen("cars.txt","r",stdin);
    cin_cars();
    freopen("res.txt","r",stdin);
    cin_res();
    puts("恭喜：您获得了如下卡牌：");
    for (int i = 1; i <= 200; i++) {
        Sleep(750);
        int p = r() % 23 + 1;
        cout << c[p] << " x";
        int cnt = r() % 10;
        if (cnt == 0) cnt = 8;
        else if (cnt >= 2 && cnt <= 3) cnt = 3;
        else if (cnt >= 4) cnt = 1;
        Sleep(250);
        cout << cnt; 
        tot[p] += cnt;
        cout << ' ' << tot[p] << "/" << res[p] << ' ';
        if (tot[p] >= res[p]) cout << "已可升星！";
        cout << '\n';
    }
    return 0;
}