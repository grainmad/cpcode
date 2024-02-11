
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
	int n, k;
    cin >> n >> k;
    vector<int> m(n), c(k+1);
    for (auto& i:m) cin >> i;
    for (int i=1; i<=k; i++) {
        cin >> c[i];
    }
    int ans = 0;
    sort(m.rbegin(), m.rend());
	vector<vector<int>> g(n+1);
    for (int i:m) {
        int l = 0, r = ans;
        while (l<r) {
            int mid = l+r>>1;
            if (g[mid].size() < c[i]) r = mid;
			else l = mid+1;
        }
        g[r].push_back(i);
        ans = max(ans, r+1);
    }
    cout << ans << "\n";
    for (int i=0; i<ans; i++) {
        cout << g[i].size();
        for (auto j:g[i]) {
            cout << " " << j;
        }
        cout << "\n";
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
