#include <iostream>
#include <string>
using namespace std;
int main() {
    string s; getline(cin, s);
    int sum = 0;
    for(auto c : s) sum += c;
    cout << (char)(sum / s.size());
}