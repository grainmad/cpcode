
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
	int n, m;
    cin >> n >> m;
    int mx = 0, mn = 0;
    auto get_min = [](string& s) {
        int sz = s.size();
        int cnt = 0, c1 = 0;
        for (int i=0, j; i<sz; i = j) {
            if (s[i] == '0') {
                j = i+1;
            }
            else {
                j = i;
            	while (j<sz && s[j] == s[i]) j++;
				cnt += (j-i)/2;
            	c1 += j-i;
            }
        }
        return c1-min(cnt, sz/4);
    };
    auto get_max = [](string& s) {
        
		int sz = s.size();
        int cnt = 0, cur = 1, c1 = count(s.begin(), s.end(), '1');
        for (int i=1; i<sz; i++) {
            if (s[i-1] == s[i] && s[i] == '1') {
                cnt += cur/2;
                cur = 1;
            } else {
                cur++;
            }
        }
    	cnt += cur/2;
        return c1 - max(sz/4-cnt, 0);
    };
    string g;
    for (int _x = 0; _x < n; _x++) {
        cin >> g;
		mx += get_max(g);
        mn += get_min(g);		
    }
    cout << mn << " " << mx << endl;


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
