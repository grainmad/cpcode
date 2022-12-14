#include <iostream>
#include <vector>
using namespace std;

vector<int> st;//由栈底到栈顶分别保存fun调用的结果fun(n),fun(n-1),...,fun(0)的结果 
//栈顶两层是已知结果的，通过退栈得到栈底的结果。 

int fun(int n, int x) {
	st.clear();
	if (n == 1) return 2*x;
	if (n == 0) return 1;
	for (int i=n; i>=2; i--) st.push_back(i);
	st.push_back(2*x);
	st.push_back(1);
	while (st.size() > 2) {
		int l = st.back(); st.pop_back();
		int g = st.back(); st.pop_back();
		st.back() = 2*x*g-2*(st.back()-1)*l;
		st.push_back(g); 
	}
	st.pop_back();
	return st.back();
}

int fun2(int n, int x) {
	st.clear();
	st.push_back(1);
	st.push_back(2*x);
	for (int i=2; i<=n; i++) {
		st.push_back(2*x*st[i-1]-2*(i-1)*st[i-2]);
	}
	return st[n];
}

int main() {
	cout << fun(5, 5) << endl;
	cout << fun2(5, 5) << endl;
	return 0;
}
