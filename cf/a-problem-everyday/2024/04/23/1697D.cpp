
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

string s = "abcdsasfasfdxwsfdsafdsaafdxdfsawzefafdsadfsa";

char ask1(int x) {
    cout << "? 1 " << x << endl;
    // return s[x-1];
    string t;
    cin >> t;
    return t[0];
}

int ask2(int l, int r) {
    cout << "? 2 " << l << " " << r << endl;
    // vector<int> c(26);
    // for (int i=l-1; i<r; i++) {
    //     c[s[i]-'a'] = 1;
    // }
    // return accumulate(c.begin(), c.end(), 0);
    int x;
    cin >> x;
    return x;
}

void sol() {
    int n;
    cin >> n;
    // n = s.size();
    string t(1+n, '0');
    vector<int> c(26, 0);
    for (int i=1; i<=n; i++) {
        vector<int> idx(26);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            return c[x] > c[y];
        });
        // cout << c << "\n";
        // cout << idx << endl;
        // int p = 1;
        // for (int j:idx) {
        //     if (c[j] == 0) break;
        //     int r = ask2(c[j], i);
        //     if (p == r) {
        //         t[i] = char(j+'a');
        //         break;
        //     } else {
        //         p = r;
        //     }
        // }
        int l = 0, r = 26;
        while (r>0 && c[idx[r-1]] == 0) r--;
        int e = r;
        while (l<r) {
            int m = l+r>>1;
            if (m+2 == ask2(c[idx[m]], i)) {
                l = m+1;
            } else {
                r = m;
            }
        }
        if (e == r) {
            t[i] = ask1(i);
        } else {
            t[i] = char(idx[r]+'a');
        }
        c[t[i]-'a'] = i;
        // cout << i << ": " << t[i] << endl;
    }
    cout << "! " << t.substr(1) << endl;
    // assert(t.substr(1) == s);
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
