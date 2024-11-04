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


void sol() {
    int n, c, k;
    cin >> n >> c >> k;
    string s;
    cin >> s;
    int cur = 0, msk = (1<<c)-1;
    vector<int> cnt(26), bad(1<<c);
    for (int i=0; i<k; i++) cnt[s[i]-'A']++, cur |= 1<<(s[i]-'A');
    bad[msk^cur] = 1;
    for (int i=k; i<n; i++) {
        if (--cnt[s[i-k]-'A'] == 0) cur ^= 1<<(s[i-k]-'A');
        if (cnt[s[i]-'A']++ == 0) cur |= 1<<(s[i]-'A');
        bad[msk^cur] = 1;
    }
    bad[msk^(1<<(s[n-1]-'A'))] = 1;
    for (int i=0; i<c; i++) {
        for (int j=0; j<1<<c; j++) {
            if (j>>i&1) bad[j^(1<<i)] |= bad[j];
        }
    }
    int ans = 1e9;
    for (int i=0; i<1<<c; i++) {
        if (bad[i]) continue;
        int b = 0;
        for (int j=i; j; j&=(j-1)) b++;
        ans = min(ans, b);
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