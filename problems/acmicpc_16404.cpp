#include <cassert>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
struct node {
    ll subtree_size;
    vector<node*> children;
    node *parent;
    void *line_ptr;
    ll income;
};
struct hld {
    struct line {
        vector<node*> nodes;
        map<line const*, ll> line_index;
        map<node const*, ll> node_index;
        ll *t;
        line *parent;
        node *top;
    };
};
void get_subtree_size(node *n) {
    n->subtree_size = 1;
    for(auto const next : n->children) {
        get_subtree_size(next);
        n->subtree_size += next->subtree_size;
    }
}
hld::line *initialize_hld(hld &h, hld::line *l, node *n) {
    ll idx;
    bool const is_new = !l;
    if(is_new) {
        l = new hld::line;
        l->nodes = {nullptr, n};
        l->node_index[n] = 1;
        l->t = nullptr;
        l->parent = nullptr;
        l->top = n;
        idx = 1;
    }
    else {
        idx = static_cast<ll>(l->nodes.size());
        l->node_index[n] = idx;
        l->nodes.push_back(n);
    }
    n->line_ptr = l;
    for(auto const next : n->children) {
        if((next->subtree_size << 1) >= n->subtree_size) {
            auto const next_l = initialize_hld(h, l, next);
            assert(next_l == l);
        }
        else {
            auto const next_l = initialize_hld(h, nullptr, next);
            assert(next_l != l);
            l->line_index[next_l] = idx;
            next_l->parent = l;
        }
    }
    if(is_new) {
        l->t = new ll[l->nodes.size() << 2]();
    }
    return l;
}
void update_segment_tree(ll *t, ll tidx, ll idx, ll val, ll l, ll r) {
    if(idx < l || idx > r) return;
    if(l == r) {
        t[tidx] += val;
        return;
    }
    ll const m = (l + r) >> 1;
    update_segment_tree(t, tidx << 1, idx, val, l, m);
    update_segment_tree(t, (tidx << 1) | 1, idx, val, m + 1, r);
    t[tidx] = t[tidx << 1] + t[(tidx << 1) | 1];
}
ll get_sum_segment_tree(ll const *t, ll tidx, ll start, ll end, ll l, ll r) {
    if(end < l || r < start) return 0;
    if(start <= l && r <= end) return t[tidx];
    ll const m = (l + r) >> 1;
    ll const x = get_sum_segment_tree(t, tidx << 1, start, end, l, m);
    ll const y = get_sum_segment_tree(t, (tidx << 1) | 1, start, end, m + 1, r);
    return x + y;
}
inline void update_node(node *n, ll val) {
    n->income += val;
    auto const l = static_cast<hld::line*>(n->line_ptr);
    update_segment_tree(l->t, 1, l->node_index[n], val, 1, static_cast<ll>(l->nodes.size() - 1));
}
ll get_income(hld::line const *l, ll idx) {
    ll res = get_sum_segment_tree(l->t, 1, 1, idx, 1, static_cast<ll>(l->nodes.size() - 1));
    if(l->parent) {
        res += get_income(l->parent, l->parent->line_index[l]);
    }
    return res;
}
inline ll get_income(node *n) {
    auto const l = static_cast<hld::line*>(n->line_ptr);
    return get_income(l, l->node_index[n]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto nodes = new node[n + 1];
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(i == 1) { nodes[i].parent = nullptr; continue; }
        nodes[i].parent = nodes + x;
        nodes[i].line_ptr = nullptr;
        nodes[i].income = 0;
        nodes[x].children.push_back(nodes + i);
    }
    get_subtree_size(nodes + 1);
    hld h;
    initialize_hld(h, nullptr, nodes + 1);
    while(m--) {
        int x, y; cin >> x >> y;
        switch(x) {
            case 1: {
                int z; cin >> z;
                update_node(nodes + y, z);
            } break;
            case 2: {
                cout << get_income(nodes + y) << '\n';
            } break;
            default: __builtin_unreachable();
        }
    }
}