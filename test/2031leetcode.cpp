#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int cnt = 0;
set<ll> v[10];

bool isok() {
	for (int i=2; i<10; i++) {
		if (v[i].size() < 30) return false;
	}
	return true;
}

bool to_k(ll n, int k) {
	std::vector<ll> vec;
	while (n) {
		vec.push_back(n%k);
		n/=k;
	}
	int l = 0, r = vec.size()-1;
	while (l < r) {
		if (vec[l] != vec[r]) return false;
		l++; r--;
	}
	return true;
}



int main() {
	vector<int> res;
    for (int len=0; len<10; len++) {
        for (int s=pow(10,len), e=pow(10,len+1); s<e; s++) {
            string a = to_string(s), b(a.rbegin(), a.rend());
            ll num = stoll(a+b.substr(1));
            cout << num << endl;
        }
        for (int s=pow(10,len), e=pow(10,len+1); s<e; s++) {
            string a = to_string(s), b(a.rbegin(), a.rend());
            ll num = stoll(a+b);
            cout << num << endl;
        }
    }
    return 0;
}
