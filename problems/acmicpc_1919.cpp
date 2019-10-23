#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    auto its=s.begin();
    auto itt=t.begin();
    int cnt=0;
    while(its!=s.end()&&itt!=t.end()){
        if(*its<*itt){its++;cnt++;}
        else if(*its>*itt){itt++;cnt++;}
        else {its++;itt++;}
    }
    cout<<cnt+(s.end()-its)+(t.end()-itt);
}