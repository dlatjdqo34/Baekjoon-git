#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int sq[224],n,k,ans =5;
queue<pair<int,int>> q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    k = (int)sqrt(n);
    for(int i=1;i<=k;i++){
        sq[i]=i*i;
    }
    q.push({n,0});
    while(!q.empty()){
        auto x = q.front();
        int num = x.first,d = x.second;
        q.pop();
        int p = (int)sqrt(num);
        if(sq[p]==num){
            ans = d+1;
            break;
        }
        for(int i=p;i>0;i--){
            q.push({num-sq[i],d+1});
        }
    }
    cout<<ans;
}