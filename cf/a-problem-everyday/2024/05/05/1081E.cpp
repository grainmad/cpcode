
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
    int n;
    cin >> n;
    vector<ll> a(n, -1);
    for (int i=1; i<n; i+=2) {
        cin >> a[i];
    }
    ll ps = 0;
    for (int i=1; i<n; i+=2) {
        ll j = 1;
        while ((j+1)*(j+1)<=a[i]) j++;
        for (;j>0; j--) {
            if (a[i]%j == 0 && (j+a[i]/j)%2 == 0 && ((j+a[i]/j)/2-j)*((j+a[i]/j)/2-j) > ps) {
                // cout << j << " " << a[i]/j << "\n";
                a[i-1] = ((j+a[i]/j)/2-j)*((j+a[i]/j)/2-j) - ps;
                ps += a[i-1] + a[i];
                break;
            }
        }
    }
    for (ll i:a) {
        if (i == -1) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n";
    for (ll i:a) {
        cout << i << " ";
    }
    cout << "\n";
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
