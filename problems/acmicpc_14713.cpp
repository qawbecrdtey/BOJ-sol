#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
inline queue<string> split(string const &str) {
    istringstream ss(str);
    string buffer;
    queue<string> result;
    while (getline(ss, buffer, ' ')) {
        result.push(buffer);
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s;
    getline(cin, s);
    int const n = stoi(s);
    list<queue<string>> l;
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        l.push_back(split(s));
    }
    getline(cin, s);
    auto q = split(s);
    while(!q.empty()) {
        auto const now = q.front(); q.pop();
        auto it = l.begin();
        bool flag = false;
        while(it != l.end()) {
            if(it->front() != now) {
                ++it;
                continue;
            }
            it->pop();
            if(it->empty()) it = l.erase(it);
            flag = true;
            break;
        }
        if(!flag) {
            cout << "Impossible";
            return 0;
        }
    }
    if(!l.empty()) cout << "Impossible";
    else cout << "Possible";
}