#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char> st;
    int l=s.length()-1;
    for(;l>=0;l-=3){
        if(l<2){
            if(l==1){
                st.push((char)((s[l-1]-'0')*2+(s[l]-'0')+'0'));
            }
            else{
                st.push((char)(s[l]));
            }
        }
        else{
            st.push((char)((s[l-2]-'0')*4+(s[l-1]-'0')*2+(s[l]-'0')+'0'));
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}