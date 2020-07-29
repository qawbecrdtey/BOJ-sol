#include <iostream>
using namespace std;
int main(){
    int n,w,h;
    cin>>n>>w>>h;
    int const x=w*w+h*h;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a*a<=x)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}