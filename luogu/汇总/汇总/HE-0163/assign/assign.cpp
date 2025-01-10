//g++ -std=c++14 T2test.cpp -o T2 -O2 -Wall

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;

const int M = 1e6 + 100;
ll n, m, v;
map<ll, ll> cnt;
ll C[M];
// ll Pow[M];

ll ksm(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void work()
{
    cin >> n >> m >> v;
    // bool flagb = 1;
    bool flagover = 0;
    for(int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        C[i] = x;
        // if(y != 1) flagb = 0;
        if(cnt[x] != 0 and cnt[x] != y)
        {
            cout << 0 << endl;
            flagover = 1;
        }
        cnt[x] = y;
        

    }

    if(flagover == 1)
        return;
    
    if(m == 1) // 6,7,8,9
    {
        cout << ksm(v * v % mod, n - 1) << endl;
        return ;
    }

    if(m == n) // 10,11,12 (A)
    {

        cout << ksm(((v - 1) * v + 1) % mod, n - 1) << endl;
        return ;
    }
    // cout << -1 << endl;


    // if(flagb)
    // {
    //     sort(C + 1, C + m + 1);

    //     // for(int i = 1; i <= m; i++)
    //     // {
    //     //     Pow[i] = ksm(v * v % mod, i);
    //     // }
        
    //     ll i = 1;
    //     ll ans = 1;
    //     while(i <= m - 1)
    //     {
    //         ll l = C[i];
    //         ll r = C[i + 1];
    //         ll len = r - l + 1;
    //         i ++;

    //         ll temp1 = ((v - 1) * v) % mod * ksm(v * v % mod, len - 1) % mod;
    //         ll temp2 = v * (v - 1) * v * ksm(v * v % mod, len - 2) % mod;

    //         ans = ans * ((temp1 + temp2) % mod) % mod;
            
    //         // temp = 

    //     }

    //     cout << ans << endl;
    //     return;
    // }

    cout << 0 << endl;
    
}



int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("assign.in", "r", stdin);
    freopen("assign.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cnt.clear();
        work();
    }
}