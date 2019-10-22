#include <iostream>
#include <cmath>
inline double x(double a){return a>0?a:-a;}
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cout<<"Case "<<tt<<": ";
        double a,b;
        cin>>a>>b;
        printf("%.12f\n",x(a-a/tan(b*0.01745329251994329576923690768488612713442871888541725456097191440171009114603449443682241569634509482212304492507379059248385469227528101239847421893404711731916824501501076956169755358123860530516878869127117208703296358960264)));
    }
}