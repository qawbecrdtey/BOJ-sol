#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<int> v; int t; cin >> t; while(t--) {
        int n, m; cin >> n; switch(n) {
            case 1:
                cin >> m;
                v.push_back(m);
                break;
            case 2:
                if(v.empty()) cout << "-1\n";
                else { cout << v.back() << '\n'; v.pop_back(); }
                break;
            case 3:
                cout << v.size() << '\n';
                break;
            case 4:
                cout << v.empty() << '\n';
                break;
            case 5:
                if(v.empty()) cout << "-1\n";
                else cout << v.back() << '\n';
                break;
            default: __builtin_unreachable();
        }
    }
}