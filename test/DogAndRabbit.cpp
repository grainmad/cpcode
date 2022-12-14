#include <bits/stdc++.h>
#define ll long long
using namespace std;


/*
  1 4 7
0 2 5 8 10
  3 6 9
*/

//isFa[a][b] a's fa is b ?
bool isFa[11][11] = {
	{0,1,1,1,0,0,0,0,0,0,0},//0
	{0,0,0,0,1,1,0,0,0,0,0},//1
	{0,0,0,0,1,1,1,0,0,0,0},//2
	{0,0,0,0,0,1,1,0,0,0,0},//3
	{0,0,0,0,0,0,0,1,1,0,0},//4
	{0,0,0,0,0,0,0,1,1,1,0},//5
	{0,0,0,0,0,0,0,0,1,1,0},//6
	{0,0,0,0,0,0,0,0,0,0,1},//7
	{0,0,0,0,0,0,0,0,0,0,1},//8
	{0,0,0,0,0,0,0,0,0,0,1},//9
	{0,0,0,0,0,0,0,0,0,0,0}//10
};

vector<int> g[11] = {
	{1,2,3},//0
	{0,2,4,5},//1
	{0,1,3,5},//2
	{0,2,5,6},//3
	{1,5,7},//4
	{1,2,3,4,6,7,8,9},//5
	{3,5,9},//6
	{4,5,8,10},//7
	{5,7,9,10},//8
	{5,6,8,10},//9
	{7,8,9}//10
};

int dp[200000][505];//dp[i][j] 当前场面状态为i，当前j轮的结果： 1赢，-1输， 2平局
bool vis[200000];


int encode(vector<int>& bit) {
	int rt = 0;
	for (int i:bit) {
		rt *=3;
		rt += i;
	}
	return rt;
}

vector<int> decode(int s) {
	std::vector<int> bit(11);
	for (int i=0; i<11; i++) {
		bit[10-i] = s%3;
		s /= 3;
	}
	return bit;
}

//打印当前状态
void statusPrint(int s) {
	char mp[3] = {'.', 'D', 'R'};
	auto bit = decode(s);
	printf("  %c %c %c  \n", mp[bit[1]], mp[bit[4]], mp[bit[7]]);
	printf("%c %c %c %c %c\n", mp[bit[0]], mp[bit[2]], mp[bit[5]], mp[bit[8]], mp[bit[10]]);
	printf("  %c %c %c  \n\n", mp[bit[3]], mp[bit[6]], mp[bit[9]]);
}

//打印当前状态
void statusPrint(vector<int>& bit) {
	char mp[3] = {'.', 'D', 'R'};
	printf("  %c %c %c  \n", mp[bit[1]], mp[bit[4]], mp[bit[7]]);
	printf("%c %c %c %c %c\n", mp[bit[0]], mp[bit[2]], mp[bit[5]], mp[bit[8]], mp[bit[10]]);
	printf("  %c %c %c  \n\n", mp[bit[3]], mp[bit[6]], mp[bit[9]]);
}

//当前状态下够可转移的状态
vector<int> dogMove(int s) {
	std::vector<int> rt;
	auto bit = decode(s);
	for (int i=0; i<11; i++) {
		if (bit[i] == 1) {
			for (int j:g[i]) {
				if (isFa[j][i] || bit[j] != 0) continue;
				swap(bit[i], bit[j]);
				rt.push_back(encode(bit));
				swap(bit[i], bit[j]);
			}
		}
	}
	return rt;
}
//当前状态下够可转移的状态
vector<int> dogMove(vector<int>& bit) {
	std::vector<int> rt;
	for (int i=0; i<11; i++) {
		if (bit[i] == 1) {
			for (int j:g[i]) {
				if (isFa[j][i] || bit[j] != 0) continue;
				swap(bit[i], bit[j]);
				rt.push_back(encode(bit));
				swap(bit[i], bit[j]);
			}
		}
	}
	return rt;
}

