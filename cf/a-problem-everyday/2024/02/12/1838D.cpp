
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
	int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> st;
    for (int i=0; i<n; i++) {
        if (s[i] == '(' && i%2) st.insert(i);
        if (s[i] == ')' && i%2 == 0) st.insert(i);
    }
    while (q--) {
        int x;
        cin >> x;
        x--;
        if (s[x] == '(' && x%2 == 1 || s[x] == ')' && x%2 == 0) st.erase(x);
        else st.insert(x);

        if (s[x] == '(') s[x] = ')';
        else s[x] = '(';
        
        if (n%2) {
            cout << "NO\n";
        } else {
			if (st.empty() || *st.begin()%2 == 1 && *st.rbegin()%2 == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
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
