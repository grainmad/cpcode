#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1000005
#define MOD 998244353
using namespace std;

bool nprime[N];
vector<int> prime;

void get_prime() {
    memset(nprime, 0, sizeof(nprime));
    int n = (int)sqrt(N + 0.5);
    for (int i = 2; i < n; i++) {
        if (!nprime[i]) {
            for (int j = i * i; j < N; j += i) {
                nprime[j] = true;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (!nprime[i]) {
            prime.push_back(i);
            //			cout << i << endl;
        }
    }
}

void sol() {
    get_prime();
    int n;
    cin >> n;
}
int main() {
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