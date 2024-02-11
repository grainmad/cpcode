
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
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

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dl(1, 0), dr(1,0), wl(1,0), wr(1,0);
    string l, r;
    for (char i:s) {
        if (i == 'L') {
			if (!l.empty()) {
            	r.push_back(l.back());
            	l.pop_back();
            	dl.pop_back();
            	wl.pop_back();
            	if (r.back() == ')') {
                	wr.push_back(wr.back()+1);
                	dr.push_back(max(dr.back(), wr.back()));
            	} else if (r.back() == '(') {
                	wr.push_back(wr.back()-1);
                	if (wr.back() < 0) dr.push_back(INF);
                	else dr.push_back(max(dr.back(), wr.back()));
            	} else {
                	wr.push_back(wr.back());
                	dr.push_back(dr.back());               
            	}
            }
        } 
        else if (i == 'R') {
        	if (r.empty()) {
                l.push_back(' ');
                dl.push_back(dl.back());
                wl.push_back(wl.back());
            } else {
                l.push_back(r.back());
                r.pop_back();
                dr.pop_back();
                wr.pop_back();
                if (l.back() == '(') {
                    wl.push_back(wl.back()+1);
                    dl.push_back(max(dl.back(), wl.back()));
                } else if (l.back() == ')') {
                    wl.push_back(wl.back()-1);
                    if (wl.back() < 0) dl.push_back(INF);
                    else dl.push_back(max(dl.back(), wl.back()));
                } else {
                    wl.push_back(wl.back());
                    dl.push_back(dl.back());               
                }   
            } 
        }
        else if (i == '(') {
			if (r.size()) {
            	wr.pop_back();
        		dr.pop_back();
                r.pop_back();    
            }
            r.push_back('(');
            wr.push_back(wr.back()-1);
            if (wr.back() < 0) dr.push_back(INF);
            else dr.push_back(max(dr.back(), wr.back()));
        }
        else if (i == ')') {
			if (r.size()) {
            	wr.pop_back();
        		dr.pop_back();
                r.pop_back();    
            }
            r.push_back(')');
            wr.push_back(wr.back()+1);
            dr.push_back(max(dr.back(), wr.back()));
        }
		else {
			if (r.size()) {
            	wr.pop_back();
        		dr.pop_back();
                r.pop_back();    
            }
            r.push_back(i);
            wr.push_back(wr.back());
            dr.push_back(dr.back());
        }
        if (wl.back() != wr.back()) {
            cout << "-1 ";
        } else {
            int t = max({dr.back(), dl.back(), wl.back()});
        	cout << (t == INF?-1:t) << " ";
        }
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
