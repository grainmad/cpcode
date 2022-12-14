#include <bits/stdc++.h>

using namespace std;
// Fe2((SO4)3P3)2
// Fe2S6O24P6

struct Node {
	string name;
	int count;
};


/*
可以将输入串拆分子串，所拆分的子串只有这四种情况，大写开头的元素名，数字，左括号，右括号。
通过nextStr函数可以获取子串。
需要一个结构体数组来模拟栈。
思路如下：
不断地通过nextStr获取子串。
当我们读入一个元素名时，紧接着会有字符串
	判断子串的类型：
		1 如果是 元素名 或者 括号，我们在向栈中添加元素，并初始出现次数为1（由于出现一次的元素名不会尾接数字）
		2 如果是数字，将字符串转化为int型。 然后看栈顶（也就是数组尾部）元素是否是右括号
			2.1 是右括号，这个数字对应一对括号里的元素，需要将括号内各个元素出现次数×数字。 具体做法就是用个临时数组存储，注意顺序。
			2.2 不是右括号，说明这个数字是对应单个元素，直接将栈顶元素次数×数字即可。

最后输出结构体数组即可。
*/


//返回值 下一个子串的首位置，s 输入的字符串，rt 得到的子串，pos 在s中的起始位置。
int nextStr(string& s, string& rt, int pos) {
	rt = "";
	if (s[pos] == '(' || s[pos] == ')') {
		rt.push_back(s[pos]);
		return pos+1;
	}
	if (isdigit(s[pos])) {
		while (pos<s.size() && isdigit(s[pos])) rt.push_back(s[pos++]);
		return pos;
	}
	if (isupper(s[pos])) {
		rt.push_back(s[pos++]);
		while (pos<s.size() && islower(s[pos])) rt.push_back(s[pos++]);
		return pos;
	}
}

int main() {
	string s;//输入的字符串
	cin >> s;// 输入 相当于scanf
	vector<Node> st; //结构体数组
	string rt;//每次得到的子串。
	int pos = 0;//每次获取子串的初始位置。
	while (pos<s.size()) {
		pos = nextStr(s, rt, pos);
		if (isdigit(rt[0])) { //子串为数字
			int num = stoi(rt); // string 转 int
			if (st.back().name == ")") {//栈顶判断为右括号。 数字对应一对括号
				st.pop_back(); //移除右括号
				vector<Node> t;
				while (st.back().name != "(") {
					t.push_back(st.back());//添加到临时数组
					st.pop_back();
				}
				st.pop_back(); //移除左括号
				while (!t.empty()) { //将临时数组逆序添加回栈。
					t.back().count *= num;
					st.push_back(t.back());
					t.pop_back();
				}
			} else { //栈顶非右括号，数字是栈顶元素出现的次数
				st.back().count *= num;
			}
		} else { //子串非数字
			st.push_back({rt, 1});
		}
	}
	// for (auto i:st) {
	// 	cout << i.name<<i.count;
	// }
	for (int i=0; i<st.size(); i++) {
		cout << st[i].name << st[i].count;
	}
	return 0;
}