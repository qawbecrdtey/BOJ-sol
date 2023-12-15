#include <iostream>
using namespace std;
struct node {
    node *left;
    node *right;
    int data;
};
node *build_tree(int n) {
    node *root = new node;
    if(n == 1) {
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    root->left = build_tree(n - 1);
    root->right = build_tree(n - 1);
    return root;
}
void set_value(node *root) {
    if(root->left) set_value(root->left);
    cin >> root->data;
    if(root->right) set_value(root->right);
}
void print_depth(node *root, int n) {
    if(n == 1) {
        cout << root->data << ' ';
        return;
    }
    if(root->left) print_depth(root->left, n - 1);
    if(root->right) print_depth(root->right, n - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto tree = build_tree(n);
    set_value(tree);
    for(int i = 1; i <= n; i++) {
        print_depth(tree, i);
        cout << '\n';
    }
}