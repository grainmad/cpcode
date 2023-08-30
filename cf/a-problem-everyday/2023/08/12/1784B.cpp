
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int m;
    cin >> m;
    map<string, vector<int>> mp;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        // cout << s << endl;
        mp[s].push_back(i);
    }
    vector<string> ans;
    // 三个全相同
    while (mp["www"].size() && mp["iii"].size() && mp["nnn"].size()) {
        ans.emplace_back(to_string(mp["www"].back()) + " w " +
                         to_string(mp["iii"].back()) + " i");
        ans.emplace_back(to_string(mp["www"].back()) + " w " +
                         to_string(mp["nnn"].back()) + " n");
        ans.emplace_back(to_string(mp["iii"].back()) + " i " +
                         to_string(mp["nnn"].back()) + " n");
        mp["www"].pop_back();
        mp["iii"].pop_back();
        mp["nnn"].pop_back();
    }
    // 含一个全相同 两次交换恢复3个
    auto case1 = [&](const string& a, const string& b, const string& c) {
        while (mp[a].size() && mp[b].size() && mp[c].size()) {
            ans.emplace_back(to_string(mp[a].back()) + " " + a[1] + " " +
                             to_string(mp[b].back()) + " " + b[1]);
            ans.emplace_back(to_string(mp[a].back()) + " " + a[1] + " " +
                             to_string(mp[c].back()) + " " + c[1]);
            mp[a].pop_back();
            mp[b].pop_back();
            mp[c].pop_back();
        }
    };
    case1("www", "iin", "inn");
    case1("iii", "nww", "nnw");
    case1("nnn", "iiw", "iww");
    // 不含全相同 两次交换恢复3个
    auto case2 = [&](const string& a, const string& b, const string& c) {
        while (mp[a].size() && mp[b].size() && mp[c].size()) {
            ans.emplace_back(to_string(mp[a].back()) + " w " +
                             to_string(mp[b].back()) + " " + b[1]);
            ans.emplace_back(to_string(mp[b].back()) + " w " +
                             to_string(mp[c].back()) + " " + c[1]);
            mp[a].pop_back();
            mp[b].pop_back();
            mp[c].pop_back();
        }
    };
    case2("nww", "iiw", "inn");
    case2("iww", "nnw", "iin");

    // 一次交换恢复两个
    auto case3 = [&](const string& a, const string& b) {
        while (mp[a].size() && mp[b].size()) {
            ans.emplace_back(to_string(mp[a].back()) + " " + a[1] + " " +
                             to_string(mp[b].back()) + " " + b[1]);
            mp[a].pop_back();
            mp[b].pop_back();
        }
    };
    case3("iww", "inn");
    case3("nww", "iin");
    case3("iiw", "nnw");

    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << "\n";
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
