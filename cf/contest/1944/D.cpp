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

struct SHash {
    // string s[] index from 0 to n-1
    // B[i] = BASE^i
    // s[i...j] = s[0...j] - s[0...i-1]
    // hash s[0...i-1] = H[i] = s[0]*B[i-1]+s[1]*B[i-2]+...+s[i-1]*B[0]
    // hash s[0...j] = H[j+1] = s[0]*B[j]+s[1]*B[j-1]+...+s[j]*B[0]
    // hash s[i...j] = H[j+1] - H[i]*B[j-i+1]
    // hash s[i...j-1] = H[j] - H[i]*B[j-i]
    vector<ull> H, B;
    ull len, base, mod;
    SHash(string& s, ull base = 173, ull mod = 998244353)
        : H(s.size() + 1, 0),
          B(s.size() + 1, 1),
          len(s.size()),
          base(base),
          mod(mod) {
        for (int i = 1; i <= len; i++) {
            H[i] = (H[i - 1] * base % mod + s[i - 1]) % mod;
            B[i] = B[i - 1] * base % mod;
        }
    }
    ull hash(int l, int r) {  // hash of s[l...r-1]
        return (H[r] - H[l] * B[r - l] % mod + mod) % mod;
    };
};

void sol() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = '#'+s+'#';
    auto rs = s;
    reverse(rs.begin(), rs.end());
    SHash h1(s), h2(rs); // s[l,r) == rs[n-r+2, n-l+2)
    SHash h3(s, 191, 1e9+7), h4(rs, 191, 1e9+7);
    vector<vector<int>> p1(n+1, vector<int>(26)), p2(n+1, vector<int>(26));
    for (int i=1; i<=n; i++) {
        int c = s[i]-'a';
        p1[i] = p1[i-1];
        p2[i] = p2[i-1];
        if (i%2) p1[i][c]++;
        else p2[i][c]++;
    }
    // cout << p1 << "\n";
    // cout << p2 << endl;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        ll len = y-x+1;
        ll cnt1, cnt2;
        int c1 = s[y-1]-'a', c2 = s[y]-'a';
        if (y%2) {
            cnt1 = p1[y][c2]-p1[x-1][c2];
            cnt2 = p2[y-1][c1]-p2[x-1][c1];
        } else {
            cnt1 = p2[y][c2]-p2[x-1][c2];
            cnt2 = p1[y-1][c1]-p1[x-1][c1];
        }
        
        // cout << cnt1 << " " << cnt2 << endl;
        if (cnt1+cnt2 == len) {
            if (s[y] == s[y-1]) cout << "0\n";
            else { // 奇偶交替，不存在奇数长度子串贡献
                ll b = len/2; // 对于2,4,6,8,,,等长度子串 存在非回文
                cout << b*(b+1)/2*2 << "\n";
            }
        } else {
            cout << (len-2)*(2+len-1)/2 + ( h1.hash(x, y+1) == h2.hash(n-y+1, n-x+2) && h3.hash(x, y+1) == h4.hash(n-y+1, n-x+2) ? 0 : len) << "\n";
        }
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