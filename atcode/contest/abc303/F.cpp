#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, h;
    cin >> n >> h;
    vector<pair<ll, ll>> a(n);
    for (auto& [x, y] : a) {
        cin >> x >> y;
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    ll l = 0, r = 1e10;
    while (l < r) {
        ll m = l + r >> 1;
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            return a[x].second * min(m, a[x].first) >
                   a[y].second * min(m, a[y].first);
        });
        ll cur = 0;
        for (int i = 0; i < min(n, m); i++) {
            cur += a[idx[i]].second * min(m, a[idx[i]].first);
            if (cur >= h) {
                break;
            }
        }
        if (cur >= h) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << "\n";
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

#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define N 1001000
int n, h, dam[N];

struct Spell {
    int t, d;
} spe[N];
bool cmp(Spell a, Spell b) {
    return a.t < b.t;
}

void read(int& x) {
    char c;
    do {
        c = getchar();
    } while (c > '9' || c < '0');
    for (x = 0; '0' <= c && c <= '9'; c = getchar())
        x = x * 10 + (c - '0');
}
void pri(int x) {
    if (x > 9)
        pri(x / 10);
    putchar(x % 10 + '0');
}

bool judge(int x) {
    int sum = 0, round_dam = 0, pos;
    for (int i = n; i >= 1; --i) {
        if (x > spe[i].t) {
            if (round_dam * x <= dam[i])
                pos = x;
            else if (round_dam * (spe[i].t + 1) >= dam[i])
                pos = spe[i].t;
            else
                pos = dam[i] / round_dam;

            sum += round_dam * (pos + 1 + x) * (x - pos) / 2 +
                   dam[i] * (pos - spe[i].t);
            x = min(x, spe[i].t);
        }
        round_dam = max(round_dam, spe[i].d);
    }
    return sum + (1 + x) * x / 2 * round_dam >= h;
}
int binary_search_min(int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (judge(mid) == true)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}
signed main() {
    read(n);
    read(h);
    for (int i = 1; i <= n; ++i)
        read(spe[i].t), read(spe[i].d);

    sort(spe + 1, spe + n + 1, cmp);

    for (int i = 1; i <= n; ++i)
        dam[i] = max(dam[i - 1], spe[i].t * spe[i].d);

    pri(binary_search_min(1, h));

    return 0;
}