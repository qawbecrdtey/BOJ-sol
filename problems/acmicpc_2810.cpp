#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(s[i]=='L')i++;
        cnt++;
    }
    cout<<(cnt>n?n:cnt);
}