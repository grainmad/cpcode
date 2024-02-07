 #include <bits/stdc++.h>
 // #define SINGLE_INPUT
 #define ull unsigned long long
 #define ll long long
 #define N 500005
 #define MOD 998244353
 using namespace std;
 
 template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
 }
 template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
 }
 template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
 }
 
 
 void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i:a) cin >> i;
    vector<ll> st;
    vector<ll> f(n);
    vector<ll> p(n+1); // p[i] 前i个f的和
    ll stf = 0; // 栈中f值的和
    for (int i=0; i<n; i++) {
        while (st.size() && a[st.back()] > a[i]) {
            stf -= f[st.back()];
            stf %= MOD;
            st.pop_back();
        }
        int j = st.size()?st.back()+1:0;
        f[i] = (stf+p[i]-p[j]+st.empty())%MOD;
        p[i+1] = (p[i]+f[i])%MOD;
        stf += f[i]; stf %= MOD;
        st.push_back(i);
    }
    cout << (stf+MOD)%MOD << "\n";
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