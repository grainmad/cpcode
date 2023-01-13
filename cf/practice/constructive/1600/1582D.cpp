#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

int a[N];
// int ans[N];
void sol()
{
    // map<int,vector<int>> st;
    // int n;
    // cin >> n;
    // for (int i=0; i<n; i++) {
    // 	cin >> a[i];
    // 	st[abs(a[i])].push_back(i);
    // }
    // if (n%2) {
    // 	vector<int> v;
    // 	int p1, p2;
    // 	for (auto& i:st) {
    // 		auto & t = i.second;
    // 		if (t.size()%2) {
    // 			v.push_back(t.back());
    // 			t.pop_back();
    // 		}
    // 		for (int i=0; i<t.size(); i+=2) {
    // 			ans[t[i]] = 1;
    // 			ans[t[i+1]] = (a[t[i]] == a[t[i+1]] ? -1 : 1);
    // 			p1 = t[i];
    // 			p2 = t[i+1];
    // 		}
    // 	}
    // 	int sz = v.size();
    // 	for (int i=0; i<sz-3; i+=2) {
    // 		ans[v[i]] = a[v[i+1]];
    // 		ans[v[i+1]] = -a[v[i]];
    // 	}
    // 	if (sz==1) {
    // 		v.push_back(p1);
    // 		v.push_back(p2);
    // 		sz = 3;
    // 	}
    // 	// for (int i:v) cout << i << "-";cout << endl;
    // 	int x = v[sz-3], y = v[sz-2], z = v[sz-1];
    // 	if (a[x] + a[y] == 0) swap(y, z);
    // 	if (a[x] + a[y] == 0) swap(x, z);
    // 	ans[x] = a[z];
    // 	ans[y] = a[z];
    // 	ans[z] = -a[x]-a[y];
    // 	for (int i=0; i<n; i++) {
    // 		cout << ans[i] << " ";
    // 	}
    // } else {
    // 	for (int i=0; i<n; i+=2) {
    // 		cout << -a[i+1] << " " << a[i] << " ";
    // 	}
    // }
    // cout << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n % 2)
    {
        for (int i = 0; i < n - 3; i += 2)
        {
            cout << -a[i + 1] << " " << a[i] << " ";
        }
        int x = a[n - 3], y = a[n - 2], z = a[n - 1];
        if (x + y)
        {
            cout << z << " " << z << " " << -x - y << " ";
        }
        else if (x + z)
        {
            cout << y << " " << -x - z << " " << y << " ";
        }
        else
        {
            cout << -y - z << " " << x << " " << x << " ";
        }
    }
    else
    {
        for (int i = 0; i < n; i += 2)
        {
            cout << -a[i + 1] << " " << a[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    while (t--)
    {
        sol();
    }
#else
    sol();
#endif
    return 0;
}