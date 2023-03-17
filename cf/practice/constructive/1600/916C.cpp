#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

int nprime[N];
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
        if (!nprime[i])
            prime.push_back(i);
    }
    // for (int i : prime) {
    //     cout << i << " ";
    // }
}

void sol() {
    get_prime();
    int n, m;
    cin >> n >> m;
    int p = *lower_bound(prime.begin(), prime.end(), n);
    cout << "2 " << p << "\n";
    cout << "1 " << n << " 2\n";
    p -= 2;
    set<pair<int, int>> st;
    st.insert({1, n});
    for (int i = 1; i <= n - 2; i++) {
        if (i == n - 2) {
            cout << i << " " << i + 1 << " " << p << "\n";
            st.insert({i, i + 1});
        } else {
            cout << i << " " << i + 1 << " " << 1 << "\n";
            st.insert({i, i + 1});
            p--;
        }
    }
    m -= n - 1;
    for (int i = 1; i <= n && m > 0; i++) {
        for (int j = i + 1; j <= n && m > 0; j++) {
            if (st.count({i, j}))
                continue;
            cout << i << " " << j << " " << max(3, p + 1) << "\n";
            m--;
        }
    }
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