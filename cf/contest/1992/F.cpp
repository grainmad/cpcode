#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

random_device seed;
ranlux48 engine(seed());
int random(int l, int r) {
    uniform_int_distribution<> distrib(l, r);
    return distrib(engine);
}
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

int divs[N];
int usd[N];

void sol() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int& i:a) cin >> i;
    vector<int> d;
    for (int i=1; i*i<=x; i++) {
        if (x%i == 0) {
            divs[i] = 1;
            d.emplace_back(i);
            if (x/i != i) {
                divs[x/i] = 1;
                d.emplace_back(x/i);
            }
        } 
    }
    int ans = 1;
    vector<int> cur{1};
    usd[1] = 1;
    for (int i:a) {
        if (!divs[i]) continue;
        vector<int> tcur;
        int ok = 1;
        for (int j : cur) {
            if (1LL*j*i <= x && divs[i*j] && !usd[i*j]) {
                usd[i*j] = 1;
                tcur.push_back(i*j);
                if (j*i == x) {
                    ok = 0;
                }
            }
        }
        for (int t:tcur) cur.push_back(t);
        if (!ok) {
            ans++;
            for (int j:cur) {
                usd[j] = 0;
            }
            usd[1] = usd[i] = 1;
            cur = vector<int>{1, i};
        }
    }
    for (int i:d) {
        usd[i] = divs[i] = 0;
    }
    cout << ans << "\n";
}

int main() {
    cout << setprecision(15) << fixed;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}