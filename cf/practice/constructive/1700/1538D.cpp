#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

bool nprime[N];
vector<int> prime;

void get_prime() {
    int sz = sqrt(N);
    for (int i = 2; i <= sz; i++) {
        if (!nprime[i])
            for (int j = i * i; j < N; j += i) {
                nprime[j] = 1;
            }
    }
    for (int i = 2; i < N; i++) {
        if (!nprime[i]) {
            prime.push_back(i);
            // cout << i << endl;
        }
    }
    // cout << "all: " << prime.size() << endl;
}

int sp(ll u) {
    if (u == 0)
        return 0;
    int rt = 0;
    for (ll i : prime) {
        if (i * i > u)
            break;
        while (u % i == 0) {
            u /= i;
            rt++;
        }
    }
    if (u != 1)
        rt++;
    return rt;
}

void sol() {
    ll a, b, k;
    cin >> a >> b >> k;
    if (k == 1) {
        if (a != b && (a % b == 0 || b % a == 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        if (sp(a) + sp(b) >= k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
int main() {
    get_prime();
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