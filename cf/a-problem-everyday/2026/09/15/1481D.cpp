
#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& i:g) {
        cin >> i;
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (g[i][j] == g[j][i]) {
                cout << "YES\n";
                for (int t=0; t<=m; t++) {
                    if (t%2) {
                        cout << i+1 << " ";
                    } else {
                        cout << j+1 << " ";
                    }
                }
                cout << "\n";
                return; 
            }
        }
    }
    if (m%2) {
        cout << "YES\n";
        for (int i=0; i<=m; i++) {
            if (i%2) {
                cout << "1 ";
            } else {
                cout << "2 ";
            }
        }
        cout << "\n";
    } else if (n > 2) {
        cout << "YES\n";
        for (int i=0; i<n; i++) {
            vector<int> pia, pib, nia, nib;
            for (int pi=0; pi<n; pi++) {
                if (g[pi][i] == 'a') pia.push_back(pi);
                if (g[pi][i] == 'b') pib.push_back(pi);
            }
            for (int ni=0; ni<n; ni++) {
                if (g[i][ni] == 'a') nia.push_back(ni);
                if (g[i][ni] == 'b') nib.push_back(ni);
            }
            if (pia.size() && nia.size()) {
                int pi = pia[0], ni = nia[0];
                for (int j=0; j<m/2; j++) {
                    if (j%2 == m/2%2) cout << i+1 << " ";
                    else cout << pi+1 << " ";
                }
                cout << i+1 << " ";
                for (int j=m/2-1; j>=0; j--) {
                    if (j%2 == m/2%2) cout << i+1 << " ";
                    else cout << ni+1 << " ";
                }
                cout << "\n";
                return ;
            }
            if (pib.size() && nib.size()) {
                int pi = pib[0], ni = nib[0];
                for (int j=0; j<m/2; j++) {
                    if (j%2 == m/2%2) cout << i+1 << " ";
                    else cout << pi+1 << " ";
                }
                cout << i+1 << " ";
                for (int j=m/2-1; j>=0; j--) {
                    if (j%2 == m/2%2) cout << i+1 << " ";
                    else cout << ni+1 << " ";
                }
                cout << "\n";
                return ;
            }
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
