#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<string,int> m;
        for(int i=0;i<n;i++){
            string a,b;
            cin>>a>>b;
            if(m.find(b)==m.end())m[b]=1;
            else m[b]++;
        }
        long long ans=1;
        for(auto now:m){
            ans*=now.second+1;
        }
        cout<<ans-1<<endl;
    }
}