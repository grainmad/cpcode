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

bool ok(vector<int>a, vector<int>b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& i:a) cin >> i;
    for (auto& i:b) cin >> i;
    if (!ok(a, b)) {
        cout << "NO\n";
        return ;
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    vector<int> sa(n), sb(n);
    for (int i=0; i<n; i++) {
        sa[i] = a[idx[i]];
        sb[i] = b[idx[i]];
    }
    // cout << sa << " " << sb << endl;
    map<int,int> mp;
    for (int i:sb) mp[i];
    int id = 1;
    for (auto& [x,y]:mp) y = id++;
    vector<int> BIT(n+1);
    auto ask = [&](int x) {
        int rt = 0;
        for (int i=x; i; i&=(i-1)) {
            rt += BIT[i];
        }
        return rt;
    };
    auto add = [&](int x, int v) {
        for (int i=x; i<=n; i+=i&-i) {
            BIT[i] += v;
        }
    };
    int ans = 0;
    reverse(sb.begin(), sb.end());
    for (int i:sb) {
        ans += ask(mp[i]);
        // cout << i << " " << ask(mp[i]) << endl;
        add(mp[i], 1);
    }
    // cout << sb << endl;
    // cout << ans << "\n";
    cout << (ans%2?"NO":"YES") << "\n";
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