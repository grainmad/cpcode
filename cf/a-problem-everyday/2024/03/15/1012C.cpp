
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 5005
#define MOD 998244353
#define INF 0x3f3f3f3f
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

int a[N];
int f[N][N][2];

void sol() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    memset(f, 0x3f, sizeof(f));
    int sz = (n+1)/2;
    f[0][0][0] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=sz; j++) {
            f[i][j][0] = min(f[i-1][j][0], f[i-1][j][1]+max(a[i]-a[i-1]+1, 0));
            if (j>=1) {
                f[i][j][1] = f[i-1][j-1][0]+max(a[i-1]-a[i]+1, 0);
                if (i>=2) f[i][j][1] = min(f[i][j][1], f[i-2][j-1][1]+max(0, a[i-1]-min(a[i-2], a[i])+1));
            }
            // cout << i << " " << j << ": " << f[i][j][0] << " " << f[i][j][1] << endl;
        }
    }
    int mn = INF;
    vector<int> ans;
    for (int i=sz; i>=1; i--) {
        mn = min(mn, f[n][i][0]);
        mn = min(mn, f[n][i][1]);
        ans.push_back(mn);
    }
    while (ans.size()) {
        cout << ans.back() << " ";
        ans.pop_back();
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
