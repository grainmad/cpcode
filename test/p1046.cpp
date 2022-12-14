#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
using namespace std;

//大数加法, 非负整数a,b
string add(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.size() < b.size()) a.push_back('0');
	while (b.size() < a.size()) b.push_back('0');
	string ans;
	int c = 0;
	for (int i=0; i<a.size(); i++) {
		int num = (a[i]-'0')+(b[i]-'0')+c;
		ans.push_back(num%10+'0');
		c = num/10;
	}
	if (c) ans.push_back(c+'0');
	reverse(ans.begin(), ans.end());
	return ans;
}

//大数比较, 可有前导0, 非负整数
int numcmp(string a, string b) {
	//注意前导0
	if (a.find_first_not_of('0') == string::npos) a = "0";
	else a = a.substr(a.find_first_not_of('0'));
	if (b.find_first_not_of('0') == string::npos) b = "0";
	else b = b.substr(b.find_first_not_of('0'));
	if (a.size() < b.size()) return -1;
	else if (a.size() > b.size()) return 1;
	else {
		if (a<b) return -1;
		else if (a>b) return 1;
		else return 0;
	}
}

//大数减法,非负整数a,b
string sub(string a, string b) {
	bool flag = false;
	if (numcmp(a, b) == 0) return "0";
	if (numcmp(a, b) == -1) {
		flag = true;
		swap(a,b);
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.size()<b.size()) a.push_back('0');
	while (b.size()<a.size()) b.push_back('0');
	string ans;
	int c=0;
	for (int i=0; i<a.size(); i++) {
		int num = (a[i]-'0')-(b[i]-'0')-c;
		if (num<0) {
			num += 10;
			c = 1; 
		} else c = 0;
		ans.push_back(num+'0');
	}
	reverse(ans.begin(), ans.end());
	if (flag) return "-"+ans.substr(ans.find_first_not_of('0'));
	else return ans.substr(ans.find_first_not_of('0'));
} 


//大数乘法, 非负整数
string mul(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ans="0";
	for (int i=0; i<a.size(); i++) {
		string t;
		for (int j=0; j<i; j++) t.push_back('0');
		int c = 0;
		for (int j=0; j<b.size(); j++) {
			int num = (a[i]-'0')*(b[j]-'0')+c;
			t.push_back(num%10+'0');
			c = num/10;
		}
		if (c) t.push_back(c+'0');
		reverse(t.begin(), t.end());
		ans = add(ans, t);
	}
	if (ans.find_first_not_of('0') == string::npos) return "0";//注意乘0情况会得到多个0 
	return ans.substr(ans.find_first_not_of('0'));
}

//大数整除, 非负整数, 返回商和余数
pair<string, string> div(string a, string b) {
	int cp = numcmp(a, b);
	if (cp == 0) return make_pair("1", "0");
	if (cp == -1) return make_pair("0", a);
	string ans, t;
	for (int i=0; i<a.size(); i++) {
		t.push_back(a[i]);
		int c = 0;
		while (numcmp(b, t) != 1) { // b<=t
			t = sub(t, b);
			c++;
		}
		ans.push_back(c+'0');
	}
	//不会出现全零情况 
	return make_pair(ans.substr(ans.find_first_not_of('0')), t); 
}


string pow_mod(string a, string b, string n) {
	string d = "1";
        while (b != "0") {
        if ((b.back()-'0')%2 == 1) d = div(mul(d, a), n).second;
        // a = (a%n)*(a%n)%n;
        a = div(mul(a, a), n).second;
        b = div(b, "2").first;
    }
	return d;
}

void sol() {
	string b, p, k; bool flag = false;
	cin >> b >> p >> k;
	cout << b <<"^" << p << " mod " << k << "=";
	if (b[0] == '-') {
		b = b.substr(1);
		flag = true;
	}
	if ((p.back()-'0')%2 == 0) {
		flag = false;
	}
	if (k[0] == '-') {
		k = k.substr(1);
		flag = !flag;
	}
	if (flag) cout << "-";
	cout << pow_mod(b, p, k) << endl;
}

int main() {
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