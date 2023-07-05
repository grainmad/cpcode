
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
	int r=0, c=0, ok = 1;
    map<pair<int,int>, int> cnt;
    for (int i=0; i<4; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) r++;
		if (y1 == y2) c++;
        if (x1 == x2 && y1 == y2) ok = 0;
        cnt[{x1,y1}]++;
        cnt[{x2,y2}]++;
    } 
    if (!ok ||r != 2 || c != 2) {
        cout << "NO\n";
        return ;
    }
    for (auto [i,j]:cnt) {
        if (j != 2) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
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
