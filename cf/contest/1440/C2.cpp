#include <bits/stdc++.h>
#define ll long long
#define N 105
using namespace std;

string g[N];
vector<vector<int>> stp;

int get1(int x, int y) {
	int rt = 0;
	for(int i=x; i<x+2; i++) {
		for (int j=y; j<y+2; j++) {
			rt += g[i][j]-'0';
		}
	}
	// cout << "rt " << rt << endl;
	return rt;
}

void rest(int x, int y, std::vector<int>& v) {
	if (g[x][y] == '1') g[x][y] = '0';
	else g[x][y] = '1';
	v.push_back(x);
	v.push_back(y);
}

void ch(int i, int l, int r, vector<pair<int,int>> idx) {
	std::vector<int> v;
	for (int j=l; j<=r; j++) {
		int rj = (j+i+4)%4;
		int rx = idx[rj].first, ry= idx[rj].second;
		rest(rx, ry, v);
	}
	stp.push_back(v);
}


void case1(int x, int y) {
	vector<pair<int,int>> idx = {{x, y}, {x, y+1}, {x+1, y+1}, {x+1, y}};
	for (int i=0; i<4; i++) {
		int sx = idx[i].first;
		int sy = idx[i].second;
		if (g[sx][sy] == '1') {
			ch(i, 0, 2, idx);
			ch(i, -2, 0, idx);
			ch(i, -1, 1, idx);
			break;
		}
	}
}

void case21(int x, int y) {
	vector<pair<int,int>> idx = {{x, y}, {x, y+1}, {x+1, y+1}, {x+1, y}};
	for (int i=0; i<4; i++) {
		int sx = idx[i].first;
		int sy = idx[i].second;
		if (g[sx][sy] == '1') {
			ch(i, -1, 1, idx);
			ch(i, 1, 3, idx);
			break;
		}
	}
}

void case22(int x, int y) {
	vector<pair<int,int>> idx = {{x, y}, {x, y+1}, {x+1, y+1}, {x+1, y}};
	for (int i=0; i<4; i++) {
		int ux = idx[i].first;
		int uy = idx[i].second;
		int nx = idx[(i+1)%4].first;
		int ny = idx[(i+1)%4].second;
		if (g[ux][uy] == '0' && g[nx][ny] == '1') {
			ch(i, -2, 0, idx);
			ch(i, -1, 1, idx);
			break;
		}
	}
}

void case2(int x, int y) {
	if (g[x][y] == g[x+1][y+1]) {
		case21(x, y);
	} else case22(x, y);
}

void case3(int x, int y) {
	vector<pair<int,int>> idx = {{x, y}, {x, y+1}, {x+1, y+1}, {x+1, y}};
	for (int i=0; i<4; i++) {
		int sx = idx[i].first;
		int sy = idx[i].second;
		if (g[sx][sy] == '0') {
			ch(i, 1, 3, idx);
			break;
		}
	}
}

void case4(int x, int y) {
	vector<pair<int,int>> idx = {{x, y}, {x, y+1}, {x+1, y+1}, {x+1, y}};
	ch(0, 1, 3, idx);
	case1(x, y);
}

void blockr(int x, int y) {
	if (g[x][y] == '0' && g[x][y+1] == '0') return;
	std::vector<int> v;
	if (g[x][y] == '1' && g[x][y+1] == '1') {
		rest(x, y, v);
		rest(x, y+1, v);
		rest(x-1, y, v);
	} else if (g[x][y] == '1' && g[x][y+1] == '0') {
		rest(x, y, v);
		rest(x-1, y, v);
		rest(x-1, y+1, v);
	} else if (g[x][y] == '0' && g[x][y+1] == '1') {
		rest(x, y+1, v);
		rest(x-1, y, v);
		rest(x-1, y+1, v);
	}
	stp.push_back(v);
}

void blockc(int x, int y) {
	if (g[x][y] == '0' && g[x+1][y] == '0') return;
	std::vector<int> v;
	if (g[x][y] == '1' && g[x+1][y] == '1') {
		rest(x, y, v);
		rest(x+1, y, v);
		rest(x, y-1, v);
	} else if (g[x][y] == '1' && g[x+1][y] == '0') {
		rest(x, y, v);
		rest(x, y-1, v);
		rest(x+1, y-1, v);
	} else if (g[x][y] == '0' && g[x+1][y] == '1') {
		rest(x+1, y, v);
		rest(x, y-1, v);
		rest(x+1, y-1, v);
	}
	stp.push_back(v);	
}

void set0(int x, int y) {
	int c = get1(x, y);
	// cout << "x=" << x << " y=" << y << " c=" << c << endl;
	if (c == 1) case1(x, y);
	if (c == 2) case2(x, y);
	if (c == 3) case3(x, y);
	if (c == 4) case4(x, y);
}

void print(int n) {
	for (int k=0; k<n; k++) {
		cout << g[k] << endl;
	}
	cout << endl;
}

void sol() {
	stp.clear();
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> g[i];
	}
	if (n%2 && m%2) {
		for (int i=0; i<n-1; i+=2) {
			blockc(i, m-1);
		}
		blockc(n-2, m-1);
		m--;
		for (int i=0; i<m; i+=2) {
			blockr(n-1, i);
		}
		n--;
	} else if (n%2) {
		for (int i=0; i<m; i+=2) {
			blockr(n-1, i);
		}
		n--;
	} else if (m%2) {
		for (int i=0; i<n; i+=2) {
			blockc(i, m-1);
		}
		m--;
	}
	for (int i=0; i<n; i+=2) {
		for (int j=0; j<m; j+=2) {
			set0(i, j);
		}
	}
	cout << stp.size() << endl;
	for (auto& i:stp) {
		for (int j:i) cout << j+1 << " ";
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}