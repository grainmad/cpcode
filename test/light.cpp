#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;

int val[8] = {1000, 1030, 1420, 1425, 1480, 1483, 1675, 1680};
int cnt[8] = {16, 12, 10, 31, 2, 4, 2, 8};
int ned[11] = {1490, 1500, 2550, 4220, 4220, 4220, 4220, 3050, 3600, 3600, 3600};
std::vector<int> v[11];

void dfs(int p, int cur) {
	if (p == 12) {
		cout << "solution: " << endl;
		for (int i=0; i<12; i++) {
			cout << ned[i] << ":"<<endl;
			int sum = 0;
			for (int j=0; j<v[i].size(); j++) {
				cout << v[i][j] << " ";
				sum += v[i][j];
			}
			cout << "totol " << sum << " need " << ned[i]-sum << endl;
		}
	}
	for (int i=0; i<8; i++) {
		if (cnt[i] == 0) continue;
		if (cur+val[i]+20 <= ned[p]) {
			cnt[i]--;
			v[p].push_back(val[i]);
			dfs(p+1, 0);
			v[p].pop_back();
			cnt[i]++;
		} 
		// else if (cur+val[i]+900 <= ned[p]) {
		// 	cnt[i]--;
		// 	v[p].push_back(val[i]);
		// 	dfs(p+1, 0);
		// 	v[p].pop_back();
		// 	cnt[i]++;
		// } 
		else {
			cnt[i]--;
			v[p].push_back(val[i]);
			dfs(p, cur+val[i]);
			v[p].pop_back();
			cnt[i]++;
		}
	}
}


int main() {
	std::vector<int> v;
	dfs(0, 0);
	return 0;
}