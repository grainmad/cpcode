#include <iostream>
#include <cmath>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, c, t, a[N], L[N], R[N], B[N], tag[N];

inline void pushdown(int x) {
    if (tag[x] != -1) {
        for (int i = L[x]; i <= R[x]; i++) a[i] = tag[x];
        tag[x] = -1;
    }
}

int solve(int l, int r, int c) {
    int p = B[l],
        q = B[r];
    int res = 0;

    if (p == q) {
        pushdown(p);
        for (int i = l; i <= r; i++) {
            if (a[i] == c) res++;
            a[i] = c;
        }

        return res;
    }

    pushdown(p);
    for (int i = l; i <= R[p]; i++) {
        if (a[i] == c) res++;
        a[i] = c;
    }

    pushdown(q);
    for (int i = L[q]; i <= r; i++) {
        if (a[i] == c) res++;
        a[i] = c;
    }

    for (int i = p + 1; i <= q - 1; i++) {
        if (tag[i] != -1) {
            if (tag[i] == c) res += R[i] - L[i] + 1;
        } else {
            for (int j = L[i]; j <= R[i]; j++) {
                if (a[j] == c) res++;
                a[j] = c;
            }
        }
        tag[i] = c;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    memset(tag, 0xff, sizeof(tag));

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    t = std::sqrt(n);
    
    for (c = 1;; c++) {
        L[c] = (c - 1) * t + 1;
        R[c] = std::min(n, c * t);

        if (c * t >= n) break;
    }

    for (int i = 1; i <= c; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            B[j] = i;
        }
    }

    for (int i = 1, l, r, c; i <= n; i++) {
        cin >> l >> r >> c;
        cout << solve(l, r, c) << endl;
    }

    return 0;
}
