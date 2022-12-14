#include <bits/stdc++.h>
#define SINGLE_INPUT
#define N 500005
using namespace std;

class Solution {
public:
    using ll = long long;
    bool ok(ll x, int k) {
        ll y = 0, p = x;
        while (x) {
            y = y*k + x%k;
            x /= k;
        }
        return p == y;
    }
    long long kMirror(int k, int n) {
        int cnt = 0;
        ll ans = 0;
        for (ll i=1; ;i*=10) {
            for (ll j=i; j<i*10; j++) {
                ll x = j, y = j/10;
                while (y) {
                    x = x*10+y%10;
                    y/=10;
                }
                if (ok(x, k)) {
                    ans += x;
                    if (++cnt == n) return ans;
                }
            }
            for (ll j=i; j<i*10; j++) {
                ll x = j, y = j;
                while (y) {
                    x = x*10+y%10;
                    y/=10;
                }
                if (ok(x, k)) {
                    ans += x;
                    if (++cnt == n) return ans;
                }
            }
        }
        return -1;
    }
};




void sol() {
    Solution s;
    cout << "vector<long long> table[10] = {\n{},\n{},\n";
    for (int i=2; i<=9; i++) {
        cout << "{";
        for (int j=1; j<=30; j++) {
            cout << s.kMirror(i, j) << "LL" <<","[j==30];
        }
        cout << "}"<< ","[i==9] << "\n";
    }
    cout << "};\n";
    
}

int main() {
    sol();
    return 0;
}