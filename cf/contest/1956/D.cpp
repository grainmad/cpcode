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


void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i:a) cin >> i;
    int ans=0, ansc=0;
    for (int i=0; i<(1<<n); i++) {
        int mx = 0;
        for (int j=0; j<n; j++) {
            if (!(i>>j&1)) {
                mx += a[j];
                continue;
            }
            int k = j;
            while (i>>k&1) k++;
            mx += (k-j)*(k-j);
            j = k-1;
        }
        if (mx > ans) {
            ans = mx;
            ansc = i;
        }
    }
    vector<pair<int,int>> ansopt;
    auto opt = [&](int l, int r) {
        int mex = 0;
        map<int,int> cnt;
        for (int i=l; i<=r; i++) {
            cnt[a[i]]++;
            while (cnt.count(mex)) mex++;
        }
        for (int i=l; i<=r; i++) {
            a[i] = mex;
        }
        ansopt.emplace_back(l, r);
    };
    
    // function<void(int, int)> dfs = [&](int l, int r) {
    //     for (int i=l; i<r; i++) {
    //         dfs(l, i);
    //     }
    //     opt(l, r);
    //     // cout << a << endl;
    //     if (r != l) dfs(l, r-1);
    // };
    function<void(int, int)> dfs = [&](int l, int r) {
        if (l == r) {
            if (a[l]) opt(l, r);
            return ;
        }
        dfs(l, r-1);
        if(a[r] != r-l) opt(l, r), dfs(l, r-1);
        cout << a << "\n";
    };

    for (int j=0; j<n; j++) {
        if (!(ansc>>j&1)) {
            continue;
        }
        int k = j;
        while (ansc>>k&1) k++;
        // cout << j << " " << k << endl;
        for (int c=j; c<k; c++) {
            if (a[c]) opt(c, c);
        }
        if (a[j] == 0) opt(j, j);
        // cout << a << endl;
        dfs(j, k-1);
        opt(j, k-1);
        j = k-1;
    }
    // cout << a << endl;
    cout << ans << " " << ansopt.size() << "\n";
    for (auto [i,j]:ansopt) {
        cout << i+1 << " " << j+1 << "\n";
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

/*
0 1 2 3 4 B4


x x x x x
0 x x x x [1, 1]
1 1 x x x [1, 2]
0 1 x x x [1, 1]
2 2 2 x x [1, 3]
0 2 2 x x [1, 1]
1 1 2 x x [1, 2]
0 1 2 x x [1, 1]
3 3 3 3 x [1, 4]
0 3 3 3 x [1, 1]
1 1 3 3 x [1, 2]
0 1 3 3 x [1, 1]
2 2 2 3 x [1, 3]
0 2 2 3 x [1, 1]
1 1 2 3 x [1, 2]
0 1 2 3 x [1, 1]
4 4 4 4 4 [1, 5]
*/