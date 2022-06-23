#include <iostream>
#include <string>
using namespace std;
inline string new_alphabet(char c) {
    switch(c) {
        case 'A':
        case 'a': return "@";
        case 'B':
        case 'b': return "8";
        case 'C':
        case 'c': return "(";
        case 'D':
        case 'd': return "|)";
        case 'E':
        case 'e': return "3";
        case 'F':
        case 'f': return "#";
        case 'G':
        case 'g': return "6";
        case 'H':
        case 'h': return "[-]";
        case 'I':
        case 'i': return "|";
        case 'J':
        case 'j': return "_|";
        case 'K':
        case 'k': return "|<";
        case 'L':
        case 'l': return "1";
        case 'M':
        case 'm': return "[]\\/[]";
        case 'N':
        case 'n': return "[]\\[]";
        case 'O':
        case 'o': return "0";
        case 'P':
        case 'p': return "|D";
        case 'Q':
        case 'q': return "(,)";
        case 'R':
        case 'r': return "|Z";
        case 'S':
        case 's': return "$";
        case 'T':
        case 't': return "']['";
        case 'U':
        case 'u': return "|_|";
        case 'V':
        case 'v': return "\\/";
        case 'W':
        case 'w': return "\\/\\/";
        case 'X':
        case 'x': return "}{";
        case 'Y':
        case 'y': return "`/";
        case 'Z':
        case 'z': return "2";
        default: return string(1, c);
    }
}
inline string convert(string const &s) {
    string res;
    for(char c : s) res += new_alphabet(c);
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; getline(cin, s); cout << convert(s);
}