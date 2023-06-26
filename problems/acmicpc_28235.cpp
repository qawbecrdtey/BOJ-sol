#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    if(s == "SONGDO") cout << "HIGHSCHOOL";
    else if(s == "CODE") cout << "MASTER";
    else if(s == "2023") cout << "0611";
    else cout << "CONTEST";
}