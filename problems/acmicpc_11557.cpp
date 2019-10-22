#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<pair<int,string>> pq;
        for(int i=0;i<n;i++){
            string s;
            int m;
            cin>>s>>m;
            pq.push(make_pair(m,s));
        }
        cout<<pq.top().second<<endl;
    }
}