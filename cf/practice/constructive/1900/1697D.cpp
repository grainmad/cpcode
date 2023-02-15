#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1005
#define MOD 998244353
using namespace std;

string test = "#abcdaxcreedd";

string q1(int p) {
    return string(1, test[p]);
}

int q2(int l, int r) {
    set<char> st;
    for (int i = l; i <= r; i++) {
        st.insert(test[i]);
    }
    return st.size();
}

void sol() {
    int n;
    // n = test.size();
    cin >> n;
    vector<int> fc;
    int mx = 0;
    string s = "#";
    for (int i = 1; i <= n; i++) {
        cout << "? 2 1 " << i << endl;
        int x;
        cin >> x;
        // x = q2(1, i);
        if (x > mx) {
            cout << "? 1 " << i << endl;
            string y;
            cin >> y;
            // y = q1(i);
            s.push_back(y[0]);
            fc.push_back(i);
            mx = x;
        } else {
            int l = 0, r = fc.size();
            while (l < r) {
                int m = l + r >> 1;
                cout << "? 2 " << fc[m] << " " << i << endl;
                int y;
                cin >> y;
                // y = q2(fc[m], i);
                if (y > mx - m) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            s.push_back(s[fc[r - 1]]);
            fc.erase(fc.begin() + r - 1);
            fc.push_back(i);
        }
    }
    cout << "! " << s.substr(1) << "\n";
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