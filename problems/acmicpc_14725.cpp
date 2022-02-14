#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct node {
    map<string, node*> children;
    node() = default;
};
void insert_node(node *root, queue<string> &q) {
    if(q.empty()) return;
    auto x = move(q.front()); q.pop();
    auto it = root->children.find(x);
    if(it == root->children.end()) {
        root->children[x] = new node;
        it = root->children.find(x);
    }
    insert_node(it->second, q);
}
void print_node(node *root, int depth) {
    for(auto const &it : root->children) {
        cout << string(depth << 1, '-') << it.first << '\n';
        print_node(it.second, depth + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    auto root = new node;
    while(n--) {
        int x; string s;
        queue<string> q;
        cin >> x;
        while(x--) {
            cin >> s;
            q.push(move(s));
        }
        insert_node(root, q);
    }
    print_node(root, 0);
}