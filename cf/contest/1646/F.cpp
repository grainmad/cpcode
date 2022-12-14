#include <bits/stdc++.h>
#define ll long long
#define N 105
using namespace std;

int a[N];
int n;
vector<int> extras[N];//extras[i] i行多余的数
int cnt[N][N];
vector<vector<int>> stp;
void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int x;
			cin >> x; x--;
			cnt[i][x]++;
			if (cnt[i][x]>1) extras[i].push_back(x);
		}
	}
	while (true) {
		//寻找第一个有多余数的行
		std::vector<int> v(n);
		int e = -1;
		for (int i=0; i<n; i++) {
			if (extras[i].size() != 0) {
				e = i;
				break;
			}
		}
		if (e == -1) break;
		int card = -1;
		for (int i=e; i<e+n; i++) {
			int ri = i%n;
			if (extras[ri].size()) {
				card = extras[ri].back();
				extras[ri].pop_back();
			}
			v[ri] = card;
		}
		stp.push_back(v);
		for (int i=0; i<n; i++) {
			int nexti = (i+1)%n;
			cnt[i][v[i]]--;
			cnt[nexti][v[i]]++;
		} 
		for (int i=0; i<n; i++) {
			int nexti = (i+1)%n;
			if (cnt[nexti][v[i]] > 1) extras[nexti].push_back(v[i]);
		}
	}
	for (int i=0; i<n; i++) {
		std::vector<int> v(n);
		for (int j=0; j<n; j++) {
			v[j] = (j-i+n)%n;
		}
		for (int j=0; j<i; j++) {
			stp.push_back(v);
		}
	}
	cout << stp.size() << "\n";
	for (auto i:stp) {
		for (int j:i) {
			cout << j+1 << " " ;
		} cout << "\n";
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	sol();
	// }
	sol();
}