
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n, k;
    cin >> n >> k;
    map<int,int> v;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v[x]++;
    }
    if (v.rbegin()->first+1-v.size()<=k) { //空位个数不超过k，操作完后DIFF=MEX
        cout << "0\n";
        return ;
    }
    // 找到填充k个空位后的mex
    int mex = 0;
    for (int j=0; j<k; mex++) {
        if (v.count(mex) == 0) j++;
    }
    while (v.count(mex)) mex++;
    // 大于mex的数可以拿来填充空位，我们优先出现频次小的数进行填充
    // 堆模拟 优先频次小
    priority_queue<int, vector<int>, greater<>> pq; // 小根堆
    for (auto& [i,j]:v) {
        if (i>mex) pq.emplace(j);
    }
    int ans = pq.size(); // DIFF-MEX，当前答案就是大于mex的不相同的数的个数。
    while (pq.size() && k) {
        auto x = pq.top();
        pq.pop();
        if (k-x>=0) k-=x, ans--;
        else k = 0;
    }
    cout << ans << "\n";
    
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