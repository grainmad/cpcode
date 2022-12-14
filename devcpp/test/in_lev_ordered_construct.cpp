#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node *left;
	Node *right;
	Node(int _val=0, Node* _left=NULL, Node* _right=NULL):val(_val), left(_left), right(_right){
	}
};

void inorder_traver(Node* root) {
	if (root == NULL) return;
	inorder_traver(root->left);
	cout << root->val << " ";
	inorder_traver(root->right);
}

void preorder_traver(Node* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	preorder_traver(root->left);
	preorder_traver(root->right);
}

void postorder_traver(Node* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	postorder_traver(root->left);
	postorder_traver(root->right);
}

Node* construct_by_in_lev(vector<int>& in, int l, int r, vector<int>& lev, int& pos) {
	if (l == r || pos == lev.size()) return NULL;
	Node* t = new Node();
	int i;
	for (i=l; i<r; i++) {
		if (in[i] == lev[pos]) break;
	}
	t->val = lev[pos++];
	t->left = construct_by_in_lev(in, l, i, lev, pos);
	t->right = construct_by_in_lev(in, i+1, r, lev, pos);
	return t;
}

int main() {
	vector<int> in = {2, 1, 4, 3, 6, 5};
	vector<int> lev = {1, 2, 3, 4, 5, 6};
	int pos = 0;
	Node* t = construct_by_in_lev(in, 0, 6, lev, pos);
	preorder_traver(t); cout << endl;
	inorder_traver(t); cout << endl;
	postorder_traver(t); cout << endl;
	return 0;
}

