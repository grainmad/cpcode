
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

vector<int> ans = {0,1,2,1,2,3,4,3,2};

int ask(int x) {
    cout << "? " << x << endl;
    int v;
    cin >> v;
	// v = ans[x];
    return v;
}


void sol() {
	int n;
    cin >> n;
    // n = 8;
    int v = ask(1)-ask(1+n/2);
	if (v%2) {
        cout << "! -1\n";
        return ;
    }
	int l = 1, r = n/2;
    while (l<r) {
		int m = l+r>>1;
        int c = ask(m)-ask(m+n/2);
        if (c == 0) {
            cout << "! " << m << endl;
			return;
        } else if (v<0 && c<0 || v>0 && c>0) {
            l = m+1;
        } else {
            r = m;
        }
    }
	cout << "! " << n/2 << endl;
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
