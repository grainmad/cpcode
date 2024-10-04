#include <bits/stdc++.h>

using ll = long long;
#define N 100005
#define ls u<<1
#define rs u<<1|1
struct line{
    ll k,b; //斜率,截距
} p[N*2];
int tr[N*4]; //线段编号
int cnt = 0;
ll Y(int id,int x){ //求Y值
    return p[id].k*x+p[id].b;
}
void change(int u,int l,int r,int id){ //修改
    int mid=(l+r)>>1;
    if(Y(id,mid)>Y(tr[u],mid)) std::swap(id,tr[u]);
    if(Y(id,l)>Y(tr[u],l)) change(ls,l,mid,id);
    if(Y(id,r)>Y(tr[u],r)) change(rs,mid+1,r,id);
}
ll query(int u,int l,int r,int x){ //查询
    if(l==r) return Y(tr[u],x);
    int mid=(l+r)>>1;
    ll t=Y(tr[u],x);
    if(x<=mid) return std::max(t,query(ls,l,mid,x));
    else return std::max(t,query(rs,mid+1,r,x));
}
void addline(ll k, ll b) {
    p[++cnt] = {k, b};
    change(1, 0, N, cnt);
}

template <bool bowl = true, int range = 100005, class T = long long> //bowl=true 维护下凸壳求最小值
struct DynamicHull {
    struct line{
        T k,b; //斜率,截距
    } p[range+4<<2];
    int tr[range+4<<2]; //线段编号
    int cnt = 0;
    DynamicHull() {
        memset(p, 0, sizeof(p));
        memset(tr, 0, sizeof(tr));
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
        return query(1, 0, range, x);
    }

    void addline(T k, T b) {
        p[++cnt] = {k, b};
        change(1, 0, range, cnt);
    }
};