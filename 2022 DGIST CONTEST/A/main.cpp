#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,ans=0,t=900;
    int cnt = 0;
    int gap[3] = {180, 180, 1080};
    int atm[3]={};
    cin>>n>>k;
    while(t < 1440*(n+1)){
        if(t/1440 == n){
            atm[ans++]=t;
        }
        cnt++;
        t+=gap[cnt-1];
        if(cnt==3) {t+=k;cnt=0;}
    }
    cout<<ans<<'\n';
    for(int i=0;i<ans;i++){
        int h = (atm[i]%1440)/60;
        int m = atm[i]%60;
        if(h < 10) cout<< '0' << h << ':';
        else cout << h << ':';
        if(m<10) cout << '0' << m << '\n';
        else cout << m << '\n';
    }
}