//当前状态下够可转移的状态
vector<int> rabbitMove(int s) {
	std::vector<int> rt;
	auto bit = decode(s);
	for (int i=0; i<11; i++) {
		if (bit[i] == 2) {
			for (int j:g[i]) {
				if (bit[j] != 0) continue;
				swap(bit[i], bit[j]);
				rt.push_back(encode(bit));
				swap(bit[i], bit[j]);
			}
		}
	}
	return rt;
}

//当前状态下够可转移的状态
vector<int> rabbitMove(vector<int>& bit) {
	std::vector<int> rt;
	for (int i=0; i<11; i++) {
		if (bit[i] == 2) {
			for (int j:g[i]) {
				if (bit[j] != 0) continue;
				swap(bit[i], bit[j]);
				rt.push_back(encode(bit));
				swap(bit[i], bit[j]);
			}
		}
	}
	return rt;
}

int dfs(int s, int u) {
	if (dp[s][u] != 0) return dp[s][u];
	if (u >= 500) return dp[s][u] = 2;


	if (u%2) {//u=1狗动
		auto ns = dogMove(s);
		if (ns.empty()) return dp[s][u] = -1;//狗不能动了，必输。 
		int win = 0, fai = 0, draw = 0;
		for (int i:ns) {
			int rslt = dfs(i, u+1);
			if (rslt == -1) win++;
			if (rslt == 1) fai++;
			if (rslt == 2) draw++;
		} 
		if (win>0) return dp[s][u] = 1;//存在赢，那么当前状态必赢
		if (draw>0) return dp[s][u] = 2;//不存在应，争取和
		return dp[s][u] = -1;//不能赢不能和，必输

	} else {//u=0兔动
		auto ns = rabbitMove(s);
		for (int i:ns) {
			if(i/59049 == 2) return dp[s][u] = 1;//兔子到达终点。 3^10 = 59,049
		}
		if (ns.empty()) return dp[s][u] = -1;//兔不能动了，必输。 
		int win = 0, fai = 0, draw = 0;
		for (int i:ns) {
			int rslt = dfs(i, u+1);
			if (rslt == -1) win++;
			if (rslt == 1) fai++;
			if (rslt == 2) draw++;
		}
		if (win>0) return dp[s][u] = 1;//存在赢，那么当前状态必赢
		if (draw>0) return dp[s][u] = 2;//不存在应，争取和
		return dp[s][u] = -1;//不能赢不能和，必输
	}
}

void imitate(int s, int u) {
	printf("###############current status#################\n");
	printf("%d\n", s);
	statusPrint(s);
	if (u%2) {
		printf("dog will move,following after moving status:\n");
		auto ns = dogMove(s);
		if (ns.empty()) {
			printf("rabbit win\n");
			return;
		}
		for (int i:ns) {
			if(i/59049 == 2) {
				printf("rabbit win\n");
				return;
			}
		}
		int id = 0;
		for (int i:ns) {
			printf("----------------------------------\n");
			printf("id:%d\n", id++);
			statusPrint(i);
			printf("rabbit result in this status:%d\n", dp[i][u+1]);
			printf("----------------------------------\n");
		}
		printf("choose next status id:\n>>");
		scanf("%d", &id);
		imitate(ns[id], u+1);
	} else {
		printf("rabbit will move,following after moving status:\n");
		auto ns = rabbitMove(s);
		if (ns.empty()) {
			printf("dog win\n");
			return;
		}
		int id = 0;
		for (int i:ns) {
			printf("----------------------------------\n");
			printf("id:%d\n", id++);
			statusPrint(i);
			printf("dog result in this status:%d\n", dp[i][u+1]);
			printf("----------------------------------\n");
		}
		printf("choose next status id:\n>>");
		scanf("%d", &id);
		imitate(ns[id], u+1);
	}
}

void sol() {
	// 19983
	// std::vector<int> v = {0,1,0,0,0,1,0,2,0,1,0};
	// statusPrint(v);
	// cout << endl;
	// cout << encode(v) << endl;

	std::vector<int> s = {1,1,0,1,0,0,0,0,0,0,2};
	// statusPrint(s);
	cout << dfs(encode(s), 0) << endl;
	imitate(encode(s), 0);
}

int main() {
	sol();
	return 0;
}