
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
    for(auto [x,y]:mp) { if (s) s = 0; else os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {
    int n;
    cin >> n;
    vector<pair<int,int>> dg1;
    int sdg1 = 0;
    vector<int> d1;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x == 1) d1.push_back(i);
        else dg1.emplace_back(i, x), sdg1+=x;
    }

    if (dg1.size() && sdg1 >= (dg1.size()-1)*2 + d1.size()) {
        int dia = dg1.size()-1 + min(2, (int)d1.size());
        cout << "YES " << dia << "\n";
        cout << (dg1.size()-1) + d1.size() << "\n";
        for (int i=1; i<dg1.size(); i++) {
            dg1[i-1].second--;
            dg1[i].second--;
            cout << dg1[i-1].first << " " << dg1[i].first << "\n";
        }
        if (d1.size()) {
            cout << dg1[0].first << " " << d1.back() << "\n";
            dg1[0].second--;
            d1.pop_back();
        }
        if (d1.size()) {
            cout << dg1.back().first << " " << d1.back() << "\n";
            dg1.back().second--;
            d1.pop_back();
        }
        int p = 0;
        for (int i:d1) {
            while (p<dg1.size() && dg1[p].second == 0) p++;
            assert(p < dg1.size());
            dg1[p].second--;
            cout << dg1[p].first << " " << i << "\n";
        }
    } else {
        cout << "NO\n";
    }

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
