#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
class trie_node {
public:
    static trie_node const *construct(vector<string> const &trie_constructor_strings) {
        auto const root = new trie_node;
        for(auto const &s : trie_constructor_strings) {
            root->add_string(s.cbegin(), s.cend(), root);
        }
        set_fail(root);
        return root;
    }
    static bool match(trie_node const *node, string::const_iterator const &cbegin, string::const_iterator const &cend) {
        if(node->suffix_is_terminal()) {
            return true;
        }
        if(cbegin == cend) {
            if(node == node->fail_) {
                return false;
            }
            return match(node->fail_, cbegin, cend);
        }
        if(int const next_idx = *cbegin - 'a'; node->next_[next_idx]) {
            return match(node->next_[next_idx], cbegin + 1, cend);
        }
        return match(node->fail_, cbegin + (node == node->fail_), cend);
    }
private:
    trie_node *next_[27];
    trie_node const *fail_;
    trie_node const *terminal_nontrivial_suffix_;
    trie_node() : next_{{}}, fail_(nullptr), terminal_nontrivial_suffix_(nullptr) {}
    [[nodiscard]] bool is_terminal() const { return next_[26]; }
    [[nodiscard]] bool nontrivial_suffix_is_terminal() const { return terminal_nontrivial_suffix_; }
    [[nodiscard]] bool suffix_is_terminal() const { return is_terminal() || nontrivial_suffix_is_terminal(); }
    void add_string(string::const_iterator const &cbegin, string::const_iterator const &cend, trie_node const *root) {
        if(cbegin == cend) {
            next_[26] = reinterpret_cast<trie_node*>(1);
            return;
        }
        int const next_idx = *cbegin - 'a';
        if(!next_[next_idx]) {
            next_[next_idx] = new trie_node;
        }
        next_[next_idx]->add_string(cbegin + 1, cend, root);
    }
    static void set_fail(trie_node *root) {
        queue<tuple<trie_node*, trie_node*, int>> q;
        q.emplace(root, nullptr, 26);
        while(!q.empty()) {
            auto const [now, prev, idx] = q.front(); q.pop();
            if(!prev) {
                now->fail_ = nullptr;
            }
            else {
                auto res = prev->fail_;
                while(res && !res->next_[idx]) {
                    res = res->fail_;
                }
                now->fail_ = res ? res->next_[idx] : root;
                if(now->fail_->is_terminal()) {
                    now->terminal_nontrivial_suffix_ = now->fail_;
                }
                else if(now->fail_->nontrivial_suffix_is_terminal()) {
                    now->terminal_nontrivial_suffix_ = now->fail_->terminal_nontrivial_suffix_;
                }
            }
            for(int i = 0; i < 26; i++) {
                if(!now->next_[i]) continue;
                q.emplace(now->next_[i], now, i);
            }
        }
        root->fail_ = root;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<string> trie_constructor_strings;
    trie_constructor_strings.reserve(n);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        trie_constructor_strings.emplace_back(std::move(s));
    }
    auto *const trie_tree = trie_node::construct(trie_constructor_strings);
    cin >> n; while(n--) {
        string s; cin >> s;
        if(trie_node::match(trie_tree, s.cbegin(), s.cend())) cout << "YES\n";
        else cout << "NO\n";
        cout << flush;
    }
}