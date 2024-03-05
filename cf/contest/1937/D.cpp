#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

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
    ll n;
    string s;
    cin >> n;
    cin >> s;
    s = "#" + s;
    vector<ll> la(1), ra(1);
    for (ll i = n; i >= 1; i--) {
        if (s[i] == '<') {
            la.push_back(la.back() + i);
        }
    }
    for (ll i = 1; i <= n; i++) {
        if (s[i] == '<')
            la.pop_back();
        // cout << i << ":" << s[i] << endl;
        // cout << ra << endl;
        // cout << la << endl;
        ll c = min(la.size(), ra.size());
        ll stp = (ra.back() - ra[ra.size() - c] - (n - i + 1) * (c - 1)) * 2 +
                 (la.back() - la[la.size() - c] - i * (c - 1)) * 2;
        if (s[i] == '>') {
            if (la.size() == c)
                stp += n + 1 - i;
            else
                stp += (la[la.size() - c] - la[la.size() - c - 1]) * 2 - i;
        } else {
            if (ra.size() == c)
                stp += i;
            else
                stp += (ra[ra.size() - c] - ra[ra.size() - c - 1]) * 2 -
                       (n + 1 - i);
        }
        cout << stp << " ";
        if (s[i] == '>')
            ra.push_back(ra.back() + n - i + 1);
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