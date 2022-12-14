#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;

int n = 116;

char s[6][116];
char g[6][116];


void init() {
	for (int i=0; i<6; i++) {
		for (int j=0; j<116; j++) {
			s[i][j] = g[i][j] = ' ';
		}
	}
	for (int i=0; i<6; i++) {
		// s[i][0] = g[i][0] = '>';
		for (int j=0; j<6; j++) {
			s[i][j] = g[i][j] = '>';
		}
		// s[i][6] = g[i][6] = '>';
	}
}

bool isOk() {
	for (int i=0; i<6; i++) {
		for (int j=0; j<116; j++) {
			if (s[i][j] != g[i][j]) return false;
		}
	}
	return true;
}

void swp(int i, int l, int r) {
	while (l < r) {
		swap(g[i][l], g[i][r]);
		l++; r--;
	}
}

void change() {
	for (int i=0; i<6; i++) {
		int t = (i+100);
		swp(i, 0, n-t); 
		swp(i, n-t+1, n-1);
		swp(i, 0, n-1);
	}
}

void print() {
	cout << "draw(\"\n";
	for (int i=0; i<6; i++) {
		for (int j=0; j<116; j++) {
			cout << g[i][j];
		} cout << endl;
	} 
	cout << "\")" << endl;
}

int main() {
	freopen("out.txt", "w", stdout);
	init();
	do {
		change();
		print();
	} while (!isOk());
	return 0;
}