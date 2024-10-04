#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

random_device seed;
ranlux48 engine(seed());
int random(int l, int r) {
    uniform_int_distribution<> distrib(l, r);
    return distrib(engine);
}
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

template <int x_range = 1000005, int lines_count = 100005, bool bowl = true, class T = long long> //bowl=true 维护下凸壳求最小值
struct DynamicHull {
    struct line{
        T k,b; //斜率,截距
    } p[lines_count+4];
    int tr[x_range+4<<2]; //线段编号
    int cnt = 0;
    DynamicHull() {
        memset(p, 0, sizeof(p));
        memset(tr, 0, sizeof(tr));
        p[0].b = bowl ? 1e18 : -1e18;
    }
    T Y(int id,int x) { //求Y值
        return p[id].k*x+p[id].b;
    }
    void change(int u, int l, int r, int id){ 
        int mid=(l+r)>>1;
        if (bowl) {
            if(Y(id,mid)<Y(tr[u],mid)) std::swap(id,tr[u]);
            if(Y(id,l)<Y(tr[u],l)) change(u<<1,l,mid,id);
            if(Y(id,r)<Y(tr[u],r)) change(u<<1|1,mid+1,r,id);
        } else {
            if(Y(id,mid)>Y(tr[u],mid)) std::swap(id,tr[u]);
            if(Y(id,l)>Y(tr[u],l)) change(u<<1,l,mid,id);
            if(Y(id,r)>Y(tr[u],r)) change(u<<1|1,mid+1,r,id);
        }
        
    }
    
    T query(int u,int l,int r,int x){
        if(l==r) return Y(tr[u],x);
        int mid=(l+r)>>1;
        T t=Y(tr[u],x);
        if(x<=mid) return bowl ? std::min(t,query(u<<1,l,mid,x)) : std::max(t,query(u<<1,l,mid,x));
        else return bowl ? std::min(t,query(u<<1|1,mid+1,r,x)) : std::max(t,query(u<<1|1,mid+1,r,x));
    }

    T query(int x){ //查询
        return query(1, 0, x_range, x);
    }

    void addline(T k, T b) {
        p[++cnt] = {k, b};
        change(1, 0, x_range, cnt);
    }
};

DynamicHull dh;

void sol() {
    int n;
    cin >> n;
    vector<ll> h(n+1), w(n+1);
    for (int i=1; i<=n; i++) {
        cin >> h[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> w[i];
        w[i] += w[i-1];
    }
    vector<ll> f(n+1);
    dh.addline(-2*h[1], f[1]+h[1]*h[1]-w[1]);
    for (int i=2; i<=n; i++) {
        f[i] = h[i]*h[i]+w[i-1] + dh.query(h[i]);
        dh.addline(-2*h[i], f[i]+h[i]*h[i]-w[i]);
    }
    cout << f[n] << "\n";
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