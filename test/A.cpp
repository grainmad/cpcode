#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long MOD = 1e9+7;
    long long dp[1005][1005];//dp[i][j] 区间从i到j有多少种
    int numberOfWays(int numPeople) {
        memset(dp, 0, sizeof(dp));
        return dfs(1, numPeople);
    }
    long long dfs(int l, int r) {
        if (dp[l][r] != 0) return dp[l][r];
        if (l+1==r) return dp[l][r] = 1;
        for (int i=l+1; i+3<r; i+=2) {
            dp[l][r] = (dp[l][r] + dfs(l, i)*dfs(i+2, r-1)%MOD)%MOD;
        }
        dp[l][r] = (dp[l][r] + dfs(l, r-2))%MOD;
        dp[l][r] = (dp[l][r] + dfs(l+1, r-1))%MOD;
        // cout << l << " " << r << " " << dp[l][r] << endl;
        return dp[l][r];
    }
};
int main() {
    Solution t;
    t.numberOfWays(1000);
    cout << t.dp[1][2];
}