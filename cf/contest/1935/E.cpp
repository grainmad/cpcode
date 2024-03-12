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


#define MB 31
 
 
#define LS (id<<1)
#define RS (id<<1|1)
 
int sum[N<<2];
 
void build(int id, int l, int r) {
    sum[id] = 0;
    if (l == r) {
        return ;
    }
    int m = l+r>>1;
    build(LS, l, m);
    build(RS, m+1, r);
}
 
void add(int id, int l, int r, int p, int x) {
    if (l == p && p == r) {
        sum[id] = x;
        return ;
    }
    int m = l+r>>1;
    if (p<=m) add(LS, l, m, p, x);
    else add(RS, m+1, r, p, x);
    sum[id] = sum[LS]|sum[RS];
}
 
int ask(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return sum[id];
    }
    int m = l+r>>1;
    int rt = 0;
    if (ql<=m) {
        rt |= ask(LS, l, m, ql, qr);
    }
    if (m<qr) {
        rt |= ask(RS, m+1, r, ql, qr);
    }
    return rt;
}
 
 
void sol() {
    int n;
    cin >> n;
    build(1, 1, n);
    vector<vector<int>> bc(n+1, vector<int>(MB));
    for (int i=1; i<=n; i++) {
        int l, r;
        cin >> l >> r;
        int u = l^r, c = 0;
        for (int i=u; i; i>>=1) c++; //c位及之上l与r一样，
        int w = (1<<c)-1; 
        int h = r - (w&r); // 低c位置为0
        add(1, 1, n, i, h);
        r &= w;
        bc[i] = bc[i-1];
        for (int j=0; j<MB; j++) {
            if (r>>j&1) bc[i][j]++;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = ask(1, 1, n, l, r);
        for (int i=0; i<MB; i++) {
            int cnt = bc[r][i]-bc[l-1][i] + (ans>>i&1);
            if (cnt == 1) {
                ans |= 1<<i;
            } else if (cnt > 1) {
                ans |= (2<<i)-1;
            }
        }
        cout << ans << " ";
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