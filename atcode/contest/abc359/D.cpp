#include <bits/stdc++.h>
#define SINGLE_INPUT
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

bool isPalindrome(int x, int k) {
    for (int i=0; i<k/2; i++) {
        if ((x>>i&1) != (x>>(k-i-1)&1)) return false;
    }
    return true;
}

void sol() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int msk = (1<<k);
    vector f(n, vector<int>(1<<k));
    for (int j=0; j<msk; j++) {
        if (isPalindrome(j, k)) continue;
        int ok = 1;
        for (int t=0; t<k; t++) {
            int c = (j>>t&1);
            if ('A'+c != s[k-t-1] && s[k-t-1] != '?') ok = 0;
        }
        if (ok) {
            f[k-1][j]++;
        }
    }
    for (int i=k; i<n; i++) {
        for (int j=0; j<msk; j++) {
            if (isPalindrome(j, k)) continue;
            int ok = 1;
            for (int t=0; t<k; t++) {
                int c = (j>>t&1);
                if ('A'+c != s[i-t] && s[i-t] != '?') ok = 0;
            }
            if (ok) {
                if (!isPalindrome(j>>1, k)) f[i][j] = (f[i][j] + f[i-1][j>>1]) % MOD;
                if (!isPalindrome(j>>1 | (1<<(k-1)), k)) f[i][j] = (f[i][j] + f[i-1][j>>1 | (1<<(k-1))]) % MOD;
            }
        }
    }
    // cout << f << endl;
    int ans = 0;
    for (int i=0; i<msk; i++) {
        ans += f[n-1][i];
        ans %= MOD;
    }
    cout << ans << endl;
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